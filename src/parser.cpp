/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1



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
     KEYWORD_STR = 288,
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
#define KEYWORD_STR 288
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




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

    #include <iostream>
    #include <string>
    #include <vector>
    #include "ast.h"
    #include "type_system.h"
    #include "symbol_table.h"
    
    extern int yylex();
    extern void yyerror(const char* s);
    extern ProgramNode* programRoot;
    extern int yylineno;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 15 "parser.y"
{
    char* str;
    ASTNode* node;
    std::vector<ASTNode*>* node_list;
}
/* Line 193 of yacc.c.  */
#line 252 "src/parser.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

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


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 277 "src/parser.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   407

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNRULES -- Number of states.  */
#define YYNSTATES  225

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   323

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     7,    10,    11,    14,    21,    23,
      26,    28,    31,    33,    36,    39,    47,    53,    55,    57,
      61,    63,    65,    68,    72,    77,    84,    86,    89,    92,
      94,    96,   103,   113,   114,   116,   118,   121,   124,   127,
     131,   132,   135,   138,   140,   142,   144,   146,   148,   150,
     152,   154,   158,   163,   167,   169,   173,   175,   179,   182,
     184,   186,   188,   190,   194,   196,   198,   201,   204,   210,
     215,   220,   222,   227,   231,   233,   236,   239,   242,   245,
     249,   254,   260,   268,   276,   277,   283,   288,   297,   301,
     304,   308,   312,   314,   316,   318,   320,   323,   326,   328,
     330,   332,   334,   336,   338,   340,   342,   344,   346,   348,
     350,   352,   354,   356,   358,   360,   362,   364,   366,   368,
     370,   372,   374
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      70,     0,    -1,    71,    72,    -1,    -1,    71,    73,    -1,
      -1,    72,    87,    -1,    15,    58,    74,    75,    76,    59,
      -1,    77,    -1,    74,    77,    -1,    84,    -1,    75,    84,
      -1,    79,    -1,    76,    79,    -1,    78,    67,    -1,    60,
      80,    61,     3,    60,    82,    61,    -1,    58,    95,     3,
      67,    59,    -1,    81,    -1,    95,    -1,    81,    65,    95,
      -1,    83,    -1,     3,    -1,    95,     3,    -1,    83,    65,
       3,    -1,    83,    65,    95,     3,    -1,    36,     3,    58,
      85,    67,    59,    -1,    86,    -1,    85,    86,    -1,    95,
       3,    -1,    89,    -1,    88,    -1,    36,     3,    58,    85,
      67,    59,    -1,    21,     3,    66,    58,    90,    59,    58,
      93,    59,    -1,    -1,    91,    -1,    92,    -1,    91,    92,
      -1,    26,    82,    -1,    29,    82,    -1,    58,    94,    59,
      -1,    -1,    94,    96,    -1,    94,    99,    -1,    27,    -1,
       9,    -1,    22,    -1,    28,    -1,    12,    -1,    18,    -1,
      33,    -1,     3,    -1,    95,    62,    63,    -1,    13,    95,
      97,    67,    -1,    95,    97,    67,    -1,    98,    -1,    97,
      65,    98,    -1,   101,    -1,   101,    43,   108,    -1,   101,
       8,    -1,   100,    -1,   102,    -1,   103,    -1,   105,    -1,
      30,   108,    67,    -1,   106,    -1,   107,    -1,    10,    67,
      -1,    14,    67,    -1,    17,    62,    63,     3,    67,    -1,
      31,    60,    95,    61,    -1,   101,    43,   108,    67,    -1,
       3,    -1,   101,    62,   108,    63,    -1,    60,   101,    61,
      -1,   102,    -1,    54,   101,    -1,    53,   101,    -1,   101,
      54,    -1,   101,    53,    -1,     3,    60,    61,    -1,     3,
      60,    83,    61,    -1,    25,    60,   108,    61,    93,    -1,
      25,    60,   108,    61,    93,    19,    93,    -1,    34,    60,
       3,    61,    58,   104,    59,    -1,    -1,   104,    11,     4,
      66,    93,    -1,   104,    16,    66,    93,    -1,    23,    60,
      96,   108,    67,   100,    61,    93,    -1,    24,     3,    67,
      -1,     3,    66,    -1,   108,   111,   108,    -1,    60,   108,
      61,    -1,   102,    -1,   101,    -1,   112,    -1,   109,    -1,
      55,   110,    -1,    44,   110,    -1,     3,    -1,     4,    -1,
       5,    -1,     6,    -1,     7,    -1,    52,    -1,    55,    -1,
      51,    -1,    56,    -1,    57,    -1,    46,    -1,    48,    -1,
      50,    -1,    49,    -1,    47,    -1,    37,    -1,    38,    -1,
      39,    -1,    40,    -1,    41,    -1,    42,    -1,     4,    -1,
       5,    -1,     6,    -1,     7,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    36,    36,    40,    41,    45,    46,    50,    55,    56,
      60,    61,    65,    66,    70,    74,    79,    84,    88,    89,
      93,    97,    98,    99,   100,   104,   109,   110,   114,   118,
     119,   123,   128,   133,   134,   135,   136,   140,   144,   148,
     152,   153,   154,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   170,   171,   175,   176,   180,   181,   182,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   197,
     202,   206,   207,   208,   209,   210,   211,   212,   213,   217,
     218,   222,   223,   225,   230,   231,   232,   236,   241,   245,
     249,   250,   251,   252,   253,   254,   258,   259,   263,   264,
     265,   266,   267,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   290,
     291,   292,   293
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "INTEGER", "REAL",
  "STRING", "BOOLEAN", "KEYWORD_ALLOCATE", "KEYWORD_BOOL", "KEYWORD_BREAK",
  "KEYWORD_CASE", "KEYWORD_CHAR", "KEYWORD_CONST", "KEYWORD_CONTINUE",
  "KEYWORD_DECLARE", "KEYWORD_DEFAULT", "KEYWORD_DESTRUCT",
  "KEYWORD_DOUBLE", "KEYWORD_ELSE", "KEYWORD_FALSE", "KEYWORD_FUNCTION",
  "KEYWORD_FLOAT", "KEYWORD_FOR", "KEYWORD_GOTO", "KEYWORD_IF",
  "KEYWORD_INPUT", "KEYWORD_INT", "KEYWORD_LONG", "KEYWORD_OUTPUT",
  "KEYWORD_RETURN", "KEYWORD_SIZEOF", "KEYWORD_STATIC", "KEYWORD_STR",
  "KEYWORD_SWITCH", "KEYWORD_TRUE", "KEYWORD_TYPE", "OPERATOR_EQ",
  "OPERATOR_NEQ", "OPERATOR_LEQ", "OPERATOR_LT", "OPERATOR_GT",
  "OPERATOR_GEQ", "OPERATOR_ASSIGN", "OPERATOR_NOT",
  "OPERATOR_BITWISE_NEG", "OPERATOR_ARITH_AND", "OPERATOR_LOGIC_AND",
  "OPERATOR_ARITH_OR", "OPERATOR_LOGIC_OR", "OPERATOR_XOR", "OPERATOR_MUL",
  "OPERATOR_ADD", "OPERATOR_INC", "OPERATOR_DEC", "OPERATOR_SUB",
  "OPERATOR_DIV", "OPERATOR_MOD", "PUNCTUATION_LBRACE",
  "PUNCTUATION_RBRACE", "PUNCTUATION_LPAREN", "PUNCTUATION_RPAREN",
  "PUNCTUATION_LBRACKET", "PUNCTUATION_RBRACKET", "PUNCTUATION_DOT",
  "PUNCTUATION_COMMA", "PUNCTUATION_COLON", "PUNCTUATION_SEMICOLON",
  "END_OF_FILE", "$accept", "program", "ft_decl_list", "ft_def_list",
  "ft_decl", "func_decl_list", "type_decl_list", "globl_var_list",
  "func_decl", "func_prot", "globl_var", "args", "type_list", "params",
  "param_list", "type_decl", "field_list", "field", "ft_def", "type_def",
  "func_def", "inout", "input_list", "output_list", "block",
  "statement_list", "type", "var_decl", "var_decl_list", "var_decl_cnt",
  "statement", "assignment", "variable", "func_call", "cond_stmt",
  "case_list", "loop_stmt", "goto_stmt", "label", "expr", "unary_op",
  "primary", "binary_op", "const_val", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    71,    72,    72,    73,    74,    74,
      75,    75,    76,    76,    77,    78,    79,    80,    81,    81,
      82,    83,    83,    83,    83,    84,    85,    85,    86,    87,
      87,    88,    89,    90,    90,    90,    90,    91,    92,    93,
      94,    94,    94,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    96,    96,    97,    97,    98,    98,    98,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
     100,   101,   101,   101,   101,   101,   101,   101,   101,   102,
     102,   103,   103,   103,   104,   104,   104,   105,   106,   107,
     108,   108,   108,   108,   108,   108,   109,   109,   110,   110,
     110,   110,   110,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   112,
     112,   112,   112
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     0,     2,     6,     1,     2,
       1,     2,     1,     2,     2,     7,     5,     1,     1,     3,
       1,     1,     2,     3,     4,     6,     1,     2,     2,     1,
       1,     6,     9,     0,     1,     1,     2,     2,     2,     3,
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     3,     1,     3,     1,     3,     2,     1,
       1,     1,     1,     3,     1,     1,     2,     2,     5,     4,
       4,     1,     4,     3,     1,     2,     2,     2,     2,     3,
       4,     5,     7,     7,     0,     5,     4,     8,     3,     2,
       3,     3,     1,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     5,     1,     0,     2,     4,     0,     0,     0,
       6,    30,    29,     0,     0,     8,     0,     0,     0,    50,
      44,    47,    48,    45,    43,    46,    49,     0,    17,    18,
       0,     0,     9,    10,    14,     0,     0,     0,     0,     0,
       0,     0,     0,    12,    11,    33,     0,    26,     0,     0,
      19,    51,     0,     0,     7,    13,     0,     0,     0,    34,
      35,     0,    27,    28,     0,     0,     0,    21,    37,    20,
       0,    38,     0,    36,    31,     0,     0,     0,     0,    22,
       0,    15,    25,    16,    23,     0,    40,     0,    24,     0,
      32,    50,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    39,     0,     0,    41,    42,    59,
       0,    60,    61,    62,    64,    65,     0,    89,    66,     0,
      67,     0,     0,     0,     0,    71,   119,   120,   121,   122,
       0,     0,     0,    93,    74,     0,    95,    94,     0,     0,
      76,    74,    75,     0,     0,    54,    56,     0,    78,    77,
       0,    79,     0,     0,     0,     0,    88,     0,    98,    99,
     100,   101,   102,    97,    96,    93,     0,   113,   114,   115,
     116,   117,   118,   108,   112,   109,   111,   110,   105,   103,
     104,   106,   107,    63,     0,     0,     0,    73,     0,    53,
      58,     0,     0,     0,    80,    52,     0,     0,     0,    91,
      90,    69,     0,    55,    57,    70,    72,    68,     0,    81,
      84,     0,     0,     0,     0,    82,     0,     0,    83,    87,
       0,     0,     0,    86,    85
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,     6,    14,    31,    42,    15,    16,
      43,    27,    28,    68,    69,    33,    46,    47,    10,    11,
      12,    58,    59,    60,    87,    89,    48,   107,   144,   145,
     108,   109,   133,   134,   112,   213,   113,   114,   115,   135,
     136,   163,   184,   137
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -122
static const yytype_int16 yypact[] =
{
    -122,    41,     2,  -122,   -10,    18,  -122,    23,    84,    91,
    -122,  -122,  -122,   165,   -24,  -122,    43,    31,    58,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,    63,    62,    68,
     137,   -23,  -122,  -122,  -122,   101,   165,   145,   165,    97,
     104,   165,    61,  -122,  -122,    49,    44,  -122,    19,   103,
      68,  -122,   165,    24,  -122,  -122,   269,   269,   105,   140,
    -122,   107,  -122,  -122,   269,    46,   108,    27,  -122,   116,
      28,  -122,   126,  -122,  -122,   129,   135,   138,   276,  -122,
     149,  -122,  -122,  -122,    27,    30,  -122,   144,  -122,   119,
    -122,   122,   152,   165,   153,   134,   168,   215,   169,   151,
     173,   180,    85,    85,  -122,    85,     7,  -122,  -122,  -122,
     146,    -5,  -122,  -122,  -122,  -122,    90,  -122,  -122,     7,
    -122,   178,   158,   183,   151,   191,  -122,  -122,  -122,  -122,
     328,   328,   151,   -48,  -122,   175,  -122,  -122,   165,   252,
     -48,  -122,   -48,   148,    17,  -122,    42,   151,  -122,  -122,
     151,  -122,   -19,    33,   259,   151,  -122,   300,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,   148,   325,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,   151,    73,   202,  -122,    85,  -122,
    -122,   151,   197,   273,  -122,  -122,   206,   219,   149,  -122,
     350,  -122,   222,  -122,   350,  -122,  -122,  -122,    85,   258,
    -122,   221,   149,    -7,   149,  -122,   279,   218,  -122,  -122,
     223,   149,   149,  -122,  -122
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,   278,  -122,
     248,  -122,  -122,   -56,   177,   264,   247,    -6,  -122,  -122,
    -122,  -122,  -122,   241,  -107,  -122,   -13,   179,   186,   118,
    -122,    99,   -87,   -82,  -122,  -122,  -122,  -122,  -122,  -121,
    -122,   185,  -122,  -122
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -75
static const yytype_int16 yytable[] =
{
      29,    71,   110,   157,   216,   148,   149,   111,    75,   217,
     125,   166,    30,    30,   150,   140,   142,     4,   143,   146,
     141,   141,    63,   141,   141,    50,   192,    66,    53,   193,
     -50,    79,   146,    88,   197,    41,    13,   141,   -74,     8,
      62,     3,   194,    70,    70,   165,    78,    19,     7,    19,
     190,    70,   218,    20,     9,    20,    21,   -74,    21,    62,
     102,   103,    22,   200,    22,    85,    23,   105,    23,    39,
     204,    24,    25,    24,    25,    56,   106,    26,    57,    26,
     119,    39,   188,    13,   189,   191,    39,    17,   125,   -50,
      39,   209,    39,    67,    18,   148,   149,    35,   188,    20,
     195,   146,    21,    70,   150,   215,   141,   219,    22,   106,
      34,    61,    23,    76,   223,   224,    36,    24,    25,    41,
      54,   110,    91,    26,    37,   185,   141,    38,    20,    92,
      39,    21,    93,    94,   201,    39,    95,    22,   102,   103,
      40,    23,    96,    97,    98,   105,    24,    25,    49,    99,
     100,   151,    26,   101,   125,   126,   127,   128,   129,    45,
      51,    19,    52,    64,    72,   -71,    74,    20,    19,    57,
      21,    93,   102,   103,    20,    77,    22,    21,   104,   105,
      23,    78,   116,    22,    80,    24,    25,    23,   117,   147,
      81,    26,    24,    25,    82,   130,   121,    83,    26,   148,
     149,   148,   149,    90,   102,   103,   131,    86,   150,   187,
     150,   132,   167,   168,   169,   170,   171,   172,   123,   118,
     120,   173,   174,   175,   176,   177,   178,   179,   122,   124,
     180,   181,   182,   138,   167,   168,   169,   170,   171,   172,
     139,   154,   183,   173,   174,   175,   176,   177,   178,   179,
     156,   116,   180,   181,   182,   186,   167,   168,   169,   170,
     171,   172,   196,   202,   205,   173,   174,   175,   176,   177,
     178,   179,    67,   207,   180,   181,   182,   212,    20,    84,
     210,    21,   214,   220,   221,    20,   208,    22,    21,   222,
      55,    23,    32,   152,    22,    44,    24,    25,    23,    65,
      73,   155,    26,    24,    25,   153,   203,   211,     0,    26,
     167,   168,   169,   170,   171,   172,   164,     0,     0,   173,
     174,   175,   176,   177,   178,   179,     0,     0,   180,   181,
     182,   158,   159,   160,   161,   162,   206,   167,   168,   169,
     170,   171,   172,     0,     0,     0,   173,   174,   175,   176,
     177,   178,   179,     0,     0,   180,   181,   182,     0,     0,
       0,   198,   167,   168,   169,   170,   171,   172,     0,     0,
       0,   173,   174,   175,   176,   177,   178,   179,     0,     0,
     180,   181,   182,     0,     0,     0,   199,   167,   168,   169,
     170,   171,   172,     0,     0,     0,   173,   174,   175,   176,
     177,   178,   179,     0,     0,   180,   181,   182
};

static const yytype_int16 yycheck[] =
{
      13,    57,    89,   124,    11,    53,    54,    89,    64,    16,
       3,   132,    36,    36,    62,   102,   103,    15,   105,   106,
     102,   103,     3,   105,   106,    38,   147,     3,    41,   150,
       3,     3,   119,     3,   155,    58,    60,   119,    43,    21,
      46,     0,    61,    56,    57,   132,    65,     3,    58,     3,
       8,    64,    59,     9,    36,     9,    12,    62,    12,    65,
      53,    54,    18,   184,    18,    78,    22,    60,    22,    62,
     191,    27,    28,    27,    28,    26,    89,    33,    29,    33,
      93,    62,    65,    60,    67,    43,    62,     3,     3,    62,
      62,   198,    62,     3,     3,    53,    54,    66,    65,     9,
      67,   188,    12,   116,    62,   212,   188,   214,    18,   122,
      67,    67,    22,    67,   221,   222,    58,    27,    28,    58,
      59,   208,     3,    33,    61,   138,   208,    65,     9,    10,
      62,    12,    13,    14,    61,    62,    17,    18,    53,    54,
       3,    22,    23,    24,    25,    60,    27,    28,     3,    30,
      31,    61,    33,    34,     3,     4,     5,     6,     7,    58,
      63,     3,    58,    60,    59,    43,    59,     9,     3,    29,
      12,    13,    53,    54,     9,    67,    18,    12,    59,    60,
      22,    65,    60,    18,    58,    27,    28,    22,    66,    43,
      61,    33,    27,    28,    59,    44,    62,    59,    33,    53,
      54,    53,    54,    59,    53,    54,    55,    58,    62,    61,
      62,    60,    37,    38,    39,    40,    41,    42,     3,    67,
      67,    46,    47,    48,    49,    50,    51,    52,    60,    60,
      55,    56,    57,    60,    37,    38,    39,    40,    41,    42,
      60,    63,    67,    46,    47,    48,    49,    50,    51,    52,
      67,    60,    55,    56,    57,     3,    37,    38,    39,    40,
      41,    42,     3,    61,    67,    46,    47,    48,    49,    50,
      51,    52,     3,    67,    55,    56,    57,    19,     9,     3,
      58,    12,    61,     4,    66,     9,    67,    18,    12,    66,
      42,    22,    14,   116,    18,    31,    27,    28,    22,    52,
      59,   122,    33,    27,    28,   119,   188,   208,    -1,    33,
      37,    38,    39,    40,    41,    42,   131,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    -1,    -1,    55,    56,
      57,     3,     4,     5,     6,     7,    63,    37,    38,    39,
      40,    41,    42,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    -1,    -1,    55,    56,    57,    -1,    -1,
      -1,    61,    37,    38,    39,    40,    41,    42,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    -1,    -1,
      55,    56,    57,    -1,    -1,    -1,    61,    37,    38,    39,
      40,    41,    42,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    -1,    -1,    55,    56,    57
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    70,    71,     0,    15,    72,    73,    58,    21,    36,
      87,    88,    89,    60,    74,    77,    78,     3,     3,     3,
       9,    12,    18,    22,    27,    28,    33,    80,    81,    95,
      36,    75,    77,    84,    67,    66,    58,    61,    65,    62,
       3,    58,    76,    79,    84,    58,    85,    86,    95,     3,
      95,    63,    58,    95,    59,    79,    26,    29,    90,    91,
      92,    67,    86,     3,    60,    85,     3,     3,    82,    83,
      95,    82,    59,    92,    59,    82,    67,    67,    65,     3,
      58,    61,    59,    59,     3,    95,    58,    93,     3,    94,
      59,     3,    10,    13,    14,    17,    23,    24,    25,    30,
      31,    34,    53,    54,    59,    60,    95,    96,    99,   100,
     101,   102,   103,   105,   106,   107,    60,    66,    67,    95,
      67,    62,    60,     3,    60,     3,     4,     5,     6,     7,
      44,    55,    60,   101,   102,   108,   109,   112,    60,    60,
     101,   102,   101,   101,    97,    98,   101,    43,    53,    54,
      62,    61,    83,    97,    63,    96,    67,   108,     3,     4,
       5,     6,     7,   110,   110,   101,   108,    37,    38,    39,
      40,    41,    42,    46,    47,    48,    49,    50,    51,    52,
      55,    56,    57,    67,   111,    95,     3,    61,    65,    67,
       8,    43,   108,   108,    61,    67,     3,   108,    61,    61,
     108,    61,    61,    98,   108,    67,    63,    67,    67,    93,
      58,   100,    19,   104,    61,    93,    11,    16,    59,    93,
       4,    66,    66,    93,    93
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 36 "parser.y"
    { programRoot = new ProgramNode((yyvsp[(1) - (2)].node_list), (yyvsp[(2) - (2)].node_list)); ;}
    break;

  case 3:
#line 40 "parser.y"
    { (yyval.node_list) = new std::vector<ASTNode*>(); ;}
    break;

  case 4:
#line 41 "parser.y"
    { (yyval.node_list)->push_back((yyvsp[(2) - (2)].node)); ;}
    break;

  case 5:
#line 45 "parser.y"
    { (yyval.node_list) = new std::vector<ASTNode*>(); ;}
    break;

  case 6:
#line 46 "parser.y"
    { (yyval.node_list)->push_back((yyvsp[(2) - (2)].node)); ;}
    break;

  case 7:
#line 51 "parser.y"
    { (yyval.node) = new ASTNode(ASTNodeType::FT_DECL, (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 8:
#line 55 "parser.y"
    { (yyval.node_list) = new std::vector<ASTNode*>(); (yyval.node_list)->push_back((yyvsp[(1) - (1)].node)); ;}
    break;

  case 9:
#line 56 "parser.y"
    { (yyval.node_list)->push_back((yyvsp[(2) - (2)].node)); ;}
    break;

  case 10:
#line 60 "parser.y"
    { (yyval.node_list) = new std::vector<ASTNode*>(); (yyval.node_list)->push_back((yyvsp[(1) - (1)].node)); ;}
    break;

  case 11:
#line 61 "parser.y"
    { (yyval.node_list)->push_back((yyvsp[(2) - (2)].node)); ;}
    break;

  case 12:
#line 65 "parser.y"
    { (yyval.node_list) = new std::vector<ASTNode*>(); (yyval.node_list)->push_back((yyvsp[(1) - (1)].node)); ;}
    break;

  case 13:
#line 66 "parser.y"
    { (yyval.node_list)->push_back((yyvsp[(2) - (2)].node)); ;}
    break;

  case 14:
#line 70 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 15:
#line 75 "parser.y"
    { (yyval.node) = new FunctionDeclNode((yyvsp[(4) - (7)].str), (yyvsp[(2) - (7)].node), (yyvsp[(6) - (7)].node), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 16:
#line 80 "parser.y"
    { (yyval.node) = new VariableDeclNode((yyvsp[(2) - (5)].node), (yyvsp[(3) - (5)].str), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 17:
#line 84 "parser.y"
    { (yyval.node) = new ASTNode(ASTNodeType::ARGS, (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 18:
#line 88 "parser.y"
    { (yyval.node_list) = new std::vector<ASTNode*>(); (yyval.node_list)->push_back((yyvsp[(1) - (1)].node)); ;}
    break;

  case 19:
#line 89 "parser.y"
    { (yyval.node_list)->push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 20:
#line 93 "parser.y"
    { (yyval.node) = new ASTNode(ASTNodeType::PARAMS, (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 21:
#line 97 "parser.y"
    { (yyval.node_list) = new std::vector<ASTNode*>(); (yyval.node_list)->push_back(new IDNode((yyvsp[(1) - (1)].str), (yyloc).first_line, (yyloc).first_column)); ;}
    break;

  case 22:
#line 98 "parser.y"
    { (yyval.node_list) = new std::vector<ASTNode*>(); (yyval.node_list)->push_back(new VariableDeclNode((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].str), (yyloc).first_line, (yyloc).first_column)); ;}
    break;

  case 23:
#line 99 "parser.y"
    { (yyval.node_list)->push_back(new IDNode((yyvsp[(3) - (3)].str), (yyloc).first_line, (yyloc).first_column)); ;}
    break;

  case 24:
#line 100 "parser.y"
    { (yyval.node_list)->push_back(new VariableDeclNode((yyvsp[(3) - (4)].node), (yyvsp[(4) - (4)].str), (yyloc).first_line, (yyloc).first_column)); ;}
    break;

  case 25:
#line 105 "parser.y"
    { (yyval.node) = new TypeDeclNode((yyvsp[(2) - (6)].str), (yyvsp[(4) - (6)].node_list), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 26:
#line 109 "parser.y"
    { (yyval.node_list) = new std::vector<ASTNode*>(); (yyval.node_list)->push_back((yyvsp[(1) - (1)].node)); ;}
    break;

  case 27:
#line 110 "parser.y"
    { (yyval.node_list)->push_back((yyvsp[(2) - (2)].node)); ;}
    break;

  case 28:
#line 114 "parser.y"
    { (yyval.node) = new VariableDeclNode((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].str), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 29:
#line 118 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 30:
#line 119 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 31:
#line 124 "parser.y"
    { (yyval.node) = new TypeDefNode((yyvsp[(2) - (6)].str), (yyvsp[(4) - (6)].node_list), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 32:
#line 129 "parser.y"
    { (yyval.node) = new FunctionDefNode((yyvsp[(2) - (9)].str), (yyvsp[(5) - (9)].node), (yyvsp[(8) - (9)].node), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 33:
#line 133 "parser.y"
    { (yyval.node) = new ASTNode(ASTNodeType::INOUT, (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 34:
#line 134 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 35:
#line 135 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 36:
#line 136 "parser.y"
    { (yyval.node) = new InOutNode((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 37:
#line 140 "parser.y"
    { (yyval.node) = new ASTNode(ASTNodeType::INPUT_LIST, (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 38:
#line 144 "parser.y"
    { (yyval.node) = new ASTNode(ASTNodeType::OUTPUT_LIST, (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 39:
#line 148 "parser.y"
    { (yyval.node) = new BlockNode((yyvsp[(2) - (3)].node_list), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 40:
#line 152 "parser.y"
    { (yyval.node_list) = new std::vector<ASTNode*>(); ;}
    break;

  case 41:
#line 153 "parser.y"
    { (yyval.node_list)->push_back((yyvsp[(2) - (2)].node)); ;}
    break;

  case 42:
#line 154 "parser.y"
    { (yyval.node_list)->push_back((yyvsp[(2) - (2)].node)); ;}
    break;

  case 43:
#line 158 "parser.y"
    { (yyval.node) = new PrimitiveTypeNode(PrimitiveType::Kind::INT, (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 44:
#line 159 "parser.y"
    { (yyval.node) = new PrimitiveTypeNode(PrimitiveType::Kind::BOOL, (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 45:
#line 160 "parser.y"
    { (yyval.node) = new PrimitiveTypeNode(PrimitiveType::Kind::FLOAT, (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 46:
#line 161 "parser.y"
    { (yyval.node) = new PrimitiveTypeNode(PrimitiveType::Kind::LONG, (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 47:
#line 162 "parser.y"
    { (yyval.node) = new PrimitiveTypeNode(PrimitiveType::Kind::CHAR, (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 48:
#line 163 "parser.y"
    { (yyval.node) = new PrimitiveTypeNode(PrimitiveType::Kind::DOUBLE, (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 49:
#line 164 "parser.y"
    { (yyval.node) = new PrimitiveTypeNode(PrimitiveType::Kind::STR, (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 50:
#line 165 "parser.y"
    { (yyval.node) = new UserTypeNode((yyvsp[(1) - (1)].str), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 51:
#line 166 "parser.y"
    { (yyval.node) = new ArrayTypeNode((yyvsp[(1) - (3)].node), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 52:
#line 170 "parser.y"
    { (yyval.node) = new VarDeclListNode((yyvsp[(3) - (4)].node_list), true, (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 53:
#line 171 "parser.y"
    { (yyval.node) = new VarDeclListNode((yyvsp[(2) - (3)].node_list), false, (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 54:
#line 175 "parser.y"
    { (yyval.node_list) = new std::vector<ASTNode*>(); (yyval.node_list)->push_back((yyvsp[(1) - (1)].node)); ;}
    break;

  case 55:
#line 176 "parser.y"
    { (yyval.node_list)->push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 56:
#line 180 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 57:
#line 181 "parser.y"
    { (yyval.node) = new AssignmentNode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 58:
#line 182 "parser.y"
    { (yyval.node) = new AllocateNode((yyvsp[(1) - (2)].node), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 59:
#line 186 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 60:
#line 187 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 61:
#line 188 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 62:
#line 189 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 63:
#line 190 "parser.y"
    { (yyval.node) = new ReturnNode((yyvsp[(2) - (3)].node), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 64:
#line 191 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 65:
#line 192 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 66:
#line 193 "parser.y"
    { (yyval.node) = new BreakNode((yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 67:
#line 194 "parser.y"
    { (yyval.node) = new ContinueNode((yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 68:
#line 196 "parser.y"
    { (yyval.node) = new DestructNode((yyvsp[(4) - (5)].str), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 69:
#line 198 "parser.y"
    { (yyval.node) = new SizeofNode((yyvsp[(3) - (4)].node), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 70:
#line 202 "parser.y"
    { (yyval.node) = new AssignmentNode((yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 71:
#line 206 "parser.y"
    { (yyval.node) = new IDNode((yyvsp[(1) - (1)].str), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 72:
#line 207 "parser.y"
    { (yyval.node) = new ArrayAccessNode((yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 73:
#line 208 "parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); ;}
    break;

  case 74:
#line 209 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 75:
#line 210 "parser.y"
    { (yyval.node) = new UnaryOpNode("--", (yyvsp[(2) - (2)].node), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 76:
#line 211 "parser.y"
    { (yyval.node) = new UnaryOpNode("++", (yyvsp[(2) - (2)].node), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 77:
#line 212 "parser.y"
    { (yyval.node) = new UnaryOpNode("--", (yyvsp[(1) - (2)].node), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 78:
#line 213 "parser.y"
    { (yyval.node) = new UnaryOpNode("++", (yyvsp[(1) - (2)].node), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 79:
#line 217 "parser.y"
    { (yyval.node) = new FunctionCallNode((yyvsp[(1) - (3)].str), nullptr, (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 80:
#line 218 "parser.y"
    { (yyval.node) = new FunctionCallNode((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].node_list), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 81:
#line 222 "parser.y"
    { (yyval.node) = new IfNode((yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node), nullptr, (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 82:
#line 224 "parser.y"
    { (yyval.node) = new IfNode((yyvsp[(3) - (7)].node), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 83:
#line 226 "parser.y"
    { (yyval.node) = new SwitchNode((yyvsp[(3) - (7)].str), (yyvsp[(6) - (7)].node_list), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 84:
#line 230 "parser.y"
    { (yyval.node_list) = new std::vector<ASTNode*>(); ;}
    break;

  case 85:
#line 231 "parser.y"
    { (yyval.node_list)->push_back(new CaseNode((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].node), (yyloc).first_line, (yyloc).first_column)); ;}
    break;

  case 86:
#line 232 "parser.y"
    { (yyval.node_list)->push_back(new DefaultNode((yyvsp[(4) - (4)].node), (yyloc).first_line, (yyloc).first_column)); ;}
    break;

  case 87:
#line 237 "parser.y"
    { (yyval.node) = new ForNode((yyvsp[(3) - (8)].node), (yyvsp[(4) - (8)].node), (yyvsp[(6) - (8)].node), (yyvsp[(8) - (8)].node), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 88:
#line 241 "parser.y"
    { (yyval.node) = new GotoNode((yyvsp[(2) - (3)].str), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 89:
#line 245 "parser.y"
    { (yyval.node) = new LabelNode((yyvsp[(1) - (2)].str), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 90:
#line 249 "parser.y"
    { (yyval.node) = new BinaryOpNode((yyvsp[(2) - (3)].str), (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 91:
#line 250 "parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); ;}
    break;

  case 92:
#line 251 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 93:
#line 252 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 94:
#line 253 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 95:
#line 254 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 96:
#line 258 "parser.y"
    { (yyval.node) = new UnaryOpNode("-", (yyvsp[(2) - (2)].node), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 97:
#line 259 "parser.y"
    { (yyval.node) = new UnaryOpNode("!", (yyvsp[(2) - (2)].node), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 98:
#line 263 "parser.y"
    { (yyval.node) = new IDNode((yyvsp[(1) - (1)].str), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 99:
#line 264 "parser.y"
    { (yyval.node) = new IntegerLiteralNode(std::stoi((yyvsp[(1) - (1)].str)), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 100:
#line 265 "parser.y"
    { (yyval.node) = new RealLiteralNode(std::stod((yyvsp[(1) - (1)].str)), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 101:
#line 266 "parser.y"
    { (yyval.node) = new StringLiteralNode((yyvsp[(1) - (1)].str), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 102:
#line 267 "parser.y"
    { (yyval.node) = new BooleanLiteralNode(std::string((yyvsp[(1) - (1)].str)) == "true", (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 103:
#line 271 "parser.y"
    { (yyval.str) = strdup("+"); ;}
    break;

  case 104:
#line 272 "parser.y"
    { (yyval.str) = strdup("-"); ;}
    break;

  case 105:
#line 273 "parser.y"
    { (yyval.str) = strdup("*"); ;}
    break;

  case 106:
#line 274 "parser.y"
    { (yyval.str) = strdup("/"); ;}
    break;

  case 107:
#line 275 "parser.y"
    { (yyval.str) = strdup("%"); ;}
    break;

  case 108:
#line 276 "parser.y"
    { (yyval.str) = strdup("&"); ;}
    break;

  case 109:
#line 277 "parser.y"
    { (yyval.str) = strdup("|"); ;}
    break;

  case 110:
#line 278 "parser.y"
    { (yyval.str) = strdup("^"); ;}
    break;

  case 111:
#line 279 "parser.y"
    { (yyval.str) = strdup("||"); ;}
    break;

  case 112:
#line 280 "parser.y"
    { (yyval.str) = strdup("&&"); ;}
    break;

  case 113:
#line 281 "parser.y"
    { (yyval.str) = strdup("=="); ;}
    break;

  case 114:
#line 282 "parser.y"
    { (yyval.str) = strdup("!="); ;}
    break;

  case 115:
#line 283 "parser.y"
    { (yyval.str) = strdup("<="); ;}
    break;

  case 116:
#line 284 "parser.y"
    { (yyval.str) = strdup("<"); ;}
    break;

  case 117:
#line 285 "parser.y"
    { (yyval.str) = strdup(">"); ;}
    break;

  case 118:
#line 286 "parser.y"
    { (yyval.str) = strdup(">="); ;}
    break;

  case 119:
#line 290 "parser.y"
    { (yyval.node) = new IntegerLiteralNode(std::stoi((yyvsp[(1) - (1)].str)), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 120:
#line 291 "parser.y"
    { (yyval.node) = new RealLiteralNode(std::stod((yyvsp[(1) - (1)].str)), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 121:
#line 292 "parser.y"
    { (yyval.node) = new StringLiteralNode((yyvsp[(1) - (1)].str), (yyloc).first_line, (yyloc).first_column); ;}
    break;

  case 122:
#line 293 "parser.y"
    { (yyval.node) = new BooleanLiteralNode(std::string((yyvsp[(1) - (1)].str)) == "true", (yyloc).first_line, (yyloc).first_column); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2362 "src/parser.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 296 "parser.y"


void yyerror(const char* s) {
    std::cerr << "Error: " << s << " at line " << yylineno << std::endl;
}

