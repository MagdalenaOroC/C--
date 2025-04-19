CC=gcc
NASM=nasm
CFLAGS=-g -Wall -m64
LDFLAGS=-m64

OBJ_C=c/interface.o
OBJ_ASM=asm/calculator.o
BIN=gini

all: $(BIN)

$(OBJ_ASM): asm/calculator.asm
	$(NASM) -f elf64 $< -o $@

$(OBJ_C): c/interface.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN): $(OBJ_C) $(OBJ_ASM)
	$(CC) $(CFLAGS) $(OBJ_C) $(OBJ_ASM) -o $@ $(LDFLAGS)

run:
	./$(BIN) 42.7

clean:
	rm -f c/*.o asm/*.o *.o $(BIN)
