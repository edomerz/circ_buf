CC=gcc
CFLAGS=-g -std=c89 -ansi -Wall -Werror -pedantic -D_DEBUG -I .
DEPS = circ_buf.h
OBJ = circ_buf.o circ_buf_test.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

circ_buf_test: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
