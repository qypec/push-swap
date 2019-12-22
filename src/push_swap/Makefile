# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 17:36:59 by yquaro            #+#    #+#              #
#    Updated: 2019/12/22 08:23:00 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../../includes/push_swap.mk

HEADER_H = -I ../../includes/

DIR_O = ../../lib
SOURCES = push_swap.c median_search.c fill_correct_position.c \
			rotate_top_down.c self_destruction_operations.c \
			combine_operations.c

OBJECTS = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SOURCES)))

all: print $(OBJECTS)

print:
	@echo \*\*\* Compiling push_swap program

$(DIR_O)/%.o: %.c
	$(COMPILING) $< -o $@
