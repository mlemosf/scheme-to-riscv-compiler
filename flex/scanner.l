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

/* Estruturas */
DIGIT [0-9]
INT [-]*{DIGIT}+
REAL [-]*{DIGIT}+"."{DIGIT}+
BOOL "t"|"nil"
ID [a-zA-Z]+[a-zA-Z0-9]*
STRING "'"[a-zA-Z]*"'"
BRANCO [ \t]
COMMENT ;.*

/* Palavras chave */
SET "set"
OPERATOR [\+|\-|\*|\/]
COMPARISON [>|<|>=|<=]

/* Regras */
%%

define {return DEFINE;}
display {return DISPLAY;}
while {return WHILE;}
\( {return OPEN;}
\) {return CLOSE;}

{BRANCO}+ {;}
{INT} {yylval.ival = atoi(yytext); return INT;}
{REAL} {printf("<real>");}
{BOOL} {printf("<bool>");}
{ID} {yylval.sval = (char*)strdup(yytext); return ID;}

{STRING} {printf("<string>");}
{OPERATOR} {yylval.cval = (char)yytext[0]; return OPERATOR;}
{COMPARISON} {yylval.sval = (char*)strdup(yytext); return COMPARISON;}
{COMMENT} {printf("<comment>");}

\n { linenum++; }

%%

int yywrap() {}
