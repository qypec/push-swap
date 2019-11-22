/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top_part_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 23:36:00 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/23 02:10:32 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void				check_to_swap(t_stack *stack)
{
	if (stack->a->arr[0]->correct_position == 2 && \
			stack->a->arr[1]->correct_position == 1)
	{
		swap_a(stack);
		add_operation(stack->operations, "sa");
	}
}

static void				sort_triplet_ascending(t_stack *stack)
{
	if (stack->a->arr[2]->correct_position == 3)
		check_to_swap(stack);
	else if (stack->a->arr[0]->correct_position == 3)
	{
		swap_a(stack);
		add_operation(stack->operations, "sa");
		rotate_a(stack);
		add_operation(stack->operations, "ra");
		swap_a(stack);
		add_operation(stack->operations, "sa");
		reverse_rotate_a(stack);
		add_operation(stack->operations, "rra");
		check_to_swap(stack);
	}
	else
	{
		rotate_a(stack);
		add_operation(stack->operations, "ra");
		swap_a(stack);
		add_operation(stack->operations, "sa");
		reverse_rotate_a(stack);
		add_operation(stack->operations, "rra");
		check_to_swap(stack);
	}
}

void					sort_top_part_a(t_stack *stack, size_t border)
{

	if (border == 1) // need?
		return ;
	fill_correct_position(stack->a, border);
	if (border == 2)
		check_to_swap(stack);
	else
		sort_triplet_ascending(stack);
}
