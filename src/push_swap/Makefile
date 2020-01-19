# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 17:36:59 by yquaro            #+#    #+#              #
#    Updated: 2020/01/17 16:34:21 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../../includes/push_swap.mk

HEADER_H = -I ../../includes/

DIR_O = ../../lib
SOURCES = push_swap.c move_to_stack_b.c  move_to_stack_a.c \
			rotate_top_down.c self_destruction_operations.c \
			combine_operations.c

OBJECTS = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SOURCES)))

all: print $(OBJECTS)

print:
	@echo \*\*\* Compiling push_swap program

$(DIR_O)/%.o: %.c
	$(COMPILING) $< -o $@
