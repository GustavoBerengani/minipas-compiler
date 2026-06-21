%{
#include "ast.hpp"
#include "parser_state.hpp"

#include <cstdlib>
#include <memory>
#include <string>

int yylex(void);
void yyerror(const char *message);
%}

%code requires {
#include "ast.hpp"
}

%define parse.error detailed
%locations

%union {
    long long integer;
    char *text;
    minipas::ValueType type;
    minipas::Expr *expr;
    minipas::Stmt *stmt;
    minipas::VarDeclList *var_list;
    minipas::ParamList *param_list;
    minipas::RoutineDecl *routine;
    minipas::RoutineList *routine_list;
    minipas::IdentifierList *identifier_list;
    minipas::ExprList *expr_list;
    minipas::StmtList *stmt_list;
}

%token PROGRAM VAR BEGIN_TOKEN END_TOKEN
%token FUNCTION PROCEDURE RETURN_TOKEN
%token INTEGER_TYPE BOOLEAN_TYPE TRUE_TOKEN FALSE_TOKEN
%token IF THEN ELSE WHILE DO FOR TO
%token WRITE WRITELN PARAM
%token AND OR NOT MOD
%token ASSIGN EQUAL NOT_EQUAL LT LTE GT GTE
%token PLUS MINUS STAR SLASH
%token LPAREN RPAREN COMMA SEMICOLON COLON DOT
%token <integer> INTEGER_LITERAL
%token <text> IDENTIFIER STRING_LITERAL

%type <type> type_specifier
%type <var_list> declarations_opt var_declaration_list
%type <identifier_list> identifier_list
%type <param_list> parameters_opt parameters parameter_group
%type <routine> routine
%type <routine_list> routine_list
%type <stmt> compound_statement statement
%type <stmt_list> statement_list statement_list_opt
%type <expr> expression
%type <expr_list> arguments_opt argument_list

%destructor { std::free($$); } <text>
%destructor { delete $$; } <expr> <stmt> <var_list> <param_list> <routine>
%destructor { delete $$; } <routine_list> <identifier_list> <expr_list> <stmt_list>

%left OR
%left AND
%nonassoc EQUAL NOT_EQUAL LT LTE GT GTE
%left PLUS MINUS
%left STAR SLASH MOD
%precedence NOT UMINUS
%precedence LOWER_THAN_ELSE
%precedence ELSE

%start program

%%

program:
    PROGRAM IDENTIFIER SEMICOLON declarations_opt routine_list
    compound_statement DOT
    {
        auto result = std::make_unique<minipas::Program>(@1.first_line);
        result->name = $2;
        std::free($2);
        result->globals = std::move(*$4);
        result->routines = std::move(*$5);
        result->body.reset(static_cast<minipas::CompoundStmt *>($6));
        delete $4;
        delete $5;
        minipas::parsedProgram = std::move(result);
    }
;

declarations_opt:
    %empty { $$ = new minipas::VarDeclList(); }
  | VAR var_declaration_list { $$ = $2; }
;

var_declaration_list:
    identifier_list COLON type_specifier SEMICOLON
    {
        $$ = new minipas::VarDeclList();
        for (const std::string &name : *$1)
            $$->push_back({name, $3, @1.first_line});
        delete $1;
    }
  | var_declaration_list identifier_list COLON type_specifier SEMICOLON
    {
        $$ = $1;
        for (const std::string &name : *$2)
            $$->push_back({name, $4, @2.first_line});
        delete $2;
    }
;

identifier_list:
    IDENTIFIER
    {
        $$ = new minipas::IdentifierList();
        $$->push_back($1);
        std::free($1);
    }
  | identifier_list COMMA IDENTIFIER
    {
        $$ = $1;
        $$->push_back($3);
        std::free($3);
    }
;

type_specifier:
    INTEGER_TYPE { $$ = minipas::ValueType::Integer; }
  | BOOLEAN_TYPE { $$ = minipas::ValueType::Boolean; }
;

routine_list:
    %empty { $$ = new minipas::RoutineList(); }
  | routine_list routine
    {
        $$ = $1;
        $$->emplace_back($2);
    }
;

routine:
    FUNCTION IDENTIFIER LPAREN parameters_opt RPAREN COLON type_specifier
    SEMICOLON declarations_opt compound_statement SEMICOLON
    {
        $$ = new minipas::RoutineDecl(@1.first_line);
        $$->name = $2;
        std::free($2);
        $$->parameters = std::move(*$4);
        $$->returnType = $7;
        $$->variables = std::move(*$9);
        $$->body.reset(static_cast<minipas::CompoundStmt *>($10));
        delete $4;
        delete $9;
    }
  | PROCEDURE IDENTIFIER LPAREN parameters_opt RPAREN SEMICOLON
    declarations_opt compound_statement SEMICOLON
    {
        $$ = new minipas::RoutineDecl(@1.first_line);
        $$->name = $2;
        std::free($2);
        $$->parameters = std::move(*$4);
        $$->returnType = minipas::ValueType::Void;
        $$->variables = std::move(*$7);
        $$->body.reset(static_cast<minipas::CompoundStmt *>($8));
        delete $4;
        delete $7;
    }
;

parameters_opt:
    %empty { $$ = new minipas::ParamList(); }
  | parameters { $$ = $1; }
;

parameters:
    parameter_group { $$ = $1; }
  | parameters SEMICOLON parameter_group
    {
        $$ = $1;
        for (const auto &parameter : *$3) $$->push_back(parameter);
        delete $3;
    }
;

parameter_group:
    identifier_list COLON type_specifier
    {
        $$ = new minipas::ParamList();
        for (const std::string &name : *$1)
            $$->push_back({name, $3, @1.first_line});
        delete $1;
    }
;

compound_statement:
    BEGIN_TOKEN statement_list_opt END_TOKEN
    {
        $$ = new minipas::CompoundStmt(std::move(*$2), @1.first_line);
        delete $2;
    }
;

statement_list_opt:
    %empty { $$ = new minipas::StmtList(); }
  | statement_list { $$ = $1; }
  | statement_list SEMICOLON { $$ = $1; }
;

statement_list:
    statement
    {
        $$ = new minipas::StmtList();
        $$->emplace_back($1);
    }
  | statement_list SEMICOLON statement
    {
        $$ = $1;
        $$->emplace_back($3);
    }
;

statement:
    compound_statement { $$ = $1; }
  | IDENTIFIER ASSIGN expression
    {
        $$ = new minipas::AssignmentStmt($1,
             std::unique_ptr<minipas::Expr>($3), @1.first_line);
        std::free($1);
    }
  | IF expression THEN statement %prec LOWER_THAN_ELSE
    {
        $$ = new minipas::IfStmt(std::unique_ptr<minipas::Expr>($2),
             std::unique_ptr<minipas::Stmt>($4), nullptr, @1.first_line);
    }
  | IF expression THEN statement ELSE statement
    {
        $$ = new minipas::IfStmt(std::unique_ptr<minipas::Expr>($2),
             std::unique_ptr<minipas::Stmt>($4),
             std::unique_ptr<minipas::Stmt>($6), @1.first_line);
    }
  | WHILE expression DO statement
    {
        $$ = new minipas::WhileStmt(std::unique_ptr<minipas::Expr>($2),
             std::unique_ptr<minipas::Stmt>($4), @1.first_line);
    }
  | FOR IDENTIFIER ASSIGN expression TO expression DO statement
    {
        $$ = new minipas::ForStmt($2,
             std::unique_ptr<minipas::Expr>($4),
             std::unique_ptr<minipas::Expr>($6),
             std::unique_ptr<minipas::Stmt>($8), @1.first_line);
        std::free($2);
    }
  | WRITE LPAREN arguments_opt RPAREN
    {
        $$ = new minipas::WriteStmt(std::move(*$3), false, @1.first_line);
        delete $3;
    }
  | WRITELN LPAREN arguments_opt RPAREN
    {
        $$ = new minipas::WriteStmt(std::move(*$3), true, @1.first_line);
        delete $3;
    }
  | IDENTIFIER LPAREN arguments_opt RPAREN
    {
        $$ = new minipas::CallStmt($1, std::move(*$3), @1.first_line);
        std::free($1);
        delete $3;
    }
  | RETURN_TOKEN expression
    {
        $$ = new minipas::ReturnStmt(std::unique_ptr<minipas::Expr>($2),
                                     @1.first_line);
    }
;

arguments_opt:
    %empty { $$ = new minipas::ExprList(); }
  | argument_list { $$ = $1; }
;

argument_list:
    expression
    {
        $$ = new minipas::ExprList();
        $$->emplace_back($1);
    }
  | argument_list COMMA expression
    {
        $$ = $1;
        $$->emplace_back($3);
    }
;

expression:
    INTEGER_LITERAL { $$ = new minipas::IntegerExpr($1, @1.first_line); }
  | TRUE_TOKEN { $$ = new minipas::BooleanExpr(true, @1.first_line); }
  | FALSE_TOKEN { $$ = new minipas::BooleanExpr(false, @1.first_line); }
  | STRING_LITERAL
    {
        $$ = new minipas::StringExpr($1, @1.first_line);
        std::free($1);
    }
  | IDENTIFIER
    {
        $$ = new minipas::VariableExpr($1, @1.first_line);
        std::free($1);
    }
  | IDENTIFIER LPAREN arguments_opt RPAREN
    {
        $$ = new minipas::CallExpr($1, std::move(*$3), @1.first_line);
        std::free($1);
        delete $3;
    }
  | PARAM LPAREN expression RPAREN
    {
        $$ = new minipas::ArgumentExpr(std::unique_ptr<minipas::Expr>($3),
                                       @1.first_line);
    }
  | LPAREN expression RPAREN { $$ = $2; }
  | MINUS expression %prec UMINUS
    { $$ = new minipas::UnaryExpr("-", std::unique_ptr<minipas::Expr>($2), @1.first_line); }
  | NOT expression
    { $$ = new minipas::UnaryExpr("not", std::unique_ptr<minipas::Expr>($2), @1.first_line); }
  | expression PLUS expression
    { $$ = new minipas::BinaryExpr("+", std::unique_ptr<minipas::Expr>($1), std::unique_ptr<minipas::Expr>($3), @2.first_line); }
  | expression MINUS expression
    { $$ = new minipas::BinaryExpr("-", std::unique_ptr<minipas::Expr>($1), std::unique_ptr<minipas::Expr>($3), @2.first_line); }
  | expression STAR expression
    { $$ = new minipas::BinaryExpr("*", std::unique_ptr<minipas::Expr>($1), std::unique_ptr<minipas::Expr>($3), @2.first_line); }
  | expression SLASH expression
    { $$ = new minipas::BinaryExpr("/", std::unique_ptr<minipas::Expr>($1), std::unique_ptr<minipas::Expr>($3), @2.first_line); }
  | expression MOD expression
    { $$ = new minipas::BinaryExpr("mod", std::unique_ptr<minipas::Expr>($1), std::unique_ptr<minipas::Expr>($3), @2.first_line); }
  | expression AND expression
    { $$ = new minipas::BinaryExpr("and", std::unique_ptr<minipas::Expr>($1), std::unique_ptr<minipas::Expr>($3), @2.first_line); }
  | expression OR expression
    { $$ = new minipas::BinaryExpr("or", std::unique_ptr<minipas::Expr>($1), std::unique_ptr<minipas::Expr>($3), @2.first_line); }
  | expression EQUAL expression
    { $$ = new minipas::BinaryExpr("=", std::unique_ptr<minipas::Expr>($1), std::unique_ptr<minipas::Expr>($3), @2.first_line); }
  | expression NOT_EQUAL expression
    { $$ = new minipas::BinaryExpr("<>", std::unique_ptr<minipas::Expr>($1), std::unique_ptr<minipas::Expr>($3), @2.first_line); }
  | expression LT expression
    { $$ = new minipas::BinaryExpr("<", std::unique_ptr<minipas::Expr>($1), std::unique_ptr<minipas::Expr>($3), @2.first_line); }
  | expression LTE expression
    { $$ = new minipas::BinaryExpr("<=", std::unique_ptr<minipas::Expr>($1), std::unique_ptr<minipas::Expr>($3), @2.first_line); }
  | expression GT expression
    { $$ = new minipas::BinaryExpr(">", std::unique_ptr<minipas::Expr>($1), std::unique_ptr<minipas::Expr>($3), @2.first_line); }
  | expression GTE expression
    { $$ = new minipas::BinaryExpr(">=", std::unique_ptr<minipas::Expr>($1), std::unique_ptr<minipas::Expr>($3), @2.first_line); }
;

%%
