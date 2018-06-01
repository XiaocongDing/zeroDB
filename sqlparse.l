%{
    #include<stdio.h>
    #include<cstring>
    #include"sqlparse.tab.hpp"
    #include<iostream>
    #include<stdlib.h>
    #include<fstream>
    string temp;
    string tempnum;
    string tempdou;
    int flag_comp;
    int flag_ifint=0;
    int flag_ifdou=0;
    ofstream pw("lexical.dyd");
    //int yylval;
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
IN IN

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
"(" {pw<<yytext<<"   "<<yy_act<<endl; return *yytext;}
")" { pw<<yytext<<"   "<<yy_act<<endl; return *yytext;}
"DATABASE" { pw<<yytext<<"   "<<yy_act<<endl; return DATABASE; }
"TABLE" { pw<<yytext<<"   "<<yy_act<<endl; return TABLE; }
"VARCHAR" { pw<<yytext<<"   "<<yy_act<<endl; return VARCHAR; }
"INT" { pw<<yytext<<"   "<<yy_act<<endl; return INT; }
"DOUBLE" { pw<<yytext<<"   "<<yy_act<<endl; return DOUBLE; }
"TIME" { pw<<yytext<<"   "<<yy_act<<endl; return TIME; }
"NOT" { pw<<yytext<<"   "<<yy_act<<endl; return NOT; }
"NULL" { pw<<yytext<<"   "<<yy_act<<endl; return NULLS; }
"DEFAULT" { pw<<yytext<<"   "<<yy_act<<endl; return DEFAULT; }
"UNIQUE" { pw<<yytext<<"   "<<yy_act<<endl; return UNIQUE; }
"PRIMARY" { pw<<yytext<<"   "<<yy_act<<endl; return PRIMARY; }
"KEY"  { pw<<yytext<<"   "<<yy_act<<endl; return KEY; }
"CREATE" { pw<<yytext<<"   "<<yy_act<<endl; return CREATE; }
"INSERT" { pw<<yytext<<"   "<<yy_act<<endl; return INSERT; }
"INTO" { pw<<yytext<<"   "<<yy_act<<endl; return INTO; }
"DELETE" { pw<<yytext<<"   "<<yy_act<<endl; return DELETE; }
"FROM" { pw<<yytext<<"   "<<yy_act<<endl; return FROM; }
"SELECT" { pw<<yytext<<"   "<<yy_act<<endl; return SELECT; }
"WHERE" { pw<<yytext<<"   "<<yy_act<<endl; return WHERE; }
"UPDATE" { pw<<yytext<<"   "<<yy_act<<endl; return UPDATE; }
"SET" { pw<<yytext<<"   "<<yy_act<<endl; return SET; }
"CHECK" { pw<<yytext<<"   "<<yy_act<<endl; return CHECK; }
"DECIMAL" { pw<<yytext<<"   "<<yy_act<<endl; return DECIMAL; }
"VALUES"  { pw<<yytext<<"   "<<yy_act<<endl; return VALUES; }
"STRING" {pw<<yytext<<"   "<<yy_act<<endl; return STRING; }
"IN" {pw<<yytext<<"   "<<yy_act<<endl; return IN;}


"&&" { pw<<yytext<<"   "<<yy_act<<endl; flag_comp=8 ;return ANDOP; }
"||" { pw<<yytext<<"   "<<yy_act<<endl; flag_comp=9 ;return OR; }
"=" { pw<<yytext<<"   "<<yy_act<<endl; flag_comp=1 ;return COMPARISON; }
"<=>" { pw<<yytext<<"   "<<yy_act<<endl; return COMPARISON; }
">=" { pw<<yytext<<"   "<<yy_act<<endl; flag_comp=3 ;return COMPARISON; }
">" { pw<<yytext<<"   "<<yy_act<<endl; flag_comp=4 ;return COMPARISON; }
"<=" { pw<<yytext<<"   "<<yy_act<<endl; flag_comp=5 ;return COMPARISON; }
"<" { pw<<yytext<<"   "<<yy_act<<endl; flag_comp=6 ;return COMPARISON; }
"!=" { pw<<yytext<<"   "<<yy_act<<endl; flag_comp=7 ;return COMPARISON; }
[-+&~|^/%*(),.;!] { pw<<yytext<<"   "<<yy_act<<endl; return yytext[0]; }
[A-Za-z][A-Za-z0-9_]*     { pw<<"NAME"<<"   "<<yy_act<<endl; temp=yytext; flag_ifint=0; flag_ifdou=0; return NAME;}
'[A-Za-z][A-Za-z0-9_]*'     { pw<<"NAME"<<"   "<<yy_act<<endl; temp=yytext; flag_ifint=0; flag_ifdou=0; return NAME;}

{op} {
    pw<<yytext<<"   "<<yy_act<<endl;
    return *yytext;
}
\n {
    return *yytext;
}
{num} {
    pw<<yytext<<"   "<<yy_act<<endl;
    tempnum=yytext;
    flag_ifint=1;
    return INTNUM;
}
{number} {
    pw<<yytext<<"   "<<yy_act<<endl;
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