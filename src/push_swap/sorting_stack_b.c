/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:36:36 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/25 21:53:54 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define ALREADY_SORTED 1
#define UNSORTED 0

static int				rotate_down(t_stack *stack, size_t last_sorted_index, \
							size_t border)
{
	size_t				i;
	size_t				number_of_rotate;

	number_of_rotate = border - last_sorted_index - 1;
	i = 0;
	while (i < number_of_rotate)
	{
		reverse_rotate_b(stack);
		i++;
	}
	sorting_stack_b(stack, number_of_rotate, 0);
	i = 0;
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
		return (rotate_down(stack, i, border));
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

static size_t			push_to_stack_a(t_stack *stack, size_t border, int median) // optimize
{
	size_t				rotate_counter;
	size_t				push_counter;
	size_t				limit;

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
							size_t need_to_return)
{
	static size_t		transfered_size = 0;
	size_t				transfer_tmp;
	size_t				number_of_push;

	if (border == 0)
		return ;
	if (border <= 3)
	{
		sort_top_part_b(stack, border);
		transfer_tmp = nulling_static_variable(&transfered_size);
		sorting_stack_a(stack, transfer_tmp, transfer_tmp);
		while (transfer_tmp <= 3 && need_to_return--)
			push_a(stack);
	}
	else if (border == stack->b->used_size && \
				(check_sorted_part(stack, border) == ALREADY_SORTED))
		return ;
	else
	{
		number_of_push = push_to_stack_a(stack, border, median_search(stack->b, border, "less"));
		transfered_size += number_of_push;
		sorting_stack_b(stack, border - number_of_push, need_to_return);
	}
}
