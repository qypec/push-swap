/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:58:57 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/23 03:02:43 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static size_t			push_to_stack_a(t_stack *stack, size_t border)
{
	size_t				rotate_counter;
	size_t				push_counter;
	int					median;
	size_t				limit;

	median = median_search(stack->b, border, "less");
	limit = stack->a->used_size + (border / 2);
	push_counter = 0;
	rotate_counter = 0;
	while (stack->a->used_size < limit)
	{
		if (HEAD_ITEM(stack->b) > median)
		{
			push_a(stack);
			push_counter++;
		}
		else
		{
			rotate_b(stack);
			rotate_counter++;
		}
	}
	while (rotate_counter--)
		reverse_rotate_b(stack);
	return (push_counter);
}

void					sorting_stack_b(t_stack *stack, size_t border, \
							int need_to_return)
{
	static size_t		transferred_size = 0;
	size_t				transfer_tmp;
	size_t				number_of_push;

	if (border <= 3)
	{
		sort_top_part_b(stack, border);
		transfer_tmp = transferred_size;
		transferred_size = 0;
		if (transfer_tmp != 0)
			sorting_stack_a(stack, transfer_tmp, transfer_tmp);
		while (need_to_return--)
			push_a(stack);
	}
	else
	{
		number_of_push = push_to_stack_a(stack, border);
		transferred_size += number_of_push;
		sorting_stack_b(stack, border - number_of_push, need_to_return);
	}
}

static size_t			push_to_stack_b(t_stack *stack, size_t border)
{
	size_t				rotate_counter;
	size_t				push_counter;
	int					median;
	size_t				limit;

	median = median_search(stack->a, border, "more");
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
	while (rotate_counter--)
		reverse_rotate_a(stack);
	return (push_counter);
}

void					sorting_stack_a(t_stack *stack, size_t border, \
							int need_to_return)
{
	static size_t		transferred_size = 0;
	size_t				transfer_tmp;
	size_t				number_of_push;

	if (border <= 3)
	{
		sort_top_part_a(stack, border);
		transfer_tmp = transferred_size;
		transferred_size = 0;
		if (transfer_tmp != 0)
			sorting_stack_b(stack, transfer_tmp, transfer_tmp);
		while (need_to_return--)
			push_b(stack);
	}
	else
	{
		number_of_push = push_to_stack_b(stack, border);
		transferred_size += number_of_push;
		sorting_stack_a(stack, border - number_of_push, need_to_return);
	}
}
