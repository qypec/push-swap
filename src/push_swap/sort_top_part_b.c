/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top_part_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 00:24:34 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/22 03:44:05 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void				check_to_swap_first_second(t_psstk *stack_a, \
							t_psstk *stack_b, t_buff *operations)
{
	if (stack_b->arr[0]->correct_position == 1 && \
			stack_b->arr[0]->correct_position == 2)
	{
		swap_b(stack_a, stack_b);
		add_operation(operations, "sb");
	}
}

static void				check_to_swap(t_psstk *stack_a,	t_psstk *stack_b, \
							t_buff *operations)
{
	if (stack_b->arr[2]->correct_position == 2 && \
			stack_b->arr[1]->correct_position == 1)
	{
		rotate_b(stack_a, stack_b);
		add_operation(operations, "rb");
		swap_b(stack_a, stack_b);
		add_operation(operations, "sb");
		reverse_rotate_b(stack_a, stack_b);
		add_operation(operations, "rrb");
	}
}

static void				sort_triplet_descending(t_psstk *stack_a, \
							t_psstk *stack_b, t_buff *operations)
{
	if (stack_b->arr[0]->correct_position == 3)
		check_to_swap(stack_a, stack_b, operations);
	else if (stack_b->arr[1]->correct_position == 3)
	{
		swap_b(stack_a, stack_b);
		add_operation(operations, "sb");
		check_to_swap(stack_a, stack_b, operations);
	}
	else
	{
		check_to_swap_first_second(stack_a, stack_b, operations);
		rotate_b(stack_a, stack_b);
		add_operation(operations, "rb");
		swap_b(stack_a, stack_b);
		add_operation(operations, "sb");
		reverse_rotate_b(stack_a, stack_b);
		add_operation(operations, "rrb");
		swap_b(stack_a, stack_b);
		add_operation(operations, "sb");
	}
}

void					sort_top_part_b(t_psstk *stack_a, t_psstk *stack_b, t_buff *operations, \
							size_t border)
{

	if (border == 1) // need?
		return ;
	fill_correct_position(stack_b, border);
	if (border == 2)
		check_to_swap(stack_a, stack_b, operations);
	else
		sort_triplet_descending(stack_a, stack_b, operations);
}
