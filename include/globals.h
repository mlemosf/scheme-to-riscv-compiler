/* Definições e variáveis globais */
#ifndef GLOBALS_H
#define GLOBALS_H


#define TRUE 1
#define FALSE 0

/* Tipos */
#define T_INT 0

/* === DEFINIÇÕES DO RISCV ===  */

/* Ponteiros do RISC-V */
#define sp "sp" // Stack pointer
#define gp "gp" // Global pointer
#define pc "pc" // Program counter
#define ra "ra" // Return address
#define x0 "x0" // Jump address

/* Registradores temporários */
#define t1 "t1"
#define t2 "t2"
#define t3 "t3"
#define t4 "t4"
#define t5 "t5"
#define t6 "t6"

/* Registradores salvos */
#define s2 "s2"
#define s3 "s3"
#define s4 "s4"

/* Offsets */
#define byte_offset 1
#define halfword_offset 2
#define word_offset 4

#endif
