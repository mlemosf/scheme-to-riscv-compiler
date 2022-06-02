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
	sprintf(exp, "li, %s, %d", t3, value);
	writeExp(stream, exp);

	sprintf(exp, "sw, %s, %d(%s)", t3, position, gp);
	writeExp(stream, exp);
}

void printInt(FILE* stream, int value) {
	char exp[20];
	sprintf(exp, "li a0, %d", value);
	writeExp(stream, "li, a7, 1");
	writeExp(stream, exp);
	writeExp(stream, "ecall");
}


