CC = gcc
CFLAGS = -g -std=c11 -Werror -Wextra -Wall -pedantic
matrixtk : main.c
	$(CC) $(CFLAGS) $^ -o $@ -lm
