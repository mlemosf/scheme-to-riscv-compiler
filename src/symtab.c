/* Definições para a tabela de símbolos */
#include "../include/symtab.h"

void insertSymtab(Symbol** symtab, char* id, int type) {
	Symbol* newSymbol = (Symbol*)malloc(sizeof(Symbol));

	newSymbol->id = id;
	newSymbol->type = type;
	newSymbol->wasUsed = FALSE;

	/* Se estiver vazia, recebe newSymbol. Caso contrário, next recebe newSymbol */
	if (*symtab == NULL) {
		newSymbol->next = NULL;
		(*symtab) = newSymbol;
	}
	else {
		Symbol* current = *symtab;
		while (current->next != NULL) {
			current = current->next;
		}
		newSymbol->next = NULL;
		current->next = newSymbol;
	}
}

int searchSymtab(Symbol* symtab, char* id) {
	Symbol* current = symtab;
	int position = -1;
	int counter = 0;

	while (current != NULL) {
		if (!strcmp(id, current->id)) {
			position = counter;
			break;
		}
		current = current->next;
		counter++;
	}
	return position;
}

Symbol* getSymbolById(Symbol* symtab, char* id) {
	Symbol* current = symtab;
	Symbol* found = NULL;
	int counter = 0;

	while (current != NULL) {
		if (!strcmp(id, current->id)) {
			found = current;
			break;
		}
		current = current->next;
		counter++;
	}
	return found;
}

void printSymtab(Symbol* symtab) {
	Symbol* current = symtab;
	while (current != NULL) {
		printf("| %s | %d | %d \n", current->id, current->type, current->wasUsed);
		current = current->next;
	}	
}

void destructSymtab(Symbol** symtab) {
	free(*symtab);
}
