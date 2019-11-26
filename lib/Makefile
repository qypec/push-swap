# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/07 15:11:54 by yquaro            #+#    #+#              #
#    Updated: 2019/11/26 04:14:11 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../includes/push_swap.mk

CFLAGS = -g -Wall -Wextra -Werror
COMPILING = $(CC) $(CFLAGS) $(HEADER_H)

checker_compile:
	@mv ../libft/$(LIBNAME) $(LIBNAME)
	$(COMPILING) *.o $(LIBNAME) -o $(EXECUTABLE_CHECKER)
	@mv $(EXECUTABLE_CHECKER) ../$(EXECUTABLE_CHECKER)
	@echo \*\*\* CHECKER COMPILED!

push_swap_compile:
	@rm -r checker.o
	$(COMPILING) *.o $(LIBNAME) -o $(EXECUTABLE_PUSH_SWAP)
	@mv $(EXECUTABLE_PUSH_SWAP) ../$(EXECUTABLE_PUSH_SWAP) # 	@rm -r push_swap.o
	@echo \*\*\* PUSH_SWAP COMPILED!

unit_test:
	@mv ../libft/$(LIBNAME) $(LIBNAME)
	$(COMPILING) *.o $(LIBNAME) -o $(UNIT_TEST_EXECUTABLE)
	@mv $(UNIT_TEST_EXECUTABLE) ../$(UNIT_TEST_EXECUTABLE)
	@echo \*\*\* UNIT_TEST COMPILED!

clean:
	@rm -f *.o

fclean:
	@rm -f $(LIBNAME)