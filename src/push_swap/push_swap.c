/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:55:39 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/23 00:28:08 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int						main(int argc, char **argv)
{
	t_psstk				*stack_a;
	t_psstk				*stack_b;
	t_buff				*operations;
	// char				**set_of_operations;

	stack_a = get_input(argc, argv);
	stack_b = psstk_init(argc - 1);
	operations = ft_buffinit(1000); // need a formula
	sorting_stack_a(stack_a, stack_b, operations, stack_a->used_size, 0);
	ft_putendl(operations->str);
	// dbg_print_stacks(stack_a, stack_b);

	psstk_delete(&stack_a);
	psstk_delete(&stack_b);
	ft_buffdel(&operations);
}
