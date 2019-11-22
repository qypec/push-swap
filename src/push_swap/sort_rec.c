/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:58:57 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/23 02:06:54 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include <stdio.h>

void					sorting_stack_b(t_stack *stack, size_t border, \
							int need_to_return)
{
	static size_t		transferred_size = 0;
	size_t				transfer_tmp;
	size_t				rotate_counter;
	size_t				push_counter;
	int					median;
	int					limit;

	if (border == 0)
		return ;
	if (border <= 3)
	{
		sort_top_part_b(stack, border);
		transfer_tmp = transferred_size;
		transferred_size = 0;
		if (transfer_tmp != 0)
			sorting_stack_a(stack, transfer_tmp, transfer_tmp);
		if (need_to_return)
		{
			while (need_to_return--)
			{
				push_a(stack);
				add_operation(stack->operations, "pa");
			}
		}
		return ;
	}
	median = median_search(stack->b, border, "less");
	limit = stack->a->used_size + (border / 2);
	push_counter = 0;
	rotate_counter = 0;
	while (stack->a->used_size < limit)
	{
		if (HEAD_ITEM(stack->b) > median)
		{
			push_a(stack);
			add_operation(stack->operations, "pa");
			transferred_size++;
			push_counter++;
		}
		else
		{
			rotate_counter++;
			rotate_b(stack);
			add_operation(stack->operations, "rb");
		}
	}
	while (rotate_counter--)
	{
		reverse_rotate_b(stack);
		add_operation(stack->operations, "rrb");
	}
	sorting_stack_b(stack, border - push_counter, need_to_return);
}

void					sorting_stack_a(t_stack *stack, size_t border, \
							int need_to_return)
{
	static size_t		transferred_size = 0;
	size_t				transfer_tmp;
	size_t				rotate_counter;
	size_t				push_counter;
	int					median;
	int					limit;

	if (border == 0)
		return ;
	if (border <= 3)
	{
		sort_top_part_a(stack, border);
		transfer_tmp = transferred_size;
		transferred_size = 0;
		if (transfer_tmp != 0)
			sorting_stack_b(stack, transfer_tmp, transfer_tmp);
		if (need_to_return)
		{
			while (need_to_return--)
			{
				push_b(stack);
				add_operation(stack->operations, "pb");
			}
		}
		return ;
	}
	median = median_search(stack->a, border, "more");
	limit = stack->b->used_size + (border / 2);
	push_counter = 0;
	rotate_counter = 0;
	while (stack->b->used_size < limit)
	{
		if (HEAD_ITEM(stack->a) < median)
		{
			push_b(stack);
			add_operation(stack->operations, "pb");
			transferred_size++;
			push_counter++;
		}
		else
		{
			rotate_counter++;
			rotate_a(stack);
			add_operation(stack->operations, "ra");
		}
	}
	while (rotate_counter--)
	{
		reverse_rotate_a(stack);
		add_operation(stack->operations, "rra");
	}
	sorting_stack_a(stack, border - push_counter, need_to_return);
}
