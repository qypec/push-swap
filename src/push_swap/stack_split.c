/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:50:30 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/20 21:47:03 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void					stack_split(t_psstk *stack_a, t_psstk *stack_b, \
							t_buff *operations)
{
	int					median;

	median = median_search(stack_a, stack_a->size);
	while (stack_b->used_size < (stack_b->size / 2))
	{
		if (HEAD_ITEM(stack_a) < median)
		{
			push_b(stack_a, stack_b);
			add_operation(operations, "pb");
		}
		else
		{
			rotate_a(stack_a, stack_b);
			add_operation(operations, "ra");
		}
	}
}
