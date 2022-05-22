# Makefile para o analisador léxico/* Functions */
#OBJS = build/tabelaSimbolos.o
# OBJS = ""

# parser.tab.c parser.tab.h: parser.y
# 	bison -d parser.y

flex/lex.yy.c: 
	flex -o flex/lex.yy.c flex/scanner.l

# build/tabelaSimbolos.o: src/tabelaSimbolos.c include/tabelaSimbolos.h
# 	gcc -o build/tabelaSimbolos.o -c src/tabelaSimbolos.c

compilador: flex/lex.yy.c 
	gcc -o compilador flex/lex.yy.c -lfl

all: compilador 

clean:
#	rm -f lex.yy.c parser.tab.c parser.tab.h parser.output compilador
	rm -f flex/lex.yy.c compilador
	rm -f build/*.o
