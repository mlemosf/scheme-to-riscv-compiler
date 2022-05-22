/*
Arquivo descritivo do analisador léxico
para o Relatório Revisado 5 para a
Linguagem Algarítmica Scheme (r5rs)
Autor: mlemosf
*/
%{
#include <stdio.h>
	extern int yylex();
%}

/* Estruturas */
DIGIT [0-9]
INT [-]*{DIGIT}*
REAL [-]*{DIGIT}*"."{DIGIT}*
BOOL "t"|"nil"
ID [a-zA-Z]*
STRING "'"[a-zA-Z]*"'"
BRANCO [ \t\r]

/* Palavras chave */



/* Regras */
%%

{BRANCO} {printf(" ");}
{INT} {printf("<int>");}
{REAL} {printf("<real>");}
{BOOL} {printf("<bool>");}
{ID} {printf("<id>");}
{STRING} {printf("<string>");}

%%

int main(int argc, char** argv) {
	while(1) {
		yylex();
	}
	return 0;
}
