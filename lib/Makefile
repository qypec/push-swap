# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/07 15:11:54 by yquaro            #+#    #+#              #
#    Updated: 2019/11/10 23:52:26 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../includes/push_swap.mk

CFLAGS = -g -Wall -Wextra -Werror
COMPILING = $(CC) $(CFLAGS) $(HEADER_H)

all:
	@mv ../libft/$(LIBNAME) $(LIBNAME)
	$(COMPILING) *.o $(LIBNAME) -o $(EXECUTABLE)
	@mv $(EXECUTABLE) ../$(EXECUTABLE)
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