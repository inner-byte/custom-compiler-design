/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     INTEGER = 259,
     REAL = 260,
     STRING = 261,
     BOOLEAN = 262,
     KEYWORD_ALLOCATE = 263,
     KEYWORD_BOOL = 264,
     KEYWORD_BREAK = 265,
     KEYWORD_CASE = 266,
     KEYWORD_CHAR = 267,
     KEYWORD_CONST = 268,
     KEYWORD_CONTINUE = 269,
     KEYWORD_DECLARE = 270,
     KEYWORD_DEFAULT = 271,
     KEYWORD_DESTRUCT = 272,
     KEYWORD_DOUBLE = 273,
     KEYWORD_ELSE = 274,
     KEYWORD_FALSE = 275,
     KEYWORD_FUNCTION = 276,
     KEYWORD_FLOAT = 277,
     KEYWORD_FOR = 278,
     KEYWORD_GOTO = 279,
     KEYWORD_IF = 280,
     KEYWORD_INPUT = 281,
     KEYWORD_INT = 282,
     KEYWORD_LONG = 283,
     KEYWORD_OUTPUT = 284,
     KEYWORD_RETURN = 285,
     KEYWORD_SIZEOF = 286,
     KEYWORD_STATIC = 287,
     KEYWORD_STRING = 288,
     KEYWORD_SWITCH = 289,
     KEYWORD_TRUE = 290,
     KEYWORD_TYPE = 291,
     OPERATOR_EQ = 292,
     OPERATOR_NEQ = 293,
     OPERATOR_LEQ = 294,
     OPERATOR_LT = 295,
     OPERATOR_GT = 296,
     OPERATOR_GEQ = 297,
     OPERATOR_ASSIGN = 298,
     OPERATOR_NOT = 299,
     OPERATOR_BITWISE_NEG = 300,
     OPERATOR_ARITH_AND = 301,
     OPERATOR_LOGIC_AND = 302,
     OPERATOR_ARITH_OR = 303,
     OPERATOR_LOGIC_OR = 304,
     OPERATOR_XOR = 305,
     OPERATOR_MUL = 306,
     OPERATOR_ADD = 307,
     OPERATOR_INC = 308,
     OPERATOR_DEC = 309,
     OPERATOR_SUB = 310,
     OPERATOR_DIV = 311,
     OPERATOR_MOD = 312,
     PUNCTUATION_LBRACE = 313,
     PUNCTUATION_RBRACE = 314,
     PUNCTUATION_LPAREN = 315,
     PUNCTUATION_RPAREN = 316,
     PUNCTUATION_LBRACKET = 317,
     PUNCTUATION_RBRACKET = 318,
     PUNCTUATION_DOT = 319,
     PUNCTUATION_COMMA = 320,
     PUNCTUATION_COLON = 321,
     PUNCTUATION_SEMICOLON = 322,
     END_OF_FILE = 323
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define INTEGER 259
#define REAL 260
#define STRING 261
#define BOOLEAN 262
#define KEYWORD_ALLOCATE 263
#define KEYWORD_BOOL 264
#define KEYWORD_BREAK 265
#define KEYWORD_CASE 266
#define KEYWORD_CHAR 267
#define KEYWORD_CONST 268
#define KEYWORD_CONTINUE 269
#define KEYWORD_DECLARE 270
#define KEYWORD_DEFAULT 271
#define KEYWORD_DESTRUCT 272
#define KEYWORD_DOUBLE 273
#define KEYWORD_ELSE 274
#define KEYWORD_FALSE 275
#define KEYWORD_FUNCTION 276
#define KEYWORD_FLOAT 277
#define KEYWORD_FOR 278
#define KEYWORD_GOTO 279
#define KEYWORD_IF 280
#define KEYWORD_INPUT 281
#define KEYWORD_INT 282
#define KEYWORD_LONG 283
#define KEYWORD_OUTPUT 284
#define KEYWORD_RETURN 285
#define KEYWORD_SIZEOF 286
#define KEYWORD_STATIC 287
#define KEYWORD_STRING 288
#define KEYWORD_SWITCH 289
#define KEYWORD_TRUE 290
#define KEYWORD_TYPE 291
#define OPERATOR_EQ 292
#define OPERATOR_NEQ 293
#define OPERATOR_LEQ 294
#define OPERATOR_LT 295
#define OPERATOR_GT 296
#define OPERATOR_GEQ 297
#define OPERATOR_ASSIGN 298
#define OPERATOR_NOT 299
#define OPERATOR_BITWISE_NEG 300
#define OPERATOR_ARITH_AND 301
#define OPERATOR_LOGIC_AND 302
#define OPERATOR_ARITH_OR 303
#define OPERATOR_LOGIC_OR 304
#define OPERATOR_XOR 305
#define OPERATOR_MUL 306
#define OPERATOR_ADD 307
#define OPERATOR_INC 308
#define OPERATOR_DEC 309
#define OPERATOR_SUB 310
#define OPERATOR_DIV 311
#define OPERATOR_MOD 312
#define PUNCTUATION_LBRACE 313
#define PUNCTUATION_RBRACE 314
#define PUNCTUATION_LPAREN 315
#define PUNCTUATION_RPAREN 316
#define PUNCTUATION_LBRACKET 317
#define PUNCTUATION_RBRACKET 318
#define PUNCTUATION_DOT 319
#define PUNCTUATION_COMMA 320
#define PUNCTUATION_COLON 321
#define PUNCTUATION_SEMICOLON 322
#define END_OF_FILE 323




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 13 "parser.y"
{
    char* str;
    ASTNode* node;
    std::vector<ASTNode*>* node_list;
}
/* Line 1529 of yacc.c.  */
#line 191 "parser.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYLTYPE yylloc;
