CC = gcc
CFLAG = -fsanitize=address,undefined -Og -g -Wall -Werror -std=c11
third: third.c
	$(CC) -o third third.c $(CFLAG)
clean: third
	rm -f third
