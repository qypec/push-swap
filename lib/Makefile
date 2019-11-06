# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/07 15:11:54 by yquaro            #+#    #+#              #
#    Updated: 2019/11/06 17:16:28 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../includes/push_swap.mk

CFLAGS = -g -Wall -Wextra -Werror
COMPILING = $(CC) $(CFLAGS) $(HEADER_H)

all:
	$(COMPILING) *.o $(LIBNAME) -o $(EXECUTABLE)
	@mv $(EXECUTABLE) ../$(EXECUTABLE)
	@echo \*\*\* PUSH_SWAP COMPILED!

clean:
	@rm -f *.o

fclean:
	@rm -f $(LIBNAME)