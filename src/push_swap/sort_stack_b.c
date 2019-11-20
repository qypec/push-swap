/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 18:23:59 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/20 20:04:04 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void				fill_correct_position_reverse(t_psstk *stack)
{
	int					*arr;
	size_t				i;
	size_t				j;

	arr = create_temp_array(stack, 3);
	ft_qsort(arr, 3);
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < stack->used_size)
		{
			if (stack->arr[j]->number == arr[i])
			{
				stack->arr[j]->correct_position = 3 - i;
				break ;
			}
			j++;
		}
		i++;
	}
	ft_memdel((void **)&arr);
}

static void				check_first_second_to_swap(t_psstk *stack_a, \
							t_psstk *stack_b, t_buff *operations)
{
	if (stack_a->arr[0]->correct_position == 2 && \
			stack_a->arr[1]->correct_position == 1)
	{
		swap_a(stack_a, stack_b);
		add_operation(operations, "sa");
	}
}

static void				sort_triplet_stack_b(t_psstk *stack_a, \
							t_psstk *stack_b, t_buff *operations)
{
	fill_correct_position_reverse(stack_b);
	if (stack_b->arr[2]->correct_position == 3)
		check_first_second_to_swap(stack_a, stack_b, operations);
	else if (stack_b->arr[0]->correct_position == 3)
	{
		swap_b(stack_a, stack_b);
		add_operation(operations, "sb");
		rotate_b(stack_a, stack_b);
		add_operation(operations, "rb");
		swap_b(stack_a, stack_b);					// optimize
		add_operation(operations, "sb");
		reverse_rotate_b(stack_a, stack_b);
		add_operation(operations, "rrb");
		check_first_second_to_swap(stack_a, stack_b, operations);
	}
	else
	{
		rotate_b(stack_a, stack_b);
		add_operation(operations, "rb");
		swap_b(stack_a, stack_b);
		add_operation(operations, "sb");
		reverse_rotate_b(stack_a, stack_b);
		add_operation(operations, "rrb");
		check_first_second_to_swap(stack_a, stack_b, operations);
	}
}

void					sort_stack_b(t_psstk *stack_a, t_psstk *stack_b, \
							t_buff *operations)
{
	size_t				i;

	while (!IS_EMPTY(stack_b))
	{
		sort_triplet_stack_b(stack_a, stack_b, operations);
		i = 0;
		while (i < 3)
		{
			push_a(stack_a, stack_b);
			add_operation(operations, "pa");
			i++;
		}
	}
}
