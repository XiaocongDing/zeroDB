%{
    #include<stdio.h>
    #include<cstring>
    #include"sqlparse.tab.hpp"
    #include<iostream>
    string temp;
    string tempnum;
    string tempdou;
    int flag_comp;
    int flag_ifint=0;
    int flag_ifdou=0;
%}
space [\ \t]+
num [0-9]+
number {num}+(\.{num}+)?(e([+-])?{num}+)?
op [\+\-\/\%\*\(\)]
DATABASE DATABASE
TABLE TABLE
VARCHAR VARCHAR
INT INT
DOUBLE DOUBLE
TIME TIME
NOT NOT
NULLS NULLS
DEFAULT DEFAULT
UNIQUE UNIQUE
PRIMARY PRIMARY
KEY KEY

CREATE CREATE
INSERT INSERT
INTO INTO
DELETE DELETE
FROM FROM
SELECT SELECT
WHERE WHERE
UPDATE UPDATE
SET SET
CHECK CHECK
VALUES VALUES

NAME NAME
INTNUM INTNUM
DOUNUM DOUNUM
DECIMAL DECIMAL
STRING STRING
COMPARISON COMPARISON
ANDOP [/&&/]
OR [/||/]
%%
{space} ;
"(" { return *yytext;}
")" { return *yytext;}
"DATABASE" { return DATABASE; }
"TABLE" { return TABLE; }
"VARCHAR" { return VARCHAR; }
"INT" { return INT; }
"DOUBLE" { return DOUBLE; }
"TIME" { return TIME; }
"NOT" { return NOT; }
"NULL" { return NULLS; }
"DEFAULT" { return DEFAULT; }
"UNIQUE" { return UNIQUE; }
"PRIMARY" { return PRIMARY; }
"KEY"  { return KEY; }
"CREATE" { return CREATE; }
"INSERT" { return INSERT; }
"INTO" { return INTO; }
"DELETE" { return DELETE; }
"FROM" { return FROM; }
"SELECT" { return SELECT; }
"WHERE" { return WHERE; }
"UPDATE" { return UPDATE; }
"SET" { return SET; }
"CHECK" { return CHECK; }
"DECIMAL" { return DECIMAL; }
"VALUES"  { return VALUES; }
"STRING" { return STRING; }


"&&" { flag_comp=8 ;return ANDOP; }
"||" { flag_comp=9 ;return OR; }
"=" { flag_comp=1 ;return COMPARISON; }
"<=>" { return COMPARISON; }
">=" { flag_comp=3 ;return COMPARISON; }
">" { flag_comp=4 ;return COMPARISON; }
"<=" { flag_comp=5 ;return COMPARISON; }
"<" { flag_comp=6 ;return COMPARISON; }
"!=" { flag_comp=7 ;return COMPARISON; }
[-+&~|^/%*(),.;!] { return yytext[0]; }
[A-Za-z][A-Za-z0-9_]*     { temp=yytext; flag_ifint=0; flag_ifdou=0; return NAME;}
'[A-Za-z][A-Za-z0-9_]*'     { temp=yytext; flag_ifint=0; flag_ifdou=0; return NAME;}

{op} {
    return *yytext;
}
\n {
    return *yytext;
}
{num} {
    tempnum=yytext;
    flag_ifint=1;
    return INTNUM;
}
{number} {
    tempdou=yytext;
    flag_ifdou=1;
    return DOUNUM;
}

. printf("illegal identifier\n");
%%
int yywrap(void)
{
    return 1;
}