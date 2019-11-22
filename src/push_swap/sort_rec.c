/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:58:57 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/23 00:49:47 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include <stdio.h>

void					sorting_stack_b(t_psstk *stack_a, t_psstk *stack_b, \
							t_buff *operations, size_t border, int need_to_return)
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
		sort_top_part_b(stack_a, stack_b, operations, border);
		transfer_tmp = transferred_size;
		transferred_size = 0;
		if (transfer_tmp != 0)
			sorting_stack_a(stack_a, stack_b, operations, transfer_tmp, transfer_tmp);
		if (need_to_return)
		{
			while (need_to_return--)
			{
				push_a(stack_a, stack_b);
				add_operation(operations, "pa");
			}
		}
		return ;
	}
	median = median_search(stack_b, border, "less");
	limit = stack_a->used_size + (border / 2);
	push_counter = 0;
	rotate_counter = 0;
	while (stack_a->used_size < limit)
	{
		if (HEAD_ITEM(stack_b) > median)
		{
			push_a(stack_a, stack_b);
			add_operation(operations, "pa");
			transferred_size++;
			push_counter++;
		}
		else
		{
			rotate_counter++;
			rotate_b(stack_a, stack_b);
			add_operation(operations, "rb");
		}
	}
	while (rotate_counter--)
	{
		reverse_rotate_b(stack_a, stack_b);
		add_operation(operations, "rrb");
	}
	sorting_stack_b(stack_a, stack_b, operations, border - push_counter, need_to_return);
}

void					sorting_stack_a(t_psstk *stack_a, t_psstk *stack_b, \
							t_buff *operations, size_t border, int need_to_return)
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
		sort_top_part_a(stack_a, stack_b, operations, border);
		transfer_tmp = transferred_size;
		transferred_size = 0;
		if (transfer_tmp != 0)
			sorting_stack_b(stack_a, stack_b, operations, transfer_tmp, transfer_tmp);
		if (need_to_return)
		{
			while (need_to_return--)
			{
				push_b(stack_a, stack_b);
				add_operation(operations, "pb");
			}
		}
		return ;
	}
	median = median_search(stack_a, border, "more");
	limit = stack_b->used_size + (border / 2);
	push_counter = 0;
	rotate_counter = 0;
	while (stack_b->used_size < limit)
	{
		if (HEAD_ITEM(stack_a) < median)
		{
			push_b(stack_a, stack_b);
			add_operation(operations, "pb");
			transferred_size++;
			push_counter++;
		}
		else
		{
			rotate_counter++;
			rotate_a(stack_a, stack_b);
			add_operation(operations, "ra");
		}
	}
	while (rotate_counter--)
	{
		reverse_rotate_a(stack_a, stack_b);
		add_operation(operations, "rra");
	}
	sorting_stack_a(stack_a, stack_b, operations, border - push_counter, need_to_return);
}
