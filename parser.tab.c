
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void yyerror(const char* msg);
int yylex(void);

// External file pointer from flex
extern FILE* yyin;
extern int yylineno;

// Token list structure
typedef struct TokenNode {
    char* token;
    char* type;
    struct TokenNode* next;
} TokenNode;

extern TokenNode* token_list;

typedef struct Symbol {
    char* name;
    int value;
    struct Symbol* next;
} Symbol;

Symbol* symbol_table = NULL;

Symbol* find_symbol(char* name) {
    Symbol* s = symbol_table;
    while (s) {
        if (strcmp(s->name, name) == 0) return s;
        s = s->next;
    }
    return NULL;
}

void add_symbol(char* name) {
    if (find_symbol(name)) {
        yyerror("Variable redeclared");
        return;
    }
    Symbol* s = malloc(sizeof(Symbol));
    s->name = strdup(name);
    s->value = 0;
    s->next = symbol_table;
    symbol_table = s;
}

void yyerror(const char* msg) {
    fprintf(stderr, "Syntax Error at line %d: %s\n", yylineno, msg);
}



/* Line 189 of yacc.c  */
#line 131 "parser.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     MYTYPE = 258,
     SHOW = 259,
     INT = 260,
     CHAR = 261,
     FLOAT = 262,
     DOUBLE = 263,
     VOID = 264,
     MAIN = 265,
     IF = 266,
     ELSE = 267,
     WHILE = 268,
     FOR = 269,
     RETURN = 270,
     PRINTF = 271,
     SCANF = 272,
     INCLUDE = 273,
     ID = 274,
     STRING = 275,
     HEADER_FILE = 276,
     NUMBER = 277,
     EQ = 278,
     NEQ = 279,
     LT = 280,
     GT = 281,
     LTE = 282,
     GTE = 283,
     INC = 284,
     DEC = 285
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 58 "parser.y"

    int num;
    char* str;



/* Line 214 of yacc.c  */
#line 204 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 216 "parser.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   488

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNRULES -- Number of states.  */
#define YYNSTATES  165

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    38,     2,     2,
      28,    29,    26,    24,    33,    25,     2,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    30,
      34,    23,    35,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    36,     2,    37,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,    32,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    39,    40,
      41,    42,    43,    44,    45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    14,    17,    24,
      31,    32,    34,    36,    40,    43,    45,    47,    49,    51,
      53,    55,    59,    60,    63,    66,    69,    72,    75,    78,
      80,    83,    85,    87,    89,    95,   103,   112,   121,   131,
     141,   147,   150,   152,   156,   158,   162,   166,   171,   176,
     183,   190,   191,   193,   195,   197,   201,   205,   208,   210,
     215,   217,   219,   223,   227,   231,   235,   239,   243,   247,
     251,   255,   259,   263,   267,   270,   273,   276
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    -1,    48,    49,    -1,    50,    -1,    51,
      -1,    62,    30,    -1,    18,    21,    -1,    55,    19,    28,
      52,    29,    56,    -1,     5,    10,    28,    52,    29,    56,
      -1,    -1,    53,    -1,    54,    -1,    53,    33,    54,    -1,
      55,    19,    -1,     5,    -1,     6,    -1,     7,    -1,     8,
      -1,     9,    -1,     3,    -1,    31,    57,    32,    -1,    -1,
      57,    58,    -1,    62,    30,    -1,    65,    30,    -1,    66,
      30,    -1,    69,    30,    -1,    71,    30,    -1,    56,    -1,
      70,    30,    -1,    59,    -1,    60,    -1,    61,    -1,    11,
      28,    71,    29,    58,    -1,    11,    28,    71,    29,    58,
      12,    58,    -1,    14,    28,    62,    71,    30,    71,    29,
      58,    -1,    14,    28,    65,    71,    30,    71,    29,    58,
      -1,    14,    28,    62,    30,    71,    30,    71,    29,    58,
      -1,    14,    28,    65,    30,    71,    30,    71,    29,    58,
      -1,    13,    28,    71,    29,    58,    -1,    55,    63,    -1,
      64,    -1,    63,    33,    64,    -1,    19,    -1,    19,    23,
      71,    -1,    19,    23,    71,    -1,    19,    28,    67,    29,
      -1,    16,    28,    20,    29,    -1,    16,    28,    20,    33,
      67,    29,    -1,    17,    28,    20,    33,    67,    29,    -1,
      -1,    68,    -1,    71,    -1,    20,    -1,    68,    33,    71,
      -1,    68,    33,    20,    -1,    15,    71,    -1,    15,    -1,
       4,    28,    19,    29,    -1,    22,    -1,    19,    -1,    28,
      71,    29,    -1,    71,    24,    71,    -1,    71,    25,    71,
      -1,    71,    26,    71,    -1,    71,    27,    71,    -1,    71,
      38,    71,    -1,    71,    39,    71,    -1,    71,    40,    71,
      -1,    71,    34,    71,    -1,    71,    35,    71,    -1,    71,
      43,    71,    -1,    71,    44,    71,    -1,    19,    45,    -1,
      19,    46,    -1,    45,    19,    -1,    46,    19,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    83,    83,    85,    89,    90,    91,    95,   102,   107,
     112,   114,   118,   119,   123,   132,   133,   134,   135,   136,
     137,   141,   144,   146,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   163,   166,   173,   176,   179,   182,
     189,   195,   201,   202,   206,   211,   223,   236,   240,   244,
     248,   254,   256,   260,   261,   265,   266,   273,   276,   282,
     291,   292,   298,   299,   300,   301,   302,   310,   318,   319,
     320,   321,   322,   323,   324,   335,   346,   358
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MYTYPE", "SHOW", "INT", "CHAR", "FLOAT",
  "DOUBLE", "VOID", "MAIN", "IF", "ELSE", "WHILE", "FOR", "RETURN",
  "PRINTF", "SCANF", "INCLUDE", "ID", "STRING", "HEADER_FILE", "NUMBER",
  "'='", "'+'", "'-'", "'*'", "'/'", "'('", "')'", "';'", "'{'", "'}'",
  "','", "'<'", "'>'", "'['", "']'", "'%'", "EQ", "NEQ", "LT", "GT", "LTE",
  "GTE", "INC", "DEC", "$accept", "program", "external_declaration",
  "include_directive", "function_definition", "parameter_list",
  "parameters", "parameter", "type", "compound_statement",
  "statement_list", "statement", "if_statement", "for_statement",
  "while_statement", "declaration", "declaration_list", "declarator",
  "assignment", "function_call", "argument_list", "arguments",
  "return_statement", "show_stmt", "expression", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,    61,    43,    45,    42,    47,    40,    41,
      59,   123,   125,    44,    60,    62,    91,    93,    37,   278,
     279,   280,   281,   282,   283,   284,   285
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    48,    49,    49,    49,    50,    51,    51,
      52,    52,    53,    53,    54,    55,    55,    55,    55,    55,
      55,    56,    57,    57,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    59,    59,    60,    60,    60,    60,
      61,    62,    63,    63,    64,    64,    65,    66,    66,    66,
      66,    67,    67,    68,    68,    68,    68,    69,    69,    70,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     2,     2,     6,     6,
       0,     1,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     3,     0,     2,     2,     2,     2,     2,     2,     1,
       2,     1,     1,     1,     5,     7,     8,     8,     9,     9,
       5,     2,     1,     3,     1,     3,     3,     4,     4,     6,
       6,     0,     1,     1,     1,     3,     3,     2,     1,     4,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    20,    15,    16,    17,    18,    19,     0,
       3,     4,     5,     0,     0,     0,     7,    44,    41,    42,
       6,    10,     0,    10,     0,    15,     0,    11,    12,     0,
      61,    60,     0,     0,     0,    45,     0,    44,    43,     0,
       0,    14,    74,    75,     0,    76,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
       9,    13,    62,    63,    64,    65,    66,    70,    71,    67,
      68,    69,    72,    73,     8,     0,     0,     0,     0,     0,
      58,     0,     0,    61,    21,     0,    29,    23,    31,    32,
      33,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    57,     0,     0,     0,    51,    24,    25,    26,    27,
      30,    28,     0,     0,     0,     0,     0,     0,     0,     0,
      46,    54,     0,    52,    53,    59,     0,     0,     0,     0,
       0,     0,    48,    51,    51,    47,     0,    34,    40,     0,
       0,     0,     0,     0,     0,    56,    55,     0,     0,     0,
       0,     0,    49,    50,    35,     0,     0,     0,     0,     0,
      36,     0,    37,    38,    39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    10,    11,    12,    26,    27,    28,    85,    86,
      75,    87,    88,    89,    90,    91,    18,    19,    92,    93,
     122,   123,    94,    95,    96
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -75
static const yytype_int16 yypact[] =
{
     -75,     6,   -75,   -75,    -5,   -75,   -75,   -75,   -75,    -3,
     -75,   -75,   -75,    34,    38,    41,   -75,    -6,    37,   -75,
     -75,   479,    35,   479,    52,   -75,    43,    42,   -75,    65,
     -42,   -75,    35,    66,    74,   416,    68,    80,   -75,    73,
     479,   -75,   -75,   -75,   164,   -75,   -75,    35,    35,    35,
      35,    35,    35,    35,    35,    35,    35,    35,    73,   -75,
     -75,   -75,   -75,   -19,   -19,   -75,   -75,    98,    98,   -75,
     437,   437,    98,    98,   -75,    33,    77,    79,    81,    82,
      35,    85,    87,    28,   -75,    52,   -75,   -75,   -75,   -75,
     -75,    86,    89,    91,    97,   108,   185,   125,    35,    35,
      83,   416,   127,   131,    35,   130,   -75,   -75,   -75,   -75,
     -75,   -75,    88,   206,   227,   123,   134,   155,   -13,   122,
     416,   -75,   136,   133,   416,   -75,   126,   126,    35,   248,
      35,   269,   -75,   130,   130,   -75,   141,   147,   -75,   290,
      35,   311,    35,   138,   139,   -75,   416,   126,    35,   332,
      35,   353,   -75,   -75,   -75,   374,   126,   395,   126,   126,
     -75,   126,   -75,   -75,   -75
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -75,   -75,   -75,   -75,   -75,   150,   -75,   142,    22,   -37,
     -75,   -60,   -75,   -75,   -75,     0,   -75,   146,    78,   -75,
     -74,   -75,   -75,   -75,   -22
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      35,    14,    60,    42,    43,    15,     2,    49,    50,     3,
      44,     4,     5,     6,     7,     8,   132,    22,    16,    53,
     133,    74,    23,    13,     9,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,     3,    76,    25,     5,
       6,     7,     8,    29,    77,    29,    78,    79,    80,    81,
      82,   104,    83,    17,    30,    31,   105,    31,   101,   143,
     144,    32,    29,    32,    59,    84,   137,   138,    20,    21,
      24,    37,    39,    42,    43,    40,   113,   114,    33,    34,
      33,    34,   120,   124,    41,    45,     3,   154,    25,     5,
       6,     7,     8,    46,   129,   131,   160,    58,   162,   163,
     116,   164,   115,    22,    59,    97,   139,    98,   141,    99,
     100,   124,   124,   102,   146,   103,   106,   125,   149,   107,
     151,   108,    47,    48,    49,    50,   155,   109,   157,     3,
      76,    25,     5,     6,     7,     8,    53,    77,   110,    78,
      79,    80,    81,    82,   112,    83,   104,   118,    31,    30,
     121,   119,    31,    30,    32,   134,    31,    59,    32,   147,
      30,   145,    32,    31,   128,   135,   136,   152,   153,    32,
      38,    33,    34,    36,    30,    33,    34,    31,   117,    33,
      34,     0,    61,    32,     0,   130,    33,    34,    47,    48,
      49,    50,     0,    62,     0,     0,     0,     0,    51,    52,
      33,    34,    53,    54,    55,     0,     0,    56,    57,    47,
      48,    49,    50,     0,     0,   111,     0,     0,     0,    51,
      52,     0,     0,    53,    54,    55,     0,     0,    56,    57,
      47,    48,    49,    50,     0,   126,     0,     0,     0,     0,
      51,    52,     0,     0,    53,    54,    55,     0,     0,    56,
      57,    47,    48,    49,    50,     0,   127,     0,     0,     0,
       0,    51,    52,     0,     0,    53,    54,    55,     0,     0,
      56,    57,    47,    48,    49,    50,     0,     0,   140,     0,
       0,     0,    51,    52,     0,     0,    53,    54,    55,     0,
       0,    56,    57,    47,    48,    49,    50,     0,     0,   142,
       0,     0,     0,    51,    52,     0,     0,    53,    54,    55,
       0,     0,    56,    57,    47,    48,    49,    50,     0,     0,
     148,     0,     0,     0,    51,    52,     0,     0,    53,    54,
      55,     0,     0,    56,    57,    47,    48,    49,    50,     0,
       0,   150,     0,     0,     0,    51,    52,     0,     0,    53,
      54,    55,     0,     0,    56,    57,    47,    48,    49,    50,
       0,   156,     0,     0,     0,     0,    51,    52,     0,     0,
      53,    54,    55,     0,     0,    56,    57,    47,    48,    49,
      50,     0,   158,     0,     0,     0,     0,    51,    52,     0,
       0,    53,    54,    55,     0,     0,    56,    57,    47,    48,
      49,    50,     0,   159,     0,     0,     0,     0,    51,    52,
       0,     0,    53,    54,    55,     0,     0,    56,    57,    47,
      48,    49,    50,     0,   161,     0,     0,     0,     0,    51,
      52,     0,     0,    53,    54,    55,     0,     0,    56,    57,
      47,    48,    49,    50,     0,     0,     0,     0,     0,     0,
      51,    52,     0,     0,    53,    54,    55,     0,     0,    56,
      57,    47,    48,    49,    50,     0,     0,     0,     0,     0,
       0,    51,    52,     0,     0,    53,     0,     0,     0,     0,
      56,    57,     3,     0,    25,     5,     6,     7,     8
};

static const yytype_int16 yycheck[] =
{
      22,     1,    39,    45,    46,    10,     0,    26,    27,     3,
      32,     5,     6,     7,     8,     9,    29,    23,    21,    38,
      33,    58,    28,     1,    18,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,     3,     4,     5,     6,
       7,     8,     9,    21,    11,    23,    13,    14,    15,    16,
      17,    23,    19,    19,    19,    22,    28,    22,    80,   133,
     134,    28,    40,    28,    31,    32,   126,   127,    30,    28,
      33,    19,    29,    45,    46,    33,    98,    99,    45,    46,
      45,    46,   104,   105,    19,    19,     3,   147,     5,     6,
       7,     8,     9,    19,   116,   117,   156,    29,   158,   159,
     100,   161,    19,    23,    31,    28,   128,    28,   130,    28,
      28,   133,   134,    28,   136,    28,    30,    29,   140,    30,
     142,    30,    24,    25,    26,    27,   148,    30,   150,     3,
       4,     5,     6,     7,     8,     9,    38,    11,    30,    13,
      14,    15,    16,    17,    19,    19,    23,    20,    22,    19,
      20,    20,    22,    19,    28,    33,    22,    31,    28,    12,
      19,    20,    28,    22,    30,    29,    33,    29,    29,    28,
      24,    45,    46,    23,    19,    45,    46,    22,   100,    45,
      46,    -1,    40,    28,    -1,    30,    45,    46,    24,    25,
      26,    27,    -1,    29,    -1,    -1,    -1,    -1,    34,    35,
      45,    46,    38,    39,    40,    -1,    -1,    43,    44,    24,
      25,    26,    27,    -1,    -1,    30,    -1,    -1,    -1,    34,
      35,    -1,    -1,    38,    39,    40,    -1,    -1,    43,    44,
      24,    25,    26,    27,    -1,    29,    -1,    -1,    -1,    -1,
      34,    35,    -1,    -1,    38,    39,    40,    -1,    -1,    43,
      44,    24,    25,    26,    27,    -1,    29,    -1,    -1,    -1,
      -1,    34,    35,    -1,    -1,    38,    39,    40,    -1,    -1,
      43,    44,    24,    25,    26,    27,    -1,    -1,    30,    -1,
      -1,    -1,    34,    35,    -1,    -1,    38,    39,    40,    -1,
      -1,    43,    44,    24,    25,    26,    27,    -1,    -1,    30,
      -1,    -1,    -1,    34,    35,    -1,    -1,    38,    39,    40,
      -1,    -1,    43,    44,    24,    25,    26,    27,    -1,    -1,
      30,    -1,    -1,    -1,    34,    35,    -1,    -1,    38,    39,
      40,    -1,    -1,    43,    44,    24,    25,    26,    27,    -1,
      -1,    30,    -1,    -1,    -1,    34,    35,    -1,    -1,    38,
      39,    40,    -1,    -1,    43,    44,    24,    25,    26,    27,
      -1,    29,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,
      38,    39,    40,    -1,    -1,    43,    44,    24,    25,    26,
      27,    -1,    29,    -1,    -1,    -1,    -1,    34,    35,    -1,
      -1,    38,    39,    40,    -1,    -1,    43,    44,    24,    25,
      26,    27,    -1,    29,    -1,    -1,    -1,    -1,    34,    35,
      -1,    -1,    38,    39,    40,    -1,    -1,    43,    44,    24,
      25,    26,    27,    -1,    29,    -1,    -1,    -1,    -1,    34,
      35,    -1,    -1,    38,    39,    40,    -1,    -1,    43,    44,
      24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    -1,    38,    39,    40,    -1,    -1,    43,
      44,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      43,    44,     3,    -1,     5,     6,     7,     8,     9
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    48,     0,     3,     5,     6,     7,     8,     9,    18,
      49,    50,    51,    55,    62,    10,    21,    19,    63,    64,
      30,    28,    23,    28,    33,     5,    52,    53,    54,    55,
      19,    22,    28,    45,    46,    71,    52,    19,    64,    29,
      33,    19,    45,    46,    71,    19,    19,    24,    25,    26,
      27,    34,    35,    38,    39,    40,    43,    44,    29,    31,
      56,    54,    29,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    56,    57,     4,    11,    13,    14,
      15,    16,    17,    19,    32,    55,    56,    58,    59,    60,
      61,    62,    65,    66,    69,    70,    71,    28,    28,    28,
      28,    71,    28,    28,    23,    28,    30,    30,    30,    30,
      30,    30,    19,    71,    71,    19,    62,    65,    20,    20,
      71,    20,    67,    68,    71,    29,    29,    29,    30,    71,
      30,    71,    29,    33,    33,    29,    33,    58,    58,    71,
      30,    71,    30,    67,    67,    20,    71,    12,    30,    71,
      30,    71,    29,    29,    58,    71,    29,    71,    29,    29,
      58,    29,    58,    58,    58
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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
        case 7:

/* Line 1455 of yacc.c  */
#line 95 "parser.y"
    {
        printf("Processed include directive: %s\n", (yyvsp[(2) - (2)].str));
        free((yyvsp[(2) - (2)].str));
    ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 102 "parser.y"
    {
        printf("Defined function: %s\n", (yyvsp[(2) - (6)].str));
        free((yyvsp[(1) - (6)].str));
        free((yyvsp[(2) - (6)].str));
    ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 107 "parser.y"
    {
        printf("Defined main function\n");
    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 123 "parser.y"
    {
        add_symbol((yyvsp[(2) - (2)].str));
        printf("Parameter: %s\n", (yyvsp[(2) - (2)].str));
        free((yyvsp[(1) - (2)].str));
        free((yyvsp[(2) - (2)].str));
    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 132 "parser.y"
    { (yyval.str) = strdup("int"); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 133 "parser.y"
    { (yyval.str) = strdup("char"); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 134 "parser.y"
    { (yyval.str) = strdup("float"); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 135 "parser.y"
    { (yyval.str) = strdup("double"); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 136 "parser.y"
    { (yyval.str) = strdup("void"); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 137 "parser.y"
    { (yyval.str) = strdup("mytype"); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 153 "parser.y"
    { printf("Expression result: %d\n", (yyvsp[(1) - (2)].num)); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 163 "parser.y"
    {
        printf("Processed if statement\n");
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 166 "parser.y"
    {
        printf("Processed if-else statement\n");
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 173 "parser.y"
    {
        printf("Processed for loop\n");
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 176 "parser.y"
    {
        printf("Processed for loop\n");
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 179 "parser.y"
    {
        printf("Processed for loop with three parts\n");
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 182 "parser.y"
    {
        printf("Processed for loop with three parts\n");
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 189 "parser.y"
    {
        printf("Processed while loop\n");
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 195 "parser.y"
    {
        free((yyvsp[(1) - (2)].str));
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 206 "parser.y"
    {
        add_symbol((yyvsp[(1) - (1)].str));
        printf("Declared variable: %s\n", (yyvsp[(1) - (1)].str));
        free((yyvsp[(1) - (1)].str));
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 211 "parser.y"
    {
        add_symbol((yyvsp[(1) - (3)].str));
        Symbol* s = find_symbol((yyvsp[(1) - (3)].str));
        if (s) {
            s->value = (yyvsp[(3) - (3)].num);
            printf("Declared and initialized variable: %s with value %d\n", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].num));
        }
        free((yyvsp[(1) - (3)].str));
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 223 "parser.y"
    {
        Symbol* s = find_symbol((yyvsp[(1) - (3)].str));
        if (s) {
            s->value = (yyvsp[(3) - (3)].num);
            printf("Assigned %d to variable %s\n", (yyvsp[(3) - (3)].num), (yyvsp[(1) - (3)].str));
        } else {
            yyerror("Undeclared variable");
        }
        free((yyvsp[(1) - (3)].str));
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 236 "parser.y"
    {
        printf("Function call: %s\n", (yyvsp[(1) - (4)].str));
        free((yyvsp[(1) - (4)].str));
    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 240 "parser.y"
    {
        printf("Printf statement with format: %s\n", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 244 "parser.y"
    {
        printf("Printf statement with format: %s\n", (yyvsp[(3) - (6)].str));
        free((yyvsp[(3) - (6)].str));
    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 248 "parser.y"
    {
        printf("Scanf statement with format: %s\n", (yyvsp[(3) - (6)].str));
        free((yyvsp[(3) - (6)].str));
    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 261 "parser.y"
    {
        printf("String argument: %s\n", (yyvsp[(1) - (1)].str));
        free((yyvsp[(1) - (1)].str));
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 266 "parser.y"
    {
        printf("String argument: %s\n", (yyvsp[(3) - (3)].str));
        free((yyvsp[(3) - (3)].str));
    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 273 "parser.y"
    {
        printf("Return statement with value: %d\n", (yyvsp[(2) - (2)].num));
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 276 "parser.y"
    {
        printf("Return statement with no value\n");
    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 282 "parser.y"
    {
        Symbol* s = find_symbol((yyvsp[(3) - (4)].str));
        if (s) printf("Displaying value of %s: %d\n", (yyvsp[(3) - (4)].str), s->value);
        else yyerror("Undeclared variable");
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 291 "parser.y"
    { (yyval.num) = (yyvsp[(1) - (1)].num); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 292 "parser.y"
    {
        Symbol* s = find_symbol((yyvsp[(1) - (1)].str));
        if (s) (yyval.num) = s->value;
        else { yyerror("Undeclared variable"); (yyval.num) = 0; }
        free((yyvsp[(1) - (1)].str));
      ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 298 "parser.y"
    { (yyval.num) = (yyvsp[(2) - (3)].num); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 299 "parser.y"
    { (yyval.num) = (yyvsp[(1) - (3)].num) + (yyvsp[(3) - (3)].num); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 300 "parser.y"
    { (yyval.num) = (yyvsp[(1) - (3)].num) - (yyvsp[(3) - (3)].num); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 301 "parser.y"
    { (yyval.num) = (yyvsp[(1) - (3)].num) * (yyvsp[(3) - (3)].num); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 302 "parser.y"
    { 
        if ((yyvsp[(3) - (3)].num) == 0) {
            yyerror("Division by zero");
            (yyval.num) = 0;
        } else {
            (yyval.num) = (yyvsp[(1) - (3)].num) / (yyvsp[(3) - (3)].num); 
        }
    ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 310 "parser.y"
    {
        if ((yyvsp[(3) - (3)].num) == 0) {
            yyerror("Modulo by zero");
            (yyval.num) = 0;
        } else {
            (yyval.num) = (yyvsp[(1) - (3)].num) % (yyvsp[(3) - (3)].num);
        }
    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 318 "parser.y"
    { (yyval.num) = ((yyvsp[(1) - (3)].num) == (yyvsp[(3) - (3)].num)); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 319 "parser.y"
    { (yyval.num) = ((yyvsp[(1) - (3)].num) != (yyvsp[(3) - (3)].num)); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 320 "parser.y"
    { (yyval.num) = ((yyvsp[(1) - (3)].num) < (yyvsp[(3) - (3)].num)); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 321 "parser.y"
    { (yyval.num) = ((yyvsp[(1) - (3)].num) > (yyvsp[(3) - (3)].num)); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 322 "parser.y"
    { (yyval.num) = ((yyvsp[(1) - (3)].num) <= (yyvsp[(3) - (3)].num)); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 323 "parser.y"
    { (yyval.num) = ((yyvsp[(1) - (3)].num) >= (yyvsp[(3) - (3)].num)); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 324 "parser.y"
    { 
        Symbol* s = find_symbol((yyvsp[(1) - (2)].str));
        if (s) {
            (yyval.num) = s->value++;
            printf("Incrementing variable %s\n", (yyvsp[(1) - (2)].str));
        } else {
            yyerror("Undeclared variable");
            (yyval.num) = 0;
        }
        free((yyvsp[(1) - (2)].str));
    ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 335 "parser.y"
    { 
        Symbol* s = find_symbol((yyvsp[(1) - (2)].str));
        if (s) {
            (yyval.num) = s->value--;
            printf("Decrementing variable %s\n", (yyvsp[(1) - (2)].str));
        } else {
            yyerror("Undeclared variable");
            (yyval.num) = 0;
        }
        free((yyvsp[(1) - (2)].str));
    ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 346 "parser.y"
    { 
        Symbol* s = find_symbol((yyvsp[(2) - (2)].str));
        if (s) {
            s->value++;
            (yyval.num) = s->value;
            printf("Pre-incrementing variable %s\n", (yyvsp[(2) - (2)].str));
        } else {
            yyerror("Undeclared variable");
            (yyval.num) = 0;
        }
        free((yyvsp[(2) - (2)].str));
    ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 358 "parser.y"
    { 
        Symbol* s = find_symbol((yyvsp[(2) - (2)].str));
        if (s) {
            s->value--;
            (yyval.num) = s->value;
            printf("Pre-decrementing variable %s\n", (yyvsp[(2) - (2)].str));
        } else {
            yyerror("Undeclared variable");
            (yyval.num) = 0;
        }
        free((yyvsp[(2) - (2)].str));
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 2095 "parser.tab.c"
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
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
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



/* Line 1675 of yacc.c  */
#line 372 "parser.y"

