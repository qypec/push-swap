/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 19:33:44 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/26 07:08:18 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define ALREADY_SORTED 1
#define UNSORTED 0

size_t					nulling_static_variable(size_t *transfered_size)
{
	size_t				transfer_tmp;

	transfer_tmp = *transfered_size;
	*transfered_size = 0;
	return (transfer_tmp);
}

static size_t			push_to_stack_b(t_stack *stack, size_t border, int median) // optimize
{
	size_t				rotate_counter;
	size_t				push_counter;
	size_t				limit;

	limit = stack->b->used_size + (border / 2);
	push_counter = 0;
	rotate_counter = 0;
	while (stack->b->used_size < limit)
	{
		if (HEAD_ITEM(stack->a) < median)
		{
			push_b(stack);
			push_counter++;
		}
		else
		{
			rotate_counter++;
			rotate_a(stack);
		}
	}
	while (rotate_counter--) // if used_size != border
		reverse_rotate_a(stack);
	return (push_counter);
}

void					sorting_stack_a(t_stack *stack, size_t border, \
							size_t need_to_return)
{
	static size_t		transfered_size = 0;
	size_t				transfer_tmp;
	size_t				number_of_push;

	if (border == 0)
		return ;
	if (border <= 3)
	{
		sort_top_part_a(stack, border);
		transfer_tmp = nulling_static_variable(&transfered_size);
		sorting_stack_b(stack, transfer_tmp, transfer_tmp);
		while (transfer_tmp <= 3 && need_to_return--)
			push_b(stack);
	}
	else if (border == stack->a->used_size && \
				(check_sorted_part_a(stack) == SORTED))
		return ;
	else
	{
		number_of_push = push_to_stack_b(stack, border, median_search(stack->a, border, "more"));
		transfered_size += number_of_push;
		sorting_stack_a(stack, border - number_of_push, need_to_return);
	}
}
