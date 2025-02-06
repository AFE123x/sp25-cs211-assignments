CC = gcc
CFLAG = -fsanitize=address,undefined -Og -g -Wall -Werror -std=c11
second: second.c
	$(CC) -o second second.c $(CFLAG)
clean: second
	rm -f second
