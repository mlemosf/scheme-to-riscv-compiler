#ifndef CODEGEN_H
#define CODEGEN_H
#include <stdio.h>
#include <string.h>
#include "globals.h"

union types {
	int intVal;
	double doubleVal;
	char* stringVal;
};


/* Utilitários de escrita em arquivo */
void writeExp(FILE* stream, char* exp); // Escreve expressão RISC-V
void writeLabel(FILE* stream, char* label); // Escreve label para procedimentos

/* Escrita simples de expressões RISC-V */
void writeHeader(FILE* stream);
void storeInt(FILE* stream, int value, int position);
void loadInt(FILE* stream, int position);
void printInt(FILE* stream, int value);

/* Funçoes compostas */
void printVariable(FILE* stream, int type, int address);

#endif
