/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted_part_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 22:46:12 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/26 11:13:41 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void					rotate_down(t_stack *stack, size_t number_of_rotate)
{
	while (number_of_rotate--)
		reverse_rotate_a(stack);
}

static size_t			is_sorted_from_top(t_stack *stack, int *is_sorted_stack)
{
	size_t				i;
	size_t				last_sorted_index;

	i = 0;
	while (i < stack->a->used_size)
	{
		if (stack->a->arr[i]->correct_position != (i + 1))
			break ;
		i++;
	}
	if (i == 0)			/// kostil
		return (0);		///
	last_sorted_index = (i - 1);
	if (last_sorted_index == stack->a->used_size - 1)
		*is_sorted_stack = 1;
	else if (last_sorted_index >= DELIMITER(stack->a->used_size))
		return (last_sorted_index);
	return (0);
}

static size_t			is_sorted_from_down(t_stack *stack, int *is_sorted_stack)
{
	size_t				i;
	size_t				last_sorted_index;

	if (*is_sorted_stack)
		return (0);
	i = stack->a->used_size;
	while (i--)
	{
		if (stack->a->arr[i]->correct_position != (i + 1))
			break ;
	}
	last_sorted_index = (i + 1);
	if (last_sorted_index == 1)
		*is_sorted_stack = 1;
	else if (last_sorted_index < DELIMITER(stack->a->used_size))
		return (last_sorted_index);
	return (0);
}

int						check_sorted_part_a(t_stack *stack)
{
	size_t				number_of_rotate;
	size_t				last_sorted_index;
	int					is_sorted_stack;

	is_sorted_stack = 0;
	fill_correct_position(stack->a, stack->a->used_size);
	// ft_printf("{red}a(check_sorted_part):{reset}\n");
	// dbg_print_stacks(stack);
	if ((last_sorted_index = is_sorted_from_top(stack, &is_sorted_stack)))
	{
		number_of_rotate = stack->a->used_size - last_sorted_index - 1;
		rotate_down(stack, number_of_rotate);
		sorting_stack_a(stack, number_of_rotate, 0);
		while (number_of_rotate--)
			rotate_a(stack);
	}
	else if ((last_sorted_index = is_sorted_from_down(stack, &is_sorted_stack)))
		sorting_stack_a(stack, last_sorted_index, 0);
	else if (!is_sorted_stack)
		return (NO_RESULT);
	return (SORTED);
}
