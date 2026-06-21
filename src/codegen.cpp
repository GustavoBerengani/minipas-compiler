#include "codegen.hpp"

#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/raw_ostream.h>

#include <system_error>

namespace minipas {

CodeGenerator::CodeGenerator()
    : context_(std::make_unique<llvm::LLVMContext>()),
      builder_(std::make_unique<llvm::IRBuilder<>>(*context_)) {}

CodeGenerator::~CodeGenerator() = default;

llvm::Type *CodeGenerator::llvmType(ValueType type) const {
    switch (type) {
    case ValueType::Integer: return llvm::Type::getInt64Ty(*context_);
    case ValueType::Boolean: return llvm::Type::getInt1Ty(*context_);
    case ValueType::String: return llvm::Type::getInt8PtrTy(*context_);
    case ValueType::Void: return llvm::Type::getVoidTy(*context_);
    }
    return llvm::Type::getVoidTy(*context_);
}

void CodeGenerator::setError(int line, const std::string &message) {
    if (error_.empty())
        error_ = "linha " + std::to_string(line) + ": " + message;
}

llvm::AllocaInst *CodeGenerator::createEntryAlloca(llvm::Function *function,
                                                   ValueType type,
                                                   const std::string &name) {
    llvm::IRBuilder<> temporary(&function->getEntryBlock(),
                                function->getEntryBlock().begin());
    return temporary.CreateAlloca(llvmType(type), nullptr, name);
}

CodeGenerator::Variable *CodeGenerator::findVariable(const std::string &name) {
    auto local = locals_.find(name);
    if (local != locals_.end()) return &local->second;
    auto global = globals_.find(name);
    return global == globals_.end() ? nullptr : &global->second;
}

ValueType CodeGenerator::expressionType(const Expr &expression) {
    if (dynamic_cast<const IntegerExpr *>(&expression) ||
        dynamic_cast<const ArgumentExpr *>(&expression))
        return ValueType::Integer;
    if (dynamic_cast<const BooleanExpr *>(&expression)) return ValueType::Boolean;
    if (dynamic_cast<const StringExpr *>(&expression)) return ValueType::String;
    if (auto variable = dynamic_cast<const VariableExpr *>(&expression)) {
        Variable *found = findVariable(variable->name);
        return found ? found->type : ValueType::Void;
    }
    if (auto unary = dynamic_cast<const UnaryExpr *>(&expression))
        return unary->op == "not" ? ValueType::Boolean : ValueType::Integer;
    if (auto binary = dynamic_cast<const BinaryExpr *>(&expression)) {
        const std::string &op = binary->op;
        if (op == "and" || op == "or" || op == "=" || op == "<>" ||
            op == "<" || op == "<=" || op == ">" || op == ">=")
            return ValueType::Boolean;
        return ValueType::Integer;
    }
    if (auto call = dynamic_cast<const CallExpr *>(&expression)) {
        auto found = routines_.find(call->name);
        if (found == routines_.end()) return ValueType::Void;
        return found->second->getReturnType()->isIntegerTy(1)
                   ? ValueType::Boolean : ValueType::Integer;
    }
    return ValueType::Void;
}

llvm::Value *CodeGenerator::generateCall(const std::string &name,
                                         const ExprList &arguments, int line) {
    auto found = routines_.find(name);
    if (found == routines_.end()) {
        setError(line, "rotina desconhecida durante geracao: " + name);
        return nullptr;
    }
    std::vector<llvm::Value *> values;
    for (const auto &argument : arguments) {
        llvm::Value *value = generateExpr(*argument);
        if (!value) return nullptr;
        values.push_back(value);
    }
    return builder_->CreateCall(found->second, values,
        found->second->getReturnType()->isVoidTy() ? "" : name + ".result");
}

llvm::Value *CodeGenerator::generateExpr(const Expr &expression) {
    if (auto integer = dynamic_cast<const IntegerExpr *>(&expression))
        return llvm::ConstantInt::get(llvmType(ValueType::Integer),
                                      integer->value, true);
    if (auto boolean = dynamic_cast<const BooleanExpr *>(&expression))
        return llvm::ConstantInt::get(llvmType(ValueType::Boolean), boolean->value);
    if (auto text = dynamic_cast<const StringExpr *>(&expression))
        return builder_->CreateGlobalStringPtr(text->value);
    if (auto variable = dynamic_cast<const VariableExpr *>(&expression)) {
        Variable *found = findVariable(variable->name);
        if (!found) {
            setError(variable->line, "variavel desconhecida: " + variable->name);
            return nullptr;
        }
        return builder_->CreateLoad(llvmType(found->type), found->address,
                                    variable->name + ".value");
    }
    if (auto argument = dynamic_cast<const ArgumentExpr *>(&expression)) {
        llvm::Value *index = generateExpr(*argument->index);
        if (!index) return nullptr;
        llvm::Type *characterPointer = llvm::Type::getInt8PtrTy(*context_);
        llvm::Value *argv = builder_->CreateLoad(argvGlobal_->getValueType(),
                                                 argvGlobal_, "argv.value");
        llvm::Value *slot = builder_->CreateInBoundsGEP(characterPointer, argv,
                                                        index, "argv.slot");
        llvm::Value *text = builder_->CreateLoad(characterPointer, slot, "argv.text");
        llvm::Value *number32 = builder_->CreateCall(atoiFunction_, {text}, "arg.number");
        return builder_->CreateSExt(number32, llvmType(ValueType::Integer), "arg.integer");
    }
    if (auto unary = dynamic_cast<const UnaryExpr *>(&expression)) {
        llvm::Value *operand = generateExpr(*unary->operand);
        if (!operand) return nullptr;
        return unary->op == "not" ? builder_->CreateNot(operand, "not.value")
                                   : builder_->CreateNeg(operand, "negative.value");
    }
    if (auto binary = dynamic_cast<const BinaryExpr *>(&expression)) {
        llvm::Value *left = generateExpr(*binary->left);
        llvm::Value *right = generateExpr(*binary->right);
        if (!left || !right) return nullptr;
        const std::string &op = binary->op;
        if (op == "+") return builder_->CreateAdd(left, right, "add.value");
        if (op == "-") return builder_->CreateSub(left, right, "sub.value");
        if (op == "*") return builder_->CreateMul(left, right, "mul.value");
        if (op == "/") return builder_->CreateSDiv(left, right, "div.value");
        if (op == "mod") return builder_->CreateSRem(left, right, "mod.value");
        if (op == "and") return builder_->CreateAnd(left, right, "and.value");
        if (op == "or") return builder_->CreateOr(left, right, "or.value");
        if (op == "=") return builder_->CreateICmpEQ(left, right, "equal.value");
        if (op == "<>") return builder_->CreateICmpNE(left, right, "different.value");
        if (op == "<") return builder_->CreateICmpSLT(left, right, "less.value");
        if (op == "<=") return builder_->CreateICmpSLE(left, right, "lesseq.value");
        if (op == ">") return builder_->CreateICmpSGT(left, right, "greater.value");
        if (op == ">=") return builder_->CreateICmpSGE(left, right, "greatereq.value");
        setError(binary->line, "operador desconhecido: " + op);
        return nullptr;
    }
    if (auto call = dynamic_cast<const CallExpr *>(&expression))
        return generateCall(call->name, call->arguments, call->line);
    setError(expression.line, "expressao desconhecida na geracao LLVM");
    return nullptr;
}

void CodeGenerator::emitWriteValue(const Expr &expression) {
    llvm::Value *value = generateExpr(expression);
    if (!value) return;
    ValueType type = expressionType(expression);
    if (type == ValueType::Integer) {
        llvm::Value *format = builder_->CreateGlobalStringPtr("%lld");
        builder_->CreateCall(printfFunction_, {format, value});
    } else if (type == ValueType::Boolean) {
        llvm::Value *trueText = builder_->CreateGlobalStringPtr("true");
        llvm::Value *falseText = builder_->CreateGlobalStringPtr("false");
        llvm::Value *text = builder_->CreateSelect(value, trueText, falseText);
        llvm::Value *format = builder_->CreateGlobalStringPtr("%s");
        builder_->CreateCall(printfFunction_, {format, text});
    } else if (type == ValueType::String) {
        llvm::Value *format = builder_->CreateGlobalStringPtr("%s");
        builder_->CreateCall(printfFunction_, {format, value});
    }
}

void CodeGenerator::generateStmt(const Stmt &statement) {
    if (!error_.empty() || builder_->GetInsertBlock()->getTerminator()) return;
    if (auto block = dynamic_cast<const CompoundStmt *>(&statement)) {
        for (const auto &child : block->statements) generateStmt(*child);
        return;
    }
    if (auto assignment = dynamic_cast<const AssignmentStmt *>(&statement)) {
        Variable *variable = findVariable(assignment->name);
        llvm::Value *value = generateExpr(*assignment->value);
        if (variable && value) builder_->CreateStore(value, variable->address);
        return;
    }
    if (auto conditional = dynamic_cast<const IfStmt *>(&statement)) {
        llvm::Value *condition = generateExpr(*conditional->condition);
        llvm::Function *function = builder_->GetInsertBlock()->getParent();
        llvm::BasicBlock *thenBlock = llvm::BasicBlock::Create(*context_, "if.then", function);
        llvm::BasicBlock *endBlock = llvm::BasicBlock::Create(*context_, "if.end", function);
        llvm::BasicBlock *elseBlock = conditional->elseBranch
            ? llvm::BasicBlock::Create(*context_, "if.else", function) : endBlock;
        builder_->CreateCondBr(condition, thenBlock, elseBlock);
        builder_->SetInsertPoint(thenBlock);
        generateStmt(*conditional->thenBranch);
        if (!builder_->GetInsertBlock()->getTerminator()) builder_->CreateBr(endBlock);
        if (conditional->elseBranch) {
            builder_->SetInsertPoint(elseBlock);
            generateStmt(*conditional->elseBranch);
            if (!builder_->GetInsertBlock()->getTerminator()) builder_->CreateBr(endBlock);
        }
        builder_->SetInsertPoint(endBlock);
        return;
    }
    if (auto loop = dynamic_cast<const WhileStmt *>(&statement)) {
        llvm::Function *function = builder_->GetInsertBlock()->getParent();
        llvm::BasicBlock *conditionBlock = llvm::BasicBlock::Create(*context_, "while.cond", function);
        llvm::BasicBlock *bodyBlock = llvm::BasicBlock::Create(*context_, "while.body", function);
        llvm::BasicBlock *endBlock = llvm::BasicBlock::Create(*context_, "while.end", function);
        builder_->CreateBr(conditionBlock);
        builder_->SetInsertPoint(conditionBlock);
        llvm::Value *condition = generateExpr(*loop->condition);
        builder_->CreateCondBr(condition, bodyBlock, endBlock);
        builder_->SetInsertPoint(bodyBlock);
        generateStmt(*loop->body);
        if (!builder_->GetInsertBlock()->getTerminator()) builder_->CreateBr(conditionBlock);
        builder_->SetInsertPoint(endBlock);
        return;
    }
    if (auto loop = dynamic_cast<const ForStmt *>(&statement)) {
        Variable *variable = findVariable(loop->variable);
        llvm::Value *start = generateExpr(*loop->start);
        builder_->CreateStore(start, variable->address);
        llvm::Function *function = builder_->GetInsertBlock()->getParent();
        llvm::BasicBlock *conditionBlock = llvm::BasicBlock::Create(*context_, "for.cond", function);
        llvm::BasicBlock *bodyBlock = llvm::BasicBlock::Create(*context_, "for.body", function);
        llvm::BasicBlock *endBlock = llvm::BasicBlock::Create(*context_, "for.end", function);
        builder_->CreateBr(conditionBlock);
        builder_->SetInsertPoint(conditionBlock);
        llvm::Value *current = builder_->CreateLoad(llvmType(ValueType::Integer),
                                                     variable->address, "for.value");
        llvm::Value *finish = generateExpr(*loop->finish);
        builder_->CreateCondBr(builder_->CreateICmpSLE(current, finish), bodyBlock, endBlock);
        builder_->SetInsertPoint(bodyBlock);
        generateStmt(*loop->body);
        if (!builder_->GetInsertBlock()->getTerminator()) {
            current = builder_->CreateLoad(llvmType(ValueType::Integer), variable->address);
            llvm::Value *next = builder_->CreateAdd(current,
                llvm::ConstantInt::get(llvmType(ValueType::Integer), 1));
            builder_->CreateStore(next, variable->address);
            builder_->CreateBr(conditionBlock);
        }
        builder_->SetInsertPoint(endBlock);
        return;
    }
    if (auto write = dynamic_cast<const WriteStmt *>(&statement)) {
        for (const auto &value : write->values) emitWriteValue(*value);
        if (write->newline) {
            llvm::Value *newline = builder_->CreateGlobalStringPtr("\n");
            builder_->CreateCall(printfFunction_, {newline});
        }
        return;
    }
    if (auto call = dynamic_cast<const CallStmt *>(&statement)) {
        generateCall(call->name, call->arguments, call->line);
        return;
    }
    if (auto result = dynamic_cast<const ReturnStmt *>(&statement)) {
        llvm::Value *value = generateExpr(*result->value);
        if (value) builder_->CreateRet(value);
        return;
    }
    setError(statement.line, "comando desconhecido na geracao LLVM");
}

llvm::Function *CodeGenerator::declareRoutine(const RoutineDecl &routine) {
    std::vector<llvm::Type *> parameterTypes;
    for (const ParamDecl &parameter : routine.parameters)
        parameterTypes.push_back(llvmType(parameter.type));
    llvm::FunctionType *type = llvm::FunctionType::get(llvmType(routine.returnType),
                                                       parameterTypes, false);
    llvm::Function *function = llvm::Function::Create(type,
        llvm::Function::ExternalLinkage, routine.name, module_.get());
    routines_[routine.name] = function;
    return function;
}

bool CodeGenerator::generateRoutine(const RoutineDecl &routine) {
    llvm::Function *function = routines_.at(routine.name);
    llvm::BasicBlock *entry = llvm::BasicBlock::Create(*context_, "entry", function);
    builder_->SetInsertPoint(entry);
    locals_.clear();
    std::size_t index = 0;
    for (llvm::Argument &argument : function->args()) {
        const ParamDecl &parameter = routine.parameters[index++];
        argument.setName(parameter.name);
        llvm::AllocaInst *storage = createEntryAlloca(function, parameter.type,
                                                       parameter.name);
        builder_->CreateStore(&argument, storage);
        locals_[parameter.name] = {parameter.type, storage};
    }
    for (const VarDecl &variable : routine.variables) {
        llvm::AllocaInst *storage = createEntryAlloca(function, variable.type,
                                                       variable.name);
        builder_->CreateStore(llvm::Constant::getNullValue(llvmType(variable.type)), storage);
        locals_[variable.name] = {variable.type, storage};
    }
    generateStmt(*routine.body);
    if (!builder_->GetInsertBlock()->getTerminator()) {
        if (routine.returnType == ValueType::Void) builder_->CreateRetVoid();
        else builder_->CreateRet(llvm::Constant::getNullValue(llvmType(routine.returnType)));
    }
    return error_.empty();
}

bool CodeGenerator::generate(const Program &program, const std::string &irPath) {
    error_.clear();
    globals_.clear();
    locals_.clear();
    routines_.clear();
    module_ = std::make_unique<llvm::Module>(program.name, *context_);
    module_->setSourceFileName(program.name + ".pas");
    llvm::Type *i8Pointer = llvm::Type::getInt8PtrTy(*context_);
    llvm::Type *i32 = llvm::Type::getInt32Ty(*context_);
    llvm::FunctionType *printfType = llvm::FunctionType::get(i32, {i8Pointer}, true);
    printfFunction_ = llvm::Function::Create(printfType,
        llvm::Function::ExternalLinkage, "printf", module_.get());
    llvm::FunctionType *atoiType = llvm::FunctionType::get(i32, {i8Pointer}, false);
    atoiFunction_ = llvm::Function::Create(atoiType,
        llvm::Function::ExternalLinkage, "atoi", module_.get());
    argcGlobal_ = new llvm::GlobalVariable(*module_, i32, false,
        llvm::GlobalValue::InternalLinkage, llvm::ConstantInt::get(i32, 0),
        "__minipas_argc");
    llvm::Type *argvType = i8Pointer->getPointerTo();
    argvGlobal_ = new llvm::GlobalVariable(*module_, argvType, false,
        llvm::GlobalValue::InternalLinkage,
        llvm::ConstantPointerNull::get(llvm::cast<llvm::PointerType>(argvType)),
        "__minipas_argv");

    for (const VarDecl &variable : program.globals) {
        llvm::Type *type = llvmType(variable.type);
        auto *global = new llvm::GlobalVariable(*module_, type, false,
            llvm::GlobalValue::InternalLinkage, llvm::Constant::getNullValue(type),
            variable.name);
        globals_[variable.name] = {variable.type, global};
    }
    for (const auto &routine : program.routines) declareRoutine(*routine);
    for (const auto &routine : program.routines)
        if (!generateRoutine(*routine)) return false;

    llvm::FunctionType *mainType = llvm::FunctionType::get(i32, {i32, argvType}, false);
    llvm::Function *mainFunction = llvm::Function::Create(mainType,
        llvm::Function::ExternalLinkage, "main", module_.get());
    auto argument = mainFunction->arg_begin();
    llvm::Argument *argc = &*argument++;
    llvm::Argument *argv = &*argument;
    argc->setName("argc");
    argv->setName("argv");
    llvm::BasicBlock *entry = llvm::BasicBlock::Create(*context_, "entry", mainFunction);
    builder_->SetInsertPoint(entry);
    builder_->CreateStore(argc, argcGlobal_);
    builder_->CreateStore(argv, argvGlobal_);
    locals_.clear();
    generateStmt(*program.body);
    if (!builder_->GetInsertBlock()->getTerminator())
        builder_->CreateRet(llvm::ConstantInt::get(i32, 0));
    if (!error_.empty()) return false;

    std::string verification;
    llvm::raw_string_ostream verificationStream(verification);
    if (llvm::verifyModule(*module_, &verificationStream)) {
        verificationStream.flush();
        error_ = "LLVM gerou um modulo invalido:\n" + verification;
        return false;
    }
    std::error_code fileError;
    llvm::raw_fd_ostream output(irPath, fileError, llvm::sys::fs::OF_Text);
    if (fileError) {
        error_ = "nao foi possivel criar '" + irPath + "': " + fileError.message();
        return false;
    }
    module_->print(output, nullptr);
    return true;
}

} // namespace minipas
