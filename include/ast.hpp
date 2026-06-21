#ifndef MINIPAS_AST_HPP
#define MINIPAS_AST_HPP

#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace minipas {

enum class ValueType { Integer, Boolean, String, Void };

struct Node {
    explicit Node(int lineNumber = 0) : line(lineNumber) {}
    virtual ~Node() = default;
    int line;
};

struct Expr : Node {
    using Node::Node;
};

struct IntegerExpr : Expr {
    IntegerExpr(long long value, int line) : Expr(line), value(value) {}
    long long value;
};

struct BooleanExpr : Expr {
    BooleanExpr(bool value, int line) : Expr(line), value(value) {}
    bool value;
};

struct StringExpr : Expr {
    StringExpr(std::string value, int line) : Expr(line), value(std::move(value)) {}
    std::string value;
};

struct VariableExpr : Expr {
    VariableExpr(std::string name, int line) : Expr(line), name(std::move(name)) {}
    std::string name;
};

struct ArgumentExpr : Expr {
    ArgumentExpr(std::unique_ptr<Expr> index, int line)
        : Expr(line), index(std::move(index)) {}
    std::unique_ptr<Expr> index;
};

struct UnaryExpr : Expr {
    UnaryExpr(std::string op, std::unique_ptr<Expr> operand, int line)
        : Expr(line), op(std::move(op)), operand(std::move(operand)) {}
    std::string op;
    std::unique_ptr<Expr> operand;
};

struct BinaryExpr : Expr {
    BinaryExpr(std::string op, std::unique_ptr<Expr> left,
               std::unique_ptr<Expr> right, int line)
        : Expr(line), op(std::move(op)), left(std::move(left)),
          right(std::move(right)) {}
    std::string op;
    std::unique_ptr<Expr> left;
    std::unique_ptr<Expr> right;
};

struct CallExpr : Expr {
    CallExpr(std::string name, std::vector<std::unique_ptr<Expr>> arguments,
             int line)
        : Expr(line), name(std::move(name)), arguments(std::move(arguments)) {}
    std::string name;
    std::vector<std::unique_ptr<Expr>> arguments;
};

struct Stmt : Node {
    using Node::Node;
};

struct CompoundStmt : Stmt {
    CompoundStmt(std::vector<std::unique_ptr<Stmt>> statements, int line)
        : Stmt(line), statements(std::move(statements)) {}
    std::vector<std::unique_ptr<Stmt>> statements;
};

struct AssignmentStmt : Stmt {
    AssignmentStmt(std::string name, std::unique_ptr<Expr> value, int line)
        : Stmt(line), name(std::move(name)), value(std::move(value)) {}
    std::string name;
    std::unique_ptr<Expr> value;
};

struct IfStmt : Stmt {
    IfStmt(std::unique_ptr<Expr> condition, std::unique_ptr<Stmt> thenBranch,
           std::unique_ptr<Stmt> elseBranch, int line)
        : Stmt(line), condition(std::move(condition)),
          thenBranch(std::move(thenBranch)), elseBranch(std::move(elseBranch)) {}
    std::unique_ptr<Expr> condition;
    std::unique_ptr<Stmt> thenBranch;
    std::unique_ptr<Stmt> elseBranch;
};

struct WhileStmt : Stmt {
    WhileStmt(std::unique_ptr<Expr> condition, std::unique_ptr<Stmt> body,
              int line)
        : Stmt(line), condition(std::move(condition)), body(std::move(body)) {}
    std::unique_ptr<Expr> condition;
    std::unique_ptr<Stmt> body;
};

struct ForStmt : Stmt {
    ForStmt(std::string variable, std::unique_ptr<Expr> start,
            std::unique_ptr<Expr> finish, std::unique_ptr<Stmt> body, int line)
        : Stmt(line), variable(std::move(variable)), start(std::move(start)),
          finish(std::move(finish)), body(std::move(body)) {}
    std::string variable;
    std::unique_ptr<Expr> start;
    std::unique_ptr<Expr> finish;
    std::unique_ptr<Stmt> body;
};

struct WriteStmt : Stmt {
    WriteStmt(std::vector<std::unique_ptr<Expr>> values, bool newline, int line)
        : Stmt(line), values(std::move(values)), newline(newline) {}
    std::vector<std::unique_ptr<Expr>> values;
    bool newline;
};

struct CallStmt : Stmt {
    CallStmt(std::string name, std::vector<std::unique_ptr<Expr>> arguments,
             int line)
        : Stmt(line), name(std::move(name)), arguments(std::move(arguments)) {}
    std::string name;
    std::vector<std::unique_ptr<Expr>> arguments;
};

struct ReturnStmt : Stmt {
    ReturnStmt(std::unique_ptr<Expr> value, int line)
        : Stmt(line), value(std::move(value)) {}
    std::unique_ptr<Expr> value;
};

struct VarDecl {
    std::string name;
    ValueType type;
    int line;
};

struct ParamDecl {
    std::string name;
    ValueType type;
    int line;
};

struct RoutineDecl : Node {
    using Node::Node;
    std::string name;
    std::vector<ParamDecl> parameters;
    ValueType returnType = ValueType::Void;
    std::vector<VarDecl> variables;
    std::unique_ptr<CompoundStmt> body;
};

struct Program : Node {
    using Node::Node;
    std::string name;
    std::vector<VarDecl> globals;
    std::vector<std::unique_ptr<RoutineDecl>> routines;
    std::unique_ptr<CompoundStmt> body;
};

using ExprList = std::vector<std::unique_ptr<Expr>>;
using StmtList = std::vector<std::unique_ptr<Stmt>>;
using VarDeclList = std::vector<VarDecl>;
using ParamList = std::vector<ParamDecl>;
using RoutineList = std::vector<std::unique_ptr<RoutineDecl>>;
using IdentifierList = std::vector<std::string>;

} // namespace minipas

#endif
