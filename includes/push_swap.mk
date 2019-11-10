# Base variables for push_swap

CC = gcc
CFLAGS = -g -c #-Wall -Wextra -Werror
HEADER_H = -I ../includes/
COMPILING = $(CC) $(CFLAGS) $(HEADER_H)
UNIT_TEST_EXECUTABLE = test_unit
EXECUTABLE = checker
LIBNAME = libft.a
