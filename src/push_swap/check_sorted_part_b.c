/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted_part_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 23:13:32 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/25 23:24:35 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int				rotate_down(t_stack *stack, size_t number_of_rotate)
{
	size_t				i;

	i = 0;
	while (i < number_of_rotate)
	{
		reverse_rotate_b(stack);
		i++;
	}
	sorting_stack_b(stack, number_of_rotate, 0);
	fill_correct_position(stack->a, number_of_rotate); // need?
	i = 0;
	if (stack->b->arr[0]->correct_position == )
	while (i < number_of_rotate)
	{
		rotate_b(stack);
		i++;
	}
	return (ALREADY_SORTED);
}

static int				check_sorted_part(t_stack *stack, size_t border)
{
	size_t				i;

	fill_correct_position(stack->b, border);
	i = 0;
	while (i < border - 1)
	{
		if ((stack->b->arr[i]->correct_position - 1) != \
				stack->b->arr[i + 1]->correct_position)
			break ;
		i++;
	}
	if ((i > (border / 2)) && (i != (border - 1)))
		return (rotate_down(stack, border - i - 1, ));
	i = border - 1;
	while (i - 1)
	{
		if ((stack->b->arr[i]->correct_position + 1) != \
				stack->b->arr[i - 1]->correct_position)
			break ;
		i--;
	}
	if (i <= ft_round_up(border / 2))
		sorting_stack_b(stack, i, 0);
	else
		return (UNSORTED);
	return (ALREADY_SORTED);
}
