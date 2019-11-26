/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted_part_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 23:13:32 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/26 07:35:40 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t			is_sorted_from_top(t_stack *stack, int *is_sorted_stack)
{
	size_t				i;
	size_t				last_sorted_index;

	i = 0;
	while (i < stack->b->used_size)
	{
		if (stack->b->arr[i]->correct_position != (stack->b->used_size - i))
			break ;
		i++;
	}
	if (i == 0)			/// kostil
		return (0);		///
	last_sorted_index = (i - 1);
	if (last_sorted_index == stack->b->used_size - 4)
		*is_sorted_stack = 1;
	else if (last_sorted_index >= DELIMITER(stack->b->used_size))
		return (last_sorted_index);
	return (0);
}

static size_t			is_sorted_from_down(t_stack *stack, int *is_sorted_stack)
{
	size_t				i;
	size_t				last_sorted_index;

	i = stack->b->used_size - 1;
	while (i)
	{
		if (stack->b->arr[i]->correct_position != (stack->b->used_size - i))
			break ;
		i--;
	}
	last_sorted_index = (i + 1);
	if (last_sorted_index == 1)
		*is_sorted_stack = 1;
	else if (last_sorted_index < DELIMITER(stack->b->used_size))
		return (last_sorted_index);
	return (0);
}

int						check_sorted_part_b(t_stack *stack)
{
	size_t				number_of_rotate;
	size_t				last_sorted_index;
	int					is_sorted_stack;

	is_sorted_stack = 0;
	fill_correct_position(stack->b, stack->b->used_size);
	if ((last_sorted_index = is_sorted_from_top(stack, &is_sorted_stack)))
	{
		number_of_rotate = stack->b->used_size - last_sorted_index - 1;
		rotate_down(stack, number_of_rotate);
		sorting_stack_b(stack, number_of_rotate, 0);
		while (number_of_rotate--)
			rotate_b(stack);
	}
	else if ((last_sorted_index = is_sorted_from_down(stack, &is_sorted_stack)))
	{
		number_of_rotate = last_sorted_index;
		sorting_stack_b(stack, last_sorted_index, 0);
		while (number_of_rotate--)
			rotate_b(stack);
	}
	else if (!is_sorted_stack)
		return (NO_RESULT);
	return (SORTED);
}
