/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
#line 104 "part3.y" /* yacc.c:1909  */

    struct node *node;
    char *string;

#line 171 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
