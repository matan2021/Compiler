/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "part3.y"

	#define _GNU_SOURCE
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "lex.yy.c"
	

	typedef enum {false,true}bool;
	typedef struct node
	{
		char *token;
		struct node *left;
		struct node *right;
		char *code;
		char *var;
		char *label;
		char *truelabel;
		char *falselabel;
		int sum;

	} node;

	typedef struct Arguments
	{
		char * name;
		char * type;
		char * len;
	}Arguments;

    typedef struct Function 
	{
        char * name;
		struct Arguments * args;
        char *returnType; 
		int countArgs;
		int findreturn;
    } Function;
	

	typedef struct Varaiables
	{	int isArg;
		char *name;
		char *value;
		char *type;
		char * len;
	}Varaiable;

		typedef struct code
	{	
		int place;
		char *name;
		Varaiable * var;
		int countvar;
		int countfunc;
		Function ** func;
		struct code * nextLVL;
		struct code * beforeLVL;
	}code;
	char * exprtype(node *,code*);
	Arguments * makeArgs(node *,int *);
	void addFunc(char * name,Arguments * args,node *returnType,int countArgs,code*);
	void addvar(Arguments * args,int,int,code * CODEscope);
	code* makeCode(char *);
	node* makeNode(char* token, node *left, node *right);
	void Printtree(node *tree);
	void printTabs(int n);
	int yylex();
	int yyerror(char *e);
	void push(code* from,char*);
	int printlevel=0;
	code* mycode=NULL;
	static node* myroot=NULL;
	code* lastCode(code * codey);
	static int scope=0;
	void CheckSyntax(node *tree,code * scope);
	char* findfunc(node * tree,code * CODEscope,int* count);
	char *findvar(node * tree,code * CODEscope);
	Arguments * callfuncargs(code *,node *tree,int * count);
	int flagMain=false;
	
		//part 3
	
	int POPParams(Arguments * args,int count);
	void addCode(node* node,char *code,char *var,char *label,char *truelabel,char *falselabel);
	void addCode2(node* node,char *code,char *var,char *label,char *truelabel,char *falselabel);
	char* freshVar();
	char* freshLabel();
	char* gen(char*,char*,char*,char*,char*);
	char* mystrcat(char*des,char*src);

	char *replaceWord(const char *s, const char *oldW, const char *newW);
	char * mkspace(char *label);
	void calc3AC(node * tree);
	static int t=0;
	static int l=0;
	static int line=0;


	
	

#line 173 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    COMMENT = 258,
    WHILE = 259,
    IF = 260,
    ELSE = 261,
    FOR = 262,
    RETURN = 263,
    DO = 264,
    BOOL = 265,
    STRING = 266,
    CHARPTR = 267,
    CHAR = 268,
    INT = 269,
    INTPTR = 270,
    PROCEDUR = 271,
    AND = 272,
    ADDRESS = 273,
    EQL = 274,
    ASSINGMENT = 275,
    OR = 276,
    LENGTH = 277,
    GREATEREQL = 278,
    GREATER = 279,
    LESSEQL = 280,
    LESS = 281,
    NOTEQL = 282,
    NOT = 283,
    DIVISION = 284,
    PLUS = 285,
    MINUS = 286,
    MULTI = 287,
    VARIABLE = 288,
    STRING_LTL = 289,
    REAL_LTL = 290,
    CHAR_LTL = 291,
    NULLL = 292,
    MAIN = 293,
    IDENTIFIER = 294,
    SEMICOLON = 295,
    COMMA = 296,
    OPENPAREN = 297,
    CLOSEPAREN = 298,
    OPENBRACKET = 299,
    CLOSEBRACKET = 300,
    OPENBRACE = 301,
    CLOSEBRACE = 302,
    DECIMAL_LTL = 303,
    HEX_LTL = 304,
    BOOLTRUE = 305,
    BOOLFALSE = 306,
    REAL = 307,
    REALPTR = 308,
    FUNCTION = 309,
    COLON = 310,
    DEREFRENCE = 311
  };
#endif
/* Tokens.  */
#define COMMENT 258
#define WHILE 259
#define IF 260
#define ELSE 261
#define FOR 262
#define RETURN 263
#define DO 264
#define BOOL 265
#define STRING 266
#define CHARPTR 267
#define CHAR 268
#define INT 269
#define INTPTR 270
#define PROCEDUR 271
#define AND 272
#define ADDRESS 273
#define EQL 274
#define ASSINGMENT 275
#define OR 276
#define LENGTH 277
#define GREATEREQL 278
#define GREATER 279
#define LESSEQL 280
#define LESS 281
#define NOTEQL 282
#define NOT 283
#define DIVISION 284
#define PLUS 285
#define MINUS 286
#define MULTI 287
#define VARIABLE 288
#define STRING_LTL 289
#define REAL_LTL 290
#define CHAR_LTL 291
#define NULLL 292
#define MAIN 293
#define IDENTIFIER 294
#define SEMICOLON 295
#define COMMA 296
#define OPENPAREN 297
#define CLOSEPAREN 298
#define OPENBRACKET 299
#define CLOSEBRACKET 300
#define OPENBRACE 301
#define CLOSEBRACE 302
#define DECIMAL_LTL 303
#define HEX_LTL 304
#define BOOLTRUE 305
#define BOOLFALSE 306
#define REAL 307
#define REALPTR 308
#define FUNCTION 309
#define COLON 310
#define DEREFRENCE 311

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 104 "part3.y"

    struct node *node;
    char *string;

#line 339 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   672

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  224

#define YYUNDEFTOK  2
#define YYMAXUTOK   311


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      55,    56
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   136,   136,   141,   144,   144,   147,   150,   155,   155,
     158,   162,   166,   166,   169,   170,   174,   178,   178,   181,
     183,   186,   187,   188,   191,   194,   196,   199,   200,   201,
     202,   203,   204,   205,   208,   209,   210,   211,   212,   213,
     214,   218,   222,   225,   229,   230,   231,   234,   241,   247,
     255,   261,   269,   276,   277,   278,   279,   282,   285,   287,
     288,   289,   292,   294,   295,   296,   297,   298,   299,   300,
     301,   303,   304,   305,   306,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   325,   327,   328,
     332,   332,   334,   335,   336,   338,   344,   347,   348,   348,
     350,   353
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COMMENT", "WHILE", "IF", "ELSE", "FOR",
  "RETURN", "DO", "BOOL", "STRING", "CHARPTR", "CHAR", "INT", "INTPTR",
  "PROCEDUR", "AND", "ADDRESS", "EQL", "ASSINGMENT", "OR", "LENGTH",
  "GREATEREQL", "GREATER", "LESSEQL", "LESS", "NOTEQL", "NOT", "DIVISION",
  "PLUS", "MINUS", "MULTI", "VARIABLE", "STRING_LTL", "REAL_LTL",
  "CHAR_LTL", "NULLL", "MAIN", "IDENTIFIER", "SEMICOLON", "COMMA",
  "OPENPAREN", "CLOSEPAREN", "OPENBRACKET", "CLOSEBRACKET", "OPENBRACE",
  "CLOSEBRACE", "DECIMAL_LTL", "HEX_LTL", "BOOLTRUE", "BOOLFALSE", "REAL",
  "REALPTR", "FUNCTION", "COLON", "DEREFRENCE", "$accept", "project",
  "program", "cmmnt", "the_main", "procedures", "procedure", "para_pro",
  "para_list", "pro_body", "declears", "declear", "var_id", "var_id_str",
  "type_id", "type_pro", "stmnts", "stmnt_block", "new_block", "stmnt",
  "assmnt_stmnt", "lhs", "expr", "address_exprs", "address_expr",
  "derefrence_expr", "expr_list", "paren_expr", "call_func", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311
};
# endif

#define YYPACT_NINF (-168)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-62)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -168,    42,    44,  -168,  -168,  -168,    -3,  -168,  -168,  -168,
    -168,  -168,  -168,  -168,    15,  -168,  -168,    21,    40,    45,
      48,    50,    43,    11,    75,    11,    16,  -168,  -168,  -168,
    -168,  -168,  -168,  -168,    78,    87,    67,    82,    88,  -168,
      90,  -168,    -2,   346,    81,  -168,  -168,   110,  -168,  -168,
    -168,    91,    44,    92,  -168,     5,    97,   103,    84,   104,
     346,  -168,  -168,  -168,  -168,     2,   346,  -168,  -168,  -168,
    -168,   137,  -168,  -168,  -168,  -168,    67,   346,   346,    99,
    -168,    20,  -168,   100,  -168,   346,    37,  -168,   126,  -168,
     346,   346,  -168,   483,   346,   346,   346,   346,   346,   346,
     346,   346,   346,   346,   346,   346,  -168,   381,   232,  -168,
     108,   112,     3,   118,  -168,   398,  -168,   346,  -168,   567,
     116,   415,  -168,  -168,  -168,  -168,  -168,  -168,  -168,  -168,
    -168,   137,   640,   640,   137,  -168,  -168,   101,    11,  -168,
     321,  -168,   432,   346,  -168,  -168,   121,   128,  -168,    67,
    -168,   127,  -168,   346,   265,    71,  -168,  -168,  -168,   131,
     586,   152,   153,   132,  -168,   346,  -168,  -168,    10,   346,
      19,   604,  -168,  -168,  -168,   173,  -168,   346,    20,  -168,
    -168,  -168,   449,    36,   346,   504,   106,  -168,  -168,   466,
      44,    44,    44,     7,  -168,   525,   265,   138,   150,    44,
      25,   175,     3,   101,    44,   265,   187,   346,   346,    61,
    -168,  -168,   265,   622,   546,  -168,  -168,   106,   156,    44,
     158,  -168,   265,  -168
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     9,     1,     4,     2,     0,    34,    39,    35,
      36,    38,    37,    40,     0,     3,     8,     0,     0,     0,
       0,     0,     0,    13,     0,    13,     0,    27,    32,    28,
      29,    31,    30,    33,     0,    12,     0,     0,     0,     5,
       0,     5,     0,     0,    22,    14,    23,     0,    60,    61,
       5,     0,     9,     0,     5,     0,    92,     0,     0,     0,
       0,    85,    84,    83,    89,    88,     0,    81,    82,    77,
      76,    96,    78,    91,    79,    80,     0,     0,     0,     0,
       5,    18,     7,     0,    15,     0,     0,    90,     0,    75,
      99,     0,   101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,    57,     6,
       0,     0,    42,     0,    11,     0,    93,     0,    86,    98,
       0,     0,    62,    69,    63,    70,    65,    66,    67,    68,
      64,    74,    71,    72,    73,    58,    10,     0,     0,    17,
      16,    94,     0,    99,   100,    87,    59,     0,    26,     0,
       5,     0,     5,     0,     0,    88,     9,    56,    41,     0,
       0,    91,    79,     0,    97,     0,    20,     5,     0,     0,
       0,     0,    46,    45,    44,     0,    43,     0,     5,     5,
       5,    95,     0,     0,     0,     0,     0,     5,     5,     0,
      18,    53,    54,    24,     5,     0,     0,    59,     0,    55,
       0,    87,    42,     0,    19,     0,    48,     0,     0,     0,
      25,    50,     0,     0,     0,     5,    49,     0,     0,    47,
       0,    52,     0,    51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -168,  -168,  -168,     0,  -168,   -51,    -4,   174,   151,    34,
      18,  -108,   -71,     8,    72,   199,    12,  -167,  -168,  -134,
     -33,  -168,   143,   155,   -20,    -5,    73,  -168,  -168
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     5,    52,    15,     6,   173,    34,    35,    53,
     112,   174,    45,   147,    36,   113,   140,   175,   157,   176,
     159,    47,   160,    72,    73,    74,   120,    92,    75
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       2,    81,    16,    46,   139,   106,   158,     7,     4,     8,
       9,    10,    11,     4,   137,    27,    48,    28,    29,    30,
      31,    27,     4,    28,    29,    30,    31,   -58,     4,   206,
       7,    49,     8,     9,    10,    11,   138,    56,   211,     4,
      57,    55,     3,    46,    90,   216,    91,     4,   203,    12,
      13,    14,   184,    18,    19,   223,    48,    32,    33,    20,
      21,   186,    39,    32,    33,   150,   151,   208,   152,   153,
     154,    49,    12,    13,   111,   158,   194,    16,   167,    58,
     116,   117,    22,    59,    79,    42,    26,    23,    83,    60,
      24,   -59,    25,    43,   139,    61,    62,    63,    64,    43,
     155,   -59,    58,    66,   148,   178,    44,   156,   215,    67,
      68,    69,    70,    90,   110,   177,    46,    48,    37,    42,
     161,    40,    76,    56,    42,    77,    57,    41,    50,    48,
      78,    51,    49,    43,   161,   162,    54,    80,    43,    82,
     146,    85,    86,    88,    49,   197,   109,   114,   118,   162,
     168,    19,   170,   198,    94,   136,    95,    21,    96,   144,
      97,    98,    99,   100,   101,   165,    48,   183,   166,   169,
     148,   179,   -60,   -61,    16,   181,   161,   188,   190,   191,
     192,    49,    77,    48,   220,   161,    71,   199,   200,   161,
     207,   162,   161,   212,   204,   -58,   221,    48,    49,    38,
     162,   222,   161,    89,   162,    17,    84,   162,   202,    93,
     149,   210,    49,    87,   209,   219,   164,   162,     0,     0,
     107,   108,     0,     0,     0,     0,     0,     0,   115,     0,
       0,     0,     0,   119,   121,     0,     0,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,    94,
       0,    95,     0,    96,     0,    97,    98,    99,   100,   101,
     142,   102,   103,   104,   105,     0,     0,     0,     0,   150,
     151,     0,   152,   153,   154,     7,   137,     8,     9,    10,
      11,     0,     0,    58,     0,     0,   119,    59,     0,     0,
       0,     0,     0,    60,     0,     0,   171,    43,   138,    61,
      62,    63,    64,     0,   155,   172,     0,    66,   182,     0,
       0,   156,   185,    67,    68,    69,    70,    12,    13,   111,
     189,     0,     0,     0,     0,   150,   151,   195,   152,   153,
     154,     0,     0,     0,     0,     0,     0,     0,     0,    58,
       0,     0,     0,    59,     0,     0,     0,     0,     0,    60,
     213,   214,     0,    43,     0,    61,    62,    63,    64,     0,
     155,     0,     0,    66,    58,     0,     0,   156,    59,    67,
      68,    69,    70,     0,    60,     0,     0,     0,    43,     0,
      61,    62,    63,    64,     0,    65,     0,     0,    66,     0,
       0,     0,     0,     0,    67,    68,    69,    70,    94,     0,
      95,     0,    96,     0,    97,    98,    99,   100,   101,     0,
     102,   103,   104,   105,     0,    94,     0,    95,     0,    96,
       0,    97,    98,    99,   100,   101,   135,   102,   103,   104,
     105,     0,    94,     0,    95,     0,    96,     0,    97,    98,
      99,   100,   101,   141,   102,   103,   104,   105,     0,    94,
       0,    95,     0,    96,     0,    97,    98,    99,   100,   101,
     145,   102,   103,   104,   105,     0,    94,     0,    95,     0,
      96,     0,    97,    98,    99,   100,   101,   163,   102,   103,
     104,   105,     0,    94,     0,    95,     0,    96,     0,    97,
      98,    99,   100,   101,   193,   102,   103,   104,   105,     0,
      94,     0,    95,     0,    96,     0,    97,    98,    99,   100,
     101,   201,   102,   103,   104,   105,     0,     0,     0,     0,
       0,    94,     0,    95,     0,    96,   122,    97,    98,    99,
     100,   101,     0,   102,   103,   104,   105,     0,     0,     0,
       0,     0,    94,     0,    95,     0,    96,   196,    97,    98,
      99,   100,   101,     0,   102,   103,   104,   105,     0,     0,
       0,     0,     0,    94,     0,    95,     0,    96,   205,    97,
      98,    99,   100,   101,     0,   102,   103,   104,   105,     0,
       0,     0,     0,     0,    94,     0,    95,     0,    96,   218,
      97,    98,    99,   100,   101,     0,   102,   103,   104,   105,
       0,     0,     0,    94,     0,    95,     0,    96,   143,    97,
      98,    99,   100,   101,     0,   102,   103,   104,   105,     0,
       0,    94,     0,    95,     0,    96,   180,    97,    98,    99,
     100,   101,     0,   102,   103,   104,   105,     0,     0,    94,
       0,    95,     0,    96,   187,    97,    98,    99,   100,   101,
       0,   102,   103,   104,   105,     0,     0,    94,     0,    95,
       0,    96,   217,    97,    98,    99,   100,   101,     0,   102,
       0,     0,   105
};

static const yytype_int16 yycheck[] =
{
       0,    52,     6,    36,   112,    76,   140,    10,     3,    12,
      13,    14,    15,     3,    11,    10,    36,    12,    13,    14,
      15,    10,     3,    12,    13,    14,    15,    20,     3,   196,
      10,    36,    12,    13,    14,    15,    33,    39,   205,     3,
      42,    41,     0,    76,    42,   212,    44,     3,    41,    52,
      53,    54,    42,    38,    39,   222,    76,    52,    53,    38,
      39,    42,    46,    52,    53,     4,     5,    42,     7,     8,
       9,    76,    52,    53,    54,   209,    40,    81,   149,    18,
      43,    44,    42,    22,    50,    18,    43,    42,    54,    28,
      42,    20,    42,    32,   202,    34,    35,    36,    37,    32,
      39,    20,    18,    42,   137,   156,    39,    46,    47,    48,
      49,    50,    51,    42,    80,    44,   149,   137,    43,    18,
     140,    43,    41,    39,    18,    44,    42,    40,    46,   149,
      20,    43,   137,    32,   154,   140,    46,    46,    32,    47,
      39,    44,    39,    39,   149,    39,    47,    47,    22,   154,
     150,    39,   152,   186,    17,    47,    19,    39,    21,    43,
      23,    24,    25,    26,    27,    44,   186,   167,    40,    42,
     203,    40,    20,    20,   178,    43,   196,     4,   178,   179,
     180,   186,    44,   203,   217,   205,    43,   187,   188,   209,
      40,   196,   212,     6,   194,    20,    40,   217,   203,    25,
     205,    43,   222,    60,   209,     6,    55,   212,   190,    66,
     138,   203,   217,    58,   202,   215,   143,   222,    -1,    -1,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,
      -1,    -1,    -1,    90,    91,    -1,    -1,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,    17,
      -1,    19,    -1,    21,    -1,    23,    24,    25,    26,    27,
     117,    29,    30,    31,    32,    -1,    -1,    -1,    -1,     4,
       5,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    -1,    18,    -1,    -1,   143,    22,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    -1,   153,    32,    33,    34,
      35,    36,    37,    -1,    39,    40,    -1,    42,   165,    -1,
      -1,    46,   169,    48,    49,    50,    51,    52,    53,    54,
     177,    -1,    -1,    -1,    -1,     4,     5,   184,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    28,
     207,   208,    -1,    32,    -1,    34,    35,    36,    37,    -1,
      39,    -1,    -1,    42,    18,    -1,    -1,    46,    22,    48,
      49,    50,    51,    -1,    28,    -1,    -1,    -1,    32,    -1,
      34,    35,    36,    37,    -1,    39,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    17,    -1,
      19,    -1,    21,    -1,    23,    24,    25,    26,    27,    -1,
      29,    30,    31,    32,    -1,    17,    -1,    19,    -1,    21,
      -1,    23,    24,    25,    26,    27,    45,    29,    30,    31,
      32,    -1,    17,    -1,    19,    -1,    21,    -1,    23,    24,
      25,    26,    27,    45,    29,    30,    31,    32,    -1,    17,
      -1,    19,    -1,    21,    -1,    23,    24,    25,    26,    27,
      45,    29,    30,    31,    32,    -1,    17,    -1,    19,    -1,
      21,    -1,    23,    24,    25,    26,    27,    45,    29,    30,
      31,    32,    -1,    17,    -1,    19,    -1,    21,    -1,    23,
      24,    25,    26,    27,    45,    29,    30,    31,    32,    -1,
      17,    -1,    19,    -1,    21,    -1,    23,    24,    25,    26,
      27,    45,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    19,    -1,    21,    43,    23,    24,    25,
      26,    27,    -1,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    19,    -1,    21,    43,    23,    24,
      25,    26,    27,    -1,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    17,    -1,    19,    -1,    21,    43,    23,
      24,    25,    26,    27,    -1,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    17,    -1,    19,    -1,    21,    43,
      23,    24,    25,    26,    27,    -1,    29,    30,    31,    32,
      -1,    -1,    -1,    17,    -1,    19,    -1,    21,    41,    23,
      24,    25,    26,    27,    -1,    29,    30,    31,    32,    -1,
      -1,    17,    -1,    19,    -1,    21,    40,    23,    24,    25,
      26,    27,    -1,    29,    30,    31,    32,    -1,    -1,    17,
      -1,    19,    -1,    21,    40,    23,    24,    25,    26,    27,
      -1,    29,    30,    31,    32,    -1,    -1,    17,    -1,    19,
      -1,    21,    40,    23,    24,    25,    26,    27,    -1,    29,
      -1,    -1,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    58,    60,     0,     3,    59,    62,    10,    12,    13,
      14,    15,    52,    53,    54,    61,    63,    72,    38,    39,
      38,    39,    42,    42,    42,    42,    43,    10,    12,    13,
      14,    15,    52,    53,    64,    65,    71,    43,    64,    46,
      43,    40,    18,    32,    39,    69,    77,    78,    81,    82,
      46,    43,    60,    66,    46,    60,    39,    42,    18,    22,
      28,    34,    35,    36,    37,    39,    42,    48,    49,    50,
      51,    79,    80,    81,    82,    85,    41,    44,    20,    66,
      46,    62,    47,    66,    65,    44,    39,    80,    39,    79,
      42,    44,    84,    79,    17,    19,    21,    23,    24,    25,
      26,    27,    29,    30,    31,    32,    69,    79,    79,    47,
      66,    54,    67,    72,    47,    79,    43,    44,    22,    79,
      83,    79,    43,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    45,    47,    11,    33,    68,
      73,    45,    79,    41,    43,    45,    39,    70,    77,    71,
       4,     5,     7,     8,     9,    39,    46,    75,    76,    77,
      79,    81,    82,    45,    83,    44,    40,    69,    60,    42,
      60,    79,    40,    63,    68,    74,    76,    44,    62,    40,
      40,    43,    79,    60,    42,    79,    42,    40,     4,    79,
      60,    60,    60,    45,    40,    79,    43,    39,    77,    60,
      60,    45,    67,    41,    60,    43,    74,    40,    42,    73,
      70,    74,     6,    79,    79,    47,    74,    40,    43,    60,
      77,    40,    43,    74
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    59,    60,    60,    61,    61,    62,    62,
      63,    63,    64,    64,    65,    65,    66,    67,    67,    68,
      68,    69,    69,    69,    70,    70,    70,    71,    71,    71,
      71,    71,    71,    71,    72,    72,    72,    72,    72,    72,
      72,    73,    73,    74,    74,    74,    74,    75,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    77,    78,    78,
      78,    78,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      80,    80,    81,    81,    81,    81,    82,    83,    83,    83,
      84,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     7,     7,     2,     0,
       8,     8,     1,     0,     2,     4,     4,     2,     0,     6,
       3,     3,     1,     1,     4,     6,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     0,     1,     1,     1,     1,     7,     5,     7,
       6,    10,     8,     3,     3,     4,     1,     3,     4,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     4,     1,     1,
       2,     1,     2,     4,     5,     7,     2,     3,     1,     0,
       3,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

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
#line 136 "part3.y"
                       { myroot=(yyvsp[0].node);
					 	 CheckSyntax((yyvsp[0].node),mycode);
					 	 calc3AC((yyvsp[0].node));
						}
#line 1761 "y.tab.c"
    break;

  case 3:
#line 141 "part3.y"
                             {(yyval.node)=makeNode("CODE",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1767 "y.tab.c"
    break;

  case 6:
#line 148 "part3.y"
        { (yyval.node)=makeNode("main",makeNode("Return",(yyvsp[-6].node),NULL),(yyvsp[-1].node));
	t=0;}
#line 1774 "y.tab.c"
    break;

  case 7:
#line 151 "part3.y"
        { (yyval.node)=makeNode("main",NULL,(yyvsp[-1].node));
	  t=0;}
#line 1781 "y.tab.c"
    break;

  case 8:
#line 155 "part3.y"
                                 {(yyval.node)=makeNode("procedures",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1787 "y.tab.c"
    break;

  case 9:
#line 155 "part3.y"
                                                                      {(yyval.node)=NULL;}
#line 1793 "y.tab.c"
    break;

  case 10:
#line 159 "part3.y"
           { (yyval.node)=makeNode("func",makeNode((yyvsp[-6].string),makeNode("ARGS",(yyvsp[-4].node),NULL)
	   ,makeNode("Return",(yyvsp[-7].node),NULL)),(yyvsp[-1].node));
	   t=0;}
#line 1801 "y.tab.c"
    break;

  case 11:
#line 163 "part3.y"
           { (yyval.node)=makeNode("func",makeNode((yyvsp[-6].string),makeNode("ARGS",(yyvsp[-4].node),NULL),NULL),(yyvsp[-1].node));t=0;}
#line 1807 "y.tab.c"
    break;

  case 12:
#line 166 "part3.y"
                    {(yyval.node)=(yyvsp[0].node);}
#line 1813 "y.tab.c"
    break;

  case 13:
#line 166 "part3.y"
                               {(yyval.node)=NULL;}
#line 1819 "y.tab.c"
    break;

  case 14:
#line 169 "part3.y"
                          {(yyval.node)=makeNode("(",(yyvsp[-1].node),makeNode("",(yyvsp[0].node),makeNode(")",NULL,NULL)));}
#line 1825 "y.tab.c"
    break;

  case 15:
#line 171 "part3.y"
           {(yyval.node)=makeNode("",(yyvsp[-3].node),makeNode("",(yyvsp[0].node),NULL));}
#line 1831 "y.tab.c"
    break;

  case 16:
#line 175 "part3.y"
          { (yyval.node)=makeNode("BODY", makeNode("",(yyvsp[-2].node),NULL),makeNode("",(yyvsp[-1].node),makeNode("",(yyvsp[0].node),NULL)));}
#line 1837 "y.tab.c"
    break;

  case 17:
#line 178 "part3.y"
                           {(yyval.node)=makeNode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1843 "y.tab.c"
    break;

  case 18:
#line 178 "part3.y"
                                                      {(yyval.node)=NULL;}
#line 1849 "y.tab.c"
    break;

  case 19:
#line 182 "part3.y"
         { (yyval.node)=makeNode("var", (yyvsp[-4].node) ,(yyvsp[-3].node));}
#line 1855 "y.tab.c"
    break;

  case 20:
#line 183 "part3.y"
                                      {(yyval.node)=(yyvsp[-1].node);}
#line 1861 "y.tab.c"
    break;

  case 21:
#line 186 "part3.y"
                                {(yyval.node)=makeNode((yyvsp[-2].string), makeNode(",", (yyvsp[0].node), NULL),NULL);}
#line 1867 "y.tab.c"
    break;

  case 22:
#line 187 "part3.y"
                                {(yyval.node)=makeNode((yyvsp[0].string), NULL, NULL);}
#line 1873 "y.tab.c"
    break;

  case 23:
#line 188 "part3.y"
                                {(yyval.node)=makeNode("",(yyvsp[0].node),NULL);}
#line 1879 "y.tab.c"
    break;

  case 24:
#line 192 "part3.y"
            {(yyval.node)=makeNode("var", makeNode("string",makeNode("",(yyvsp[-1].node),NULL), NULL),
		 makeNode((yyvsp[-3].string),NULL,NULL));}
#line 1886 "y.tab.c"
    break;

  case 25:
#line 195 "part3.y"
            {(yyval.node)=makeNode("", makeNode("var", makeNode("string",makeNode("",(yyvsp[-3].node),NULL), NULL), makeNode((yyvsp[-5].string),NULL,NULL)), (yyvsp[0].node));}
#line 1892 "y.tab.c"
    break;

  case 26:
#line 196 "part3.y"
                         {(yyval.node)=makeNode("",(yyvsp[0].node),NULL);}
#line 1898 "y.tab.c"
    break;

  case 27:
#line 199 "part3.y"
              {(yyval.node)=makeNode("boolean", NULL, NULL);}
#line 1904 "y.tab.c"
    break;

  case 28:
#line 200 "part3.y"
               {(yyval.node)=makeNode("char", NULL, NULL);}
#line 1910 "y.tab.c"
    break;

  case 29:
#line 201 "part3.y"
              {(yyval.node)=makeNode("int", NULL, NULL);}
#line 1916 "y.tab.c"
    break;

  case 30:
#line 202 "part3.y"
               {(yyval.node)=makeNode("real", NULL, NULL);}
#line 1922 "y.tab.c"
    break;

  case 31:
#line 203 "part3.y"
                 {(yyval.node)=makeNode("int*", NULL, NULL);}
#line 1928 "y.tab.c"
    break;

  case 32:
#line 204 "part3.y"
                  {(yyval.node)=makeNode("char*", NULL, NULL);}
#line 1934 "y.tab.c"
    break;

  case 33:
#line 205 "part3.y"
                  {(yyval.node)=makeNode("real*", NULL, NULL);}
#line 1940 "y.tab.c"
    break;

  case 34:
#line 208 "part3.y"
               {(yyval.node)=makeNode("boolean", NULL, NULL);}
#line 1946 "y.tab.c"
    break;

  case 35:
#line 209 "part3.y"
               {(yyval.node)=makeNode("char", NULL, NULL);}
#line 1952 "y.tab.c"
    break;

  case 36:
#line 210 "part3.y"
              {(yyval.node)=makeNode("int", NULL, NULL);}
#line 1958 "y.tab.c"
    break;

  case 37:
#line 211 "part3.y"
               {(yyval.node)=makeNode("real", NULL, NULL);}
#line 1964 "y.tab.c"
    break;

  case 38:
#line 212 "part3.y"
                 {(yyval.node)=makeNode("int*", NULL, NULL);}
#line 1970 "y.tab.c"
    break;

  case 39:
#line 213 "part3.y"
                  {(yyval.node)=makeNode("char*", NULL, NULL);}
#line 1976 "y.tab.c"
    break;

  case 40:
#line 214 "part3.y"
                  {(yyval.node)=makeNode("real*", NULL, NULL);}
#line 1982 "y.tab.c"
    break;

  case 41:
#line 219 "part3.y"
                { (yyval.node)=makeNode("stmnts",(yyvsp[-1].node),(yyvsp[0].node));
		  if(strcmp((yyvsp[0].node)->token, "if") == 0||strcmp((yyvsp[0].node)->token, "for") == 0||strcmp((yyvsp[0].node)->token, "if-else") == 0||
		  strcmp((yyvsp[0].node)->token, "while") == 0||strcmp((yyvsp[0].node)->token, "do") == 0){ if((yyval.node)->sum==0) {addCode((yyvsp[0].node),NULL,NULL,freshLabel(),NULL,NULL); (yyval.node)->sum=1;}}}
#line 1990 "y.tab.c"
    break;

  case 42:
#line 222 "part3.y"
                  {(yyval.node)=NULL;}
#line 1996 "y.tab.c"
    break;

  case 43:
#line 226 "part3.y"
                         { (yyval.node)=(yyvsp[0].node);
			   if(strcmp((yyvsp[0].node)->token, "if") == 0||strcmp((yyvsp[0].node)->token, "for") == 0||strcmp((yyvsp[0].node)->token, "if-else") == 0||
			   strcmp((yyvsp[0].node)->token, "while") == 0||strcmp((yyvsp[0].node)->token, "do") == 0) addCode((yyvsp[0].node),NULL,NULL,freshLabel(),NULL,NULL);}
#line 2004 "y.tab.c"
    break;

  case 44:
#line 229 "part3.y"
                                  {(yyval.node)=(yyvsp[0].node);}
#line 2010 "y.tab.c"
    break;

  case 45:
#line 230 "part3.y"
                                    {(yyval.node)=(yyvsp[0].node);}
#line 2016 "y.tab.c"
    break;

  case 46:
#line 231 "part3.y"
                                     {(yyval.node)=makeNode("",NULL,NULL);}
#line 2022 "y.tab.c"
    break;

  case 47:
#line 235 "part3.y"
        { (yyval.node)=makeNode("{",(yyvsp[-5].node),
						makeNode("", (yyvsp[-3].node),
										makeNode("", (yyvsp[-2].node),
														makeNode("}",NULL,NULL))));}
#line 2031 "y.tab.c"
    break;

  case 48:
#line 242 "part3.y"
        { (yyval.node)=makeNode("if",
	  makeNode("(", (yyvsp[-2].node), 
	  makeNode(")",NULL,NULL)),(yyvsp[0].node));
	  addCode((yyvsp[-2].node),NULL,NULL,NULL,freshLabel(),NULL);
	}
#line 2041 "y.tab.c"
    break;

  case 49:
#line 248 "part3.y"
        { (yyval.node)=makeNode("if-else",
	  makeNode("(", (yyvsp[-4].node), 
	  makeNode(")",NULL,NULL)),
	  makeNode("",(yyvsp[-2].node),
	  makeNode("",(yyvsp[0].node),NULL)));
	  addCode((yyvsp[-4].node),NULL,NULL,NULL,freshLabel(),NULL);
	  addCode((yyvsp[-4].node),NULL,NULL,NULL,NULL,freshLabel());}
#line 2053 "y.tab.c"
    break;

  case 50:
#line 256 "part3.y"
        { (yyval.node)=makeNode("while",
	  makeNode("(", (yyvsp[-2].node), 
	  makeNode(")",NULL,NULL)),(yyvsp[0].node));
	  addCode((yyval.node),NULL,NULL,NULL,freshLabel(),NULL);
	  addCode((yyval.node),NULL,NULL,NULL,NULL,freshLabel());}
#line 2063 "y.tab.c"
    break;

  case 51:
#line 262 "part3.y"
        { (yyval.node)= makeNode("for",
		makeNode("(",
		makeNode("",(yyvsp[-6].node),(yyvsp[-4].node)),
		makeNode("",(yyvsp[-2].node),
		makeNode(")",NULL,NULL))),(yyvsp[0].node));
		addCode((yyval.node),NULL,NULL,NULL,freshLabel(),NULL);
		addCode((yyval.node),NULL,NULL,NULL,NULL,freshLabel());	}
#line 2075 "y.tab.c"
    break;

  case 52:
#line 270 "part3.y"
        { (yyval.node)=makeNode("do",
		makeNode("(",(yyvsp[-2].node),
		makeNode(")",NULL,NULL)),(yyvsp[-6].node));
		addCode((yyval.node),NULL,NULL,NULL,freshLabel(),NULL);
	    //addCode($$,NULL,NULL,NULL,NULL,freshLabel());
	    }
#line 2086 "y.tab.c"
    break;

  case 53:
#line 276 "part3.y"
                                       {(yyval.node)=makeNode("",(yyvsp[-2].node),NULL);}
#line 2092 "y.tab.c"
    break;

  case 54:
#line 277 "part3.y"
                               {(yyval.node)=(yyvsp[-2].node);}
#line 2098 "y.tab.c"
    break;

  case 55:
#line 278 "part3.y"
                                      {(yyval.node)=makeNode("return",(yyvsp[-2].node),NULL);}
#line 2104 "y.tab.c"
    break;

  case 56:
#line 279 "part3.y"
                    {(yyval.node)=(yyvsp[0].node);}
#line 2110 "y.tab.c"
    break;

  case 57:
#line 282 "part3.y"
                                  { (yyval.node)=makeNode("=",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2116 "y.tab.c"
    break;

  case 58:
#line 286 "part3.y"
        { (yyval.node)=makeNode((yyvsp[-3].string), makeNode("[",(yyvsp[-1].node),makeNode("]",NULL,NULL)), NULL);}
#line 2122 "y.tab.c"
    break;

  case 59:
#line 287 "part3.y"
                     {(yyval.node)=makeNode((yyvsp[0].string),NULL,NULL);}
#line 2128 "y.tab.c"
    break;

  case 60:
#line 288 "part3.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 2134 "y.tab.c"
    break;

  case 61:
#line 289 "part3.y"
                         {(yyval.node)=(yyvsp[0].node);}
#line 2140 "y.tab.c"
    break;

  case 62:
#line 292 "part3.y"
                                {(yyval.node)=makeNode("(",(yyvsp[-1].node),makeNode(")",NULL,NULL));}
#line 2146 "y.tab.c"
    break;

  case 63:
#line 294 "part3.y"
                        {(yyval.node)=makeNode("==",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2152 "y.tab.c"
    break;

  case 64:
#line 295 "part3.y"
                           {(yyval.node)=makeNode("!=",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2158 "y.tab.c"
    break;

  case 65:
#line 296 "part3.y"
                               {(yyval.node)=makeNode(">=",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2164 "y.tab.c"
    break;

  case 66:
#line 297 "part3.y"
                            {(yyval.node)=makeNode(">",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2170 "y.tab.c"
    break;

  case 67:
#line 298 "part3.y"
                            {(yyval.node)=makeNode("<=",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2176 "y.tab.c"
    break;

  case 68:
#line 299 "part3.y"
                         {(yyval.node)=makeNode("<",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2182 "y.tab.c"
    break;

  case 69:
#line 300 "part3.y"
                        {(yyval.node)=makeNode("&&",(yyvsp[-2].node),(yyvsp[0].node)); addCode((yyvsp[-2].node),NULL,NULL,NULL,freshLabel(),NULL);}
#line 2188 "y.tab.c"
    break;

  case 70:
#line 301 "part3.y"
                       {(yyval.node)=makeNode("||",(yyvsp[-2].node),(yyvsp[0].node)); addCode((yyvsp[-2].node),NULL,NULL,NULL,NULL,freshLabel());}
#line 2194 "y.tab.c"
    break;

  case 71:
#line 303 "part3.y"
                         {(yyval.node)=makeNode("+",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2200 "y.tab.c"
    break;

  case 72:
#line 304 "part3.y"
                          {(yyval.node)=makeNode("-",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2206 "y.tab.c"
    break;

  case 73:
#line 305 "part3.y"
                          {(yyval.node)=makeNode("*",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2212 "y.tab.c"
    break;

  case 74:
#line 306 "part3.y"
                             {(yyval.node)=makeNode("/",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2218 "y.tab.c"
    break;

  case 75:
#line 308 "part3.y"
                   {(yyval.node)=makeNode("!",(yyvsp[0].node),NULL);}
#line 2224 "y.tab.c"
    break;

  case 76:
#line 309 "part3.y"
                    {(yyval.node)=makeNode((yyvsp[0].string),makeNode("BOOLEAN", NULL, NULL),NULL);}
#line 2230 "y.tab.c"
    break;

  case 77:
#line 310 "part3.y"
                   {(yyval.node)=makeNode((yyvsp[0].string),makeNode("BOOLEAN", NULL, NULL),NULL);}
#line 2236 "y.tab.c"
    break;

  case 78:
#line 311 "part3.y"
                        {(yyval.node)=(yyvsp[0].node);}
#line 2242 "y.tab.c"
    break;

  case 79:
#line 312 "part3.y"
                          {(yyval.node)=(yyvsp[0].node);}
#line 2248 "y.tab.c"
    break;

  case 80:
#line 313 "part3.y"
                    {(yyval.node)=(yyvsp[0].node);}
#line 2254 "y.tab.c"
    break;

  case 81:
#line 314 "part3.y"
                      {(yyval.node)=makeNode((yyvsp[0].string),makeNode("INT",NULL,NULL),NULL);}
#line 2260 "y.tab.c"
    break;

  case 82:
#line 315 "part3.y"
                  {(yyval.node)=makeNode((yyvsp[0].string),makeNode("HEX", NULL, NULL),NULL);}
#line 2266 "y.tab.c"
    break;

  case 83:
#line 316 "part3.y"
                   {(yyval.node)=makeNode((yyvsp[0].string),makeNode("CHAR", NULL, NULL),NULL);}
#line 2272 "y.tab.c"
    break;

  case 84:
#line 317 "part3.y"
                   {(yyval.node)=makeNode((yyvsp[0].string),makeNode("REAL", NULL, NULL),NULL);}
#line 2278 "y.tab.c"
    break;

  case 85:
#line 318 "part3.y"
                     {(yyval.node)=makeNode((yyvsp[0].string),makeNode("STRING", NULL, NULL),NULL);}
#line 2284 "y.tab.c"
    break;

  case 86:
#line 320 "part3.y"
        {
		(yyval.node)=makeNode("|",
		makeNode((yyvsp[-1].string),NULL,NULL),
		makeNode("|",NULL,NULL));
	}
#line 2294 "y.tab.c"
    break;

  case 87:
#line 326 "part3.y"
        {(yyval.node)=makeNode("[",(yyvsp[-1].node),makeNode("]",NULL,NULL));}
#line 2300 "y.tab.c"
    break;

  case 88:
#line 327 "part3.y"
                     {(yyval.node)=makeNode((yyvsp[0].string),NULL,NULL);}
#line 2306 "y.tab.c"
    break;

  case 89:
#line 328 "part3.y"
                {(yyval.node)=makeNode("null",NULL,NULL);}
#line 2312 "y.tab.c"
    break;

  case 90:
#line 332 "part3.y"
                                    {(yyval.node)=makeNode((yyvsp[-1].string),(yyvsp[0].node),NULL);}
#line 2318 "y.tab.c"
    break;

  case 91:
#line 332 "part3.y"
                                                                              {(yyval.node)=(yyvsp[0].node);}
#line 2324 "y.tab.c"
    break;

  case 92:
#line 334 "part3.y"
                                 {(yyval.node)=makeNode("&",makeNode((yyvsp[0].string),NULL,NULL),NULL);}
#line 2330 "y.tab.c"
    break;

  case 93:
#line 335 "part3.y"
                                                  {(yyval.node)=makeNode("&",makeNode("(",makeNode((yyvsp[-1].string),NULL,NULL),NULL),makeNode(")",NULL,NULL));}
#line 2336 "y.tab.c"
    break;

  case 94:
#line 337 "part3.y"
        { (yyval.node)=makeNode("&", makeNode((yyvsp[-3].string),NULL,NULL), makeNode("[",(yyvsp[-1].node),makeNode("]",NULL,NULL)));}
#line 2342 "y.tab.c"
    break;

  case 95:
#line 339 "part3.y"
        { (yyval.node)=makeNode("&",
	  				  makeNode("(",makeNode((yyvsp[-4].string),NULL,NULL),makeNode("[",(yyvsp[-2].node),NULL)), 
	  															makeNode("]",NULL,makeNode(")",NULL,NULL)));}
#line 2350 "y.tab.c"
    break;

  case 96:
#line 344 "part3.y"
                            {(yyval.node)=makeNode("^",makeNode("(",(yyvsp[0].node),NULL),makeNode(")",NULL,NULL));}
#line 2356 "y.tab.c"
    break;

  case 97:
#line 347 "part3.y"
                                {(yyval.node)=makeNode("expr_list",(yyvsp[-2].node),makeNode(",",(yyvsp[0].node),NULL));}
#line 2362 "y.tab.c"
    break;

  case 98:
#line 348 "part3.y"
                {(yyval.node)=makeNode("expr_list",(yyvsp[0].node),NULL);}
#line 2368 "y.tab.c"
    break;

  case 99:
#line 348 "part3.y"
                                                      {(yyval.node)=NULL;}
#line 2374 "y.tab.c"
    break;

  case 100:
#line 350 "part3.y"
                                          {(yyval.node)=(yyvsp[-1].node);}
#line 2380 "y.tab.c"
    break;

  case 101:
#line 353 "part3.y"
                                 {(yyval.node)=makeNode("Call func",makeNode((yyvsp[-1].string),NULL,NULL),makeNode("ARGS",(yyvsp[0].node),NULL));}
#line 2386 "y.tab.c"
    break;


#line 2390 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
#line 355 "part3.y"




int main()
{
	FILE * f=fopen("out3AC.txt","w+");
	int x= yyparse();
	if(x==0)
	{
		//printf("syntax and Semantics are valid\n"); 
		Printtree(myroot);
		fprintf(f,"%s",myroot->code);
		// printf("%s",myroot->code);
	}
	fclose(f);
	return x;	
}
Arguments * callfuncargs(code * CODEscope,node *tree,int * count)
{
	Arguments *arr=NULL,ar[50];
	char* type,*len;
	while(tree!=NULL)
	{
		ar[(*count)++].type=exprtype(tree->left,CODEscope);
		if(tree->right!=NULL)
			tree=tree->right->left;
		else
			tree=NULL;
	}
	arr=(Arguments*)malloc(sizeof(Arguments)*(*count));
	for(int i=0;i<*count;i++)
		arr[i].type=ar[i].type;
	return arr;
}
char* findfunc(node * tree,code * CODEscope,int * countParams)
{
	code*temp=CODEscope;
	Arguments* args;
	int find=false,flag=true;
	while(temp!=NULL)
	{
		for(int i=0;i<temp->countfunc;i++)
			if(strcmp(tree->left->token,temp->func[i]->name)==0)
			{
				find=true;
				flag=true;
				int count=0;
				args=callfuncargs(CODEscope,tree->right->left,&count);
				if(count==temp->func[i]->countArgs)
				{
					for(int j=0,t=count-1;j<count;j++,t--)
				{
					//printf("%s %s %s",args[j].type,temp->func[i]->args[t].type, temp->func[i]->args[t].name);
					if(strcmp(args[j].type,temp->func[i]->args[t].type)!=0)
						flag=false;
					}
					if(flag==true)
					{	if(countParams!= NULL)
							*countParams = POPParams(args,count);
						return temp->func[i]->returnType;
					}	
				}
			}
		temp=temp->beforeLVL;
	}
	printf("ERORR,func %s not find call in scope %s in func/proc %s\n",tree->left->token,CODEscope->name,mycode->func[mycode->countfunc-1]->name);
	if(find==true)
		printf("but find func with same name but other args\n");
	exit(1);
}
char *findvar(node * tree,code * CODEscope)
{
	code*temp=CODEscope;
	while(temp!=NULL)
	{
		for(int i=0;i<temp->countvar;i++)
		if(strcmp(tree->token,temp->var[i].name)==0)
		{
			if(tree->left!=NULL && strcmp(tree->left->token,"[")==0)
			{
				if(strcmp(temp->var[i].type,"string")==0)
					if(strcmp(exprtype(tree->left->left,CODEscope),"int")==0)
						return "char";
					else
					{
						printf("ERORR, index in string can be only int (<string>[<int>])in scope %s in func/proc %s\n",CODEscope->name,mycode->func[mycode->countfunc-1]->name);
						exit(1);
					}
				else
				{
					printf("ERORR,you can use index only on string type (<string>[<int>]) in scope %s in func/proc %s\n",CODEscope->name,mycode->func[mycode->countfunc-1]->name);
					exit(1);
				}
			}
			else
				return temp->var[i].type;
		}
		temp=temp->beforeLVL;
	}
	printf("ERORR,var %s not find in scope %s in func/proc %s\n ",tree->token,CODEscope->name,mycode->func[mycode->countfunc-1]->name);
	exit(1);
}
char * exprtype(node * tree,code* CODEscope){
	char* msg=(char*)malloc(sizeof(char)*7);
	msg="";
	if(strcmp(tree->token,"null")==0)
		msg="NULL";
	else
	if(tree->left!=NULL){
		if(strcmp(tree->left->token,"INT")==0)
			msg= "int";
		if(strcmp(tree->left->token,"HEX")==0)
			msg= "hex";
		if(strcmp(tree->left->token,"CHAR")==0)
			msg= "char";
		if(strcmp(tree->left->token,"REAL")==0)
			msg= "real";
		if(strcmp(tree->left->token,"STRING")==0)
			msg= "string";
		if(strcmp(tree->left->token,"BOOLEAN")==0)
			msg= "boolean";
		if(strcmp(tree->token,"-")==0||strcmp(tree->token,"+")==0)
		{
			if((strcmp(exprtype(tree->left,CODEscope),"int")==0||strcmp(exprtype(tree->left,CODEscope),"real")==0)&&(strcmp(exprtype(tree->right,CODEscope),"int")==0||strcmp(exprtype(tree->right,CODEscope),"real")==0))
			{
				if(strcmp(exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope))==0&&strcmp(exprtype(tree->left,CODEscope),"int")==0)
					msg="int";
				else
					msg="real";
			}
			if(strcmp(exprtype(tree->left,CODEscope),"int")==0&&(strcmp(exprtype(tree->right,CODEscope),"char*")==0||strcmp(exprtype(tree->right,CODEscope),"int*")==0||strcmp(exprtype(tree->right,CODEscope),"real*")==0)){
				msg=exprtype(tree->right,CODEscope);
			}
			else if(strcmp(exprtype(tree->right,CODEscope),"int")==0&&(strcmp(exprtype(tree->left,CODEscope),"char*")==0||strcmp(exprtype(tree->left,CODEscope),"int*")==0||strcmp(exprtype(tree->left,CODEscope),"real*")==0)){
				msg=exprtype(tree->left,CODEscope);
			}
			else if(strcmp(msg,"")==0)
			{
				printf("ERORR, you cant do %s between %s and %s",tree->token,exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope));
				printf(" in func/proc %s\n",mycode->func[mycode->countfunc-1]->name);
				exit(1);
			}
		}
		if(strcmp(tree->token,"*")==0||strcmp(tree->token,"/")==0)
		{
			if((strcmp(exprtype(tree->left,CODEscope),"int")==0||strcmp(exprtype(tree->left,CODEscope),"real")==0)&&(strcmp(exprtype(tree->right,CODEscope),"int")==0||strcmp(exprtype(tree->right,CODEscope),"real")==0))
			{
				if(strcmp(exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope))==0&&strcmp(exprtype(tree->left,CODEscope),"int")==0)
					msg="int";
				else
					msg="real";
			}
			else
			{
				printf("ERORR, you cant do %s between %s and %s",tree->token,exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope));
				printf(" in func/proc %s\n",mycode->func[mycode->countfunc-1]->name);
				exit(1);
			}
		}
		if(strcmp(tree->token,"&&")==0||strcmp(tree->token,"||")==0)
		{
			if(strcmp(exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope))==0&&strcmp(exprtype(tree->right,CODEscope),"boolean")==0)
				msg="boolean";
			else{
				printf("ERORR, you cant do %s between %s and %s",tree->token,exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope));
				printf(" in func/proc %s\n",mycode->func[mycode->countfunc-1]->name);
				exit(1);
			}
		}
		if(strcmp(tree->token,">=")==0||strcmp(tree->token,">")==0||strcmp(tree->token,"<=")==0||strcmp(tree->token,"<")==0)
		{
			if((strcmp(exprtype(tree->left,CODEscope),"int")==0||strcmp(exprtype(tree->left,CODEscope),"real")==0)&&(strcmp(exprtype(tree->right,CODEscope),"int")==0||strcmp(exprtype(tree->right,CODEscope),"real")==0))
				msg="boolean";
			else{
				printf("ERORR, you cant do %s between %s and %s in func/proc %s\n",tree->token,exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope),mycode->func[mycode->countfunc-1]->name);
				exit(1);
			}
		}
				if(strcmp(tree->token,"==")==0||strcmp(tree->token,"!=")==0)
		{
			if(strcmp(exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope))==0 && strcmp(exprtype(tree->right,CODEscope),"string")!=0)
				msg="boolean";
			else{
				printf("ERORR, you cant do %s between %s and %s in func/proc %s\n",tree->token,exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope),mycode->func[mycode->countfunc-1]->name);
				exit(1);
			}
			
		}
		if(strcmp(tree->token,"|")==0){
			if(strcmp(exprtype(tree->left,CODEscope),"string")==0){
				msg="int";
			}
			else{
				printf("ERORR, you need to use string type in func/proc %s",mycode->func[mycode->countfunc-1]->name);
				exit(1);
			}
		}
		if(strcmp(tree->token,"!")==0){
			if(strcmp(exprtype(tree->left,CODEscope),"boolean")==0)
				msg="boolean";
			else{
			printf("ERORR, you need to use boolean type");
			exit(1);
			}
		}
		if(strcmp(tree->token,"&")==0)
		{
			if(strcmp(tree->left->token,"(")==0)
				msg=exprtype(tree->left->left,CODEscope);
			else
				msg=exprtype(tree->left,CODEscope);
			if(strcmp(msg,"char")==0)
				msg="char*";
			else if(strcmp(msg,"int")==0)
				msg="int*";
			else if(strcmp(msg,"real")==0)
				msg="real*";
			else
			{
				printf("ERORR, you cant do %s on %s \n",tree->token,msg);
				exit(1);
			}
		}
		if(strcmp(tree->token,"^")==0)
		{
			if(strcmp(tree->left->token,"(")==0)
				msg=exprtype(tree->left->left,CODEscope);
			else
				msg=exprtype(tree->left,CODEscope);
			
			if(strcmp(msg,"char*")==0)
				msg="char";
			else if(strcmp(msg,"int*")==0)
				msg="int";
			else if(strcmp(msg,"real*")==0)
				msg="real";
			else
			{
				printf("ERORR, you cant do %s on %s \n",tree->token,msg);
				exit(1);
			}
		}
		if(strcmp(tree->token,"(")==0)
			msg=exprtype(tree->left,CODEscope);
		if(strcmp(tree->token,"Call func")==0)
			msg=findfunc(tree,CODEscope,NULL);
	}
	if(strcmp(msg,"")==0)
		msg=findvar(tree,CODEscope);
	return msg;
}
void push(code* from,char* name)
{
	code * point;
	if(mycode==NULL)
		mycode=makeCode(name);
	else{
		point=mycode;
		while(point->nextLVL!=NULL)
			point=point->nextLVL;
		point->nextLVL=makeCode(name);
		point->nextLVL->beforeLVL=from;
	}
}
code* makeCode(char* name)
{	
	code *newlvl = (code*)malloc(sizeof(code));
	newlvl->place=++scope;
	newlvl->name=name;
	newlvl->var=NULL;
	newlvl->countvar=0;
	newlvl->func=NULL;
	newlvl->countfunc=0;
	newlvl->nextLVL=NULL;
	newlvl->beforeLVL=NULL;
	return newlvl;
}
void addvar(Arguments * args,int countvars,int isArg,code * CODEscope){
	if(countvars==0)
		return;
	Varaiable* temp;
	code * codey=CODEscope;
	for(int i=0;i<countvars;i++)
		for(int j=0;j<countvars;j++)
			if(i!=j && strcmp(args[j].name,args[i].name)==0 )
			{
				printf("sorry you can't some vars %s in one declear",args[i].name);
				code * t=codey->beforeLVL;
				while(t->beforeLVL!=NULL && t->beforeLVL->countfunc==0)
					t=t->beforeLVL;
				if(t->func!=NULL)
				printf(",in func %s\n",t->func[t->countfunc-1]->name);
					else
				printf("\n");
				exit(1);
			}
	if(codey->var==NULL)
		codey->var=(Varaiable*) malloc(sizeof(Varaiable)*countvars);
	else
	{
		temp=codey->var;
		codey->var=(Varaiable*) malloc(sizeof(Varaiable)*(codey->countvar+countvars));
		for(int i=0;i<codey->countvar;i++)
		{
			for(int j=0;j<countvars;j++)
			{
				if(strcmp(temp[i].name,args[j].name)==0 )
				{
					printf("sorry you can't some var %s in some scope",temp[i].name);
					code * t=codey->beforeLVL;
					while(t->beforeLVL!=NULL && t->beforeLVL->countfunc==0)
						t=t->beforeLVL;
					if(t->func!=NULL)
					printf(",in func %s\n",t->func[t->countfunc-1]->name);
					else
					printf("\n");
					exit(1);
				}
			}
			codey->var[i]=temp[i];	
		}
	}
	for(int j=0;j<countvars;j++)
	{
		codey->var[codey->countvar].name=args[j].name;
		codey->var[codey->countvar].value=NULL;
		codey->var[codey->countvar].isArg=isArg;
		codey->var[codey->countvar].len=args[j].len;
		codey->var[(codey->countvar)++].type=args[j].type;
	}
}
void addFunc(char * name,Arguments * args,node *returnType,int countArgs,code * CODEscope){
	Function** temp;
	code * codey=CODEscope;
	for(int i=0;i<countArgs;i++)
		for(int j=0;j<countArgs;j++)
			if(i!=j && strcmp(args[j].name,args[i].name)==0 )
			{
			printf("sorry you can't same Arguments %s in func %s\n",args[i].name,name);
			exit(1);
			}
	if(codey->func==NULL)
		codey->func=(Function**) malloc(sizeof(Function*));
	else
	{
		temp=codey->func;
		codey->func=(Function**) malloc(sizeof(Function*)*(codey->countfunc+1));
		for(int i=0;i<codey->countfunc;i++)
		{
				if(strcmp(temp[i]->name,name)==0 )
				{
					printf("sorry you can't same func %s in same scope \n",temp[i]->name);
					exit(1);
				}
				codey->func[i]=temp[i];
		}
	}
		codey->func[codey->countfunc]=(Function*) malloc(sizeof(Function));
		codey->func[codey->countfunc]->name=name;
		codey->func[codey->countfunc]->args=args;
		if(returnType==NULL)
			codey->func[codey->countfunc]->returnType=NULL;
		else
		{
			if(strcmp(returnType->token,"string")==0)
			{
				printf("ERORR,return type func %s cant be string\n",name);
				exit(1);
			}
			codey->func[codey->countfunc]->returnType=returnType->token;
		}
		codey->func[codey->countfunc]->countArgs=countArgs;
		codey->func[codey->countfunc]->findreturn=false;
		++(codey->countfunc); 
}
Arguments * makeArgs(node *tree,int *count){
	Arguments  *arr=NULL,ar[50];
	char* type,*len;
	if(tree!=NULL)
	{
		node * temp1=tree,*temp=tree;
		do{
			if(strcmp(temp1->token, "")==0)
			{
				temp=temp1->right->left;
				temp1=temp1->left;	
				if(strcmp(temp->token, "(")==0||strcmp(temp->token, "var")==0)
				{
				type=temp->left->token;
				if(temp->left->left!=NULL)
					len=temp->left->left->left->token;
					node * treee;
					treee=temp->right->left;
				do{
					ar[*count].name=treee->token;
					ar[*count].type=type;
					ar[*count].len=len;
					(*count)++;
				if(treee->left==NULL)
					treee=NULL;
				else
					treee=treee->left->left;
				} while(treee!=NULL);
			}
		}
		} while(strcmp(temp1->token, "(")!=0&&strcmp(temp->token, "var")!=0);
			temp=temp1;
			if(strcmp(temp->token, "(")==0||strcmp(temp->token, "var")==0)
			{
				type=temp->left->token;
				node * treee;
				if(strcmp(temp->token, "var")==0)
				treee=temp->right;
				else
				treee=temp->right->left;
				if(temp->left->left!=NULL)
				len=temp->left->left->left->token;
				do{
					ar[*count].name=treee->token;
					ar[*count].type=type;
					ar[*count].len=len;
					(*count)++;
					if(treee->left==NULL)
						treee=NULL;
					else
						treee=treee->left->left;
				} while(treee!=NULL);
			}
			arr=(Arguments*)malloc(sizeof(Arguments)*(*count));
			for(int i=0;i<*count;i++)
			{
				arr[i].name=ar[i].name;
				arr[i].type=ar[i].type;
			}
	}
	return arr;
}
node* makeNode (char *token, node *left, node *right)
{
	node *newnode = (node*)malloc(sizeof(node));
	newnode->left=left;
	newnode->right=right;
	newnode->token=token;
	newnode->code=NULL;
	newnode->var=NULL;
	newnode->label=NULL;
	newnode->truelabel=NULL;
	newnode->falselabel=NULL;
	newnode->sum=0;
	return newnode;
}
void printTabs(int n)
{
	for(int i=0;i<n/9;i++)
		printf("   ");
}
void Printtree(node* tree)
{
	int flag = 4;
	printTabs(printlevel); 
	if(strcmp(tree->token, "var") == 0){
		printf("(DECLARE ");
		flag=2;	
	} else if(strcmp(tree->token, "if") == 0){
		printf("(IF\n");
		flag = 1;
	} else if(strcmp(tree->token, "while") == 0){
		printf("(WHILE\n");
		flag = 1;	
	} else if(strcmp(tree->token, "for") == 0){
		printf("(FOR\n");
		flag = 1;	
	} else if(strcmp(tree->token, "func") == 0){
		printf("(%s \n\t",tree->token);
		flag= 2;
        } else if(strcmp(tree->token, "Call func") == 0){
		printf("(%s \n",tree->token);
		flag= 1;	
	} else if(strcmp(tree->token, "CODE") == 0){
		printf("(%s \n",tree->token);
		flag= 2;
	} else if(strcmp(tree->token, "BODY") == 0){
		if(tree->left)
			printf("(%s \n",tree->token);
		else
			flag =1;
        } else if(strcmp(tree->token, "ARGS") == 0){
		printf("(ARGS ");
		if(tree->left)
		{
			flag = 2;
			printf("\n\t");
		}
		else
			printf(" NONE)\n"); 
	} else if(strcmp(tree->token, "if-else") == 0){
		printf("\n(IF-ELSE ");
		flag = 2;
	} else if(strcmp(tree->token, "return") == 0){
		printf("(RET ");
		flag = 2;   
	} else if(strcmp(tree->token, "{") == 0)
                printf("(BLOCK\n");
	else if(strcmp(tree->token, "}") == 0)
                flag =2;           
        else if(strcmp(tree->token, "") == 0||strcmp(tree->token, "BOOLEAN") == 0||strcmp(tree->token, "STRING") == 0||strcmp(tree->token, "REAL") == 0||strcmp(tree->token, "CHAR") == 0||strcmp(tree->token, "INT") == 0||strcmp(tree->token, "HEX") == 0);
	else if(strcmp(tree->token, "(") == 0)
		printf("(");
	else if(strcmp(tree->token, "\n") == 0)
		printf("\n");
	else if(strcmp(tree->token, ")") == 0)
		printf(")\n");
	else if(strcmp(tree->token, ",") == 0)
		printf(",");
	else if(strcmp(tree->token, ";") == 0)
		printf("\n");
	else if(strcmp(tree->token, "&&") == 0 ||
		strcmp(tree->token, "/") == 0 || 
		strcmp(tree->token, "=") == 0 || 
		strcmp(tree->token, "==") == 0 || 
		strcmp(tree->token, ">") == 0 || 
		strcmp(tree->token, ">=") == 0 || 
		strcmp(tree->token, "<") == 0 || 
		strcmp(tree->token, "<=") == 0 || 
		strcmp(tree->token, "-") == 0 || 
		strcmp(tree->token, "!") == 0 || 
		strcmp(tree->token, "!=") == 0 || 
		strcmp(tree->token, "||") == 0 || 
		strcmp(tree->token, "+") == 0 || 
		strcmp(tree->token, "*") == 0 || 
		strcmp(tree->token, "&") == 0 || 
		strcmp(tree->token, "|") == 0 || 
		strcmp(tree->token, ",") == 0 ){
			printf("(%s",tree->token);
			flag=2;
			if(strcmp(tree->token, "=") == 0)
				flag=1;	
	} else if(strcmp(tree->token, "^") == 0 ){
			printf("(*");
			flag=2;
	}else if(strcmp(tree->token, "procedures") == 0 || strcmp(tree->token, "stmnts") == 0|| strcmp(tree->token, "Return") == 0|| strcmp(tree->token, "expr_list") == 0){
			printf(" ");
	}
	else {
		if(tree && (!tree->left && !tree->right)||strcmp(tree->token, "main") == 0)
			printf("%s ", tree->token);
		else
            printf("%s", tree->token);
	}
	if (tree->left){
		printlevel++;
		Printtree(tree->left);
		printlevel--;
	}
	if (tree->right) {
		printlevel++;
		Printtree(tree->right);
		printlevel--;
	}
	if(flag == 2)
		printf(")\n");
	if(flag == 1)
		printf(")");
	if(flag == 0)
		printf("\n)");
}
int yyerror(char *e)
{
	int yydebug=1; 
	fflush(stdout);
	fprintf(stderr,"Error %s at line %d\n" ,e,yylineno);
	fprintf(stderr, "does not accept '%s'\n",yytext);
	return 0;
}
code* lastCode(code * codey)
{
	code * CODEscope=codey;
	if(CODEscope!=NULL)
	while(CODEscope->nextLVL!=NULL)
		CODEscope=CODEscope->nextLVL;
	return CODEscope;
}
void CheckSyntax(node *tree,code * CODEscope)
{
	if(tree){
		if(strcmp(tree->token, "CODE") == 0)
		{
			push(NULL,tree->token);
			if (tree->left) 
				CheckSyntax(tree->left,mycode);
			if (tree->right)
				CheckSyntax(tree->right,mycode);
			scope--;
			return;
		}
		
		if(strcmp(tree->token,"main")==0)
		{
			if(flagMain==true && strcmp(CODEscope->name,"CODE")==0)
			{
				printf("main needs to be one and only\n");
				exit(1);
			}
			flagMain=true;
			if(tree->left)
				addFunc(tree->token,NULL,tree->left->left,0,CODEscope);
			else		
				addFunc(tree->token,NULL,NULL,0,CODEscope);
		
			push(CODEscope,tree->token);
			if (tree->left) 
				CheckSyntax(tree->left,lastCode( CODEscope->nextLVL));
			if (tree->right)
				CheckSyntax(tree->right,lastCode( CODEscope->nextLVL));
			scope--;
			return;
		}

		if(strcmp(tree->token, "func") == 0 )
		{
			int count=0;
			Arguments * arg=makeArgs(tree->left->left->left,&count);
			if (tree->left->right)
				addFunc(tree->left->token,arg,tree->left->right->left,count,CODEscope);
			else
				addFunc(tree->left->token,arg,NULL,count,CODEscope);
			push(CODEscope,tree->token);
			addvar(arg,count,1,lastCode(CODEscope));
			if (tree->left) 
				CheckSyntax(tree->left,lastCode( CODEscope->nextLVL));
			if (tree->right)
				CheckSyntax(tree->right,lastCode( CODEscope->nextLVL));
			scope--;		
			return;
		}



		if(strcmp(tree->token, "=") == 0)
		{
			if(!(strcmp(exprtype(tree->right,CODEscope),"NULL")==0&& (strcmp(exprtype(tree->left,CODEscope),"real*")==0||strcmp(exprtype(tree->left,CODEscope),"int*")==0||strcmp(exprtype(tree->left,CODEscope),"char*")==0)))
				if(strcmp(exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope))!=0)
				{
					printf("ERORR, can't do = between %s and %s\n",exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope));
					exit(1);
				}
		}

		else if(strcmp(tree->token, "var") == 0)
		{
			int countvar=0;
			Arguments * var=makeArgs(tree,&countvar);
			addvar(var,countvar,0,CODEscope);
		}
		else if(strcmp(tree->token, "Call func") == 0)
		{
			int count=0;
			findfunc(tree,CODEscope,&count);
			tree->sum=count;
		}

	if(strcmp(tree->token, "for") == 0){
		if(strcmp(exprtype(tree->left->left->right,CODEscope),"boolean")!=0)
		{
			printf("ERORR, in for expr most be type boolean\n");
			exit(1);
		}
		CheckSyntax(tree->left->left->left,CODEscope);
		CheckSyntax(tree->left->right->left,CODEscope);
		if(strcmp(tree->right->token,"{")!=0)
		{
			push(CODEscope,tree->token);
			if (tree->left) 
				CheckSyntax(tree->left,lastCode( CODEscope->nextLVL));
			if (tree->right)
				CheckSyntax(tree->right,lastCode( CODEscope->nextLVL));
			scope--;
			return;
		}}


	if(strcmp(tree->token, "while") == 0) {
		if(strcmp(exprtype(tree->left->left,CODEscope),"boolean")!=0)
		{
			printf("ERORR, in %s expr most be type boolean\n",tree->token);
			exit(1);
		}
		if(strcmp(tree->right->token,"{")!=0)
		{
			push(CODEscope,tree->token);
			if (tree->left) 
				CheckSyntax(tree->left,lastCode( CODEscope->nextLVL));
			if (tree->right)
				CheckSyntax(tree->right,lastCode( CODEscope->nextLVL));
			scope--;
			return;
		}
	}


	if(strcmp(tree->token, "do") == 0) {
		if(strcmp(exprtype(tree->left->left,CODEscope),"boolean")!=0)
		{
			printf("ERORR, in %s expr most be type boolean\n",tree->token);
			exit(1);
		}
		if(strcmp(tree->right->token,"{")!=0)
		{
			push(CODEscope,tree->token);
			if (tree->left) 
				CheckSyntax(tree->left,lastCode( CODEscope->nextLVL));
			if (tree->right)
				CheckSyntax(tree->right,lastCode( CODEscope->nextLVL));
			scope--;
			return;
		}
	}
	if(strcmp(tree->token, "if") == 0 )
	{
		if(strcmp(exprtype(tree->left->left,CODEscope),"boolean")!=0)
		{
			printf("ERORR, in if expr most be type boolean\n");
			exit(1);
		}

		if(strcmp(tree->right->token,"{")!=0)
		{
			push(CODEscope,tree->token);
			if (tree->left) 
				CheckSyntax(tree->left,lastCode( CODEscope->nextLVL));
			if (tree->right)
				CheckSyntax(tree->right,lastCode( CODEscope->nextLVL));
		scope--;
			return;
		}


	}

	if(strcmp(tree->token,"if-else") == 0)
	{
		if(strcmp(exprtype(tree->left->left,CODEscope),"boolean")!=0)
		{
			printf("ERORR, in if expr most be type boolean\n");
			exit(1);
		}
		if(strcmp(tree->right->left->token,"{")!=0)
			{
				push(CODEscope,tree->token);
				if(tree->right)
					CheckSyntax(tree->right->left,lastCode( CODEscope->nextLVL));
				scope--;
				push(CODEscope,tree->token);
				if(tree->right->right)
					CheckSyntax(tree->right->right->left,lastCode( CODEscope->nextLVL));
				scope--;
				return;
			}
	
	}
	if(strcmp(tree->token, "return") == 0)
	{
		code * temp= CODEscope;
		int flag=true;
		while(strcmp(temp->name,"func")!=0 && strcmp(temp->name,"main")!=0 && strcmp(temp->name,"CODE")!=0)
		{
			temp=temp->beforeLVL;
			flag=false;
		}
		if(flag==false)
		{
			if(strcmp(exprtype(tree->left,CODEscope),temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->returnType))
			{
				printf("ERORR,wrong type of return in func %s \n",temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->name);
				printf("%s ,%s %s\n",exprtype(tree->left,CODEscope),temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->returnType,temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->name);
				exit(1);
			}
		}
		else{
			if(temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->returnType!=NULL){
				if(strcmp(exprtype(tree->left,CODEscope),temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->returnType)==0){
					temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->findreturn=true;
				}
				else{
					printf("ERORR,invalid return type in func %s \n",temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->name);
					exit(1);
				}
			}
			else
			{
				printf("ERORR,return cant be in proc %s\n",temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->name);
				exit(1);
			}  
		}
	}else if(strcmp(tree->token, "{") == 0)
	{
		push(CODEscope,tree->token);
		if (tree->left) 
			CheckSyntax(tree->left,lastCode( CODEscope->nextLVL));
		if (tree->right)
			CheckSyntax(tree->right,lastCode( CODEscope->nextLVL));
			scope--;
		return;			
	}
	if (tree->left) 
		CheckSyntax(tree->left,CODEscope);
	if (tree->right)
		CheckSyntax(tree->right,CODEscope);
}
}


int POPParams(Arguments * args,int count){
	int size=0;
	for(int i =0;i<count;i++)
	{
		if(strcmp(args[i].type,"int")==0)
			size += 4;
		else if(strcmp(args[i].type,"char")==0)
			size += 1;
		else if(strcmp(args[i].type,"real")==0)
			size += 8;
		else if(strcmp(args[i].type,"string")==0)
			size += atoi(args[i].len);
		else if(strcmp(args[i].type,"boolean")==0)
			size += 4;
		else if(strcmp(args[i].type,"int*")==0)
			size += 4;
		else if(strcmp(args[i].type,"char*")==0)
			size += 4;
		else if(strcmp(args[i].type,"real*")==0)
			size += 4;
	}
	return size;
}

void addCode(node* node,char *code,char *var,char *label,char *truelabel,char *falselabel)
	{
		if(code!=NULL){
		node->code=(char*)malloc(sizeof(char)*(1+strlen(code)));
		strcpy(node->code,code);
		}
		else if(node->code==NULL)
		{
		node->code=(char*)malloc(sizeof(char)*2);
		strcpy(node->code,"");
		}
		if(var!=NULL){
		node->var=(char*)malloc(sizeof(char)*(1+strlen(var)));
		strcpy(node->var,var);
		}
		else if(node->var==NULL)
		{
		node->var=(char*)malloc(sizeof(char)*2);
		strcpy(node->var,"");
		}
		if(label!=NULL&& node->label==NULL){
		node->label=(char*)malloc(sizeof(char)*(1+strlen(label)));
		strcpy(node->label,label);
		}
		if(truelabel!=NULL && node->truelabel==NULL){
		node->truelabel=(char*)malloc(sizeof(char)*(1+strlen(truelabel)));
		strcpy(node->truelabel,truelabel);
		}
		if(falselabel!=NULL && node->falselabel==NULL){
		node->falselabel=(char*)malloc(sizeof(char)*(1+strlen(falselabel)));
		strcpy(node->falselabel,falselabel);
		}

	}



void addCode2(node* node,char *code,char *var,char *label,char *truelabel,char *falselabel)
	{
		if(code!=NULL){
		node->code=(char*)malloc(sizeof(char)*(1+strlen(code)));
		strcpy(node->code,code);
		}
		else if(node->code==NULL)
		{
		node->code=(char*)malloc(sizeof(char)*2);
		strcpy(node->code,"");
		}

		if(var!=NULL){
		node->var=(char*)malloc(sizeof(char)*(1+strlen(var)));
		strcpy(node->var,var);
		}
		else if(node->var==NULL)
		{
		node->var=(char*)malloc(sizeof(char)*2);
		strcpy(node->var,"");
		}

		if(label!=NULL){
		node->label=(char*)malloc(sizeof(char)*(1+strlen(label)));
		strcpy(node->label,label);
		}

		if(truelabel!=NULL){
		node->truelabel=(char*)malloc(sizeof(char)*(1+strlen(truelabel)));
		strcpy(node->truelabel,truelabel);
		}
		
		if(falselabel!=NULL && node->falselabel==NULL){
		node->falselabel=(char*)malloc(sizeof(char)*(1+strlen(falselabel)));
		strcpy(node->falselabel,falselabel);
		}

	}
char* freshVar()
	{
		char* x;
		asprintf(&x,"t%d",t++);
		return x;
	}
char* freshLabel()
	{
		char* x;
		asprintf(&x,"L%d",l++);
		return x;
	}
char* gen(char*s1,char*s2,char*s3,char*s4,char*s5)
	{
		char* x;
		asprintf(&x,"%s %s %s %s %s\n",s1,s2,s3,s4,s5);
		return x;
	}
	
char* mystrcat(char*des,char*src){
		char* tamp=des;
		char* num;
		asprintf(&num,"%d ",line++);
		if(src!=NULL){
			if(des==NULL){
				des=(char*)malloc((strlen(src)+1)*sizeof(char));
				strcpy(des,src);
				return des;
			}
		des=(char*)malloc((strlen(des)+strlen(src)+1+strlen(num))*sizeof(char));
		if(tamp!=NULL){
		strcat(des,tamp);
		}
		if(src!=NULL)
		{
		strcat(des,src);
		}
		}
		return des;
	}
char *replaceWord(const char *s, const char *oldW, const char *newW) 
{ 
    char *result; 
    int i, cnt = 0; 
    int newWlen = strlen(newW); 
    int oldWlen = strlen(oldW); 
  
    // Counting the number of times old word 
    // occur in the string 
    for (i = 0; s[i] != '\0'; i++) 
    { 
        if (strstr(&s[i], oldW) == &s[i]) 
        { 
            cnt++; 
  
            // Jumping to index after the old word. 
            i += oldWlen - 1; 
        } 
    } 
  
    // Making new string of enough length 
    result = (char *)malloc(i + cnt * (newWlen - oldWlen) + 1); 
  
    i = 0; 
    while (*s) 
    { 
        // compare the substring with the result 
        if (strstr(s, oldW) == s) 
        { 
            strcpy(&result[i], newW); 
            i += newWlen; 
            s += oldWlen; 
        } 
        else
            result[i++] = *s++; 
    } 
  
    result[i] = '\0'; 
    return result; 
} 

 
char * mkspace(char *label)
{
	char * msg;
	char x=' ';
	int len = strlen(mystrcat(label,"\0"));
	if(label==NULL || !strcmp(label,""))
		msg="";
	else
		{
		asprintf(&msg,"%c",x);
		while(len<5){
			asprintf(&msg,"%c%s",x,msg);
			len++;
		}
		asprintf(&label,"%s: ",mystrcat(label,"\0"));
		msg=mystrcat(msg,label);
		}
		return msg;
}


void calc3AC(node * tree)
{ 
	
	
	if(strcmp(tree->token, "=") == 0 )
	{ if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
	   addCode(tree,mystrcat(tree->right->code,gen(tree->left->var,"=",tree->right->var,"","")),NULL,NULL,NULL,NULL); 
	   return;  
	}
	else if(strcmp(tree->token, "if") == 0)
	{ 
		if(tree->left->left)
		addCode(tree->left->left,NULL,NULL,NULL,NULL,tree->label);
		if(tree->right)
		addCode2(tree->right,NULL,NULL,tree->label,NULL,NULL);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		addCode(tree,mystrcat(tree->left->left->code,mystrcat(mkspace(tree->left->left->label),mystrcat(mkspace(tree->left->left->truelabel),mystrcat(tree->right->code,mkspace(tree->truelabel))))),NULL,NULL,NULL,NULL);
		return;
	}
else if(strcmp(tree->token, "if-else") == 0)
	{ 
		if(tree->right->left)
		addCode(tree->right->left,NULL,NULL,tree->label,NULL,NULL);			
		if(tree->right->right->left)
		addCode2(tree->right->right->left,NULL,NULL,tree->label,NULL,tree->label);
		if(tree->right->left)
		addCode2(tree->right->left,NULL,NULL,tree->label,NULL,tree->label);
		
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		addCode(tree,mystrcat(mystrcat(tree->left->left->code,mystrcat(mkspace(tree->left->left->truelabel),tree->right->left->code))
		,mystrcat(mystrcat("goto ",mystrcat(mystrcat(tree->label,"\n"),mystrcat(mkspace(tree->left->left->falselabel),tree->right->right->left->code))),mkspace(tree->label))),NULL,NULL,NULL,NULL);
	return;
	}
	else if(strcmp(tree->token, "while") == 0)
	{ 
		if(tree->left->left)
			addCode(tree->left->left,NULL,NULL,NULL,tree->falselabel,tree->label);
		if(tree->right)
			addCode2(tree->right,NULL,NULL,tree->label,NULL,NULL);
		
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
			
			addCode(tree,mystrcat(mystrcat(mystrcat( mkspace(tree->truelabel),tree->left->left->code),mkspace(tree->falselabel)),
				mystrcat(tree->right->code,mystrcat(mystrcat("\tgoto ",mystrcat(tree->truelabel,"\n")),mkspace(tree->label)))),NULL,NULL,NULL,NULL);
		return ;
	}
		else if(strcmp(tree->token, "do") == 0)
	{ 

		if(tree->left->left)
			addCode(tree->left->left,NULL,NULL,NULL,tree->truelabel,NULL);
		if(tree->right)
			addCode2(tree->right,NULL,NULL,NULL,NULL,NULL);
		
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
			
			addCode(tree,mystrcat( mkspace(tree->truelabel),
				mystrcat(tree->right->code,mkspace(mystrcat("\t",tree->left->left->code)))),NULL,NULL,NULL,NULL);
		return ;
	}
	else if(strcmp(tree->token, "stmnts") == 0)
	{ 
		
		if(tree->right!=NULL)
			if(strcmp(tree->right->token, "for") == 0||strcmp(tree->right->token, "if-else") == 0||strcmp(tree->right->token, "while") == 0)
				addCode2(tree->right,NULL,NULL,tree->label,NULL,NULL);
        if(tree->right!=NULL && tree->left!=NULL)
        if(strcmp(tree->left->right->token, "if") == 0||strcmp(tree->left->right->token, "for") == 0||strcmp(tree->left->right->token, "if-else") == 0||strcmp(tree->left->right->token, "while") == 0)
				addCode2(tree->right,NULL,NULL,NULL,tree->left->right->label,NULL);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);

			if(tree->right!=NULL && tree->left!=NULL)
                if((strcmp(tree->right->token, "while") == 0||strcmp(tree->right->token, "for") == 0||strcmp(tree->right->token, "if-else") == 0)&&(strcmp(tree->left->right->token, "if") == 0||strcmp(tree->left->right->token, "for") == 0||strcmp(tree->left->right->token, "if-else") == 0||strcmp(tree->left->right->token, "while") == 0))
                    addCode(tree,mystrcat(tree->left->code,&tree->right->code[8]),NULL,NULL,NULL,NULL);
                    else
					addCode(tree,mystrcat(tree->left->code,tree->right->code),NULL,NULL,NULL,NULL);
			else if(tree->right!=NULL)
            {
                if(strcmp(tree->right->token, "for") == 0||strcmp(tree->right->token, "if-else") == 0||strcmp(tree->right->token, "while") == 0)
                    addCode(tree,tree->right->code,NULL,NULL,NULL,NULL);
                    else        
				    addCode(tree,mystrcat(tree->right->code ,mkspace(tree->right->label)),NULL,NULL,NULL,NULL);
            }else
				addCode(tree,"",NULL,NULL,NULL,NULL);
			
	return;
		
	}
	else if(strcmp(tree->token, "for") == 0)
	{ 
		if(tree->left->left->right)
			addCode(tree->left->left->right,NULL,NULL,NULL,tree->falselabel,tree->label);
		if(tree->right)
			addCode2(tree->right,NULL,NULL,tree->label,NULL,NULL);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
					addCode(tree,	
		mystrcat(mystrcat(mystrcat(tree->left->left->left->code, mkspace(tree->truelabel)),tree->left->left->right->code),
		mystrcat(mystrcat(mystrcat(mkspace(tree->falselabel),tree->right->code),tree->left->right->left->code),mystrcat("\tgoto ",mystrcat(tree->truelabel,mystrcat("\n",mkspace(tree->label)))))),NULL,NULL,NULL,NULL);
	}
    
	else if(strcmp(tree->token, "func") == 0)
	{
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		char*x; asprintf(&x," %s:\n",tree->left->token);addCode(tree,mystrcat(x,tree->right->code),NULL,NULL,NULL,NULL);
		
		return;
	}
		else if(strcmp(tree->token, "expr_list") == 0)
	{
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
			if(tree->right==NULL)
				addCode(tree,mystrcat(tree->left->code,mystrcat("PushParam ",mystrcat(tree->left->var,"\n"))),NULL,NULL,NULL,NULL);
			else
				addCode(tree,mystrcat(mystrcat(tree->left->code,mystrcat("PushParam ",mystrcat(tree->left->var,"\n"))),tree->right->left->code),NULL,NULL,NULL,NULL);
	}	
	else if(strcmp(tree->token, "Call func") == 0)
	{ 

		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		char * x,*parm=(char*)malloc(sizeof(char));
		if(tree->right->left==NULL)
			strcpy(parm,"");
		else
			parm=tree->right->left->code;
		addCode(tree,NULL,freshVar(),NULL,NULL,NULL);
		asprintf(&x,"%s%s = LCALL %s\n‪\tPopParams %d‬‬‬‬\n",parm,tree->var,tree->left->token,tree->sum);
		addCode(tree,x,NULL,NULL,NULL,NULL);
		return;
	}
	else if(strcmp(tree->token, "CODE") == 0)
	{ if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		 if(tree->left)
			addCode(tree,mystrcat(tree->left->code,tree->right->code),NULL,NULL,NULL,NULL);
		else
			addCode(tree,tree->right->code,NULL,NULL,NULL,NULL);
		tree->code=replaceWord(tree->code, "\n\n", "\n") ;
		char x='a',*y,*z;

		while (x<='z')
		{
			asprintf(&y,"\n%c",x);
			asprintf(&z,"\n\t%c",x);
			tree->code=replaceWord(tree->code, y, z) ;
			x++;
		}
		x='A';
				while (x<='Z')
		{
			asprintf(&y,"\n%c",x);
			asprintf(&z,"\n\t%c",x);
			tree->code=replaceWord(tree->code, y, z) ;
			x++;
		}
		return;
	}
    else if(strcmp(tree->token, "BODY") == 0)
	{ 
		
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		if(tree->right->right->left){
		
			if(tree->right->right->left->code[strlen(mystrcat(tree->right->right->left->code,"\0"))-2]==':')
				addCode(tree,mystrcat(mystrcat("\tBeginFunc‬‬\n",tree->right->right->left->code),"EndFunc\n"),NULL,NULL,NULL,NULL);
			else
				addCode(tree,mystrcat(mystrcat("\tBeginFunc‬‬\n",tree->right->right->left->code),"\tEndFunc\n"),NULL,NULL,NULL,NULL);
		}
		else
			 addCode(tree,mystrcat("\tBeginFunc‬‬\n","\tEndFunc\n"),NULL,NULL,NULL,NULL);
		
		return;
	}
    else if(strcmp(tree->token, "main") == 0)
	{ 
		 
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		
		addCode(tree,mystrcat(" main:\n",tree->right->code),NULL,NULL,NULL,NULL);
          return;   
    } 
	else if(strcmp(tree->token, "procedures") == 0)
	{ if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		if(tree->left!=NULL) addCode(tree,mystrcat(tree->left->code,tree->right->code),NULL,NULL,NULL,NULL);
		else addCode(tree,tree->right->code,NULL,NULL,NULL,NULL);
    return;
	}        
	else if(strcmp(tree->token, "return") == 0)
	{
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		addCode(tree,mystrcat(tree->left->code,gen("return",tree->left->var,"","","")),NULL,NULL,NULL,NULL);
		return;
	}
	else if(strcmp(tree->token, "{") == 0)
	{ 
		if(tree->right->right->left) addCode(tree,NULL,NULL,tree->right->right->left->label,tree->right->right->left->truelabel,tree->right->right->left->falselabel); 
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		if(tree->right->right->left) addCode(tree,tree->right->right->left->code,tree->right->right->left->var,NULL,NULL,NULL); 
		return;			
	}
	else if(strcmp(tree->token, "}") == 0)
	{ if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
                      
                      
    }
	else if(strcmp(tree->token, "assmnt_stmnt") == 0)
	{ if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
                     addCode(tree,tree->left->code,tree->left->var,tree->left->label,tree->left->truelabel,tree->left->falselabel); 
					 return;
                      
    }
	
    else if(strcmp(tree->token, "+") == 0 || 
            strcmp(tree->token, "*") == 0 || 
            strcmp(tree->token, "-") == 0 || 
            strcmp(tree->token, "/") == 0 )
	{ 
		
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		addCode(tree,NULL,freshVar(),NULL,NULL,NULL);
		addCode(tree,mystrcat(mystrcat(tree->left->code,tree->right->code),gen(tree->var,"=",tree->left->var,tree->token,tree->right->var)),NULL,NULL,NULL,NULL);
    return;}
    
	else if(strcmp(tree->token, "&") == 0)
	{ 
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
				if((tree->left->left == NULL))
				addCode(tree,"",mystrcat("&",(tree->left->token)),NULL,NULL,NULL);
			else if(strcmp(tree->left->left->token,"[")==0)
					{
						char *x,*fv1,*fv2;
						asprintf(&fv1,"%s",freshVar()); 
						asprintf(&fv2,"%s",freshVar());
						asprintf(&x,"\t%s = &%s\n\t%s = %s + %s\n",fv1,tree->left->token,fv2,fv1,tree->left->left->left->var);
						addCode(tree,mystrcat(tree->left->left->left->code,x),fv2,NULL,NULL,NULL);
					}
				else if (tree->left->left->left==NULL)
				addCode(tree,"",mystrcat("&",(tree->left->left->token)),NULL,NULL,NULL);
			else
			{
				char *x,*fv1,*fv2;
				asprintf(&fv1,"%s",freshVar());
				asprintf(&fv2,"%s",freshVar()); 
				asprintf(&x,"\t%s = &%s\n\t%s = %s + %s\n",fv1,tree->left->left->token,fv2,fv1,tree->left->left->left->left->var); 
				addCode(tree,mystrcat(tree->left->left->left->left->code,x),fv2,NULL,NULL,NULL);
			}
			
			

	return;}
	else if(strcmp(tree->token, "^") == 0 )
	{ 
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
			if((tree->left->left == NULL))
				addCode(tree,"",mystrcat("*",(tree->left->token)),NULL,NULL,NULL);
			else
			{
				addCode(tree,"",mystrcat("*",(tree->left->left->token)),NULL,NULL,NULL);
			}
			
	return;}
	else if(strcmp(tree->token, "==") == 0 || 
			strcmp(tree->token, ">") == 0 || 
			strcmp(tree->token, ">=") == 0 || 
			strcmp(tree->token, "<") == 0 || 
			strcmp(tree->token, "<=") == 0 || 
			strcmp(tree->token, "!=") == 0) 
	{ 

		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
				addCode(tree,mystrcat(mystrcat(tree->left->code,tree->right->code),mystrcat(gen("if",tree->left->var,tree->token,tree->right->var,mystrcat("goto ",mystrcat(tree->truelabel,"\n")))
				,mystrcat("\tgoto ",mystrcat(tree->falselabel,"\n")))),NULL,NULL,NULL,NULL);

				
	return;}
	else if(strcmp(tree->token, "(") == 0)
	{
			addCode(tree->left,NULL,NULL,NULL,tree->truelabel,tree->falselabel);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		addCode(tree,tree->left->code,tree->left->var,NULL,NULL,NULL);
	return;}
	else if(strcmp(tree->token, "!") == 0)
	{ 
		addCode(tree->left,NULL,NULL,NULL,tree->truelabel,tree->falselabel);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
				
		 addCode(tree,tree->left->code,NULL,NULL,NULL,NULL);
		
	return;}
	else if(strcmp(tree->token, "||") == 0) 
	{
		addCode(tree->left,NULL,NULL,NULL,tree->truelabel,NULL);
		addCode(tree->right,NULL,NULL,NULL,tree->truelabel,tree->falselabel);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		addCode(tree,mystrcat(tree->left->code,mystrcat(mkspace(tree->left->falselabel),tree->right->code)),NULL,NULL,NULL,NULL);
	return;}
	else if(strcmp(tree->token, "&&") == 0 )
	{
		
		addCode(tree->left,NULL,NULL,NULL,NULL,tree->falselabel);
		addCode(tree->right,NULL,NULL,NULL,tree->truelabel,tree->falselabel);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
			addCode(tree,mystrcat(tree->left->code,mystrcat(mkspace(tree->left->truelabel),tree->right->code)),NULL,NULL,NULL,NULL);
	return;}
	else if(strcmp(tree->token, "null") == 0 )
	{ 
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		addCode(tree,"",tree->token,NULL,NULL,NULL);
	return;}	
	else if(strcmp(tree->token, "solovar") == 0 )
	{ 
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
			if(tree->left->left==NULL)
				addCode(tree,"",tree->left->token,NULL,NULL,NULL);
			else
			{
				char *x,*fv1,*fv2; asprintf(&fv1,"%s",freshVar()); asprintf(&fv2,"%s",freshVar()); asprintf(&x,"\t%s = &%s\n\t%s = %s + %s\n",fv1,tree->left->token,fv2,fv1,tree->left->left->left->var); addCode(tree,mystrcat(tree->left->left->left->code,x),mystrcat("*",fv2),NULL,NULL,NULL);
			}
			
	return;}
	else if((tree->left!=NULL)&&
			(strcmp(tree->left->token,"INT")==0||
			strcmp(tree->left->token,"HEX")==0||
			strcmp(tree->left->token,"CHAR")==0||
			strcmp(tree->left->token,"REAL")==0||
			strcmp(tree->left->token,"STRING")==0||
			strcmp(tree->left->token,"BOOLEAN")==0))
			{

			if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
			if(strcmp(tree->left->token,"STRING")==0)
			addCode(tree,"",tree->token,NULL,NULL,NULL);
			else
			if(strcmp(tree->left->token,"BOOLEAN")==0)
			{
			if(strcmp(tree->token,"true")==0 && tree->truelabel!=NULL)	
			addCode(tree,mystrcat("goto ",mystrcat(tree->truelabel,"\n")),tree->token,NULL,NULL,NULL);
			else if(strcmp(tree->token,"false")==0 && tree->falselabel!=NULL)
			addCode(tree,mystrcat("goto ",mystrcat(tree->falselabel,"\n")),tree->token,NULL,NULL,NULL);
			else
			addCode(tree,tree->token,tree->token,NULL,NULL,NULL);
			}
			else
			addCode(tree,"",tree->token,NULL,NULL,NULL);
			return;}
	else if(strcmp(tree->token, "") == 0||strcmp(tree->token, " ") == 0)
	{
		
		if(tree->left)
		//if(tree->left->label==NULL&&tree->left->truelabel&&tree->left->falselabel==NULL)
		addCode(tree->left,NULL,NULL,tree->label,tree->truelabel,tree->falselabel);
		if(tree->right)
			//if(tree->right->label==NULL&&tree->right->truelabel&&tree->right->falselabel==NULL)
		addCode(tree->right,NULL,NULL,tree->label,tree->truelabel,tree->falselabel);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		if(tree->left && tree->right)
			addCode(tree,mystrcat(tree->left->code,tree->right->code),tree->right->var,NULL,NULL,NULL);
		else if(tree->left)
			addCode(tree,tree->left->code,tree->left->var,NULL,NULL,NULL);	
		else if(tree->right)
			addCode(tree,tree->right->code,tree->right->var,NULL,NULL,NULL);	
	return;
	}
	else
	{
	if (tree->left) 
		calc3AC(tree->left);
	
	if (tree->right)
		calc3AC(tree->right);
addCode(tree,"",tree->token,NULL,NULL,NULL);
	return;}
	if (tree->left) 
		calc3AC(tree->left);
	
	if (tree->right)
		calc3AC(tree->right);
}
