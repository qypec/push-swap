/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 21:36:54 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/02 22:18:41 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t			move_maxitem_to_top(t_stack *stack, size_t pushed_chunk, size_t pushed_elem)
{
	size_t				maxitem_of_chunk;
	size_t				need_to_rotate;
	size_t				i;
   	
	maxitem_of_chunk = pushed_chunk * stack->chunk[0].size + \
			stack->chunk[pushed_chunk].size - pushed_elem;
	need_to_rotate = 0;
	i = 0;
	while (i < stack->chunk[pushed_chunk].size)
	{
		if (stack->b->arr[i].correct_position == maxitem_of_chunk)
			break ;			
		need_to_rotate++;
		i++;
	}
	rotate_top_b(stack, need_to_rotate);
	return (need_to_rotate);
}

void                    move_to_stack_a(t_stack *stack)
{
	int					pushed_chunk;
	size_t				need_to_rotate;
	size_t				i;

	pushed_chunk = stack->num_of_chunks - 1;
	while (pushed_chunk >= 0)
	{
		i = 0;
		while (i < stack->chunk[pushed_chunk].size)
		{
			need_to_rotate = move_maxitem_to_top(stack, pushed_chunk, i);
			push_a(stack);
			rotate_down_b(stack, need_to_rotate);
			i++;
		}
		pushed_chunk--;
	}
}
