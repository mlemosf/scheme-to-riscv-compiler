#include "../include/codegen.h"


void writeExp(FILE* stream, char* exp) {
	fprintf(stream, "\t%s\n", exp);
}

void writeLabel(FILE* stream, char* exp) {
	fprintf(stream, "%s:\n", exp);
}

void writeHeader(FILE* stream) {
	fprintf(stream, ".text\n");
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


void intVariableArithmeticOperation(FILE *stream, char operator, int arg1, int arg2) {
	char exp[20];

	// Carrega valor da variável em registrador
	sprintf(exp, "lw %s, %d(%s)", t3, arg1, gp);
	writeExp(stream, exp);

	// Coloca o valor constante em um registrador
	sprintf(exp, "li %s, %d", t4, arg2);
	writeExp(stream, exp);

	// Realiza a operação
	switch(operator) {
	case '+':
		sprintf(exp, "add %s, %s, %s", t3, t3, t4);
		writeExp(stream, exp);
		break;
	case '-':
		sprintf(exp, "sub %s, %s, %s", t3, t3, t4);
		writeExp(stream, exp);
		break;
	case '*':
		sprintf(exp, "mul %s, %s, %s", t3, t3, t4);
		writeExp(stream, exp);
		break;
	case '/':
		sprintf(exp, "div %s, %s, %s", t3, t3, t4);
		writeExp(stream, exp);
		break;
	}
}

void variableVariableArithmeticOperation(FILE *stream, char operator, int arg1, int arg2) {
	char exp[20];

	// Carrega valor da variável 1 em registrador
	sprintf(exp, "lw %s, %d(%s)", t3, arg1, gp);
	writeExp(stream, exp);

	// Carrega valor da variável 2 em registrador
	sprintf(exp, "lw %s, %d(%s)", t4, arg2, gp);
	writeExp(stream, exp);

	// Realiza a operação
	switch(operator) {
	case '+':
		sprintf(exp, "add %s, %s, %s", t3, t3, t4);
		writeExp(stream, exp);
		break;
	case '-':
		sprintf(exp, "sub %s, %s, %s", t3, t3, t4);
		writeExp(stream, exp);
		break;
	case '*':
		sprintf(exp, "mul %s, %s, %s", t3, t3, t4);
		writeExp(stream, exp);
		break;
	case '/':
		sprintf(exp, "div %s, %s, %s", t3, t3, t4);
		writeExp(stream, exp);
		break;
	break;

	}
}

/* === Loops === */
void writeWhileHeader(FILE* stream, int counter, int cmp1, int cmp2) {
	char exp[20];

	// Define o registradores de comparação
	sprintf(exp, "lw %s, %d(%s)", t3, cmp1, gp);
	writeExp(stream, exp);

	sprintf(exp, "li, %s, %d", t2, cmp2);
	writeExp(stream, exp);

	sprintf(exp, "loop_%d", counter);
	writeLabel(stream, exp);
}

void writeWhileCondition(FILE* stream, char* operator, int address, int value, char* label) {
	char exp[20];
	if (!strcmp(operator, "<")) {
		sprintf(exp, "bge %s, %s, %s", t3, t2, label);
		writeExp(stream, exp);
	}
}

void writeWhileFooter(FILE* stream, int counter) {
	char exp[20];

	// Adiciona loop incondicional para o loop;
	sprintf(exp, "jal %s, loop_%d", x0, counter);
	writeExp(stream, exp);

	sprintf(exp, "endloop_%d", counter);
	writeLabel(stream, exp);
}
