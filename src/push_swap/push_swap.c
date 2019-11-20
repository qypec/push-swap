/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:55:39 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/20 18:14:47 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int						main(int argc, char **argv)
{
	t_psstk				*stack_a;
	t_psstk				*stack_b;
	t_buff				*operations;
	char				**set_of_operations;

	stack_a = get_input(argc, argv);
	stack_b = psstk_init(argc - 1);
	operations = ft_buffinit(100); // need a formula
	// if (stack_a->size <= 3)
	// {

	// 	return ;
	// }
	push_to_stack_b(stack_a, stack_b, operations);
	sort_triplet_stack_a(stack_a, stack_b, operations);
	ft_putendl(operations->str);

	// sort_stack_b(stack_a, stack_b, operations);
	// psstk_delete(&stack_a);
	// psstk_delete(&stack_b);
	// set_of_operations = operations_analysis(operations);
	// ft_buffdel(&operations);
	// print_operations(set_of_operations);
	// ft_matrdel(&set_of_operations);
}
