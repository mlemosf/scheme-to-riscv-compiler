# Makefile para o analisador léxico/* Functions */
OBJS = build/symtab.o build/codegen.o
# OBJS = ""

TARGET: compilador 

bison/parser.tab.c bison/parser.tab.h: bison/parser.y
	bison -o bison/parser.tab.c -d bison/parser.y

flex/lex.yy.c: bison/parser.tab.h
	flex -o flex/lex.yy.c flex/scanner.l

build/symtab.o: src/symtab.c include/symtab.h
	gcc -o build/symtab.o -c src/symtab.c

build/codegen.o: src/codegen.c include/codegen.h
	gcc -o build/codegen.o -c src/codegen.c


compilador: flex/lex.yy.c bison/parser.tab.c ${OBJS}
	gcc -o compilador flex/lex.yy.c bison/parser.tab.c ${OBJS} -lfl


clean:
#	rm -f lex.yy.c parser.tab.c parser.tab.h parser.output compilador
	rm -f flex/lex.yy.c bison/parser.tab.* build/*.o compilador
	rm -f build/*.o
