# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 17:36:59 by yquaro            #+#    #+#              #
#    Updated: 2019/11/29 00:02:37 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../../includes/push_swap.mk

HEADER_H = -I ../../includes/

DIR_O = ../../lib
SOURCES = push_swap.c median_search.c fill_correct_position.c \
			sorting_stack_a.c sorting_stack_b.c \
			sort_top_part_a.c sort_top_part_b.c \
			check_sorted_part_a.c check_sorted_part_b.c rotate_top_down.c \
			operations_analyzer.c

OBJECTS = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SOURCES)))

all: print $(OBJECTS)

print:
	@echo \*\*\* Compiling push_swap program

$(DIR_O)/%.o: %.c
	$(COMPILING) $< -o $@
