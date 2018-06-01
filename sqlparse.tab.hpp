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

#ifndef YY_YY_SQLPARSE_TAB_HPP_INCLUDED
# define YY_YY_SQLPARSE_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    DATABASE = 258,
    TABLE = 259,
    VARCHAR = 260,
    INT = 261,
    DOUBLE = 262,
    TIME = 263,
    NOT = 264,
    NULLS = 265,
    DEFAULT = 266,
    UNIQUE = 267,
    PRIMARY = 268,
    KEY = 269,
    IN = 270,
    CREATE = 271,
    INSERT = 272,
    INTO = 273,
    DELETE = 274,
    FROM = 275,
    SELECT = 276,
    WHERE = 277,
    UPDATE = 278,
    SET = 279,
    CHECK = 280,
    VALUES = 281,
    NAME = 282,
    INTNUM = 283,
    DOUNUM = 284,
    DECIMAL = 285,
    STRING = 286,
    COMPARISON = 287,
    ANDOP = 288,
    OR = 289
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 55 "sqlparse.ypp" /* yacc.c:1909  */

    int intval;       
    double floatval;      
    char strval[16];  
    //int subtok; 

#line 96 "sqlparse.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SQLPARSE_TAB_HPP_INCLUDED  */
