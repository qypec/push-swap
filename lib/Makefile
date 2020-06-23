# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/07 15:11:54 by yquaro            #+#    #+#              #
#    Updated: 2020/02/07 21:29:11 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../includes/push_swap.mk

CFLAGS = -g -Wall -Wextra -Werror
COMPILING = $(CC) $(CFLAGS) -lncurses $(HEADER_H)

checker_compile:
	@mv ../libft/$(LIBNAME) $(LIBNAME)
	@mv checker.o checker_/checker.o
	$(COMPILING) *.o checker_/checker.o $(LIBNAME) -o $(EXECUTABLE_CHECKER)
	@mv $(EXECUTABLE_CHECKER) ../$(EXECUTABLE_CHECKER)
	@echo \*\*\* CHECKER COMPILED!

push_swap_compile:
	@mv push_swap.o push_swap_/push_swap.o
	$(COMPILING) *.o push_swap_/push_swap.o $(LIBNAME) -o $(EXECUTABLE_PUSH_SWAP)
	@mv $(EXECUTABLE_PUSH_SWAP) ../$(EXECUTABLE_PUSH_SWAP) 
	@echo \*\*\* PUSH_SWAP COMPILED!

clean:
	@rm -f *.o
	@rm -f checker_/checker.o
	@rm -f push_swap_/push_swap.o

fclean: clean
	@rm -f $(LIBNAME)