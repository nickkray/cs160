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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

