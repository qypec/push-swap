/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top_part_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 23:36:00 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/22 00:44:20 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void				check_to_swap(t_psstk *stack_a,	t_psstk *stack_b, \
							t_buff *operations)
{
	if (stack_a->arr[0]->correct_position == 2 && \
			stack_a->arr[1]->correct_position == 1)
	{
		swap_a(stack_a, stack_b);
		add_operation(operations, "sa");
	}
}

static void				sort_triplet_ascending(t_psstk *stack_a, \
							t_psstk *stack_b, t_buff *operations)
{
	if (stack_a->arr[2]->correct_position == 3)
		check_to_swap(stack_a, stack_b, operations);
	else if (stack_a->arr[0]->correct_position == 3)
	{
		swap_a(stack_a, stack_b);
		add_operation(operations, "sa");
		rotate_a(stack_a, stack_b);
		add_operation(operations, "ra");
		swap_a(stack_a, stack_b);
		add_operation(operations, "sa");
		reverse_rotate_a(stack_a, stack_b);
		add_operation(operations, "rra");
		check_to_swap(stack_a, stack_b, operations);
	}
	else
	{
		rotate_a(stack_a, stack_b);
		add_operation(operations, "ra");
		swap_a(stack_a, stack_b);
		add_operation(operations, "sa");
		reverse_rotate_a(stack_a, stack_b);
		add_operation(operations, "rra");
		check_to_swap(stack_a, stack_b, operations);
	}
}

void					sort_top_part_a(t_psstk *stack_a, t_psstk *stack_b, t_buff *operations, \
							size_t border)
{

	if (border == 1) // need?
		return ;
	fill_correct_position(stack_a, border);
	if (border == 2)
		check_to_swap(stack_a, stack_b, operations);
	else
		sort_triplet_ascending(stack_a, stack_b, operations);
}
