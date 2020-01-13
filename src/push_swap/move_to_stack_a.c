/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 21:36:54 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/13 17:57:48 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int				correct_place_a(t_stack *stack, size_t correct_position)
{
	size_t				i;

	if (stack->a->arr[stack->a->used_size - 1].correct_position + 1 == correct_position)
		return (0);
	i = 0;
	while (i < stack->a->used_size && stack->a->arr[i].correct_position - 1 != correct_position)
		i++;
	if (i == stack->a->used_size)
		return (-1);
	return (i);
}

static void				move_optimum_item_to_top(t_stack *stack)
{
	size_t				num_of_operations[stack->b->used_size];
	size_t				i;
	int					num_to_correct_place;

	i = 0;
	while (i < stack->b->used_size)
	{
		num_of_operations[i] = i;
		if (num_of_operations[i] > stack->b->used_size / 2)
			num_of_operations[i] = stack->b->used_size - num_of_operations[i];
		if ((num_to_correct_place = correct_place_a(stack, stack->b->arr[i].correct_position)) == -1)
			num_of_operations[i] = (size_t)0 - 1;
		else
			num_of_operations[i] += num_to_correct_place;
		i++;
	}
	if ((i = ft_arraymin((size_t *)&num_of_operations, stack->b->used_size)) <= stack->b->used_size / 2)
		rotate_top_b(stack, i);
	else
		rotate_down_b(stack, stack->b->used_size - i);
}

static void				push_to_a(t_stack *stack)
{
	size_t				need_to_rotate;

	need_to_rotate = correct_place_a(stack, HEAD_ITEM(stack->b).correct_position);
	if (need_to_rotate <= stack->a->used_size / 2)
		rotate_top_a(stack, need_to_rotate);
	else
		rotate_down_a(stack, stack->a->used_size - need_to_rotate);
	push_a(stack);
}

void                    move_to_stack_a(t_stack *stack)
{
	while (stack->b->used_size != 0)
	{
		move_optimum_item_to_top(stack);
		push_to_a(stack);

// /* debugging */

		// dbg_print_stacks(stack);
	
// /* */
	}
}
