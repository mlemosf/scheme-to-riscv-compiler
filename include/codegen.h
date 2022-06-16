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
void printChar(FILE* stream, char* value);
void storeVariable(FILE* stream, int address);

/* Funçoes compostas */
void printVariable(FILE* stream, int type, int address);
void intArithmeticOperation(FILE *stream, char operator, int arg1, int arg2);
void intVariableArithmeticOperation(FILE *stream, char operator, int arg1, int arg2);
void variableVariableArithmeticOperation(FILE *stream, char operator, int arg1, int arg2);

/* Loops */
//void writeWhileHeader(FILE* stream, int counter);
void writeWhileHeader(FILE* stream, int counter, int cmp1, int cmp2);
void writeWhileCondition(FILE* stream, char* operator, int address, int value, char* label);
void writeWhileFooter(FILE* stream, int counter);
#endif
