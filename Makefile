CC = gcc
CFLAGS = -std=c11 -Werror -Wextra -Wall -pedantic
main : main.c
	$(CC) $(CFLAGS) $^ -o $@