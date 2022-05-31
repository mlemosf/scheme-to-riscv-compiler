# Makefile para o analisador léxico/* Functions */
#OBJS = build/tabelaSimbolos.o
# OBJS = ""

TARGET: compilador 

bison/parser.tab.c bison/parser.tab.h: bison/parser.y
	bison -o bison/parser.tab.c -d bison/parser.y

flex/lex.yy.c: bison/parser.tab.h
	flex -o flex/lex.yy.c flex/scanner.l

# build/tabelaSimbolos.o: src/tabelaSimbolos.c include/tabelaSimbolos.h
# 	gcc -o build/tabelaSimbolos.o -c src/tabelaSimbolos.c

compilador: flex/lex.yy.c bison/parser.tab.c
	gcc -o compilador flex/lex.yy.c bison/parser.tab.c -lfl


clean:
#	rm -f lex.yy.c parser.tab.c parser.tab.h parser.output compilador
	rm -f flex/lex.yy.c bison/parser.tab.* compilador
	rm -f build/*.o
