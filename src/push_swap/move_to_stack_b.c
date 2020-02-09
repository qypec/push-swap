/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 16:26:12 by yquaro            #+#    #+#             */
/*   Updated: 2020/02/07 22:48:02 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define NUM_OF_OPERATIONS_FROM_DOWN (stack->a->used_size - down_position)
#define BORDER (stack->chunk[chunk_num].size * (chunk_num + 1))

static int				is_fixed(t_stack *stack, size_t index_a)
{
	size_t				i;

	i = 0;
	while (i < NUM_OF_CHUNKS)
	{
		if (stack->a->num[index_a] == stack->chunk[i].fixed_item)
			return (1);
		i++;
	}
	return (0);
}

static size_t			chunk_element_from_top(t_stack *stack, size_t chunk_num)
{
	size_t				i;

	i = 0;
	while (i < stack->a->used_size)
	{
		if (!is_fixed(stack, i) && stack->a->num[i] <= (int)BORDER)
			return (i);
		i++;
	}
	return (0);
}

static size_t			chunk_element_from_down(t_stack *stack, \
							size_t chunk_num)
{
	size_t				i;

	i = stack->a->used_size - 1;
	while (i)
	{
		if (!is_fixed(stack, i) && stack->a->num[i] <= (int)BORDER)
			return (i);
		i--;
	}
	return (0);
}

static void				move_to_top(t_stack *stack, size_t chunk_num)
{
	size_t				top_position;
	size_t				down_position;

	top_position = chunk_element_from_top(stack, chunk_num);
	down_position = chunk_element_from_down(stack, chunk_num);
	if (top_position <= NUM_OF_OPERATIONS_FROM_DOWN)
		rotate_top_a(stack, top_position);
	else
		rotate_down_a(stack, NUM_OF_OPERATIONS_FROM_DOWN);
}

void					move_to_stack_b(t_stack *stack)
{
	size_t				chunk_num;
	size_t				i;

	if (STACK_SIZE < 3)
		return ;
	chunk_num = 0;
	while (chunk_num < NUM_OF_CHUNKS)
	{
		i = 0;
		while (i < stack->chunk[chunk_num].size - 1)
		{
			move_to_top(stack, chunk_num);
			push_b(stack);
			i++;
		}
		chunk_num++;
	}
}
