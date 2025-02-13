# This is a reference Makefile for you benefit.

CC=gcc
CFLAG = -fsanitize=address,undefined  -Wall -Werror -std=c11 -lm -g -Og

first: first.c 
	$(CC) -o first first.c $(CFLAG)
clean: first
	rm -f first
