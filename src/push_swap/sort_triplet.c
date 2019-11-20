/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_triplet.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:53:30 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/20 18:21:32 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void					fill_correct_position(t_psstk *stack)
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
				stack->arr[j]->correct_position = i + 1;
				break ;
			}
			j++;
		}
		i++;
	}
}

static void				check_first_second_for_swap(t_psstk *stack_a, \
							t_psstk *stack_b, t_buff *operations)
{
	if (stack_a->arr[0]->correct_position == 2 && \
			stack_a->arr[1]->correct_position == 1)
	{
		swap_a(stack_a, stack_b);
		add_operation(operations, "sa");
	}
}

void					sort_triplet_stack_a(t_psstk *stack_a, \
							t_psstk *stack_b, t_buff *operations)
{
	fill_correct_position(stack_a);
	if (stack_a->arr[2]->correct_position == 3)
		check_first_second_for_swap(stack_a, stack_b, operations);
	else if (stack_a->arr[0]->correct_position == 3)
	{
		rotate_a(stack_a, stack_b);
		add_operation(operations, "ra");
		check_first_second_for_swap(stack_a, stack_b, operations);
	}
	else
	{
		reverse_rotate_a(stack_a, stack_b);
		add_operation(operations, "rra");
		check_first_second_for_swap(stack_a, stack_b, operations);	
	}
}
