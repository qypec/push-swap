# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 17:35:05 by yquaro            #+#    #+#              #
#    Updated: 2019/11/06 17:37:52 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../includes/push_swap.mk

DIR_O = ../lib
SOURCES =

OBJECTS = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SOURCES)))

all: print $(OBJECTS)

print:
	@echo \*\*\* Compiling checker program

$(DIR_O)/%.o: %.c
	$(COMPILING) $< -o $@
