/*
Arquivo descritivo dos analisadores
sintático e semântico para o Relatório
Revisado 5 para a Linguagem Algorítmica Scheme (r5rs).
Autor: mlemosf
*/

%{
#include <stdio.h>
#include <stdlib.h>
#include "../include/globals.h"
#include "../include/symtab.h"
/* Globals */

#define YYDEBUG 1

extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern FILE *yyout;

void yyerror(char* s);

%}

/* Tipos */
%union {
	int ival;
	char* sval;
}

/* Tokens */
%token <ival> INT
%token <sval> ID

// Expressões tipadas
%type <ival> int


/* Regras */
%%

program: form_list 
{printf("PROGRAM IS OK\n");}
;

form_list: %empty
| form form_list 
;

form: expression {;}
;

expression: constant {;}
;

definition_list: %empty 
| definition definition_list {;}
;

definition: "(define" variable expression ")" {;}
;

variable: ID {;}
;

constant: int {;}
;

int: INT {$$ = $1; printf("<int>");}
;

%%

int main(int argc, char** argv) {
	yydebug = FALSE;

	// Se for passado um arquivo de input, busca o programa do arquivo
	if (argc > 1) {
		char* filename = argv[1];
		FILE *input = fopen(filename, "r");

		if (!input) {
			printf("Não foi possível abrir o arquivo de input\n");
			return -1;
		}
		yyin = input;
	}

	yyout = stdout;

	/* Faz o parse do arquivo */
	yyparse();

	/* Fecha o arquivo de input */
	fclose(yyin);
	fclose(yyout);

	return 0;
}

void yyerror(char* s) {
	printf("Erro: %s\n", s);
	exit(-1);
}

