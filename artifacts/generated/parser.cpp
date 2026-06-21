/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include "ast.hpp"
#include "parser_state.hpp"

#include <cstdlib>
#include <memory>
#include <string>

int yylex(void);
void yyerror(const char *message);

#line 83 "build/parser.cpp"

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

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PROGRAM = 3,                    /* PROGRAM  */
  YYSYMBOL_VAR = 4,                        /* VAR  */
  YYSYMBOL_BEGIN_TOKEN = 5,                /* BEGIN_TOKEN  */
  YYSYMBOL_END_TOKEN = 6,                  /* END_TOKEN  */
  YYSYMBOL_FUNCTION = 7,                   /* FUNCTION  */
  YYSYMBOL_PROCEDURE = 8,                  /* PROCEDURE  */
  YYSYMBOL_RETURN_TOKEN = 9,               /* RETURN_TOKEN  */
  YYSYMBOL_INTEGER_TYPE = 10,              /* INTEGER_TYPE  */
  YYSYMBOL_BOOLEAN_TYPE = 11,              /* BOOLEAN_TYPE  */
  YYSYMBOL_TRUE_TOKEN = 12,                /* TRUE_TOKEN  */
  YYSYMBOL_FALSE_TOKEN = 13,               /* FALSE_TOKEN  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_THEN = 15,                      /* THEN  */
  YYSYMBOL_ELSE = 16,                      /* ELSE  */
  YYSYMBOL_WHILE = 17,                     /* WHILE  */
  YYSYMBOL_DO = 18,                        /* DO  */
  YYSYMBOL_FOR = 19,                       /* FOR  */
  YYSYMBOL_TO = 20,                        /* TO  */
  YYSYMBOL_WRITE = 21,                     /* WRITE  */
  YYSYMBOL_WRITELN = 22,                   /* WRITELN  */
  YYSYMBOL_PARAM = 23,                     /* PARAM  */
  YYSYMBOL_AND = 24,                       /* AND  */
  YYSYMBOL_OR = 25,                        /* OR  */
  YYSYMBOL_NOT = 26,                       /* NOT  */
  YYSYMBOL_MOD = 27,                       /* MOD  */
  YYSYMBOL_ASSIGN = 28,                    /* ASSIGN  */
  YYSYMBOL_EQUAL = 29,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 30,                 /* NOT_EQUAL  */
  YYSYMBOL_LT = 31,                        /* LT  */
  YYSYMBOL_LTE = 32,                       /* LTE  */
  YYSYMBOL_GT = 33,                        /* GT  */
  YYSYMBOL_GTE = 34,                       /* GTE  */
  YYSYMBOL_PLUS = 35,                      /* PLUS  */
  YYSYMBOL_MINUS = 36,                     /* MINUS  */
  YYSYMBOL_STAR = 37,                      /* STAR  */
  YYSYMBOL_SLASH = 38,                     /* SLASH  */
  YYSYMBOL_LPAREN = 39,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 40,                    /* RPAREN  */
  YYSYMBOL_COMMA = 41,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 42,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 43,                     /* COLON  */
  YYSYMBOL_DOT = 44,                       /* DOT  */
  YYSYMBOL_INTEGER_LITERAL = 45,           /* INTEGER_LITERAL  */
  YYSYMBOL_IDENTIFIER = 46,                /* IDENTIFIER  */
  YYSYMBOL_STRING_LITERAL = 47,            /* STRING_LITERAL  */
  YYSYMBOL_UMINUS = 48,                    /* UMINUS  */
  YYSYMBOL_LOWER_THAN_ELSE = 49,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_program = 51,                   /* program  */
  YYSYMBOL_declarations_opt = 52,          /* declarations_opt  */
  YYSYMBOL_var_declaration_list = 53,      /* var_declaration_list  */
  YYSYMBOL_identifier_list = 54,           /* identifier_list  */
  YYSYMBOL_type_specifier = 55,            /* type_specifier  */
  YYSYMBOL_routine_list = 56,              /* routine_list  */
  YYSYMBOL_routine = 57,                   /* routine  */
  YYSYMBOL_parameters_opt = 58,            /* parameters_opt  */
  YYSYMBOL_parameters = 59,                /* parameters  */
  YYSYMBOL_parameter_group = 60,           /* parameter_group  */
  YYSYMBOL_compound_statement = 61,        /* compound_statement  */
  YYSYMBOL_statement_list_opt = 62,        /* statement_list_opt  */
  YYSYMBOL_statement_list = 63,            /* statement_list  */
  YYSYMBOL_statement = 64,                 /* statement  */
  YYSYMBOL_arguments_opt = 65,             /* arguments_opt  */
  YYSYMBOL_argument_list = 66,             /* argument_list  */
  YYSYMBOL_expression = 67                 /* expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   273

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  144

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    76,    76,    92,    93,    97,   104,   114,   120,   129,
     130,   134,   135,   143,   156,   172,   173,   177,   178,   187,
     197,   205,   206,   207,   211,   216,   224,   225,   231,   236,
     242,   247,   255,   260,   265,   271,   279,   280,   284,   289,
     297,   298,   299,   300,   305,   310,   316,   321,   322,   324,
     326,   328,   330,   332,   334,   336,   338,   340,   342,   344,
     346,   348,   350
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  static const char *const yy_sname[] =
  {
  "end of file", "error", "invalid token", "PROGRAM", "VAR",
  "BEGIN_TOKEN", "END_TOKEN", "FUNCTION", "PROCEDURE", "RETURN_TOKEN",
  "INTEGER_TYPE", "BOOLEAN_TYPE", "TRUE_TOKEN", "FALSE_TOKEN", "IF",
  "THEN", "ELSE", "WHILE", "DO", "FOR", "TO", "WRITE", "WRITELN", "PARAM",
  "AND", "OR", "NOT", "MOD", "ASSIGN", "EQUAL", "NOT_EQUAL", "LT", "LTE",
  "GT", "GTE", "PLUS", "MINUS", "STAR", "SLASH", "LPAREN", "RPAREN",
  "COMMA", "SEMICOLON", "COLON", "DOT", "INTEGER_LITERAL", "IDENTIFIER",
  "STRING_LITERAL", "UMINUS", "LOWER_THAN_ELSE", "$accept", "program",
  "declarations_opt", "var_declaration_list", "identifier_list",
  "type_specifier", "routine_list", "routine", "parameters_opt",
  "parameters", "parameter_group", "compound_statement",
  "statement_list_opt", "statement_list", "statement", "arguments_opt",
  "argument_list", "expression", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#define YYPACT_NINF (-125)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,   -30,    31,    -7,  -125,    34,    -3,  -125,  -125,    -3,
      -2,     4,     1,    19,    48,    15,    21,    22,  -125,    25,
      48,  -125,  -125,  -125,    28,    50,    50,    50,    26,    35,
      36,    -9,  -125,    71,    37,  -125,    39,    41,  -125,    42,
    -125,  -125,  -125,    44,    50,    50,    50,  -125,    46,  -125,
     196,    84,   107,    53,    50,    50,    50,    50,  -125,    15,
      -3,    -3,  -125,    50,  -125,  -125,   162,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    15,    15,    50,    47,    49,   196,    51,   196,    52,
    -125,    23,    54,    56,  -125,    61,   179,  -125,    62,   223,
     211,  -125,   235,   235,   235,   235,   235,   235,   -12,   -12,
    -125,  -125,    72,  -125,   147,  -125,    50,  -125,  -125,    48,
      63,    -3,    65,  -125,  -125,    15,    50,   196,  -125,    48,
    -125,    34,  -125,   128,    70,    99,    15,    34,    81,  -125,
      99,  -125,    85,  -125
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     3,     0,    11,     7,     4,
       0,     0,     0,     0,     0,    21,     0,     0,    12,     0,
       0,     8,     9,    10,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,    22,    24,     0,     0,     2,     0,
       5,    41,    42,     0,     0,     0,     0,    40,    44,    43,
      35,     0,     0,     0,    36,    36,     0,    36,    20,    23,
      15,    15,     6,     0,    49,    48,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,    38,     0,    27,     0,
      25,     0,     0,    16,    17,     0,     0,    47,     0,    55,
      56,    54,    57,    58,    59,    60,    61,    62,    50,    51,
      52,    53,    28,    30,     0,    32,     0,    33,    34,     0,
       0,     0,     0,    46,    45,     0,     0,    39,    19,     0,
      18,     3,    29,     0,     0,     0,     0,     3,     0,    31,
       0,    14,     0,    13
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -125,  -125,  -124,  -125,     8,   -19,  -125,  -125,    67,  -125,
     -16,   -11,  -125,  -125,   -54,   -49,  -125,   -23
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     7,     9,    91,    24,    11,    18,    92,    93,
      94,    32,    33,    34,    35,    84,    85,    86
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,    39,    50,    51,    52,    90,    87,   135,    89,    15,
       1,    16,    17,   140,    10,    70,     3,    12,    98,    56,
      15,    64,    65,    66,    25,    79,    80,   112,   113,    26,
      57,     4,    27,    88,    28,     5,    29,    30,     6,    13,
      96,    14,    13,     8,    20,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,    22,    23,
     114,    31,    41,    42,    13,    21,   119,    36,    37,    38,
      40,   132,    53,    43,    54,    55,    44,    58,    60,    59,
      61,    83,   139,    63,    62,    67,    45,   115,   125,    46,
     116,   117,   118,   127,   120,    47,    48,    49,   121,    81,
     128,   122,   124,   133,    15,   130,   129,   131,    68,    69,
     134,    70,   137,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,   141,   138,    82,     0,   143,    95,   142,
       0,    68,    69,     0,    70,     0,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,   136,     0,     0,     0,
       0,     0,    68,    69,     0,    70,     0,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,   126,     0,     0,
       0,    68,    69,     0,    70,     0,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    68,    69,     0,    70,
       0,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,     0,    97,    68,    69,     0,    70,     0,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,     0,   123,
      68,    69,     0,    70,     0,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    68,     0,     0,    70,     0,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      70,     0,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    70,     0,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    78,    79,    80
};

static const yytype_int16 yycheck[] =
{
      11,    20,    25,    26,    27,    59,    55,   131,    57,     5,
       3,     7,     8,   137,     6,    27,    46,     9,    67,    28,
       5,    44,    45,    46,     9,    37,    38,    81,    82,    14,
      39,     0,    17,    56,    19,    42,    21,    22,     4,    41,
      63,    43,    41,    46,    43,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    10,    11,
      83,    46,    12,    13,    41,    46,    43,    46,    46,    44,
      42,   125,    46,    23,    39,    39,    26,     6,    39,    42,
      39,    28,   136,    39,    42,    39,    36,    40,    16,    39,
      41,    40,    40,   116,    40,    45,    46,    47,    42,    15,
     119,    40,    40,   126,     5,   121,    43,    42,    24,    25,
     129,    27,    42,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    42,   135,    18,    -1,    42,    61,   140,
      -1,    24,    25,    -1,    27,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    18,    -1,    -1,    -1,
      -1,    -1,    24,    25,    -1,    27,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    20,    -1,    -1,
      -1,    24,    25,    -1,    27,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    24,    25,    -1,    27,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,    24,    25,    -1,    27,    -1,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    40,
      24,    25,    -1,    27,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    24,    -1,    -1,    27,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      27,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    27,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    51,    46,     0,    42,     4,    52,    46,    53,
      54,    56,    54,    41,    43,     5,     7,     8,    57,    61,
      43,    46,    10,    11,    55,     9,    14,    17,    19,    21,
      22,    46,    61,    62,    63,    64,    46,    46,    44,    55,
      42,    12,    13,    23,    26,    36,    39,    45,    46,    47,
      67,    67,    67,    46,    39,    39,    28,    39,     6,    42,
      39,    39,    42,    39,    67,    67,    67,    39,    24,    25,
      27,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    15,    18,    28,    65,    66,    67,    65,    67,    65,
      64,    54,    58,    59,    60,    58,    67,    40,    65,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    64,    64,    67,    40,    41,    40,    40,    43,
      40,    42,    40,    40,    40,    16,    20,    67,    55,    43,
      60,    42,    64,    67,    55,    52,    18,    42,    61,    64,
      52,    42,    61,    42
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    53,    54,    54,    55,
      55,    56,    56,    57,    57,    58,    58,    59,    59,    60,
      61,    62,    62,    62,    63,    63,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    65,    65,    66,    66,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     0,     2,     4,     5,     1,     3,     1,
       1,     0,     2,    11,     9,     0,     1,     1,     3,     3,
       3,     0,     1,     2,     1,     3,     1,     3,     4,     6,
       4,     8,     4,     4,     4,     2,     0,     1,     1,     3,
       1,     1,     1,     1,     1,     4,     4,     3,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif



static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yystrlen (yysymbol_name (yyarg[yyi]));
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp = yystpcpy (yyp, yysymbol_name (yyarg[yyi++]));
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


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_IDENTIFIER: /* IDENTIFIER  */
#line 58 "parser.y"
            { std::free(((*yyvaluep).text)); }
#line 1302 "build/parser.cpp"
        break;

    case YYSYMBOL_STRING_LITERAL: /* STRING_LITERAL  */
#line 58 "parser.y"
            { std::free(((*yyvaluep).text)); }
#line 1308 "build/parser.cpp"
        break;

    case YYSYMBOL_declarations_opt: /* declarations_opt  */
#line 59 "parser.y"
            { delete ((*yyvaluep).var_list); }
#line 1314 "build/parser.cpp"
        break;

    case YYSYMBOL_var_declaration_list: /* var_declaration_list  */
#line 59 "parser.y"
            { delete ((*yyvaluep).var_list); }
#line 1320 "build/parser.cpp"
        break;

    case YYSYMBOL_identifier_list: /* identifier_list  */
#line 60 "parser.y"
            { delete ((*yyvaluep).identifier_list); }
#line 1326 "build/parser.cpp"
        break;

    case YYSYMBOL_routine_list: /* routine_list  */
#line 60 "parser.y"
            { delete ((*yyvaluep).routine_list); }
#line 1332 "build/parser.cpp"
        break;

    case YYSYMBOL_routine: /* routine  */
#line 59 "parser.y"
            { delete ((*yyvaluep).routine); }
#line 1338 "build/parser.cpp"
        break;

    case YYSYMBOL_parameters_opt: /* parameters_opt  */
#line 59 "parser.y"
            { delete ((*yyvaluep).param_list); }
#line 1344 "build/parser.cpp"
        break;

    case YYSYMBOL_parameters: /* parameters  */
#line 59 "parser.y"
            { delete ((*yyvaluep).param_list); }
#line 1350 "build/parser.cpp"
        break;

    case YYSYMBOL_parameter_group: /* parameter_group  */
#line 59 "parser.y"
            { delete ((*yyvaluep).param_list); }
#line 1356 "build/parser.cpp"
        break;

    case YYSYMBOL_compound_statement: /* compound_statement  */
#line 59 "parser.y"
            { delete ((*yyvaluep).stmt); }
#line 1362 "build/parser.cpp"
        break;

    case YYSYMBOL_statement_list_opt: /* statement_list_opt  */
#line 60 "parser.y"
            { delete ((*yyvaluep).stmt_list); }
#line 1368 "build/parser.cpp"
        break;

    case YYSYMBOL_statement_list: /* statement_list  */
#line 60 "parser.y"
            { delete ((*yyvaluep).stmt_list); }
#line 1374 "build/parser.cpp"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 59 "parser.y"
            { delete ((*yyvaluep).stmt); }
#line 1380 "build/parser.cpp"
        break;

    case YYSYMBOL_arguments_opt: /* arguments_opt  */
#line 60 "parser.y"
            { delete ((*yyvaluep).expr_list); }
#line 1386 "build/parser.cpp"
        break;

    case YYSYMBOL_argument_list: /* argument_list  */
#line 60 "parser.y"
            { delete ((*yyvaluep).expr_list); }
#line 1392 "build/parser.cpp"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 59 "parser.y"
            { delete ((*yyvaluep).expr); }
#line 1398 "build/parser.cpp"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: PROGRAM IDENTIFIER SEMICOLON declarations_opt routine_list compound_statement DOT  */
#line 78 "parser.y"
    {
        auto result = std::make_unique<minipas::Program>((yylsp[-6]).first_line);
        result->name = (yyvsp[-5].text);
        std::free((yyvsp[-5].text));
        result->globals = std::move(*(yyvsp[-3].var_list));
        result->routines = std::move(*(yyvsp[-2].routine_list));
        result->body.reset(static_cast<minipas::CompoundStmt *>((yyvsp[-1].stmt)));
        delete (yyvsp[-3].var_list);
        delete (yyvsp[-2].routine_list);
        minipas::parsedProgram = std::move(result);
    }
#line 1706 "build/parser.cpp"
    break;

  case 3: /* declarations_opt: %empty  */
#line 92 "parser.y"
           { (yyval.var_list) = new minipas::VarDeclList(); }
#line 1712 "build/parser.cpp"
    break;

  case 4: /* declarations_opt: VAR var_declaration_list  */
#line 93 "parser.y"
                             { (yyval.var_list) = (yyvsp[0].var_list); }
#line 1718 "build/parser.cpp"
    break;

  case 5: /* var_declaration_list: identifier_list COLON type_specifier SEMICOLON  */
#line 98 "parser.y"
    {
        (yyval.var_list) = new minipas::VarDeclList();
        for (const std::string &name : *(yyvsp[-3].identifier_list))
            (yyval.var_list)->push_back({name, (yyvsp[-1].type), (yylsp[-3]).first_line});
        delete (yyvsp[-3].identifier_list);
    }
#line 1729 "build/parser.cpp"
    break;

  case 6: /* var_declaration_list: var_declaration_list identifier_list COLON type_specifier SEMICOLON  */
#line 105 "parser.y"
    {
        (yyval.var_list) = (yyvsp[-4].var_list);
        for (const std::string &name : *(yyvsp[-3].identifier_list))
            (yyval.var_list)->push_back({name, (yyvsp[-1].type), (yylsp[-3]).first_line});
        delete (yyvsp[-3].identifier_list);
    }
#line 1740 "build/parser.cpp"
    break;

  case 7: /* identifier_list: IDENTIFIER  */
#line 115 "parser.y"
    {
        (yyval.identifier_list) = new minipas::IdentifierList();
        (yyval.identifier_list)->push_back((yyvsp[0].text));
        std::free((yyvsp[0].text));
    }
#line 1750 "build/parser.cpp"
    break;

  case 8: /* identifier_list: identifier_list COMMA IDENTIFIER  */
#line 121 "parser.y"
    {
        (yyval.identifier_list) = (yyvsp[-2].identifier_list);
        (yyval.identifier_list)->push_back((yyvsp[0].text));
        std::free((yyvsp[0].text));
    }
#line 1760 "build/parser.cpp"
    break;

  case 9: /* type_specifier: INTEGER_TYPE  */
#line 129 "parser.y"
                 { (yyval.type) = minipas::ValueType::Integer; }
#line 1766 "build/parser.cpp"
    break;

  case 10: /* type_specifier: BOOLEAN_TYPE  */
#line 130 "parser.y"
                 { (yyval.type) = minipas::ValueType::Boolean; }
#line 1772 "build/parser.cpp"
    break;

  case 11: /* routine_list: %empty  */
#line 134 "parser.y"
           { (yyval.routine_list) = new minipas::RoutineList(); }
#line 1778 "build/parser.cpp"
    break;

  case 12: /* routine_list: routine_list routine  */
#line 136 "parser.y"
    {
        (yyval.routine_list) = (yyvsp[-1].routine_list);
        (yyval.routine_list)->emplace_back((yyvsp[0].routine));
    }
#line 1787 "build/parser.cpp"
    break;

  case 13: /* routine: FUNCTION IDENTIFIER LPAREN parameters_opt RPAREN COLON type_specifier SEMICOLON declarations_opt compound_statement SEMICOLON  */
#line 145 "parser.y"
    {
        (yyval.routine) = new minipas::RoutineDecl((yylsp[-10]).first_line);
        (yyval.routine)->name = (yyvsp[-9].text);
        std::free((yyvsp[-9].text));
        (yyval.routine)->parameters = std::move(*(yyvsp[-7].param_list));
        (yyval.routine)->returnType = (yyvsp[-4].type);
        (yyval.routine)->variables = std::move(*(yyvsp[-2].var_list));
        (yyval.routine)->body.reset(static_cast<minipas::CompoundStmt *>((yyvsp[-1].stmt)));
        delete (yyvsp[-7].param_list);
        delete (yyvsp[-2].var_list);
    }
#line 1803 "build/parser.cpp"
    break;

  case 14: /* routine: PROCEDURE IDENTIFIER LPAREN parameters_opt RPAREN SEMICOLON declarations_opt compound_statement SEMICOLON  */
#line 158 "parser.y"
    {
        (yyval.routine) = new minipas::RoutineDecl((yylsp[-8]).first_line);
        (yyval.routine)->name = (yyvsp[-7].text);
        std::free((yyvsp[-7].text));
        (yyval.routine)->parameters = std::move(*(yyvsp[-5].param_list));
        (yyval.routine)->returnType = minipas::ValueType::Void;
        (yyval.routine)->variables = std::move(*(yyvsp[-2].var_list));
        (yyval.routine)->body.reset(static_cast<minipas::CompoundStmt *>((yyvsp[-1].stmt)));
        delete (yyvsp[-5].param_list);
        delete (yyvsp[-2].var_list);
    }
#line 1819 "build/parser.cpp"
    break;

  case 15: /* parameters_opt: %empty  */
#line 172 "parser.y"
           { (yyval.param_list) = new minipas::ParamList(); }
#line 1825 "build/parser.cpp"
    break;

  case 16: /* parameters_opt: parameters  */
#line 173 "parser.y"
               { (yyval.param_list) = (yyvsp[0].param_list); }
#line 1831 "build/parser.cpp"
    break;

  case 17: /* parameters: parameter_group  */
#line 177 "parser.y"
                    { (yyval.param_list) = (yyvsp[0].param_list); }
#line 1837 "build/parser.cpp"
    break;

  case 18: /* parameters: parameters SEMICOLON parameter_group  */
#line 179 "parser.y"
    {
        (yyval.param_list) = (yyvsp[-2].param_list);
        for (const auto &parameter : *(yyvsp[0].param_list)) (yyval.param_list)->push_back(parameter);
        delete (yyvsp[0].param_list);
    }
#line 1847 "build/parser.cpp"
    break;

  case 19: /* parameter_group: identifier_list COLON type_specifier  */
#line 188 "parser.y"
    {
        (yyval.param_list) = new minipas::ParamList();
        for (const std::string &name : *(yyvsp[-2].identifier_list))
            (yyval.param_list)->push_back({name, (yyvsp[0].type), (yylsp[-2]).first_line});
        delete (yyvsp[-2].identifier_list);
    }
#line 1858 "build/parser.cpp"
    break;

  case 20: /* compound_statement: BEGIN_TOKEN statement_list_opt END_TOKEN  */
#line 198 "parser.y"
    {
        (yyval.stmt) = new minipas::CompoundStmt(std::move(*(yyvsp[-1].stmt_list)), (yylsp[-2]).first_line);
        delete (yyvsp[-1].stmt_list);
    }
#line 1867 "build/parser.cpp"
    break;

  case 21: /* statement_list_opt: %empty  */
#line 205 "parser.y"
           { (yyval.stmt_list) = new minipas::StmtList(); }
#line 1873 "build/parser.cpp"
    break;

  case 22: /* statement_list_opt: statement_list  */
#line 206 "parser.y"
                   { (yyval.stmt_list) = (yyvsp[0].stmt_list); }
#line 1879 "build/parser.cpp"
    break;

  case 23: /* statement_list_opt: statement_list SEMICOLON  */
#line 207 "parser.y"
                             { (yyval.stmt_list) = (yyvsp[-1].stmt_list); }
#line 1885 "build/parser.cpp"
    break;

  case 24: /* statement_list: statement  */
#line 212 "parser.y"
    {
        (yyval.stmt_list) = new minipas::StmtList();
        (yyval.stmt_list)->emplace_back((yyvsp[0].stmt));
    }
#line 1894 "build/parser.cpp"
    break;

  case 25: /* statement_list: statement_list SEMICOLON statement  */
#line 217 "parser.y"
    {
        (yyval.stmt_list) = (yyvsp[-2].stmt_list);
        (yyval.stmt_list)->emplace_back((yyvsp[0].stmt));
    }
#line 1903 "build/parser.cpp"
    break;

  case 26: /* statement: compound_statement  */
#line 224 "parser.y"
                       { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1909 "build/parser.cpp"
    break;

  case 27: /* statement: IDENTIFIER ASSIGN expression  */
#line 226 "parser.y"
    {
        (yyval.stmt) = new minipas::AssignmentStmt((yyvsp[-2].text),
             std::unique_ptr<minipas::Expr>((yyvsp[0].expr)), (yylsp[-2]).first_line);
        std::free((yyvsp[-2].text));
    }
#line 1919 "build/parser.cpp"
    break;

  case 28: /* statement: IF expression THEN statement  */
#line 232 "parser.y"
    {
        (yyval.stmt) = new minipas::IfStmt(std::unique_ptr<minipas::Expr>((yyvsp[-2].expr)),
             std::unique_ptr<minipas::Stmt>((yyvsp[0].stmt)), nullptr, (yylsp[-3]).first_line);
    }
#line 1928 "build/parser.cpp"
    break;

  case 29: /* statement: IF expression THEN statement ELSE statement  */
#line 237 "parser.y"
    {
        (yyval.stmt) = new minipas::IfStmt(std::unique_ptr<minipas::Expr>((yyvsp[-4].expr)),
             std::unique_ptr<minipas::Stmt>((yyvsp[-2].stmt)),
             std::unique_ptr<minipas::Stmt>((yyvsp[0].stmt)), (yylsp[-5]).first_line);
    }
#line 1938 "build/parser.cpp"
    break;

  case 30: /* statement: WHILE expression DO statement  */
#line 243 "parser.y"
    {
        (yyval.stmt) = new minipas::WhileStmt(std::unique_ptr<minipas::Expr>((yyvsp[-2].expr)),
             std::unique_ptr<minipas::Stmt>((yyvsp[0].stmt)), (yylsp[-3]).first_line);
    }
#line 1947 "build/parser.cpp"
    break;

  case 31: /* statement: FOR IDENTIFIER ASSIGN expression TO expression DO statement  */
#line 248 "parser.y"
    {
        (yyval.stmt) = new minipas::ForStmt((yyvsp[-6].text),
             std::unique_ptr<minipas::Expr>((yyvsp[-4].expr)),
             std::unique_ptr<minipas::Expr>((yyvsp[-2].expr)),
             std::unique_ptr<minipas::Stmt>((yyvsp[0].stmt)), (yylsp[-7]).first_line);
        std::free((yyvsp[-6].text));
    }
#line 1959 "build/parser.cpp"
    break;

  case 32: /* statement: WRITE LPAREN arguments_opt RPAREN  */
#line 256 "parser.y"
    {
        (yyval.stmt) = new minipas::WriteStmt(std::move(*(yyvsp[-1].expr_list)), false, (yylsp[-3]).first_line);
        delete (yyvsp[-1].expr_list);
    }
#line 1968 "build/parser.cpp"
    break;

  case 33: /* statement: WRITELN LPAREN arguments_opt RPAREN  */
#line 261 "parser.y"
    {
        (yyval.stmt) = new minipas::WriteStmt(std::move(*(yyvsp[-1].expr_list)), true, (yylsp[-3]).first_line);
        delete (yyvsp[-1].expr_list);
    }
#line 1977 "build/parser.cpp"
    break;

  case 34: /* statement: IDENTIFIER LPAREN arguments_opt RPAREN  */
#line 266 "parser.y"
    {
        (yyval.stmt) = new minipas::CallStmt((yyvsp[-3].text), std::move(*(yyvsp[-1].expr_list)), (yylsp[-3]).first_line);
        std::free((yyvsp[-3].text));
        delete (yyvsp[-1].expr_list);
    }
#line 1987 "build/parser.cpp"
    break;

  case 35: /* statement: RETURN_TOKEN expression  */
#line 272 "parser.y"
    {
        (yyval.stmt) = new minipas::ReturnStmt(std::unique_ptr<minipas::Expr>((yyvsp[0].expr)),
                                     (yylsp[-1]).first_line);
    }
#line 1996 "build/parser.cpp"
    break;

  case 36: /* arguments_opt: %empty  */
#line 279 "parser.y"
           { (yyval.expr_list) = new minipas::ExprList(); }
#line 2002 "build/parser.cpp"
    break;

  case 37: /* arguments_opt: argument_list  */
#line 280 "parser.y"
                  { (yyval.expr_list) = (yyvsp[0].expr_list); }
#line 2008 "build/parser.cpp"
    break;

  case 38: /* argument_list: expression  */
#line 285 "parser.y"
    {
        (yyval.expr_list) = new minipas::ExprList();
        (yyval.expr_list)->emplace_back((yyvsp[0].expr));
    }
#line 2017 "build/parser.cpp"
    break;

  case 39: /* argument_list: argument_list COMMA expression  */
#line 290 "parser.y"
    {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->emplace_back((yyvsp[0].expr));
    }
#line 2026 "build/parser.cpp"
    break;

  case 40: /* expression: INTEGER_LITERAL  */
#line 297 "parser.y"
                    { (yyval.expr) = new minipas::IntegerExpr((yyvsp[0].integer), (yylsp[0]).first_line); }
#line 2032 "build/parser.cpp"
    break;

  case 41: /* expression: TRUE_TOKEN  */
#line 298 "parser.y"
               { (yyval.expr) = new minipas::BooleanExpr(true, (yylsp[0]).first_line); }
#line 2038 "build/parser.cpp"
    break;

  case 42: /* expression: FALSE_TOKEN  */
#line 299 "parser.y"
                { (yyval.expr) = new minipas::BooleanExpr(false, (yylsp[0]).first_line); }
#line 2044 "build/parser.cpp"
    break;

  case 43: /* expression: STRING_LITERAL  */
#line 301 "parser.y"
    {
        (yyval.expr) = new minipas::StringExpr((yyvsp[0].text), (yylsp[0]).first_line);
        std::free((yyvsp[0].text));
    }
#line 2053 "build/parser.cpp"
    break;

  case 44: /* expression: IDENTIFIER  */
#line 306 "parser.y"
    {
        (yyval.expr) = new minipas::VariableExpr((yyvsp[0].text), (yylsp[0]).first_line);
        std::free((yyvsp[0].text));
    }
#line 2062 "build/parser.cpp"
    break;

  case 45: /* expression: IDENTIFIER LPAREN arguments_opt RPAREN  */
#line 311 "parser.y"
    {
        (yyval.expr) = new minipas::CallExpr((yyvsp[-3].text), std::move(*(yyvsp[-1].expr_list)), (yylsp[-3]).first_line);
        std::free((yyvsp[-3].text));
        delete (yyvsp[-1].expr_list);
    }
#line 2072 "build/parser.cpp"
    break;

  case 46: /* expression: PARAM LPAREN expression RPAREN  */
#line 317 "parser.y"
    {
        (yyval.expr) = new minipas::ArgumentExpr(std::unique_ptr<minipas::Expr>((yyvsp[-1].expr)),
                                       (yylsp[-3]).first_line);
    }
#line 2081 "build/parser.cpp"
    break;

  case 47: /* expression: LPAREN expression RPAREN  */
#line 321 "parser.y"
                             { (yyval.expr) = (yyvsp[-1].expr); }
#line 2087 "build/parser.cpp"
    break;

  case 48: /* expression: MINUS expression  */
#line 323 "parser.y"
    { (yyval.expr) = new minipas::UnaryExpr("-", std::unique_ptr<minipas::Expr>((yyvsp[0].expr)), (yylsp[-1]).first_line); }
#line 2093 "build/parser.cpp"
    break;

  case 49: /* expression: NOT expression  */
#line 325 "parser.y"
    { (yyval.expr) = new minipas::UnaryExpr("not", std::unique_ptr<minipas::Expr>((yyvsp[0].expr)), (yylsp[-1]).first_line); }
#line 2099 "build/parser.cpp"
    break;

  case 50: /* expression: expression PLUS expression  */
#line 327 "parser.y"
    { (yyval.expr) = new minipas::BinaryExpr("+", std::unique_ptr<minipas::Expr>((yyvsp[-2].expr)), std::unique_ptr<minipas::Expr>((yyvsp[0].expr)), (yylsp[-1]).first_line); }
#line 2105 "build/parser.cpp"
    break;

  case 51: /* expression: expression MINUS expression  */
#line 329 "parser.y"
    { (yyval.expr) = new minipas::BinaryExpr("-", std::unique_ptr<minipas::Expr>((yyvsp[-2].expr)), std::unique_ptr<minipas::Expr>((yyvsp[0].expr)), (yylsp[-1]).first_line); }
#line 2111 "build/parser.cpp"
    break;

  case 52: /* expression: expression STAR expression  */
#line 331 "parser.y"
    { (yyval.expr) = new minipas::BinaryExpr("*", std::unique_ptr<minipas::Expr>((yyvsp[-2].expr)), std::unique_ptr<minipas::Expr>((yyvsp[0].expr)), (yylsp[-1]).first_line); }
#line 2117 "build/parser.cpp"
    break;

  case 53: /* expression: expression SLASH expression  */
#line 333 "parser.y"
    { (yyval.expr) = new minipas::BinaryExpr("/", std::unique_ptr<minipas::Expr>((yyvsp[-2].expr)), std::unique_ptr<minipas::Expr>((yyvsp[0].expr)), (yylsp[-1]).first_line); }
#line 2123 "build/parser.cpp"
    break;

  case 54: /* expression: expression MOD expression  */
#line 335 "parser.y"
    { (yyval.expr) = new minipas::BinaryExpr("mod", std::unique_ptr<minipas::Expr>((yyvsp[-2].expr)), std::unique_ptr<minipas::Expr>((yyvsp[0].expr)), (yylsp[-1]).first_line); }
#line 2129 "build/parser.cpp"
    break;

  case 55: /* expression: expression AND expression  */
#line 337 "parser.y"
    { (yyval.expr) = new minipas::BinaryExpr("and", std::unique_ptr<minipas::Expr>((yyvsp[-2].expr)), std::unique_ptr<minipas::Expr>((yyvsp[0].expr)), (yylsp[-1]).first_line); }
#line 2135 "build/parser.cpp"
    break;

  case 56: /* expression: expression OR expression  */
#line 339 "parser.y"
    { (yyval.expr) = new minipas::BinaryExpr("or", std::unique_ptr<minipas::Expr>((yyvsp[-2].expr)), std::unique_ptr<minipas::Expr>((yyvsp[0].expr)), (yylsp[-1]).first_line); }
#line 2141 "build/parser.cpp"
    break;

  case 57: /* expression: expression EQUAL expression  */
#line 341 "parser.y"
    { (yyval.expr) = new minipas::BinaryExpr("=", std::unique_ptr<minipas::Expr>((yyvsp[-2].expr)), std::unique_ptr<minipas::Expr>((yyvsp[0].expr)), (yylsp[-1]).first_line); }
#line 2147 "build/parser.cpp"
    break;

  case 58: /* expression: expression NOT_EQUAL expression  */
#line 343 "parser.y"
    { (yyval.expr) = new minipas::BinaryExpr("<>", std::unique_ptr<minipas::Expr>((yyvsp[-2].expr)), std::unique_ptr<minipas::Expr>((yyvsp[0].expr)), (yylsp[-1]).first_line); }
#line 2153 "build/parser.cpp"
    break;

  case 59: /* expression: expression LT expression  */
#line 345 "parser.y"
    { (yyval.expr) = new minipas::BinaryExpr("<", std::unique_ptr<minipas::Expr>((yyvsp[-2].expr)), std::unique_ptr<minipas::Expr>((yyvsp[0].expr)), (yylsp[-1]).first_line); }
#line 2159 "build/parser.cpp"
    break;

  case 60: /* expression: expression LTE expression  */
#line 347 "parser.y"
    { (yyval.expr) = new minipas::BinaryExpr("<=", std::unique_ptr<minipas::Expr>((yyvsp[-2].expr)), std::unique_ptr<minipas::Expr>((yyvsp[0].expr)), (yylsp[-1]).first_line); }
#line 2165 "build/parser.cpp"
    break;

  case 61: /* expression: expression GT expression  */
#line 349 "parser.y"
    { (yyval.expr) = new minipas::BinaryExpr(">", std::unique_ptr<minipas::Expr>((yyvsp[-2].expr)), std::unique_ptr<minipas::Expr>((yyvsp[0].expr)), (yylsp[-1]).first_line); }
#line 2171 "build/parser.cpp"
    break;

  case 62: /* expression: expression GTE expression  */
#line 351 "parser.y"
    { (yyval.expr) = new minipas::BinaryExpr(">=", std::unique_ptr<minipas::Expr>((yyvsp[-2].expr)), std::unique_ptr<minipas::Expr>((yyvsp[0].expr)), (yylsp[-1]).first_line); }
#line 2177 "build/parser.cpp"
    break;


#line 2181 "build/parser.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 354 "parser.y"

