/* Declarações para a tabela de símbolos */
#ifndef SYMTAB_H
#define SYMTAB_H
#include "globals.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Symbol {
	char* id;
	int type;
	int wasUsed;
	struct Symbol* next;
} Symbol;

//void createSymtab(Symbol* symtab);
void destructSymtab(Symbol** symtab);
void insertSymtab(Symbol** symtab, char* id, int type);
int searchSymtab(Symbol* symtab, char* id);
void markSymbolUsed(Symbol** symtab, char* id);
void printSymtab(Symbol* symtab);

#endif
