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
     IDENTIFIER = 258,
     CONSTANT = 259,
     STRING_LITERAL = 260,
     SIZEOF = 261,
     PTR_OP = 262,
     INC_OP = 263,
     DEC_OP = 264,
     LEFT_OP = 265,
     RIGHT_OP = 266,
     LE_OP = 267,
     GE_OP = 268,
     EQ_OP = 269,
     NE_OP = 270,
     AND_OP = 271,
     OR_OP = 272,
     MUL_ASSIGN = 273,
     DIV_ASSIGN = 274,
     MOD_ASSIGN = 275,
     ADD_ASSIGN = 276,
     SUB_ASSIGN = 277,
     LEFT_ASSIGN = 278,
     RIGHT_ASSIGN = 279,
     AND_ASSIGN = 280,
     XOR_ASSIGN = 281,
     OR_ASSIGN = 282,
     TYPE_NAME = 283,
     TYPEDEF = 284,
     EXTERN = 285,
     STATIC = 286,
     AUTO = 287,
     REGISTER = 288,
     INLINE = 289,
     RESTRICT = 290,
     CHAR = 291,
     SHORT = 292,
     INT = 293,
     LONG = 294,
     SIGNED = 295,
     UNSIGNED = 296,
     FLOAT = 297,
     DOUBLE = 298,
     CONST = 299,
     VOLATILE = 300,
     VOID = 301,
     BOOL = 302,
     COMPLEX = 303,
     IMAGINARY = 304,
     STRUCT = 305,
     UNION = 306,
     ENUM = 307,
     ELLIPSIS = 308,
     CASE = 309,
     DEFAULT = 310,
     IF = 311,
     ELSE = 312,
     SWITCH = 313,
     WHILE = 314,
     DO = 315,
     FOR = 316,
     GOTO = 317,
     CONTINUE = 318,
     BREAK = 319,
     RETURN = 320
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define CONSTANT 259
#define STRING_LITERAL 260
#define SIZEOF 261
#define PTR_OP 262
#define INC_OP 263
#define DEC_OP 264
#define LEFT_OP 265
#define RIGHT_OP 266
#define LE_OP 267
#define GE_OP 268
#define EQ_OP 269
#define NE_OP 270
#define AND_OP 271
#define OR_OP 272
#define MUL_ASSIGN 273
#define DIV_ASSIGN 274
#define MOD_ASSIGN 275
#define ADD_ASSIGN 276
#define SUB_ASSIGN 277
#define LEFT_ASSIGN 278
#define RIGHT_ASSIGN 279
#define AND_ASSIGN 280
#define XOR_ASSIGN 281
#define OR_ASSIGN 282
#define TYPE_NAME 283
#define TYPEDEF 284
#define EXTERN 285
#define STATIC 286
#define AUTO 287
#define REGISTER 288
#define INLINE 289
#define RESTRICT 290
#define CHAR 291
#define SHORT 292
#define INT 293
#define LONG 294
#define SIGNED 295
#define UNSIGNED 296
#define FLOAT 297
#define DOUBLE 298
#define CONST 299
#define VOLATILE 300
#define VOID 301
#define BOOL 302
#define COMPLEX 303
#define IMAGINARY 304
#define STRUCT 305
#define UNION 306
#define ENUM 307
#define ELLIPSIS 308
#define CASE 309
#define DEFAULT 310
#define IF 311
#define ELSE 312
#define SWITCH 313
#define WHILE 314
#define DO 315
#define FOR 316
#define GOTO 317
#define CONTINUE 318
#define BREAK 319
#define RETURN 320




/* Copy the first part of user declarations.  */
#line 2 "c99.y"

#include <stdio.h>
#include <stdlib.h>
void yyerror(FILE* fp, char const *s);
int yylex();
extern FILE * yyin;


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
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 244 "c99.tab.c"

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
#define YYFINAL  55
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1561

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  90
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  238
/* YYNRULES -- Number of states.  */
#define YYNSTATES  400

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   320

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    79,     2,     2,     2,    81,    74,     2,
      66,    67,    75,    76,    73,    77,    70,    80,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    87,    89,
      82,    88,    83,    86,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    68,     2,    69,    84,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    71,    85,    72,    78,     2,     2,     2,
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
      65
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    13,    15,    20,    24,
      29,    33,    37,    40,    43,    50,    58,    60,    64,    66,
      69,    72,    75,    78,    83,    85,    87,    89,    91,    93,
      95,    97,   102,   104,   108,   112,   116,   118,   122,   126,
     128,   132,   136,   138,   142,   146,   150,   154,   156,   160,
     164,   166,   170,   172,   176,   178,   182,   184,   188,   190,
     194,   196,   202,   204,   208,   210,   212,   214,   216,   218,
     220,   222,   224,   226,   228,   230,   232,   236,   238,   241,
     245,   247,   250,   252,   255,   257,   260,   262,   265,   267,
     271,   273,   277,   279,   281,   283,   285,   287,   289,   291,
     293,   295,   297,   299,   301,   303,   305,   307,   309,   311,
     313,   315,   317,   323,   328,   331,   333,   335,   337,   340,
     344,   347,   349,   352,   354,   356,   360,   362,   365,   369,
     374,   380,   386,   393,   396,   398,   402,   404,   408,   410,
     412,   414,   416,   419,   421,   423,   427,   433,   438,   443,
     450,   457,   463,   468,   472,   477,   482,   486,   488,   491,
     494,   498,   500,   503,   505,   509,   511,   515,   518,   521,
     523,   525,   529,   531,   534,   536,   538,   541,   545,   548,
     552,   556,   561,   565,   570,   573,   577,   581,   586,   588,
     592,   597,   599,   602,   606,   611,   614,   616,   619,   623,
     626,   628,   630,   632,   634,   636,   638,   642,   647,   651,
     654,   658,   660,   663,   665,   667,   669,   672,   678,   686,
     692,   698,   706,   713,   721,   728,   736,   740,   743,   746,
     749,   753,   755,   758,   760,   762,   767,   771,   773
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     155,     0,    -1,     3,    -1,     4,    -1,     5,    -1,    66,
     110,    67,    -1,    91,    -1,    92,    68,   110,    69,    -1,
      92,    66,    67,    -1,    92,    66,    93,    67,    -1,    92,
      70,     3,    -1,    92,     7,     3,    -1,    92,     8,    -1,
      92,     9,    -1,    66,   138,    67,    71,   142,    72,    -1,
      66,   138,    67,    71,   142,    73,    72,    -1,   108,    -1,
      93,    73,   108,    -1,    92,    -1,     8,    94,    -1,     9,
      94,    -1,    95,    96,    -1,     6,    94,    -1,     6,    66,
     138,    67,    -1,    74,    -1,    75,    -1,    76,    -1,    77,
      -1,    78,    -1,    79,    -1,    94,    -1,    66,   138,    67,
      96,    -1,    96,    -1,    97,    75,    96,    -1,    97,    80,
      96,    -1,    97,    81,    96,    -1,    97,    -1,    98,    76,
      97,    -1,    98,    77,    97,    -1,    98,    -1,    99,    10,
      98,    -1,    99,    11,    98,    -1,    99,    -1,   100,    82,
      99,    -1,   100,    83,    99,    -1,   100,    12,    99,    -1,
     100,    13,    99,    -1,   100,    -1,   101,    14,   100,    -1,
     101,    15,   100,    -1,   101,    -1,   102,    74,   101,    -1,
     102,    -1,   103,    84,   102,    -1,   103,    -1,   104,    85,
     103,    -1,   104,    -1,   105,    16,   104,    -1,   105,    -1,
     106,    17,   105,    -1,   106,    -1,   106,    86,   110,    87,
     107,    -1,   107,    -1,    94,   109,   108,    -1,    88,    -1,
      18,    -1,    19,    -1,    20,    -1,    21,    -1,    22,    -1,
      23,    -1,    24,    -1,    25,    -1,    26,    -1,    27,    -1,
     108,    -1,   110,    73,   108,    -1,   107,    -1,   113,    89,
      -1,   113,   114,    89,    -1,   116,    -1,   116,   113,    -1,
     117,    -1,   117,   113,    -1,   128,    -1,   128,   113,    -1,
     129,    -1,   129,   113,    -1,   115,    -1,   114,    73,   115,
      -1,   130,    -1,   130,    88,   141,    -1,    29,    -1,    30,
      -1,    31,    -1,    32,    -1,    33,    -1,    46,    -1,    36,
      -1,    37,    -1,    38,    -1,    39,    -1,    42,    -1,    43,
      -1,    40,    -1,    41,    -1,    47,    -1,    48,    -1,    49,
      -1,   118,    -1,   125,    -1,    28,    -1,   119,     3,    71,
     120,    72,    -1,   119,    71,   120,    72,    -1,   119,     3,
      -1,    50,    -1,    51,    -1,   121,    -1,   120,   121,    -1,
     122,   123,    89,    -1,   117,   122,    -1,   117,    -1,   128,
     122,    -1,   128,    -1,   124,    -1,   123,    73,   124,    -1,
     130,    -1,    87,   111,    -1,   130,    87,   111,    -1,    52,
      71,   126,    72,    -1,    52,     3,    71,   126,    72,    -1,
      52,    71,   126,    73,    72,    -1,    52,     3,    71,   126,
      73,    72,    -1,    52,     3,    -1,   127,    -1,   126,    73,
     127,    -1,     3,    -1,     3,    88,   111,    -1,    44,    -1,
      35,    -1,    45,    -1,    34,    -1,   132,   131,    -1,   131,
      -1,     3,    -1,    66,   130,    67,    -1,   131,    68,   133,
     108,    69,    -1,   131,    68,   133,    69,    -1,   131,    68,
     108,    69,    -1,   131,    68,    31,   133,   108,    69,    -1,
     131,    68,   133,    31,   108,    69,    -1,   131,    68,   133,
      75,    69,    -1,   131,    68,    75,    69,    -1,   131,    68,
      69,    -1,   131,    66,   134,    67,    -1,   131,    66,   137,
      67,    -1,   131,    66,    67,    -1,    75,    -1,    75,   133,
      -1,    75,   132,    -1,    75,   133,   132,    -1,   128,    -1,
     133,   128,    -1,   135,    -1,   135,    73,    53,    -1,   136,
      -1,   135,    73,   136,    -1,   113,   130,    -1,   113,   139,
      -1,   113,    -1,     3,    -1,   137,    73,     3,    -1,   122,
      -1,   122,   139,    -1,   132,    -1,   140,    -1,   132,   140,
      -1,    66,   139,    67,    -1,    68,    69,    -1,    68,   108,
      69,    -1,   140,    68,    69,    -1,   140,    68,   108,    69,
      -1,    68,    75,    69,    -1,   140,    68,    75,    69,    -1,
      66,    67,    -1,    66,   134,    67,    -1,   140,    66,    67,
      -1,   140,    66,   134,    67,    -1,   108,    -1,    71,   142,
      72,    -1,    71,   142,    73,    72,    -1,   141,    -1,   143,
     141,    -1,   142,    73,   141,    -1,   142,    73,   143,   141,
      -1,   144,    88,    -1,   145,    -1,   144,   145,    -1,    68,
     111,    69,    -1,    70,     3,    -1,   147,    -1,   148,    -1,
     151,    -1,   152,    -1,   153,    -1,   154,    -1,     3,    87,
     146,    -1,    54,   111,    87,   146,    -1,    55,    87,   146,
      -1,    71,    72,    -1,    71,   149,    72,    -1,   150,    -1,
     149,   150,    -1,   112,    -1,   146,    -1,    89,    -1,   110,
      89,    -1,    56,    66,   110,    67,   146,    -1,    56,    66,
     110,    67,   146,    57,   146,    -1,    58,    66,   110,    67,
     146,    -1,    59,    66,   110,    67,   146,    -1,    60,   146,
      59,    66,   110,    67,    89,    -1,    61,    66,   151,   151,
      67,   146,    -1,    61,    66,   151,   151,   110,    67,   146,
      -1,    61,    66,   112,   151,    67,   146,    -1,    61,    66,
     112,   151,   110,    67,   146,    -1,    62,     3,    89,    -1,
      63,    89,    -1,    64,    89,    -1,    65,    89,    -1,    65,
     110,    89,    -1,   156,    -1,   155,   156,    -1,   157,    -1,
     112,    -1,   113,   130,   158,   148,    -1,   113,   130,   148,
      -1,   112,    -1,   158,   112,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    30,    30,    31,    32,    33,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    50,    51,    55,    56,
      57,    58,    59,    60,    64,    65,    66,    67,    68,    69,
      73,    74,    78,    79,    80,    81,    85,    86,    87,    91,
      92,    93,    97,    98,    99,   100,   101,   105,   106,   107,
     111,   112,   116,   117,   121,   122,   126,   127,   131,   132,
     136,   137,   141,   142,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   160,   161,   165,   169,   170,
     174,   175,   176,   177,   178,   179,   180,   181,   185,   186,
     190,   191,   195,   196,   197,   198,   199,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   221,   222,   223,   227,   228,   232,   233,   237,
     241,   242,   243,   244,   248,   249,   253,   254,   255,   259,
     260,   261,   262,   263,   267,   268,   272,   273,   277,   278,
     279,   283,   287,   288,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   309,   310,   311,
     312,   316,   317,   322,   323,   327,   328,   332,   333,   334,
     338,   339,   343,   344,   348,   349,   350,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   368,   369,
     370,   374,   375,   376,   377,   381,   385,   386,   390,   391,
     395,   396,   397,   398,   399,   400,   404,   405,   406,   410,
     411,   415,   416,   420,   421,   425,   426,   430,   431,   432,
     436,   437,   438,   439,   440,   441,   445,   446,   447,   448,
     449,   453,   454,   458,   459,   463,   464,   468,   469
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "INLINE",
  "RESTRICT", "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED",
  "FLOAT", "DOUBLE", "CONST", "VOLATILE", "VOID", "BOOL", "COMPLEX",
  "IMAGINARY", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE", "DEFAULT",
  "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO", "CONTINUE",
  "BREAK", "RETURN", "'('", "')'", "'['", "']'", "'.'", "'{'", "'}'",
  "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'",
  "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'", "$accept",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "function_specifier", "declarator",
  "direct_declarator", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "initializer_list",
  "designation", "designator_list", "designator", "statement",
  "labeled_statement", "compound_statement", "block_item_list",
  "block_item", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", "declaration_list", 0
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
     315,   316,   317,   318,   319,   320,    40,    41,    91,    93,
      46,   123,   125,    44,    38,    42,    43,    45,   126,    33,
      47,    37,    60,    62,    94,   124,    63,    58,    61,    59
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    90,    91,    91,    91,    91,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    93,    93,    94,    94,
      94,    94,    94,    94,    95,    95,    95,    95,    95,    95,
      96,    96,    97,    97,    97,    97,    98,    98,    98,    99,
      99,    99,   100,   100,   100,   100,   100,   101,   101,   101,
     102,   102,   103,   103,   104,   104,   105,   105,   106,   106,
     107,   107,   108,   108,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   110,   110,   111,   112,   112,
     113,   113,   113,   113,   113,   113,   113,   113,   114,   114,
     115,   115,   116,   116,   116,   116,   116,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   118,   118,   118,   119,   119,   120,   120,   121,
     122,   122,   122,   122,   123,   123,   124,   124,   124,   125,
     125,   125,   125,   125,   126,   126,   127,   127,   128,   128,
     128,   129,   130,   130,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   132,   132,   132,
     132,   133,   133,   134,   134,   135,   135,   136,   136,   136,
     137,   137,   138,   138,   139,   139,   139,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   141,   141,
     141,   142,   142,   142,   142,   143,   144,   144,   145,   145,
     146,   146,   146,   146,   146,   146,   147,   147,   147,   148,
     148,   149,   149,   150,   150,   151,   151,   152,   152,   152,
     153,   153,   153,   153,   153,   153,   154,   154,   154,   154,
     154,   155,   155,   156,   156,   157,   157,   158,   158
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     6,     7,     1,     3,     1,     2,
       2,     2,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     2,     3,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     4,     2,     1,     1,     1,     2,     3,
       2,     1,     2,     1,     1,     3,     1,     2,     3,     4,
       5,     5,     6,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     2,     1,     1,     3,     5,     4,     4,     6,
       6,     5,     4,     3,     4,     4,     3,     1,     2,     2,
       3,     1,     2,     1,     3,     1,     3,     2,     2,     1,
       1,     3,     1,     2,     1,     1,     2,     3,     2,     3,
       3,     4,     3,     4,     2,     3,     3,     4,     1,     3,
       4,     1,     2,     3,     4,     2,     1,     2,     3,     2,
       1,     1,     1,     1,     1,     1,     3,     4,     3,     2,
       3,     1,     2,     1,     1,     1,     2,     5,     7,     5,
       5,     7,     6,     7,     6,     7,     3,     2,     2,     2,
       3,     1,     2,     1,     1,     4,     3,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   111,    92,    93,    94,    95,    96,   141,   139,    98,
      99,   100,   101,   104,   105,   102,   103,   138,   140,    97,
     106,   107,   108,   115,   116,     0,   234,     0,    80,    82,
     109,     0,   110,    84,    86,     0,   231,   233,   133,     0,
     144,     0,   157,    78,     0,    88,    90,   143,     0,    81,
      83,   114,     0,    85,    87,     1,   232,     0,   136,     0,
     134,     0,   161,   159,   158,     0,    79,     0,     0,   237,
       0,   236,     0,     0,     0,   142,     0,   121,     0,   117,
       0,   123,     0,     0,   129,     0,   145,   162,   160,    89,
      90,     2,     3,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   209,
      24,    25,    26,    27,    28,    29,   215,     6,    18,    30,
       0,    32,    36,    39,    42,    47,    50,    52,    54,    56,
      58,    60,    62,    75,     0,   213,   214,   200,   201,     0,
     211,   202,   203,   204,   205,     2,     0,   188,    91,   238,
     235,   170,   156,   169,     0,   163,   165,     0,     0,   153,
      25,     0,     0,     0,   120,   113,   118,     0,     0,   124,
     126,   122,   130,     0,    30,    77,   137,   131,   135,     0,
       0,    22,     0,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,   227,   228,   229,     0,     0,   172,     0,
       0,    12,    13,     0,     0,     0,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    64,     0,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   216,
     210,   212,     0,     0,   191,     0,     0,     0,   196,     0,
       0,   167,   174,   168,   175,   154,     0,   155,     0,     0,
     152,   148,     0,   147,    25,     0,   112,   127,     0,   119,
       0,   132,   206,     0,     0,     0,   208,     0,     0,     0,
       0,     0,     0,   226,   230,     5,     0,   174,   173,     0,
      11,     8,     0,    16,     0,    10,    63,    33,    34,    35,
      37,    38,    40,    41,    45,    46,    43,    44,    48,    49,
      51,    53,    55,    57,    59,     0,    76,     0,   199,   189,
       0,   192,   195,   197,   184,     0,     0,   178,    25,     0,
     176,     0,     0,   164,   166,   171,     0,     0,   151,   146,
     125,   128,    23,     0,   207,     0,     0,     0,     0,     0,
       0,     0,    31,     9,     0,     7,     0,   198,   190,   193,
       0,   185,   177,   182,   179,   186,     0,   180,    25,     0,
     149,   150,   217,   219,   220,     0,     0,     0,     0,     0,
       0,    17,    61,   194,   187,   183,   181,     0,     0,   224,
       0,   222,     0,    14,     0,   218,   221,   225,   223,    15
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   117,   118,   292,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   217,
     134,   176,    26,    70,    44,    45,    28,    29,    30,    31,
      78,    79,    80,   168,   169,    32,    59,    60,    33,    34,
      61,    47,    48,    64,   325,   155,   156,   157,   199,   326,
     254,   244,   245,   246,   247,   248,   136,   137,   138,   139,
     140,   141,   142,   143,   144,    35,    36,    37,    72
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -294
static const yytype_int16 yypact[] =
{
    1484,  -294,  -294,  -294,  -294,  -294,  -294,  -294,  -294,  -294,
    -294,  -294,  -294,  -294,  -294,  -294,  -294,  -294,  -294,  -294,
    -294,  -294,  -294,  -294,  -294,    51,  -294,    27,  1484,  1484,
    -294,    61,  -294,  1484,  1484,   337,  -294,  -294,   -45,    33,
    -294,    59,    95,  -294,   -36,  -294,  1189,   153,    16,  -294,
    -294,    19,  1509,  -294,  -294,  -294,  -294,    33,   -42,   179,
    -294,    36,  -294,  -294,    95,    59,  -294,   394,   872,  -294,
      27,  -294,  1374,  1149,   712,   153,  1509,  1509,  1291,  -294,
      54,  1509,   228,  1015,  -294,     9,  -294,  -294,  -294,  -294,
     101,    20,  -294,  -294,  1022,  1029,  1029,  1015,    62,    94,
      97,   102,   598,   111,   195,   131,   159,    80,   662,  -294,
    -294,  -294,  -294,  -294,  -294,  -294,  -294,  -294,   177,   207,
    1015,  -294,   116,   229,   302,    55,   305,   166,   183,   178,
     255,     6,  -294,  -294,   -28,  -294,  -294,  -294,  -294,   471,
    -294,  -294,  -294,  -294,  -294,  -294,   794,  -294,  -294,  -294,
    -294,  -294,  -294,    49,   214,   219,  -294,    -8,   107,  -294,
     227,   234,   761,  1329,  -294,  -294,  -294,  1015,   -17,  -294,
     211,  -294,  -294,    47,  -294,  -294,  -294,  -294,  -294,   598,
     662,  -294,   662,  -294,  -294,   221,   598,  1015,  1015,  1015,
     270,   548,   241,  -294,  -294,  -294,    75,   109,    99,   271,
     336,  -294,  -294,   886,  1015,   339,  -294,  -294,  -294,  -294,
    -294,  -294,  -294,  -294,  -294,  -294,  -294,  1015,  -294,  1015,
    1015,  1015,  1015,  1015,  1015,  1015,  1015,  1015,  1015,  1015,
    1015,  1015,  1015,  1015,  1015,  1015,  1015,  1015,  1015,  -294,
    -294,  -294,  1015,   340,  -294,   249,   872,   105,  -294,  1099,
     903,  -294,    67,  -294,   200,  -294,  1458,  -294,   341,   839,
    -294,  -294,  1015,  -294,   276,   277,  -294,  -294,    54,  -294,
    1015,  -294,  -294,   280,   287,   598,  -294,   121,   151,   168,
     289,   274,   274,  -294,  -294,  -294,  1250,   223,  -294,   917,
    -294,  -294,   169,  -294,   -18,  -294,  -294,  -294,  -294,  -294,
     116,   116,   229,   229,   302,   302,   302,   302,    55,    55,
     305,   166,   183,   178,   255,    -7,  -294,   288,  -294,  -294,
     564,  -294,  -294,  -294,  -294,   291,   292,  -294,   293,   295,
     200,  1418,   931,  -294,  -294,  -294,   321,   323,  -294,  -294,
    -294,  -294,   285,   285,  -294,   598,   598,   598,  1015,   981,
    1008,   794,  -294,  -294,  1015,  -294,  1015,  -294,  -294,  -294,
     872,  -294,  -294,  -294,  -294,  -294,   294,  -294,   324,   325,
    -294,  -294,   303,  -294,  -294,   171,   598,   188,   598,   197,
     251,  -294,  -294,  -294,  -294,  -294,  -294,   598,   312,  -294,
     598,  -294,   598,  -294,   745,  -294,  -294,  -294,  -294,  -294
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -294,  -294,  -294,  -294,   -20,  -294,  -111,   103,   108,    89,
     104,   172,   173,   174,   170,   175,  -294,   -80,   -67,  -294,
     -76,   -89,   -25,     0,  -294,   342,  -294,   -37,  -294,  -294,
     333,   -58,   -59,  -294,   142,  -294,   355,   -74,   233,  -294,
     -22,   -35,   -26,   -64,   -69,  -294,   158,  -294,    57,  -129,
    -227,   -66,    65,  -293,  -294,   204,   -88,  -294,    72,  -294,
     278,  -185,  -294,  -294,  -294,  -294,   383,  -294,  -294
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      27,   147,   148,   175,   154,    46,   282,   161,   185,   218,
     162,   178,    58,    75,   190,    77,    63,   175,   164,    40,
     166,    69,   171,   236,   253,   330,    57,   360,    49,    50,
      40,   196,   197,    53,    54,    27,    58,    65,    88,    77,
      77,    77,   135,    90,    77,   238,    83,   149,    90,   198,
      58,   355,    40,    66,    38,   238,   268,    40,   170,   257,
     330,   239,    40,   174,    51,   258,   238,   226,   227,   288,
      40,    77,   269,   153,   181,   183,   184,   174,   267,   147,
     356,   177,    41,   145,    92,    93,    94,   175,    95,    96,
      76,   272,   237,    41,   259,   265,   349,   350,   276,   178,
     174,   360,    42,    86,   197,   166,   197,   179,   297,   298,
     299,   277,   278,   279,   135,   249,    43,   250,    71,   271,
      41,   198,    39,   198,    42,    41,    77,   252,   294,    42,
       8,   251,    52,   249,    42,   250,   293,   228,   229,    17,
      18,   167,     8,    77,   150,    77,   108,   174,   238,   186,
     296,    17,    18,   317,   110,   111,   112,   113,   114,   115,
     187,   315,   175,   188,   284,   286,   281,   250,   189,   195,
      42,   316,   287,   242,    42,   243,   285,   191,   352,   147,
     321,   341,   238,   329,   200,   201,   202,   344,   345,    68,
     175,   219,   336,   322,   238,   337,   220,   221,   192,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,    75,   346,    73,
     193,    74,   174,   252,   238,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   347,   353,   273,   388,   274,
     232,   238,   354,   203,   238,   204,   170,   205,   194,   153,
     174,    84,    85,   147,   359,   390,   153,   372,   373,   374,
     287,   238,   366,   234,   392,   369,   331,   233,   332,   174,
     238,   235,   375,   377,   379,    62,   382,   145,    92,    93,
      94,   255,    95,    96,   147,    81,   153,   381,   389,   286,
     391,   250,   256,   147,   383,   216,   260,    87,   270,   395,
     172,   173,   397,   261,   398,   222,   223,    62,   275,    81,
      81,    81,   224,   225,    81,   304,   305,   306,   307,   230,
     231,   319,   320,   393,   394,   300,   301,   147,   359,   280,
     283,   153,   302,   303,   308,   309,   174,    55,   289,   290,
     108,    81,   295,   318,   335,   338,   339,   342,   110,   111,
     112,   113,   114,   115,   343,   348,   351,   357,   361,   362,
     387,   384,   363,   116,   364,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     370,    62,   371,   385,   386,    87,    81,    91,    92,    93,
      94,   396,    95,    96,   310,   313,   311,    89,   312,   163,
     340,   314,    82,    81,   334,    81,   380,   241,    56,     0,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,    97,    98,
      99,   323,   100,   101,   102,   103,   104,   105,   106,   107,
     108,     0,     0,     0,     0,    67,   109,     0,   110,   111,
     112,   113,   114,   115,    91,    92,    93,    94,     0,    95,
      96,     0,     0,   116,     0,     0,     0,     0,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     0,     0,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    97,    98,    99,     0,   100,
     101,   102,   103,   104,   105,   106,   107,   108,     0,     0,
       0,     0,    67,   240,     0,   110,   111,   112,   113,   114,
     115,   145,    92,    93,    94,     0,    95,    96,     0,     0,
     116,     0,     0,     0,     0,     0,     0,   145,    92,    93,
      94,     0,    95,    96,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    91,    92,    93,    94,     0,    95,    96,     0,     0,
       0,     0,     0,     0,   108,     0,     0,     0,     0,     0,
       0,     0,   110,   111,   112,   113,   114,   115,     0,     0,
     108,     0,   242,     0,   243,   146,   358,   116,   110,   111,
     112,   113,   114,   115,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    98,    99,     0,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   145,    92,    93,    94,    67,
      95,    96,   110,   111,   112,   113,   114,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   116,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   145,    92,    93,    94,     0,
      95,    96,     0,     0,     0,     0,     0,     0,   108,     0,
       0,     0,     0,     0,     0,     0,   110,   111,   112,   113,
     114,   115,     0,   158,     0,     0,     0,     8,   145,    92,
      93,    94,     0,    95,    96,     0,    17,    18,     0,     0,
       0,     0,     0,     0,   145,    92,    93,    94,     0,    95,
      96,     0,     0,     0,     0,     0,     0,     0,   108,     0,
       0,   159,     0,     0,     0,     0,   110,   160,   112,   113,
     114,   115,   262,     0,     0,     0,     8,   145,    92,    93,
      94,     0,    95,    96,     0,    17,    18,     0,     0,     0,
       0,   108,     0,   242,     0,   243,   146,   399,     0,   110,
     111,   112,   113,   114,   115,     0,     0,   108,     0,     0,
     263,     0,     0,     0,     0,   110,   264,   112,   113,   114,
     115,     0,   145,    92,    93,    94,     0,    95,    96,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     108,     0,   242,     0,   243,   146,     0,     0,   110,   111,
     112,   113,   114,   115,     8,   145,    92,    93,    94,     0,
      95,    96,     0,    17,    18,     0,     0,     0,     0,   145,
      92,    93,    94,     0,    95,    96,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   108,   145,    92,    93,    94,
       0,    95,    96,   110,   111,   112,   113,   114,   115,     0,
     145,    92,    93,    94,     0,    95,    96,     0,     0,     0,
       0,     0,     0,     0,   145,    92,    93,    94,   108,    95,
      96,     0,     0,   146,     0,     0,   110,   111,   112,   113,
     114,   115,   108,   291,     0,     0,     0,     0,     0,     0,
     110,   111,   112,   113,   114,   115,     0,     0,     0,   108,
       0,     0,   327,     0,     0,     0,     0,   110,   328,   112,
     113,   114,   115,   108,   145,    92,    93,    94,   351,    95,
      96,   110,   111,   112,   113,   114,   115,   108,     0,     0,
     367,     0,     0,     0,     0,   110,   368,   112,   113,   114,
     115,   145,    92,    93,    94,     0,    95,    96,   145,    92,
      93,    94,     0,    95,    96,   145,    92,    93,    94,     0,
      95,    96,   145,    92,    93,    94,     0,    95,    96,     0,
       0,     0,     0,     0,     0,     0,     0,   108,   376,     0,
       0,     0,     0,     0,     0,   110,   111,   112,   113,   114,
     115,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   108,   378,     0,     0,     0,     0,
       0,   108,   110,   111,   112,   113,   114,   115,   180,   110,
     111,   112,   113,   114,   115,   182,   110,   111,   112,   113,
     114,   115,    40,   110,   111,   112,   113,   114,   115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   151,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   249,   324,   250,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   152,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    68,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   286,   324,   250,     1,
       0,     0,     0,     0,     0,    42,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     0,
       0,     0,     0,   165,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   266,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    67,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   365,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   333,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     1,     0,     0,
       0,     0,     0,     0,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25
};

static const yytype_int16 yycheck[] =
{
       0,    68,    68,    83,    73,    27,   191,    74,    97,   120,
      74,    85,     3,    48,   102,    52,    42,    97,    77,     3,
      78,    46,    81,    17,   153,   252,    71,   320,    28,    29,
       3,   107,   108,    33,    34,    35,     3,    73,    64,    76,
      77,    78,    67,    65,    81,    73,    88,    72,    70,   108,
       3,    69,     3,    89,     3,    73,    73,     3,    80,    67,
     287,    89,     3,    83,     3,    73,    73,    12,    13,   198,
       3,   108,    89,    73,    94,    95,    96,    97,   167,   146,
      87,    72,    66,     3,     4,     5,     6,   167,     8,     9,
      71,   179,    86,    66,   158,   162,   281,   282,   186,   173,
     120,   394,    75,    67,   180,   163,   182,    87,   219,   220,
     221,   187,   188,   189,   139,    66,    89,    68,    46,    72,
      66,   180,    71,   182,    75,    66,   163,   153,   204,    75,
      35,   153,    71,    66,    75,    68,   203,    82,    83,    44,
      45,    87,    35,   180,    72,   182,    66,   167,    73,    87,
     217,    44,    45,   242,    74,    75,    76,    77,    78,    79,
      66,   237,   242,    66,    89,    66,   191,    68,    66,    89,
      75,   238,   198,    68,    75,    70,    67,    66,   289,   246,
     246,   270,    73,   250,     7,     8,     9,   275,    67,    88,
     270,    75,   259,    88,    73,   262,    80,    81,     3,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   252,    67,    66,
      89,    68,   242,   249,    73,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    67,    67,   180,    67,   182,
      74,    73,    73,    66,    73,    68,   268,    70,    89,   249,
     270,    72,    73,   320,   320,    67,   256,   345,   346,   347,
     286,    73,   331,    85,    67,   332,    66,    84,    68,   289,
      73,    16,   348,   349,   350,    42,   356,     3,     4,     5,
       6,    67,     8,     9,   351,    52,   286,   354,   376,    66,
     378,    68,    73,   360,   360,    88,    69,    64,    87,   387,
      72,    73,   390,    69,   392,    76,    77,    74,    87,    76,
      77,    78,    10,    11,    81,   226,   227,   228,   229,    14,
      15,    72,    73,    72,    73,   222,   223,   394,   394,    59,
      89,   331,   224,   225,   230,   231,   356,     0,    67,     3,
      66,   108,     3,     3,     3,    69,    69,    67,    74,    75,
      76,    77,    78,    79,    67,    66,    71,    69,    67,    67,
      57,    67,    69,    89,    69,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      69,   158,    69,    69,    69,   162,   163,     3,     4,     5,
       6,    89,     8,     9,   232,   235,   233,    65,   234,    76,
     268,   236,    57,   180,   256,   182,   351,   139,    35,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    55,
      56,   247,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    -1,    -1,    -1,    71,    72,    -1,    74,    75,
      76,    77,    78,    79,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    71,    72,    -1,    74,    75,    76,    77,    78,
      79,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      89,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    75,    76,    77,    78,    79,    -1,    -1,
      66,    -1,    68,    -1,    70,    71,    72,    89,    74,    75,
      76,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    55,    56,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,     3,     4,     5,     6,    71,
       8,     9,    74,    75,    76,    77,    78,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    76,    77,
      78,    79,    -1,    31,    -1,    -1,    -1,    35,     3,     4,
       5,     6,    -1,     8,     9,    -1,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,
      -1,    69,    -1,    -1,    -1,    -1,    74,    75,    76,    77,
      78,    79,    31,    -1,    -1,    -1,    35,     3,     4,     5,
       6,    -1,     8,     9,    -1,    44,    45,    -1,    -1,    -1,
      -1,    66,    -1,    68,    -1,    70,    71,    72,    -1,    74,
      75,    76,    77,    78,    79,    -1,    -1,    66,    -1,    -1,
      69,    -1,    -1,    -1,    -1,    74,    75,    76,    77,    78,
      79,    -1,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    -1,    68,    -1,    70,    71,    -1,    -1,    74,    75,
      76,    77,    78,    79,    35,     3,     4,     5,     6,    -1,
       8,     9,    -1,    44,    45,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,     3,     4,     5,     6,
      -1,     8,     9,    74,    75,    76,    77,    78,    79,    -1,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    66,     8,
       9,    -1,    -1,    71,    -1,    -1,    74,    75,    76,    77,
      78,    79,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    75,    76,    77,    78,    79,    -1,    -1,    -1,    66,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    74,    75,    76,
      77,    78,    79,    66,     3,     4,     5,     6,    71,     8,
       9,    74,    75,    76,    77,    78,    79,    66,    -1,    -1,
      69,    -1,    -1,    -1,    -1,    74,    75,    76,    77,    78,
      79,     3,     4,     5,     6,    -1,     8,     9,     3,     4,
       5,     6,    -1,     8,     9,     3,     4,     5,     6,    -1,
       8,     9,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    75,    76,    77,    78,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    66,    74,    75,    76,    77,    78,    79,    66,    74,
      75,    76,    77,    78,    79,    66,    74,    75,    76,    77,
      78,    79,     3,    74,    75,    76,    77,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,    28,
      -1,    -1,    -1,    -1,    -1,    75,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    -1,    -1,    72,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,   112,   113,   116,   117,
     118,   119,   125,   128,   129,   155,   156,   157,     3,    71,
       3,    66,    75,    89,   114,   115,   130,   131,   132,   113,
     113,     3,    71,   113,   113,     0,   156,    71,     3,   126,
     127,   130,   128,   132,   133,    73,    89,    71,    88,   112,
     113,   148,   158,    66,    68,   131,    71,   117,   120,   121,
     122,   128,   126,    88,    72,    73,    67,   128,   132,   115,
     130,     3,     4,     5,     6,     8,     9,    54,    55,    56,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    72,
      74,    75,    76,    77,    78,    79,    89,    91,    92,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   110,   112,   146,   147,   148,   149,
     150,   151,   152,   153,   154,     3,    71,   108,   141,   112,
     148,     3,    67,   113,   134,   135,   136,   137,    31,    69,
      75,   108,   133,   120,   122,    72,   121,    87,   123,   124,
     130,   122,    72,    73,    94,   107,   111,    72,   127,    87,
      66,    94,    66,    94,    94,   111,    87,    66,    66,    66,
     146,    66,     3,    89,    89,    89,   110,   110,   122,   138,
       7,     8,     9,    66,    68,    70,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    88,   109,    96,    75,
      80,    81,    76,    77,    10,    11,    12,    13,    82,    83,
      14,    15,    74,    84,    85,    16,    17,    86,    73,    89,
      72,   150,    68,    70,   141,   142,   143,   144,   145,    66,
      68,   130,   132,   139,   140,    67,    73,    67,    73,   133,
      69,    69,    31,    69,    75,   108,    72,   111,    73,    89,
      87,    72,   146,   138,   138,    87,   146,   110,   110,   110,
      59,   112,   151,    89,    89,    67,    66,   132,   139,    67,
       3,    67,    93,   108,   110,     3,   108,    96,    96,    96,
      97,    97,    98,    98,    99,    99,    99,    99,   100,   100,
     101,   102,   103,   104,   105,   110,   108,   111,     3,    72,
      73,   141,    88,   145,    67,   134,   139,    69,    75,   108,
     140,    66,    68,    53,   136,     3,   108,   108,    69,    69,
     124,   111,    67,    67,   146,    67,    67,    67,    66,   151,
     151,    71,    96,    67,    73,    69,    87,    69,    72,   141,
     143,    67,    67,    69,    69,    67,   134,    69,    75,   108,
      69,    69,   146,   146,   146,   110,    67,   110,    67,   110,
     142,   108,   107,   141,    67,    69,    69,    57,    67,   146,
      67,   146,    67,    72,    73,   146,    89,   146,   146,    72
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
      yyerror (fp, YY_("syntax error: cannot back up")); \
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
		  Type, Value, fp); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, FILE* fp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, fp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    FILE* fp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (fp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, FILE* fp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, fp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    FILE* fp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, fp);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, FILE* fp)
#else
static void
yy_reduce_print (yyvsp, yyrule, fp)
    YYSTYPE *yyvsp;
    int yyrule;
    FILE* fp;
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
		       		       , fp);
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, fp); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, FILE* fp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, fp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    FILE* fp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (fp);

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
int yyparse (FILE* fp);
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
yyparse (FILE* fp)
#else
int
yyparse (fp)
    FILE* fp;
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
#line 30 "c99.y"
    {printf("IDENTIFIER!!!\n");;}
    break;

  case 3:
#line 31 "c99.y"
    {printf("CONSTANT!!!\n");;}
    break;


/* Line 1267 of yacc.c.  */
#line 2098 "c99.tab.c"
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
      yyerror (fp, YY_("syntax error"));
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
	    yyerror (fp, yymsg);
	  }
	else
	  {
	    yyerror (fp, YY_("syntax error"));
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
		      yytoken, &yylval, fp);
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
		  yystos[yystate], yyvsp, fp);
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
  yyerror (fp, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, fp);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, fp);
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


#line 472 "c99.y"

//#include <stdio.h>

extern char yytext[];
extern int column;

void yyerror(FILE* fp, char const *s)
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}

/*int main(){
    FILE* fp = fopen("file.txt", "r");
    yyin = fp;
    yyparse(fp);
    fclose(fp);
}*/
