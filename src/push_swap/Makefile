# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 17:36:59 by yquaro            #+#    #+#              #
#    Updated: 2019/11/20 18:13:45 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../../includes/push_swap.mk

HEADER_H = -I ../../includes/

DIR_O = ../../lib
SOURCES = push_swap.c push_to_stack_b.c add_operation.c sort_triplet.c

OBJECTS = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SOURCES)))

all: print $(OBJECTS)

print:
	@echo \*\*\* Compiling push_swap program

$(DIR_O)/%.o: %.c
	$(COMPILING) $< -o $@
