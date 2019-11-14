# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/14 16:07:49 by yquaro            #+#    #+#              #
#    Updated: 2019/11/14 16:08:35 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../includes/libft.mk

SOURCES = ft_qsort.c
OBJECTS = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SOURCES)))

all: print $(OBJECTS)
	
print:
	@echo \*\*\* Compiling ft_sort

$(DIR_O)/%.o: %.c
	$(COMPILING) $< -o $@

clean:
	@rm -f ../lib/$(OBJECTS)

fclean: clean
	