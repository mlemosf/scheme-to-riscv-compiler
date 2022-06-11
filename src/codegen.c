#include "../include/codegen.h"


void writeExp(FILE* stream, char* exp) {
	fprintf(stream, "\t%s\n", exp);
}

void writeLabel(FILE* stream, char* exp) {
	fprintf(stream, "%s", exp);
}

void writeHeader(FILE* stream) {
	writeLabel(stream, ".text\n");
}

void storeInt(FILE* stream, int value, int position) {
	char exp[20];
	sprintf(exp, "li %s, %d", t3, value);
	writeExp(stream, exp);

	sprintf(exp, "sw %s, %d(%s)", t3, position, gp);
	writeExp(stream, exp);
}

void loadInt(FILE* stream, int position) {
	char exp[20];
	sprintf(exp, "lw %s, %d(%s)", t3, position, gp);
	writeExp(stream, exp);
}

void printInt(FILE* stream, int value) {
	char exp[20];
	sprintf(exp, "li a0, %d", value);
	writeExp(stream, "li a7, 1");
	writeExp(stream, exp);
	writeExp(stream, "ecall");
}

void storeVariable(FILE* stream, int address) {
	char exp[20];
	sprintf(exp, "sw %s, %d(%s)", t3, address, gp);
	writeExp(stream, exp);
}

/* Funções complexas */
void printVariable(FILE* stream, int type, int address) {
	char exp[50];

	switch(type) {
	case T_INT:
		sprintf(exp, "lw a0, %d(%s)", address, gp);
		writeExp(stream, "li, a7, 1");
		writeExp(stream, exp);
		break;
	}
	writeExp(stream, "ecall");
}

void intArithmeticOperation(FILE *stream, char operator, int arg1, int arg2) {
	char exp[20];

		// Verifica o operador e gera o código correspondente
	switch(operator) {
	case '+':
		sprintf(exp, "li %s, %d", t3, arg1);
		writeExp(stream, exp);

		sprintf(exp, "addi %s, %s, %d", t3, t3, arg2);
		writeExp(stream, exp);
		break;
	case '-':
		sprintf(exp, "li %s, %d", t3, arg1);
		writeExp(stream, exp);
		
		sprintf(exp, "addi %s, %s, %d", t3, t3, (-1) * arg2);
		writeExp(stream, exp);
		break;
	case '*':
		sprintf(exp, "li %s, %d", t3, arg1);
		writeExp(stream, exp);

		sprintf(exp, "li %s, %d", t4, arg2);
		writeExp(stream, exp);

		sprintf(exp, "mul %s, %s, %s", t3, t3, t4);
		writeExp(stream, exp);
		break;
	case '/':
		sprintf(exp, "li %s, %d", t3, arg1);
		writeExp(stream, exp);

		sprintf(exp, "li %s, %d", t4, arg2);
		writeExp(stream, exp);

		sprintf(exp, "div %s, %s, %s", t3, t3, t4);
		writeExp(stream, exp);
		break;
	}
}

