/*
Arquivo descritivo do analisador léxico
para o Relatório Revisado 5 para a
Linguagem Algarítmica Scheme (r5rs)
Autor: mlemosf
*/
%{
#include <stdio.h>
#include "../bison/parser.tab.h"
	extern int yylex();
	int linenum = 0;
	int yywrap();
	extern FILE *yyin;
%}

/* Tipos primitivos */
DIGIT [0-9]
INT [-]*{DIGIT}+
REAL [-]*{DIGIT}+"."{DIGIT}+
BOOL "t"|"nil"
CHAR [\\]*[ a-zA-Z]

/* Estruturas */
ID [a-zA-Z]+[a-zA-Z0-9]*
STRING "'"[a-zA-Z]*"'"
BRANCO [ \t]
COMMENT ;.*

/* Palavras chave */
OPERATOR [\+|\-|\*|\/]
COMPARISON ">"|"<"|">="|"<="|"eq"|"neq"

/* Regras */
%%

define {return DEFINE;}
setq {return SETQ;}
display {return DISPLAY;}
while {return WHILE;}
\( {return OPEN;}
\) {return CLOSE;}
{COMPARISON} {yylval.sval = (char*)strdup(yytext); return COMPARISON;}

{BRANCO}+ {;}
{INT} {yylval.ival = atoi(yytext); return INT;}
{REAL} {printf("<real>");}
{BOOL} {printf("<bool>");}
"'"{CHAR}"'" {yylval.sval = (char*)strdup(yytext); return CHAR;}
{ID} {yylval.sval = (char*)strdup(yytext); return ID;}

{STRING} {printf("<string>");}
{OPERATOR} {yylval.cval = (char)yytext[0]; return OPERATOR;}
{COMMENT} {;}

\n { linenum++; }

%%

int yywrap() {}
