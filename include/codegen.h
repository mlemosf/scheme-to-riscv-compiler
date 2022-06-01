#ifndef CODEGEN_H
#define CODEGEN_H
#include <stdio.h>
#include <string.h>
#include "globals.h"


/* Utilitários de escrita em arquivo */
void writeExp(FILE* stream, char* exp); // Escreve expressão RISC-V
void writeLabel(FILE* stream, char* label); // Escreve label para procedimentos

/* Escrita de expressões RISC-V */
void writeHeader(FILE* stream);
void storeInt(FILE* stream, int value, int position);

#endif
