#ifndef MINIPAS_CODEGEN_HPP
#define MINIPAS_CODEGEN_HPP

#include "ast.hpp"

#include <llvm/IR/IRBuilder.h>

#include <memory>
#include <string>
#include <unordered_map>

namespace llvm {
class AllocaInst;
class Function;
class GlobalVariable;
class LLVMContext;
class Module;
class Type;
class Value;
} // namespace llvm

namespace minipas {

class CodeGenerator {
public:
    CodeGenerator();
    ~CodeGenerator();

    bool generate(const Program &program, const std::string &irPath);
    const std::string &error() const { return error_; }

private:
    struct Variable {
        ValueType type;
        llvm::Value *address;
    };

    llvm::Type *llvmType(ValueType type) const;
    llvm::AllocaInst *createEntryAlloca(llvm::Function *function,
                                        ValueType type,
                                        const std::string &name);
    Variable *findVariable(const std::string &name);
    llvm::Value *generateExpr(const Expr &expression);
    ValueType expressionType(const Expr &expression);
    void generateStmt(const Stmt &statement);
    bool generateRoutine(const RoutineDecl &routine);
    llvm::Function *declareRoutine(const RoutineDecl &routine);
    llvm::Value *generateCall(const std::string &name,
                              const ExprList &arguments, int line);
    void emitWriteValue(const Expr &expression);
    void setError(int line, const std::string &message);

    std::unique_ptr<llvm::LLVMContext> context_;
    std::unique_ptr<llvm::Module> module_;
    std::unique_ptr<llvm::IRBuilder<>> builder_;
    std::unordered_map<std::string, Variable> globals_;
    std::unordered_map<std::string, Variable> locals_;
    std::unordered_map<std::string, llvm::Function *> routines_;
    llvm::Function *printfFunction_ = nullptr;
    llvm::Function *atoiFunction_ = nullptr;
    llvm::GlobalVariable *argcGlobal_ = nullptr;
    llvm::GlobalVariable *argvGlobal_ = nullptr;
    std::string error_;
};

} // namespace minipas

#endif
