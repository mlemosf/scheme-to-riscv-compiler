/*
Arquivo descritivo dos analisadores
sintático e semântico para o Relatório
Revisado 5 para a Linguagem Algorítmica Scheme (r5rs).
Autor: mlemosf
*/

%{
	#include <stdio.h>
	#include <stdlib.h>

	extern int yylex();
	extern int yyparse();
	extern FILE *yyin;
	extern FILE *yyout;

	void yyerror(char* s);
%}

/* Regras */
%%

program: 
{;}
;

%%

int main(int argc, char** argv) {
	
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
	return 0;
}

void yyerror(char* s) {
	printf("Erro: %s\n", s);
	exit(-1);
}

