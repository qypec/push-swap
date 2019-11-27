/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 19:33:44 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/27 16:22:34 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int				tail_item_should_be_push(t_stack *stack, \
							size_t border, int median)
{
	if (stack->a->used_size == border && \
		TAIL_ITEM(stack->a)->number < median && \
			(TAIL_ITEM(stack->a)->correct_position < \
				HEAD_ITEM(stack->a)->correct_position))
		return (1);
	return (0);
}

static void				check_to_swap(t_stack *stack, int median)
{
	if (stack->a->arr[1]->number < median && \
		(HEAD_ITEM(stack->a)->correct_position > \
			stack->a->arr[1]->correct_position))
		swap_a(stack);
}

static size_t			split_unsorted_part(t_stack *stack, size_t border, \
							int median)
{
	size_t				rotate_counter;
	size_t				push_counter;
	size_t				limit;

	limit = stack->b->used_size + (border / 2);
	push_counter = 0;
	rotate_counter = 0;
	while (stack->b->used_size < limit)
	{
		if (tail_item_should_be_push(stack, border - push_counter, median))
		{
			reverse_rotate_a(stack);
			push_b(stack);
			push_counter++;
		}
		else if (HEAD_ITEM(stack->a)->number < median)
		{
			check_to_swap(stack, median);
			push_b(stack);
			push_counter++;
		}
		else
		{
			rotate_a(stack);
			rotate_counter++;
		}
	}
	if (stack->a->used_size != (border - push_counter))
		rotate_down_a(stack, rotate_counter);
	return (push_counter);
}

void					sorting_stack_a(t_stack *stack, size_t border, \
							size_t need_to_return)
{
	static size_t		transfered_size = 0;
	size_t				transfer_tmp;
	size_t				number_of_push;

	// ft_printf("{red}a: transfer = {reset} %d {red} need_to_return = {reset} %d \n", transfered_size, need_to_return);
	// dbg_print_stacks(stack);
	if (border == 0)
		return ;
	if (border <= 3)
	{
		sort_top_part_a(stack, border);
		transfer_tmp = nulling_static_variable(&transfered_size);
		sorting_stack_b(stack, transfer_tmp, transfer_tmp);
		while (need_to_return--)
			push_b(stack);
	}
	else if (border == stack->a->used_size && \
				(check_sorted_part_a(stack) == SORTED))
	{
		transfer_tmp = nulling_static_variable(&transfered_size);
		sorting_stack_b(stack, transfer_tmp, transfer_tmp);
		while (need_to_return--)
			push_b(stack);
		return ;
	}
	else
	{
		number_of_push = split_unsorted_part(stack, border, median_search(stack->a, border, "more"));
		transfered_size += number_of_push;
		sorting_stack_a(stack, border - number_of_push, need_to_return);
	}
}
