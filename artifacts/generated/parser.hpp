/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_BUILD_PARSER_HPP_INCLUDED
# define YY_YY_BUILD_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 13 "parser.y"

#include "ast.hpp"

#line 53 "build/parser.hpp"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PROGRAM = 258,                 /* PROGRAM  */
    VAR = 259,                     /* VAR  */
    BEGIN_TOKEN = 260,             /* BEGIN_TOKEN  */
    END_TOKEN = 261,               /* END_TOKEN  */
    FUNCTION = 262,                /* FUNCTION  */
    PROCEDURE = 263,               /* PROCEDURE  */
    RETURN_TOKEN = 264,            /* RETURN_TOKEN  */
    INTEGER_TYPE = 265,            /* INTEGER_TYPE  */
    BOOLEAN_TYPE = 266,            /* BOOLEAN_TYPE  */
    TRUE_TOKEN = 267,              /* TRUE_TOKEN  */
    FALSE_TOKEN = 268,             /* FALSE_TOKEN  */
    IF = 269,                      /* IF  */
    THEN = 270,                    /* THEN  */
    ELSE = 271,                    /* ELSE  */
    WHILE = 272,                   /* WHILE  */
    DO = 273,                      /* DO  */
    FOR = 274,                     /* FOR  */
    TO = 275,                      /* TO  */
    WRITE = 276,                   /* WRITE  */
    WRITELN = 277,                 /* WRITELN  */
    PARAM = 278,                   /* PARAM  */
    AND = 279,                     /* AND  */
    OR = 280,                      /* OR  */
    NOT = 281,                     /* NOT  */
    MOD = 282,                     /* MOD  */
    ASSIGN = 283,                  /* ASSIGN  */
    EQUAL = 284,                   /* EQUAL  */
    NOT_EQUAL = 285,               /* NOT_EQUAL  */
    LT = 286,                      /* LT  */
    LTE = 287,                     /* LTE  */
    GT = 288,                      /* GT  */
    GTE = 289,                     /* GTE  */
    PLUS = 290,                    /* PLUS  */
    MINUS = 291,                   /* MINUS  */
    STAR = 292,                    /* STAR  */
    SLASH = 293,                   /* SLASH  */
    LPAREN = 294,                  /* LPAREN  */
    RPAREN = 295,                  /* RPAREN  */
    COMMA = 296,                   /* COMMA  */
    SEMICOLON = 297,               /* SEMICOLON  */
    COLON = 298,                   /* COLON  */
    DOT = 299,                     /* DOT  */
    INTEGER_LITERAL = 300,         /* INTEGER_LITERAL  */
    IDENTIFIER = 301,              /* IDENTIFIER  */
    STRING_LITERAL = 302,          /* STRING_LITERAL  */
    UMINUS = 303,                  /* UMINUS  */
    LOWER_THAN_ELSE = 304          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "parser.y"

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

#line 134 "build/parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_BUILD_PARSER_HPP_INCLUDED  */
