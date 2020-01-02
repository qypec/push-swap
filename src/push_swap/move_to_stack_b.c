/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 16:26:12 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/02 21:20:40 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t					chunk_element_from_top(t_psstk *stack, \
							size_t pushed_chunk, size_t chunk_size)
{
	size_t				i;

	i = 0;
	while (i < stack->used_size)
	{
		if (stack->arr[i].correct_position <= chunk_size * (pushed_chunk + 1))
			return (i);
		i++;
	}
	return (0);
}

size_t					chunk_element_from_down(t_psstk *stack, \
							size_t pushed_chunk, size_t chunk_size)
{
	size_t				i;

	i = stack->used_size - 1;
	while (i)
	{
		if (stack->arr[i].correct_position <= chunk_size * (pushed_chunk + 1))
			return (i);
		i--;
	}
	return (0);
}

void                    move_to_top(t_stack *stack, size_t pushed_chunk)
{
    size_t				top_position;
	size_t				down_position;
	
    top_position = chunk_element_from_top(stack->a, pushed_chunk, stack->chunk[pushed_chunk].size);
	down_position = chunk_element_from_down(stack->a, pushed_chunk, stack->chunk[pushed_chunk].size);
	if (top_position < stack->a->used_size - down_position)
		rotate_top_a(stack, top_position);
	else
		rotate_down_a(stack, stack->a->used_size - down_position);
}

void                    move_to_stack_b(t_stack *stack)
{
    size_t              pushed_chunk;
    size_t              i;

    pushed_chunk = 0;
    while (pushed_chunk < stack->num_of_chunks)
    {
        i = 0;
        while (i < stack->chunk[pushed_chunk].size)
        {
            move_to_top(stack, pushed_chunk);
            push_b(stack);
            i++;
        }
        pushed_chunk++;
    }
}
