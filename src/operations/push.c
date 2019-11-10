/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 20:15:05 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/10 21:07:02 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void				stack_shift_forward(t_psstk *stk)
{
	size_t				i;

	if (IS_EMPTY(stk))
		return ;
	i = stk->used_size - 1;
	while (i)
	{
		stk->arr[i]->number = stk->arr[i - 1]->number;
		i--;
	}
}

static void				stack_shift_back(t_psstk *stk)
{
	size_t				i;

	if (IS_EMPTY(stk))
		return ;
	i = 0;
	while (i < stk->used_size - 1)
	{
		stk->arr[i]->number = stk->arr[i + 1]->number;
		i++;
	}
	stk->arr[i]->number = 0;
}

void					push_a(t_psstk *stack_a, t_psstk *stack_b)
{
	if (IS_EMPTY(stack_b))
		return ;
	stack_shift_forward(stack_a);
	add_to_psstk(stack_a, 0, stack_b->arr[0]->number);
	stack_a->arr[0]->correct_position = stack_b->arr[0]->correct_position;
	stack_shift_back(stack_b);
	stack_b->used_size--;
}

void					push_b(t_psstk *stack_a, t_psstk *stack_b)
{
	if (IS_EMPTY(stack_a))
		return ;
	stack_shift_forward(stack_b);
	add_to_psstk(stack_b, 0, stack_a->arr[0]->number);
	stack_b->arr[0]->correct_position = stack_a->arr[0]->correct_position;
	stack_shift_back(stack_a);
	stack_a->used_size--;
}
