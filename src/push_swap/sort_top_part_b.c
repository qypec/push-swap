/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top_part_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 00:24:34 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/23 02:13:38 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void				check_to_swap_first_second(t_stack *stack)
{
	if (stack->b->arr[0]->correct_position == 1 && \
			stack->b->arr[1]->correct_position == 2)
	{
		swap_b(stack);
		add_operation(stack->operations, "sb");
	}
}

static void				check_to_swap(t_stack *stack)
{
	if (stack->b->arr[2]->correct_position == 2 && \
			stack->b->arr[1]->correct_position == 1)
	{
		rotate_b(stack);
		add_operation(stack->operations, "rb");
		swap_b(stack);
		add_operation(stack->operations, "sb");
		reverse_rotate_b(stack);
		add_operation(stack->operations, "rrb");
	}
}

static void				sort_triplet_descending(t_stack *stack)
{
	if (stack->b->arr[0]->correct_position == 3)
		check_to_swap(stack);
	else if (stack->b->arr[1]->correct_position == 3)
	{
		swap_b(stack);
		add_operation(stack->operations, "sb");
		check_to_swap(stack);
	}
	else
	{
		check_to_swap_first_second(stack);
		rotate_b(stack);
		add_operation(stack->operations, "rb");
		swap_b(stack);
		add_operation(stack->operations, "sb");
		reverse_rotate_b(stack);
		add_operation(stack->operations, "rrb");
		swap_b(stack);
		add_operation(stack->operations, "sb");
	}
}

void					sort_top_part_b(t_stack *stack, size_t border)
{

	if (border == 1) // need?
		return ;
	fill_correct_position(stack->b, border);
	if (border == 2)
		check_to_swap_first_second(stack);
	else
		sort_triplet_descending(stack);
}
