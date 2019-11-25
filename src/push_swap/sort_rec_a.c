/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rec_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 05:26:24 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/25 18:25:57 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define UNSORTED 1
#define SORTED 0

static int				check_sorted_part(t_stack *stack, size_t border);

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

static int				rotate_down(t_stack *stack, size_t last_sorted_index, \
							size_t border)
{
	size_t				i;
	size_t				number_of_rotate;

	number_of_rotate = border - last_sorted_index - 1;
	i = 0;
	while (i < number_of_rotate)
	{
		reverse_rotate_a(stack);
		i++;
	}
	// if (check_sorted_part(stack, border) == SORTED)
		// return (SORTED);
	sorting_stack_a(stack, number_of_rotate, 0);
	i = 0;
	while (i < number_of_rotate)
	{
		rotate_a(stack);
		i++;
	}
	return (SORTED);
}

static int				check_sorted_part(t_stack *stack, size_t border)
{
	size_t				i;

	fill_correct_position(stack->a, border);
	i = 0;
	while (i < border - 1)
	{
		if ((stack->a->arr[i]->correct_position + 1) != \
				stack->a->arr[i + 1]->correct_position)
			break ;
		i++;
	}
	if ((i > (border / 2)) && (i != (border - 1)))
		return (rotate_down(stack, i, border));
	i = border - 1;
	while (i - 1)
	{
		if ((stack->a->arr[i]->correct_position - 1) != \
				stack->a->arr[i - 1]->correct_position)
			break ;
		i--;
	}
	if (i <= ft_round_up(border / 2))
		sorting_stack_a(stack, i, 0);
	else
		return (UNSORTED);
	return (SORTED);
}

void					sorting_stack_a(t_stack *stack, size_t border, \
							int need_to_return)
{
	static size_t		transferred_size = 0;
	size_t				transfer_tmp;
	size_t				number_of_push;

	if (border > 4 && check_sorted_part(stack, border) == SORTED)
		return ;
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
