/*
Arquivo descritivo do analisador léxico
para o Relatório Revisado 5 para a
Linguagem Algarítmica Scheme (r5rs)
Autor: mlemosf
*/
%{
#include <stdio.h>
	extern int yylex();
	int linenum = 0;
%}

/* Estruturas */
DIGIT [0-9]
INT [-]*{DIGIT}*
REAL [-]*{DIGIT}*"."{DIGIT}*
BOOL "t"|"nil"
ID [a-zA-Z]+[a-zA-Z0-9]*
STRING "'"[a-zA-Z]*"'"
BRANCO [ \t\r]
COMMENT ;.*

/* Palavras chave */
DEFINE "define"
SET "set"
OPERATOR [+|-|\*|\\]

/* Regras */
%%

{BRANCO} {printf(" ");}
{INT} {printf("<int>");}
{REAL} {printf("<real>");}
{BOOL} {printf("<bool>");}
{ID} {printf("<id>");}

{STRING} {printf("<string>");}
{OPERATOR} {printf("<operator>");}
{COMMENT} {printf("<comment>");}

\n { linenum++; printf("\n");}

%%

int main(int argc, char** argv) {
	while(1) {
		yylex();
	}
	return 0;
}
