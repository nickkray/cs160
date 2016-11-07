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
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PROCEDURE = 258,
     ELSE = 259,
     IF = 260,
     FOR = 261,
     VAR = 262,
     RET = 263,
     WHILE = 264,
     EQEQ = 265,
     GT = 266,
     GTEQ = 267,
     LT = 268,
     LTEQ = 269,
     NE = 270,
     ANDAND = 271,
     OROR = 272,
     NOT = 273,
     PLUS = 274,
     MINUS = 275,
     MULT = 276,
     DIV = 277,
     AND = 278,
     XOR = 279,
     OR = 280,
     PIPE = 281,
     _INTPTR = 282,
     _CHARPTR = 283,
     _BOOL = 284,
     _INT = 285,
     _CHAR = 286,
     _STRING = 287,
     TRUE = 288,
     FALSE = 289,
     NULLTOKEN = 290,
     VARNAME = 291,
     INT = 292,
     CHAR = 293,
     STRING = 294,
     SEMI_COLON = 295,
     COLON = 296,
     COMMA = 297,
     ABS = 298,
     LEFT_BRACE = 299,
     RIGHT_BRACE = 300,
     LEFT_PAREN = 301,
     RIGHT_PAREN = 302,
     LEFT_BRACKET = 303,
     RIGHT_BRACKET = 304,
     EQ = 305
   };
#endif
/* Tokens.  */
#define PROCEDURE 258
#define ELSE 259
#define IF 260
#define FOR 261
#define VAR 262
#define RET 263
#define WHILE 264
#define EQEQ 265
#define GT 266
#define GTEQ 267
#define LT 268
#define LTEQ 269
#define NE 270
#define ANDAND 271
#define OROR 272
#define NOT 273
#define PLUS 274
#define MINUS 275
#define MULT 276
#define DIV 277
#define AND 278
#define XOR 279
#define OR 280
#define PIPE 281
#define _INTPTR 282
#define _CHARPTR 283
#define _BOOL 284
#define _INT 285
#define _CHAR 286
#define _STRING 287
#define TRUE 288
#define FALSE 289
#define NULLTOKEN 290
#define VARNAME 291
#define INT 292
#define CHAR 293
#define STRING 294
#define SEMI_COLON 295
#define COLON 296
#define COMMA 297
#define ABS 298
#define LEFT_BRACE 299
#define RIGHT_BRACE 300
#define LEFT_PAREN 301
#define RIGHT_PAREN 302
#define LEFT_BRACKET 303
#define RIGHT_BRACKET 304
#define EQ 305




/* Copy the first part of user declarations.  */
#line 1 "parser.ypp"

    #include <cstdio>
    #include <cstdlib>

    #include "ast.hpp"
    #include "primitive.hpp"
    #include "symtab.hpp"

    #define YYDEBUG 1

    extern Program_ptr ast;
    int yylex(void);
    void yyerror(const char *);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 221 "parser.cpp"

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
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   369

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNRULES -- Number of states.  */
#define YYNSTATES  146

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,    17,    19,    20,    24,    30,    34,
      36,    40,    45,    49,    52,    53,    56,    57,    63,    67,
      69,    72,    74,    80,    85,    90,    98,   105,   107,   109,
     113,   115,   123,   129,   135,   140,   143,   145,   150,   152,
     154,   156,   158,   160,   164,   166,   170,   174,   178,   182,
     186,   190,   194,   198,   202,   206,   210,   214,   219,   222,
     225,   229,   231,   235,   238,   240,   242,   244,   246,   248,
     251
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    53,    59,    -1,     3,    36,    46,    54,
      47,     8,    69,    44,    58,    45,    -1,    55,    -1,    -1,
      56,    41,    69,    -1,    56,    41,    69,    40,    55,    -1,
      56,    42,    36,    -1,    36,    -1,     8,    71,    40,    -1,
      59,    60,    63,    57,    -1,    59,    60,    57,    -1,    59,
      53,    -1,    -1,    60,    61,    -1,    -1,     7,    62,    41,
      68,    40,    -1,    36,    42,    62,    -1,    36,    -1,    63,
      64,    -1,    64,    -1,    36,    70,    50,    71,    40,    -1,
      36,    50,    39,    40,    -1,    36,    50,    71,    40,    -1,
      36,    50,    36,    46,    65,    47,    40,    -1,    36,    50,
      36,    46,    47,    40,    -1,    66,    -1,    67,    -1,    71,
      42,    65,    -1,    71,    -1,     5,    46,    71,    47,    67,
       4,    67,    -1,     5,    46,    71,    47,    67,    -1,     9,
      46,    71,    47,    67,    -1,    44,    60,    63,    45,    -1,
      44,    45,    -1,    69,    -1,    32,    48,    37,    49,    -1,
      30,    -1,    31,    -1,    28,    -1,    27,    -1,    29,    -1,
      48,    71,    49,    -1,    72,    -1,    71,    10,    71,    -1,
      71,    11,    71,    -1,    71,    13,    71,    -1,    71,    14,
      71,    -1,    71,    25,    71,    -1,    71,    15,    71,    -1,
      71,    16,    71,    -1,    71,    19,    71,    -1,    71,    20,
      71,    -1,    71,    21,    71,    -1,    71,    22,    71,    -1,
      26,    71,    26,    -1,    24,    46,    71,    47,    -1,    18,
      71,    -1,    20,    71,    -1,    46,    71,    47,    -1,    36,
      -1,    23,    36,    70,    -1,    23,    36,    -1,    37,    -1,
      38,    -1,    33,    -1,    34,    -1,    35,    -1,    24,    36,
      -1,    36,    48,    71,    49,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   143,   143,   156,   162,   167,   175,   180,   189,   194,
     204,   215,   220,   227,   233,   240,   248,   255,   262,   267,
     275,   280,   298,   309,   321,   325,   329,   334,   336,   345,
     350,   375,   379,   383,   389,   393,   400,   404,   410,   411,
     412,   413,   414,   418,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     480
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROCEDURE", "ELSE", "IF", "FOR", "VAR",
  "RET", "WHILE", "EQEQ", "GT", "GTEQ", "LT", "LTEQ", "NE", "ANDAND",
  "OROR", "NOT", "PLUS", "MINUS", "MULT", "DIV", "AND", "XOR", "OR",
  "PIPE", "_INTPTR", "_CHARPTR", "_BOOL", "_INT", "_CHAR", "_STRING",
  "TRUE", "FALSE", "NULLTOKEN", "VARNAME", "INT", "CHAR", "STRING",
  "SEMI_COLON", "COLON", "COMMA", "ABS", "LEFT_BRACE", "RIGHT_BRACE",
  "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACKET", "RIGHT_BRACKET", "EQ",
  "$accept", "Program", "Proc", "ParameterListOrNot", "TypedParamList",
  "Paramlist", "Return", "Structure", "Procs", "VarDecs", "VarDec",
  "VAR_DEC_LHS", "Statements", "Statement", "FuncCall", "IF_WHILE",
  "CodeBlock", "StringType", "Primitive", "ArrayIndex", "Expr", "Value", 0
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
     305
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    54,    54,    55,    55,    56,    56,
      57,    58,    58,    59,    59,    60,    60,    61,    62,    62,
      63,    63,    64,    64,    64,    64,    64,    64,    64,    65,
      65,    66,    66,    66,    67,    67,    68,    68,    69,    69,
      69,    69,    69,    70,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,    10,     1,     0,     3,     5,     3,     1,
       3,     4,     3,     2,     0,     2,     0,     5,     3,     1,
       2,     1,     5,     4,     4,     7,     6,     1,     1,     3,
       1,     7,     5,     5,     4,     2,     1,     4,     1,     1,
       1,     1,     1,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     4,     2,     2,
       3,     1,     3,     2,     1,     1,     1,     1,     1,     2,
       4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    14,     0,     1,     2,     5,    13,     9,
       0,     4,     0,     0,     0,     0,     0,    41,    40,    42,
      38,    39,     6,     8,     0,     0,    14,     7,     0,    16,
       3,     0,     0,     0,     0,     0,     0,    16,    12,    15,
       0,    21,    27,    28,     0,    19,     0,     0,     0,     0,
       0,     0,    66,    67,    68,    61,    64,    65,     0,     0,
      44,     0,     0,     0,     0,    35,     0,    11,    20,     0,
       0,     0,    58,    59,    63,    69,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,     0,     0,    61,     0,     0,     0,     0,     0,
      18,     0,     0,    36,    62,     0,    56,     0,    60,    45,
      46,    47,    48,    50,    51,    52,    53,    54,    55,    49,
       0,    43,     0,    23,    24,     0,    34,    32,     0,    17,
      57,    70,    33,     0,     0,    30,    22,     0,     0,    26,
       0,     0,    31,    37,    25,    29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,    10,    11,    12,    38,    28,     6,    31,
      39,    46,    40,    41,   134,    42,    43,   102,    22,    64,
     135,    60
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -80
static const yytype_int16 yypact[] =
{
       0,   -24,    16,   -80,   -15,   -80,     0,    -4,   -80,   -80,
      -2,   -80,   -16,    52,     9,    26,     9,   -80,   -80,   -80,
     -80,   -80,    -7,   -80,    20,    -4,   -80,   -80,    21,     0,
     -80,    -1,    19,    31,   272,    22,   -27,    28,   -80,   -80,
      92,   -80,   -80,   -80,   272,    36,    38,   272,   272,    55,
     -31,   272,   -80,   -80,   -80,    44,   -80,   -80,   272,   182,
     -80,   272,   272,   248,    48,   -80,    97,   -80,   -80,   105,
      31,   337,    78,    -3,    57,   -80,   272,   301,   272,   124,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   -80,   140,    61,   -37,    67,   199,   272,    25,    64,
     -80,    63,    69,   -80,   -80,   153,   -80,    74,   -80,   331,
     338,   338,   338,   331,   318,    -3,    -3,    78,    78,   -80,
      64,   -80,   223,   -80,   -80,   215,   -80,   108,    76,   -80,
     -80,   -80,   -80,    77,    75,   169,   -80,    64,    65,   -80,
      89,   272,   -80,   -80,   -80,   -80
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -80,   -80,   131,   -80,   107,   -80,   102,   -80,   121,   111,
     -80,    87,   104,   -39,    17,   -80,   -79,   -80,   -14,   103,
     -34,   -80
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      59,    68,    24,     1,    32,    75,    33,    34,    35,   122,
      69,    78,     4,    72,    73,    76,     5,    77,    88,    89,
     127,    62,    90,    63,    79,    14,    15,    92,    93,    96,
      32,     7,     9,    25,    35,    36,    17,    18,    19,    20,
      21,   132,   105,    37,   107,    13,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   103,   142,    68,
      16,    36,    23,   125,    26,    44,    30,    45,    61,    37,
     126,    80,    81,    65,    82,    83,    84,    85,    70,    71,
      86,    87,    88,    89,    80,    81,    90,    82,    83,    84,
      85,    74,    78,    86,    87,    88,    89,    32,    97,    90,
      34,    35,    32,    90,    33,    62,    35,   123,    37,   129,
     121,   128,   137,   138,   143,    80,    81,   139,    82,    83,
      84,    85,   140,   131,    86,    87,    88,    89,    36,   144,
      90,     3,    27,    36,    80,    81,    37,    82,    83,    84,
      85,    37,    67,    86,    87,    88,    89,    29,    66,    90,
      80,    81,    99,    82,    83,    84,    85,   100,   145,    86,
      87,    88,    89,    80,    81,    90,    82,    83,    84,    85,
      98,   108,    86,    87,    88,    89,     0,   104,    90,    80,
      81,     0,    82,    83,    84,    85,     0,   120,    86,    87,
      88,    89,    80,    81,    90,    82,    83,    84,    85,     0,
     130,    86,    87,    88,    89,     0,     0,    90,     0,    80,
      81,   141,    82,    83,    84,    85,     0,     0,    86,    87,
      88,    89,    91,     0,    90,    80,    81,     0,    82,    83,
      84,    85,     0,     0,    86,    87,    88,    89,     0,   124,
      90,    47,     0,    48,     0,     0,    49,    50,     0,    51,
       0,     0,     0,     0,     0,   136,    52,    53,    54,    55,
      56,    57,     0,     0,     0,     0,    47,     0,    48,    58,
     133,    49,    50,     0,    51,     0,     0,     0,     0,     0,
       0,    52,    53,    54,    94,    56,    57,    95,     0,     0,
      47,     0,    48,     0,    58,    49,    50,     0,    51,     0,
       0,     0,     0,     0,     0,    52,    53,    54,    55,    56,
      57,    80,    81,     0,    82,    83,    84,    85,    58,     0,
      86,    87,    88,    89,     0,     0,    90,   106,    80,    81,
       0,    82,    83,    84,     0,     0,     0,    86,    87,    88,
      89,     0,    81,    90,    82,    83,     0,     0,     0,     0,
      86,    87,    88,    89,     0,     0,    90,    86,    87,    88,
      89,     0,     0,    90,    17,    18,    19,    20,    21,   101
};

static const yytype_int16 yycheck[] =
{
      34,    40,    16,     3,     5,    36,     7,     8,     9,    46,
      44,    48,    36,    47,    48,    46,     0,    51,    21,    22,
      99,    48,    25,    50,    58,    41,    42,    61,    62,    63,
       5,    46,    36,    40,     9,    36,    27,    28,    29,    30,
      31,   120,    76,    44,    78,    47,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    71,   137,    98,
       8,    36,    36,    97,    44,    46,    45,    36,    46,    44,
      45,    10,    11,    45,    13,    14,    15,    16,    42,    41,
      19,    20,    21,    22,    10,    11,    25,    13,    14,    15,
      16,    36,    48,    19,    20,    21,    22,     5,    50,    25,
       8,     9,     5,    25,     7,    48,     9,    40,    44,    40,
      49,    48,     4,    37,    49,    10,    11,    40,    13,    14,
      15,    16,    47,    49,    19,    20,    21,    22,    36,    40,
      25,     0,    25,    36,    10,    11,    44,    13,    14,    15,
      16,    44,    40,    19,    20,    21,    22,    26,    37,    25,
      10,    11,    47,    13,    14,    15,    16,    70,   141,    19,
      20,    21,    22,    10,    11,    25,    13,    14,    15,    16,
      66,    47,    19,    20,    21,    22,    -1,    74,    25,    10,
      11,    -1,    13,    14,    15,    16,    -1,    47,    19,    20,
      21,    22,    10,    11,    25,    13,    14,    15,    16,    -1,
      47,    19,    20,    21,    22,    -1,    -1,    25,    -1,    10,
      11,    42,    13,    14,    15,    16,    -1,    -1,    19,    20,
      21,    22,    40,    -1,    25,    10,    11,    -1,    13,    14,
      15,    16,    -1,    -1,    19,    20,    21,    22,    -1,    40,
      25,    18,    -1,    20,    -1,    -1,    23,    24,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    40,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    18,    -1,    20,    46,
      47,    23,    24,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    35,    36,    37,    38,    39,    -1,    -1,
      18,    -1,    20,    -1,    46,    23,    24,    -1,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,
      38,    10,    11,    -1,    13,    14,    15,    16,    46,    -1,
      19,    20,    21,    22,    -1,    -1,    25,    26,    10,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    19,    20,    21,
      22,    -1,    11,    25,    13,    14,    -1,    -1,    -1,    -1,
      19,    20,    21,    22,    -1,    -1,    25,    19,    20,    21,
      22,    -1,    -1,    25,    27,    28,    29,    30,    31,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    52,    53,    36,     0,    59,    46,    53,    36,
      54,    55,    56,    47,    41,    42,     8,    27,    28,    29,
      30,    31,    69,    36,    69,    40,    44,    55,    58,    59,
      45,    60,     5,     7,     8,     9,    36,    44,    57,    61,
      63,    64,    66,    67,    46,    36,    62,    18,    20,    23,
      24,    26,    33,    34,    35,    36,    37,    38,    46,    71,
      72,    46,    48,    50,    70,    45,    60,    57,    64,    71,
      42,    41,    71,    71,    36,    36,    46,    71,    48,    71,
      10,    11,    13,    14,    15,    16,    19,    20,    21,    22,
      25,    40,    71,    71,    36,    39,    71,    50,    63,    47,
      62,    32,    68,    69,    70,    71,    26,    71,    47,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      47,    49,    46,    40,    40,    71,    45,    67,    48,    40,
      47,    49,    67,    47,    65,    71,    40,     4,    37,    40,
      47,    42,    67,    49,    40,    65
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


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


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

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

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 144 "parser.ypp"
    {
                ast = new ProgramImpl((yyvsp[(2) - (2)]).u_proc_list);
                ((yyvsp[(2) - (2)]).u_proc_list)->push_front((yyvsp[(1) - (2)]).u_proc);
            ;}
    break;

  case 3:
#line 157 "parser.ypp"
    {
                (yyval).u_proc=new ProcImpl(new SymName((yyvsp[(2) - (10)]).u_base_charptr), (yyvsp[(4) - (10)]).u_decl_list, (yyvsp[(7) - (10)]).u_type, (yyvsp[(9) - (10)]).u_procedure_block);
            ;}
    break;

  case 4:
#line 163 "parser.ypp"
    {
                        (yyval) = (yyvsp[(1) - (1)]);
                    ;}
    break;

  case 5:
#line 167 "parser.ypp"
    {
                        (yyval).u_decl_list=new std::list<Decl_ptr>();
                        std::fprintf(stderr, "no parameter list.\n");
                    ;}
    break;

  case 6:
#line 176 "parser.ypp"
    {
                    (yyval).u_decl_list=new std::list<Decl_ptr>();
                    ((yyval).u_decl_list)->push_back(new DeclImpl((yyvsp[(1) - (3)]).u_symname_list, (yyvsp[(3) - (3)]).u_type));
                ;}
    break;

  case 7:
#line 181 "parser.ypp"
    {
                    ((yyvsp[(5) - (5)]).u_decl_list)->push_front(new DeclImpl((yyvsp[(1) - (5)]).u_symname_list,(yyvsp[(3) - (5)]).u_type));
                    (yyval) = (yyvsp[(5) - (5)]);
                ;}
    break;

  case 8:
#line 190 "parser.ypp"
    {
                (yyvsp[(1) - (3)]).u_symname_list->push_back(new SymName((yyvsp[(3) - (3)]).u_base_charptr));
                (yyval) = (yyvsp[(1) - (3)]);
            ;}
    break;

  case 9:
#line 195 "parser.ypp"
    {
                (yyval).u_symname_list = new std::list<SymName_ptr>();
                ((yyval).u_symname_list)->push_back(new SymName((yyvsp[(1) - (1)]).u_base_charptr));
            ;}
    break;

  case 10:
#line 205 "parser.ypp"
    {
                (yyval).u_return_stat = new Return((yyvsp[(2) - (3)]).u_expr);
            ;}
    break;

  case 11:
#line 216 "parser.ypp"
    {
                std::fprintf(stderr, "Entering Proc structure.\n");
                (yyval).u_procedure_block = new Procedure_blockImpl((yyvsp[(1) - (4)]).u_proc_list, (yyvsp[(2) - (4)]).u_decl_list, (yyvsp[(3) - (4)]).u_stat_list, (yyvsp[(4) - (4)]).u_return_stat);
            ;}
    break;

  case 12:
#line 221 "parser.ypp"
    {
                std::fprintf(stderr, "Entering Proc structure w/o statements.\n");
                (yyval).u_procedure_block = new Procedure_blockImpl((yyvsp[(1) - (3)]).u_proc_list,(yyvsp[(2) - (3)]).u_decl_list, new std::list<Stat_ptr>, (yyvsp[(3) - (3)]).u_return_stat);
            ;}
    break;

  case 13:
#line 228 "parser.ypp"
    {
                ((yyvsp[(1) - (2)]).u_proc_list)->push_back((yyvsp[(2) - (2)]).u_proc);
                (yyval)=(yyvsp[(1) - (2)]);
            ;}
    break;

  case 14:
#line 233 "parser.ypp"
    {
                (yyval).u_proc_list = new std::list<Proc_ptr>();
                std::fprintf(stderr, "procedures done.\n");
            ;}
    break;

  case 15:
#line 241 "parser.ypp"
    {
    
    /*                ($$.u_decl_list)->push_back(new DeclImpl($3.u_symname_list, $5.u_type))   */
                (yyvsp[(1) - (2)]).u_decl_list->push_back((yyvsp[(2) - (2)]).u_decl);
                (yyval) = (yyvsp[(1) - (2)]);
            ;}
    break;

  case 16:
#line 248 "parser.ypp"
    {
                (yyval).u_decl_list = new std::list<Decl_ptr>();
            ;}
    break;

  case 17:
#line 256 "parser.ypp"
    {
                (yyval).u_decl = new DeclImpl((yyvsp[(2) - (5)]).u_symname_list, (yyvsp[(4) - (5)]).u_type);
            ;}
    break;

  case 18:
#line 263 "parser.ypp"
    {
                ((yyvsp[(3) - (3)]).u_symname_list)->push_front(new SymName((yyvsp[(1) - (3)]).u_base_charptr));
                ((yyval).u_symname_list) = (yyvsp[(3) - (3)]).u_symname_list;
            ;}
    break;

  case 19:
#line 268 "parser.ypp"
    {
                ((yyval).u_symname_list) = new std::list<SymName_ptr>();
                ((yyval).u_symname_list)->push_back(new SymName((yyvsp[(1) - (1)]).u_base_charptr));
            ;}
    break;

  case 20:
#line 276 "parser.ypp"
    {
                (yyvsp[(1) - (2)]).u_stat_list->push_back((yyvsp[(2) - (2)]).u_stat);
                (yyval) = (yyvsp[(1) - (2)]);
            ;}
    break;

  case 21:
#line 281 "parser.ypp"
    {
                (yyval).u_stat_list = new std::list<Stat_ptr>();
                (yyval).u_stat_list -> push_back((yyvsp[(1) - (1)]).u_stat);
            ;}
    break;

  case 22:
#line 299 "parser.ypp"
    {
    (yyval).u_stat = new Assignment(new ArrayElement(new SymName((yyvsp[(1) - (5)]).u_base_charptr), (yyvsp[(2) - (5)]).u_expr), (yyvsp[(4) - (5)]).u_expr);
;}
    break;

  case 23:
#line 310 "parser.ypp"
    {
    
    (yyval).u_stat = new StringAssignment(new Variable(new SymName((yyvsp[(1) - (4)]).u_base_charptr)), new StringPrimitive((yyvsp[(3) - (4)]).u_base_charptr));
    
;}
    break;

  case 24:
#line 322 "parser.ypp"
    {
    (yyval).u_stat = new Assignment(new Variable(new SymName((yyvsp[(1) - (4)]).u_base_charptr)), (yyvsp[(3) - (4)]).u_expr)
;}
    break;

  case 25:
#line 326 "parser.ypp"
    {
    (yyval).u_stat=new Call(new Variable(new SymName((yyvsp[(1) - (7)]).u_base_charptr)),new SymName((yyvsp[(3) - (7)]).u_base_charptr), (yyvsp[(5) - (7)]).u_expr_list);
;}
    break;

  case 26:
#line 330 "parser.ypp"
    {
    (yyval).u_stat=new Call(new Variable(new SymName((yyvsp[(1) - (6)]).u_base_charptr)),new SymName((yyvsp[(3) - (6)]).u_base_charptr), new std::list<Expr_ptr>());
;}
    break;

  case 28:
#line 337 "parser.ypp"
    {
    (yyval).u_stat = new CodeBlock((yyvsp[(1) - (1)]).u_nested_block);
;}
    break;

  case 29:
#line 346 "parser.ypp"
    {
    (yyvsp[(3) - (3)]).u_expr_list->push_back((yyvsp[(1) - (3)]).u_expr);
    (yyval) = (yyvsp[(3) - (3)]);
;}
    break;

  case 30:
#line 351 "parser.ypp"
    {
    (yyval).u_expr_list = new std::list<Expr_ptr>();
    (yyval).u_expr_list->push_back((yyvsp[(1) - (1)]).u_expr);
;}
    break;

  case 31:
#line 376 "parser.ypp"
    {
    (yyval).u_stat = new IfWithElse((yyvsp[(3) - (7)]).u_expr, (yyvsp[(5) - (7)]).u_nested_block, (yyvsp[(7) - (7)]).u_nested_block);
;}
    break;

  case 32:
#line 380 "parser.ypp"
    {
    (yyval).u_stat = new IfNoElse((yyvsp[(3) - (5)]).u_expr, (yyvsp[(5) - (5)]).u_nested_block);
;}
    break;

  case 33:
#line 384 "parser.ypp"
    {
    (yyval).u_stat = new WhileLoop((yyvsp[(3) - (5)]).u_expr, (yyvsp[(5) - (5)]).u_nested_block);
;}
    break;

  case 34:
#line 390 "parser.ypp"
    {
    (yyval).u_nested_block = new Nested_blockImpl((yyvsp[(2) - (4)]).u_decl_list, (yyvsp[(3) - (4)]).u_stat_list);
;}
    break;

  case 35:
#line 394 "parser.ypp"
    {
    (yyval).u_nested_block = new Nested_blockImpl(new std::list<Decl_ptr>(), new std::list<Stat_ptr>());
;}
    break;

  case 36:
#line 401 "parser.ypp"
    {
    (yyval) = (yyvsp[(1) - (1)]);
;}
    break;

  case 37:
#line 405 "parser.ypp"
    {
    (yyval).u_type = new TString(new Primitive((yyvsp[(3) - (4)]).u_base_int));                                   /* TODO */
;}
    break;

  case 38:
#line 410 "parser.ypp"
    {(yyval).u_type = new TInteger();;}
    break;

  case 39:
#line 411 "parser.ypp"
    {(yyval).u_type = new TCharacter();;}
    break;

  case 40:
#line 412 "parser.ypp"
    {(yyval).u_type = new TCharPtr();;}
    break;

  case 41:
#line 413 "parser.ypp"
    {(yyval).u_type = new TIntPtr();;}
    break;

  case 42:
#line 414 "parser.ypp"
    {(yyval).u_type = new TBoolean();;}
    break;

  case 43:
#line 419 "parser.ypp"
    {
    (yyval).u_expr = (yyvsp[(2) - (3)]).u_expr;
;}
    break;

  case 44:
#line 424 "parser.ypp"
    {(yyval).u_expr = (yyvsp[(1) - (1)]).u_expr;;}
    break;

  case 45:
#line 425 "parser.ypp"
    {(yyval).u_expr = new Compare((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);;}
    break;

  case 46:
#line 426 "parser.ypp"
    {(yyval).u_expr = new Gt((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);;}
    break;

  case 47:
#line 427 "parser.ypp"
    {(yyval).u_expr = new Lt((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);;}
    break;

  case 48:
#line 428 "parser.ypp"
    {(yyval).u_expr = new Lteq((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);;}
    break;

  case 49:
#line 429 "parser.ypp"
    {(yyval).u_expr = new Or((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);;}
    break;

  case 50:
#line 430 "parser.ypp"
    {(yyval).u_expr = new Noteq((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);;}
    break;

  case 51:
#line 431 "parser.ypp"
    {(yyval).u_expr = new And((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);;}
    break;

  case 52:
#line 432 "parser.ypp"
    {(yyval).u_expr = new Plus((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);;}
    break;

  case 53:
#line 433 "parser.ypp"
    {(yyval).u_expr = new Minus((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);;}
    break;

  case 54:
#line 434 "parser.ypp"
    {(yyval).u_expr = new Times((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);;}
    break;

  case 55:
#line 435 "parser.ypp"
    {(yyval).u_expr = new Div((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);;}
    break;

  case 56:
#line 436 "parser.ypp"
    {(yyval).u_expr = new AbsoluteValue((yyvsp[(2) - (3)]).u_expr);;}
    break;

  case 57:
#line 437 "parser.ypp"
    {(yyval).u_expr=new Deref((yyvsp[(1) - (4)]).u_expr);;}
    break;

  case 58:
#line 438 "parser.ypp"
    {(yyval).u_expr = new Not((yyvsp[(2) - (2)]).u_expr);;}
    break;

  case 59:
#line 439 "parser.ypp"
    {(yyval).u_expr = new Uminus((yyvsp[(2) - (2)]).u_expr);;}
    break;

  case 60:
#line 440 "parser.ypp"
    {(yyval).u_expr = ((yyvsp[(2) - (3)]).u_expr);;}
    break;

  case 61:
#line 465 "parser.ypp"
    { (yyval).u_expr=new Ident(new SymName((yyvsp[(1) - (1)]).u_base_charptr));;}
    break;

  case 62:
#line 466 "parser.ypp"
    {(yyval).u_expr = new ArrayAccess(new SymName((yyvsp[(1) - (3)]).u_base_charptr), (yyvsp[(3) - (3)]).u_expr);;}
    break;

  case 63:
#line 467 "parser.ypp"
    {(yyval).u_expr= new AddressOf(new Variable(new SymName((yyvsp[(2) - (2)]).u_base_charptr)));;}
    break;

  case 64:
#line 468 "parser.ypp"
    {(yyval).u_expr=new IntLit(new Primitive((yyvsp[(1) - (1)]).u_base_int)); ;}
    break;

  case 65:
#line 469 "parser.ypp"
    {(yyval).u_expr=new CharLit(new Primitive((yyvsp[(1) - (1)]).u_base_int)); ;}
    break;

  case 66:
#line 470 "parser.ypp"
    {(yyval).u_expr=new BoolLit(new Primitive((yyvsp[(1) - (1)]).u_base_int));;}
    break;

  case 67:
#line 471 "parser.ypp"
    {(yyval).u_expr=new BoolLit(new Primitive((yyvsp[(1) - (1)]).u_base_int));;}
    break;

  case 69:
#line 473 "parser.ypp"
    {(yyval).u_expr=new Deref(new Ident(new SymName((yyvsp[(2) - (2)]).u_base_charptr)));;}
    break;

  case 70:
#line 480 "parser.ypp"
    {(yyval).u_expr=new ArrayAccess(new SymName((yyvsp[(1) - (4)]).u_base_charptr), (yyvsp[(3) - (4)]).u_expr);;}
    break;


/* Line 1267 of yacc.c.  */
#line 2018 "parser.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


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
		      yytoken, &yylval);
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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


#line 499 "parser.ypp"


/** You shall not pass!
 *  You should not  have to do or edit anything past this.
 */


extern int yylineno;

void yyerror(const char *s)
{
    fprintf(stderr, "%s at line %d\n", s, yylineno);
    return;
}

