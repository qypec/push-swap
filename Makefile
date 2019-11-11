# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/07 15:01:42 by yquaro            #+#    #+#              #
#    Updated: 2019/11/11 19:06:57 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include includes/push_swap.mk

all:
	@make -C libft/ all
	@make -C src/init/ all
	@make -C src/operations/ all
	@make -C src/checker/ all
	@make -C lib/ checker_compile
	@make -C src/push_swap/ all
	@make -C lib/ push_swap_compile

clean:
	@make -C libft/ clean
	@make -C lib/ clean

fclean: clean
	@make -C libft/ fclean
	@make -C lib/ fclean
	@rm -f $(EXECUTABLE_CHECKER)
	@rm -f $(UNIT_TEST_EXECUTABLE)
	@rm -f $(EXECUTABLE_PUSH_SWAP)

re: fclean all

tests:
	@make -C unit_test/ all
