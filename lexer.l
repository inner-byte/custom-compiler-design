%{
#include <string>
#include <iostream>
#include "ast.h"
#include "type_system.h"
#include "symbol_table.h"
#include "parser.hpp"

extern int yylineno;
%}

%option noyywrap
%option yylineno

%%

[ \t\n\r]+        ;

"allocate"        { yylval.str = strdup(yytext); return KEYWORD_ALLOCATE; }
"bool"            { yylval.str = strdup(yytext); return KEYWORD_BOOL; }
"break"           { yylval.str = strdup(yytext); return KEYWORD_BREAK; }
"case"            { yylval.str = strdup(yytext); return KEYWORD_CASE; }
"char"            { yylval.str = strdup(yytext); return KEYWORD_CHAR; }
"const"           { yylval.str = strdup(yytext); return KEYWORD_CONST; }
"continue"        { yylval.str = strdup(yytext); return KEYWORD_CONTINUE; }
"declare"         { yylval.str = strdup(yytext); return KEYWORD_DECLARE; }
"default"         { yylval.str = strdup(yytext); return KEYWORD_DEFAULT; }
"destruct"        { yylval.str = strdup(yytext); return KEYWORD_DESTRUCT; }
"double"          { yylval.str = strdup(yytext); return KEYWORD_DOUBLE; }
"else"            { yylval.str = strdup(yytext); return KEYWORD_ELSE; }
"false"           { yylval.str = strdup(yytext); return KEYWORD_FALSE; }
"function"        { yylval.str = strdup(yytext); return KEYWORD_FUNCTION; }
"float"           { yylval.str = strdup(yytext); return KEYWORD_FLOAT; }
"for"             { yylval.str = strdup(yytext); return KEYWORD_FOR; }
"goto"            { yylval.str = strdup(yytext); return KEYWORD_GOTO; }
"if"              { yylval.str = strdup(yytext); return KEYWORD_IF; }
"input"           { yylval.str = strdup(yytext); return KEYWORD_INPUT; }
"int"             { yylval.str = strdup(yytext); return KEYWORD_INT; }
"long"            { yylval.str = strdup(yytext); return KEYWORD_LONG; }
"output"          { yylval.str = strdup(yytext); return KEYWORD_OUTPUT; }
"return"          { yylval.str = strdup(yytext); return KEYWORD_RETURN; }
"sizeof"          { yylval.str = strdup(yytext); return KEYWORD_SIZEOF; }
"static"          { yylval.str = strdup(yytext); return KEYWORD_STATIC; }
"str"             { yylval.str = strdup(yytext); return KEYWORD_STR; }
"switch"          { yylval.str = strdup(yytext); return KEYWORD_SWITCH; }
"true"            { yylval.str = strdup(yytext); return KEYWORD_TRUE; }
"type"            { yylval.str = strdup(yytext); return KEYWORD_TYPE; }

"=="              { yylval.str = strdup(yytext); return OPERATOR_EQ; }
"!="              { yylval.str = strdup(yytext); return OPERATOR_NEQ; }
"<="              { yylval.str = strdup(yytext); return OPERATOR_LEQ; }
"<"               { yylval.str = strdup(yytext); return OPERATOR_LT; }
">"               { yylval.str = strdup(yytext); return OPERATOR_GT; }
">="              { yylval.str = strdup(yytext); return OPERATOR_GEQ; }
"="               { yylval.str = strdup(yytext); return OPERATOR_ASSIGN; }
"!"               { yylval.str = strdup(yytext); return OPERATOR_NOT; }
"~"               { yylval.str = strdup(yytext); return OPERATOR_BITWISE_NEG; }
"&"               { yylval.str = strdup(yytext); return OPERATOR_ARITH_AND; }
"&&"              { yylval.str = strdup(yytext); return OPERATOR_LOGIC_AND; }
"|"               { yylval.str = strdup(yytext); return OPERATOR_ARITH_OR; }
"||"              { yylval.str = strdup(yytext); return OPERATOR_LOGIC_OR; }
"^"               { yylval.str = strdup(yytext); return OPERATOR_XOR; }
"*"               { yylval.str = strdup(yytext); return OPERATOR_MUL; }
"+"               { yylval.str = strdup(yytext); return OPERATOR_ADD; }
"++"              { yylval.str = strdup(yytext); return OPERATOR_INC; }
"--"              { yylval.str = strdup(yytext); return OPERATOR_DEC; }
"-"               { yylval.str = strdup(yytext); return OPERATOR_SUB; }
"/"               { yylval.str = strdup(yytext); return OPERATOR_DIV; }
"%"               { yylval.str = strdup(yytext); return OPERATOR_MOD; }

"{"               { yylval.str = strdup(yytext); return PUNCTUATION_LBRACE; }
"}"               { yylval.str = strdup(yytext); return PUNCTUATION_RBRACE; }
"("               { yylval.str = strdup(yytext); return PUNCTUATION_LPAREN; }
")"               { yylval.str = strdup(yytext); return PUNCTUATION_RPAREN; }
"["               { yylval.str = strdup(yytext); return PUNCTUATION_LBRACKET; }
"]"               { yylval.str = strdup(yytext); return PUNCTUATION_RBRACKET; }
"."               { yylval.str = strdup(yytext); return PUNCTUATION_DOT; }
","               { yylval.str = strdup(yytext); return PUNCTUATION_COMMA; }
":"               { yylval.str = strdup(yytext); return PUNCTUATION_COLON; }
";"               { yylval.str = strdup(yytext); return PUNCTUATION_SEMICOLON; }

[a-zA-Z_][a-zA-Z0-9_]*  { yylval.str = strdup(yytext); return IDENTIFIER; }
[0-9]+                  { yylval.str = strdup(yytext); return INTEGER; }
[0-9]+\.[0-9]*         { yylval.str = strdup(yytext); return REAL; }
\"([^"\\]|\\.)*\"      { yylval.str = strdup(yytext); return STRING; }
(true|false)           { yylval.str = strdup(yytext); return BOOLEAN; }

<<EOF>>           { return END_OF_FILE; }

.                 { std::cerr << "Unknown token: " << yytext << " at line " << yylineno << std::endl; }

%%

void yyerror(const char* s) {
    std::cerr << "Error: " << s << " at line " << yylineno << std::endl;
}
