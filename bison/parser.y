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
#include "../include/codegen.h"

#define YYDEBUG FALSE

extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern FILE *yyout;
int yydebug = YYDEBUG;

void yyerror(char* s);

/* Tabela de símbolos */
Symbol* symtab = NULL;

%}

/* Tipos */
%union {
	int ival;
	char* sval;
	void* vval;
}

/* Tokens */
%token <ival> INT
%token <sval> ID
%token <vval> DEFINE DISPLAY OPEN CLOSE 

// Expressões tipadas
%type <ival> int
%type <sval> variable


/* Regras */
%%

program: form 
{
	if (YYDEBUG) printf("PROGRAM IS OK\n");}
;

form: %empty
| expression form
{;}
;

expression: constant
| definition
| display {;}
;


definition: OPEN DEFINE variable int CLOSE {
	int position;
	int address;

	// Insere elemento na tabela de símbolos
	insertSymtab(&symtab, (char*)$3, T_INT);

	// Gera o código de atribuição de variável (carregamento de inteiro em memória)
	position = searchSymtab(symtab, (char*)$3);
	if (position == -1) {
		yyerror("Erro semântico: Variável não declarada\n");
	}
	address = word_offset * position;
	storeInt(yyout, $4, address);
}
;

display: OPEN DISPLAY int CLOSE {
	printInt(yyout, $3);
}

variable: ID {;}
;

constant: int {;}
;

int: INT {$$ = $1;}
;

%%

int main(int argc, char** argv) {
	//yydebug = 0;

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

	// Escreve o header do arquivo ASM
	writeHeader(yyout);

	/* Faz o parse do arquivo */
	yyparse();

	/* Fecha o arquivo de input */
	fclose(yyin);
	fclose(yyout);

	/* Destroi a tabela de símbolos */
	destructSymtab(&symtab);

	return 0;
}

void yyerror(char* s) {
	printf("Erro: %s\n", s);
	exit(-1);
}

