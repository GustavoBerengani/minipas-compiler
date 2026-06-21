#ifndef MINIPAS_SEMANTIC_HPP
#define MINIPAS_SEMANTIC_HPP

#include "ast.hpp"

#include <string>
#include <unordered_map>
#include <vector>

namespace minipas {

class SemanticAnalyzer {
public:
    bool analyze(const Program &program);
    const std::vector<std::string> &errors() const { return errors_; }

private:
    struct RoutineInfo {
        std::vector<ValueType> parameters;
        ValueType returnType;
    };

    using Scope = std::unordered_map<std::string, ValueType>;

    void report(int line, const std::string &message);
    bool declare(Scope &scope, const std::string &name, ValueType type, int line);
    ValueType lookupVariable(const std::string &name, int line);
    ValueType analyzeExpr(const Expr &expression);
    void analyzeStmt(const Stmt &statement);
    void checkCall(const std::string &name, const ExprList &arguments,
                   ValueType expectedReturn, int line);
    bool containsReturn(const Stmt &statement) const;

    std::vector<std::string> errors_;
    Scope globals_;
    Scope locals_;
    std::unordered_map<std::string, RoutineInfo> routines_;
    ValueType currentReturnType_ = ValueType::Void;
};

std::string typeName(ValueType type);

} // namespace minipas

#endif
