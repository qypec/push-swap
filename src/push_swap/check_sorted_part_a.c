/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted_part_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 22:46:12 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/25 23:37:42 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int						check_sorted_part_a(t_stack *stack)
{
	if ((last_sorted_index = is_sorted_from_top(stack)))
	{
		number_of_rotate = rotate_down(stack, last_sorted_index);
		sorting_stack_a(stack, number_of_rotate, 0);
		while (number_of_rotate--)
			reverse_rotate_a(stack);
	}
	else if ((last_sorted_index = is_sorted_from_down(stack)))
		sorting_stack_a(stack, stack->used_size - last_sorted_index, 0);
	else if (search_sorted_piece(stack) == NOT_RESULT)
		return (NOT_RESULT);
	return (ALREADY_SORTED);
}
