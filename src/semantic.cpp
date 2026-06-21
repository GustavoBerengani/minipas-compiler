#include "semantic.hpp"

#include <algorithm>
#include <sstream>

namespace minipas {

std::string typeName(ValueType type) {
    switch (type) {
    case ValueType::Integer: return "integer";
    case ValueType::Boolean: return "boolean";
    case ValueType::String: return "string";
    case ValueType::Void: return "void";
    }
    return "unknown";
}

void SemanticAnalyzer::report(int line, const std::string &message) {
    std::ostringstream output;
    output << "linha " << line << ": " << message;
    errors_.push_back(output.str());
}

bool SemanticAnalyzer::declare(Scope &scope, const std::string &name,
                               ValueType type, int line) {
    if (scope.count(name) != 0) {
        report(line, "identificador '" + name + "' ja foi declarado");
        return false;
    }
    scope[name] = type;
    return true;
}

ValueType SemanticAnalyzer::lookupVariable(const std::string &name, int line) {
    auto local = locals_.find(name);
    if (local != locals_.end()) return local->second;
    auto global = globals_.find(name);
    if (global != globals_.end()) return global->second;
    report(line, "variavel '" + name + "' nao foi declarada");
    return ValueType::Void;
}

void SemanticAnalyzer::checkCall(const std::string &name,
                                 const ExprList &arguments,
                                 ValueType expectedReturn, int line) {
    auto found = routines_.find(name);
    if (found == routines_.end()) {
        report(line, "rotina '" + name + "' nao foi declarada");
        for (const auto &argument : arguments) analyzeExpr(*argument);
        return;
    }

    const RoutineInfo &routine = found->second;
    if (routine.returnType != expectedReturn) {
        if (expectedReturn == ValueType::Void)
            report(line, "a funcao '" + name + "' nao pode ser usada como comando");
        else
            report(line, "o procedimento '" + name + "' nao retorna valor");
    }

    if (arguments.size() != routine.parameters.size()) {
        report(line, "rotina '" + name + "' esperava " +
                     std::to_string(routine.parameters.size()) +
                     " argumento(s), mas recebeu " +
                     std::to_string(arguments.size()));
    }

    const std::size_t count = std::min(arguments.size(), routine.parameters.size());
    for (std::size_t i = 0; i < arguments.size(); ++i) {
        ValueType received = analyzeExpr(*arguments[i]);
        if (i < count && received != ValueType::Void &&
            received != routine.parameters[i]) {
            report(arguments[i]->line, "argumento " + std::to_string(i + 1) +
                   " de '" + name + "' deveria ser " +
                   typeName(routine.parameters[i]) + ", mas recebeu " +
                   typeName(received));
        }
    }
}

ValueType SemanticAnalyzer::analyzeExpr(const Expr &expression) {
    if (dynamic_cast<const IntegerExpr *>(&expression)) return ValueType::Integer;
    if (dynamic_cast<const BooleanExpr *>(&expression)) return ValueType::Boolean;
    if (dynamic_cast<const StringExpr *>(&expression)) return ValueType::String;

    if (auto variable = dynamic_cast<const VariableExpr *>(&expression))
        return lookupVariable(variable->name, variable->line);

    if (auto argument = dynamic_cast<const ArgumentExpr *>(&expression)) {
        ValueType indexType = analyzeExpr(*argument->index);
        if (indexType != ValueType::Integer && indexType != ValueType::Void)
            report(argument->line, "o indice de param deve ser integer");
        return ValueType::Integer;
    }

    if (auto unary = dynamic_cast<const UnaryExpr *>(&expression)) {
        ValueType operand = analyzeExpr(*unary->operand);
        ValueType expected = unary->op == "not" ? ValueType::Boolean
                                                : ValueType::Integer;
        if (operand != expected && operand != ValueType::Void)
            report(unary->line, "operador '" + unary->op + "' exige " +
                   typeName(expected));
        return expected;
    }

    if (auto binary = dynamic_cast<const BinaryExpr *>(&expression)) {
        ValueType left = analyzeExpr(*binary->left);
        ValueType right = analyzeExpr(*binary->right);
        const std::string &op = binary->op;

        if (op == "and" || op == "or") {
            if (left != ValueType::Boolean || right != ValueType::Boolean)
                report(binary->line, "operador '" + op + "' exige boolean nos dois lados");
            return ValueType::Boolean;
        }
        if (op == "=" || op == "<>") {
            if (left != right || left == ValueType::String || left == ValueType::Void)
                report(binary->line, "comparacao '" + op + "' recebeu tipos incompativeis");
            return ValueType::Boolean;
        }
        if (op == "<" || op == "<=" || op == ">" || op == ">=") {
            if (left != ValueType::Integer || right != ValueType::Integer)
                report(binary->line, "comparacao '" + op + "' exige integer");
            return ValueType::Boolean;
        }
        if (left != ValueType::Integer || right != ValueType::Integer)
            report(binary->line, "operador '" + op + "' exige integer");
        return ValueType::Integer;
    }

    if (auto call = dynamic_cast<const CallExpr *>(&expression)) {
        auto found = routines_.find(call->name);
        if (found == routines_.end()) {
            checkCall(call->name, call->arguments, ValueType::Void, call->line);
            return ValueType::Void;
        }
        ValueType result = found->second.returnType;
        checkCall(call->name, call->arguments, result, call->line);
        if (result == ValueType::Void)
            report(call->line, "procedimento '" + call->name + "' usado em expressao");
        return result;
    }

    report(expression.line, "expressao interna desconhecida");
    return ValueType::Void;
}

void SemanticAnalyzer::analyzeStmt(const Stmt &statement) {
    if (auto compound = dynamic_cast<const CompoundStmt *>(&statement)) {
        for (const auto &child : compound->statements) analyzeStmt(*child);
        return;
    }
    if (auto assignment = dynamic_cast<const AssignmentStmt *>(&statement)) {
        ValueType variable = lookupVariable(assignment->name, assignment->line);
        ValueType value = analyzeExpr(*assignment->value);
        if (variable != ValueType::Void && value != ValueType::Void && variable != value)
            report(assignment->line, "atribuicao para '" + assignment->name +
                   "' esperava " + typeName(variable) + ", mas recebeu " +
                   typeName(value));
        return;
    }
    if (auto conditional = dynamic_cast<const IfStmt *>(&statement)) {
        if (analyzeExpr(*conditional->condition) != ValueType::Boolean)
            report(conditional->line, "a condicao do if deve ser boolean");
        analyzeStmt(*conditional->thenBranch);
        if (conditional->elseBranch) analyzeStmt(*conditional->elseBranch);
        return;
    }
    if (auto loop = dynamic_cast<const WhileStmt *>(&statement)) {
        if (analyzeExpr(*loop->condition) != ValueType::Boolean)
            report(loop->line, "a condicao do while deve ser boolean");
        analyzeStmt(*loop->body);
        return;
    }
    if (auto loop = dynamic_cast<const ForStmt *>(&statement)) {
        if (lookupVariable(loop->variable, loop->line) != ValueType::Integer)
            report(loop->line, "a variavel do for deve ser integer");
        if (analyzeExpr(*loop->start) != ValueType::Integer ||
            analyzeExpr(*loop->finish) != ValueType::Integer)
            report(loop->line, "os limites do for devem ser integer");
        analyzeStmt(*loop->body);
        return;
    }
    if (auto write = dynamic_cast<const WriteStmt *>(&statement)) {
        for (const auto &value : write->values) analyzeExpr(*value);
        return;
    }
    if (auto call = dynamic_cast<const CallStmt *>(&statement)) {
        checkCall(call->name, call->arguments, ValueType::Void, call->line);
        return;
    }
    if (auto result = dynamic_cast<const ReturnStmt *>(&statement)) {
        if (currentReturnType_ == ValueType::Void) {
            report(result->line, "return so pode ser usado dentro de funcao");
        } else {
            ValueType value = analyzeExpr(*result->value);
            if (value != currentReturnType_ && value != ValueType::Void)
                report(result->line, "return deveria devolver " +
                       typeName(currentReturnType_) + ", mas recebeu " +
                       typeName(value));
        }
        return;
    }
    report(statement.line, "comando interno desconhecido");
}

bool SemanticAnalyzer::containsReturn(const Stmt &statement) const {
    if (dynamic_cast<const ReturnStmt *>(&statement)) return true;
    if (auto block = dynamic_cast<const CompoundStmt *>(&statement)) {
        for (const auto &child : block->statements)
            if (containsReturn(*child)) return true;
    } else if (auto conditional = dynamic_cast<const IfStmt *>(&statement)) {
        if (containsReturn(*conditional->thenBranch)) return true;
        return conditional->elseBranch && containsReturn(*conditional->elseBranch);
    } else if (auto loop = dynamic_cast<const WhileStmt *>(&statement)) {
        return containsReturn(*loop->body);
    } else if (auto loop = dynamic_cast<const ForStmt *>(&statement)) {
        return containsReturn(*loop->body);
    }
    return false;
}

bool SemanticAnalyzer::analyze(const Program &program) {
    errors_.clear();
    globals_.clear();
    locals_.clear();
    routines_.clear();

    for (const VarDecl &variable : program.globals)
        declare(globals_, variable.name, variable.type, variable.line);

    for (const auto &routine : program.routines) {
        if (routines_.count(routine->name) != 0) {
            report(routine->line, "rotina '" + routine->name + "' ja foi declarada");
            continue;
        }
        RoutineInfo info;
        info.returnType = routine->returnType;
        for (const ParamDecl &parameter : routine->parameters)
            info.parameters.push_back(parameter.type);
        routines_[routine->name] = std::move(info);
    }

    for (const auto &routine : program.routines) {
        locals_.clear();
        currentReturnType_ = routine->returnType;
        for (const ParamDecl &parameter : routine->parameters)
            declare(locals_, parameter.name, parameter.type, parameter.line);
        for (const VarDecl &variable : routine->variables)
            declare(locals_, variable.name, variable.type, variable.line);
        analyzeStmt(*routine->body);
        if (routine->returnType != ValueType::Void &&
            !containsReturn(*routine->body))
            report(routine->line, "funcao '" + routine->name + "' nao possui return");
    }

    locals_.clear();
    currentReturnType_ = ValueType::Void;
    analyzeStmt(*program.body);
    return errors_.empty();
}

} // namespace minipas
