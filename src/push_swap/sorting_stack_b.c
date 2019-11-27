/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:36:36 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/27 16:26:19 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// HEAD_ITEM(stack->b)->number > median

static int				tail_item_should_be_push(t_stack *stack, \
							size_t border, int median)
{
	if (stack->b->used_size == border && \
		TAIL_ITEM(stack->b)->number > median && \
			(TAIL_ITEM(stack->b)->correct_position > \
				HEAD_ITEM(stack->b)->correct_position))
		return (1);
	return (0);
}

static void				check_to_swap(t_stack *stack, int median)
{
	if (stack->b->arr[1]->number > median && \
		(HEAD_ITEM(stack->b)->correct_position < \
			stack->b->arr[1]->correct_position))
		swap_b(stack);
}

static size_t			split_unsorted_part(t_stack *stack, size_t border, \
							int median)
{
	size_t				rotate_counter;
	size_t				push_counter;
	size_t				limit;

	limit = stack->a->used_size + (border / 2);
	push_counter = 0;
	rotate_counter = 0;
	while (stack->a->used_size < limit)
	{
		if (tail_item_should_be_push(stack, border - push_counter, median))
		{
			reverse_rotate_b(stack);
			push_a(stack);
			push_counter++;
		}
		else if (HEAD_ITEM(stack->b)->number > median)
		{
			check_to_swap(stack, median);
			push_a(stack);
			push_counter++;
		}
		else
		{
			rotate_b(stack);
			rotate_counter++;
		}
	}
	if (stack->b->used_size != (border - push_counter))
		rotate_down_b(stack, rotate_counter);
	return (push_counter);
}

void					sorting_stack_b(t_stack *stack, size_t border, \
							size_t need_to_return)
{
	static size_t		transfered_size = 0;
	size_t				transfer_tmp;
	size_t				number_of_push;

	// ft_printf("{green}b: transfer = {reset} %d {green} need_to_return = {reset} %d \n", transfered_size, need_to_return);
	// dbg_print_stacks(stack);
	if (border == 0)
		return ;
	if (border <= 3)
	{
		sort_top_part_b(stack, border);
		transfer_tmp = nulling_static_variable(&transfered_size);
		sorting_stack_a(stack, transfer_tmp, transfer_tmp);
		while (need_to_return--)
			push_a(stack);
	}
	else if (border == stack->b->used_size && \
				(check_sorted_part_b(stack) == SORTED))
	{
		transfer_tmp = nulling_static_variable(&transfered_size);
		sorting_stack_a(stack, transfer_tmp, transfer_tmp);
		while (need_to_return--)
			push_a(stack);
		return ;
	}
	else
	{
		number_of_push = split_unsorted_part(stack, border, median_search(stack->b, border, "less"));
		transfered_size += number_of_push;
		sorting_stack_b(stack, border - number_of_push, need_to_return);
	}
}
