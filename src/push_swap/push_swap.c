/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:55:39 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/12 15:43:01 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int						main(int argc, char **argv)
{
	t_psstk				*stack_a;
	t_psstk				*stack_b;
	t_buff				*operations;
	char				**set_of_operations;
	int					partition;

	stack_a = get_input(argc, argv);
	stack_b = psstk_init(argc - 1);
	if (stack_a->used_size <= 3)
	{
		little_stack_sort(stack_a);
		return ;
	}
	partition = get_supporting_element(stack_a);
	move_elements_to_stack_b(stack_a, stack_b, operations, partition);
	quick_sort(stack_b, operations);
	move_elements_to_stack_a(stack_a, stack_b, operations);
	psstk_delete(&stack_a);
	psstk_delete(&stack_b);
	set_of_operations = operations_analysis(operations);
	ft_buffdel(&operations);
	print_operations(set_of_operations);
	ft_matrdel(&set_of_operations);
}
