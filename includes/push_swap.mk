# Base variables for push_swap

CC = gcc
CFLAGS = -g -c -Wall -Wextra -Werror
HEADER_H = -I ../includes/
COMPILING = $(CC) $(CFLAGS) $(HEADER_H)
EXECUTABLE_CHECKER = checker
EXECUTABLE_PUSH_SWAP = push_swap
LIBNAME = libft.a
