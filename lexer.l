%option noyywrap nodefault yylineno caseless
%x BRACE_COMMENT PAREN_COMMENT

%{
#include "parser.hpp"
#include "lexer_state.hpp"

#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

#define YY_USER_ACTION                         \
    yylloc.first_line = yylineno;              \
    yylloc.last_line = yylineno;

namespace minipas {
bool lexerHadError = false;
}

static char *copyText(const std::string &text) {
    char *result = static_cast<char *>(std::malloc(text.size() + 1));
    if (!result) return nullptr;
    std::memcpy(result, text.c_str(), text.size() + 1);
    return result;
}

static char *identifierText(const char *text) {
    std::string value(text);
    for (char &character : value)
        character = static_cast<char>(std::tolower(static_cast<unsigned char>(character)));
    return copyText(value);
}

static char *stringText(const char *text, int length) {
    std::string input(text + 1, static_cast<std::size_t>(length - 2));
    std::string output;
    for (std::size_t i = 0; i < input.size(); ++i) {
        if (input[i] == '\'' && i + 1 < input.size() && input[i + 1] == '\'') ++i;
        output.push_back(input[i]);
    }
    return copyText(output);
}
%}

LETTER      [A-Za-z_]
DIGIT       [0-9]
IDENT       {LETTER}({LETTER}|{DIGIT})*

%%

[ \t\r]+                   ;
\n                         ;
"//"[^\n]*                ;
"{"                        BEGIN(BRACE_COMMENT);
<BRACE_COMMENT>"}"         BEGIN(INITIAL);
<BRACE_COMMENT>\n          ;
<BRACE_COMMENT>.           ;
"(*"                       BEGIN(PAREN_COMMENT);
<PAREN_COMMENT>"*)"        BEGIN(INITIAL);
<PAREN_COMMENT>\n          ;
<PAREN_COMMENT>.           ;
<BRACE_COMMENT,PAREN_COMMENT><<EOF>> {
    minipas::lexerHadError = true;
    std::fprintf(stderr, "Erro lexico na linha %d: comentario nao terminado\n", yylineno);
    return 0;
}

"program"                  return PROGRAM;
"var"                      return VAR;
"begin"                    return BEGIN_TOKEN;
"end"                      return END_TOKEN;
"function"                 return FUNCTION;
"procedure"                return PROCEDURE;
"return"                   return RETURN_TOKEN;
"integer"                  return INTEGER_TYPE;
"boolean"                  return BOOLEAN_TYPE;
"true"                     return TRUE_TOKEN;
"false"                    return FALSE_TOKEN;
"if"                       return IF;
"then"                     return THEN;
"else"                     return ELSE;
"while"                    return WHILE;
"do"                       return DO;
"for"                      return FOR;
"to"                       return TO;
"write"                    return WRITE;
"writeln"                  return WRITELN;
"param"                    return PARAM;
"and"                      return AND;
"or"                       return OR;
"not"                      return NOT;
"mod"                      return MOD;

":="                       return ASSIGN;
"<>"                       return NOT_EQUAL;
"<="                       return LTE;
">="                       return GTE;
"="                        return EQUAL;
"<"                        return LT;
">"                        return GT;
"+"                        return PLUS;
"-"                        return MINUS;
"*"                        return STAR;
"/"                        return SLASH;
"("                        return LPAREN;
")"                        return RPAREN;
","                        return COMMA;
";"                        return SEMICOLON;
":"                        return COLON;
"."                        return DOT;

{DIGIT}+                   {
    yylval.integer = std::strtoll(yytext, nullptr, 10);
    return INTEGER_LITERAL;
}
\'([^\'\n]|\'\')*\'        {
    yylval.text = stringText(yytext, yyleng);
    return STRING_LITERAL;
}
{IDENT}                    {
    yylval.text = identifierText(yytext);
    return IDENTIFIER;
}

.                          {
    minipas::lexerHadError = true;
    std::fprintf(stderr, "Erro lexico na linha %d: caractere inesperado '%s'\n",
                 yylineno, yytext);
    return yytext[0];
}

%%
