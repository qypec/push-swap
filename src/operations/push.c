/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 20:15:05 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/11 17:35:50 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void				stack_shift_down(t_psstk *stk)
{
	size_t				i;

	if (IS_EMPTY(stk))
		return ;
	i = stk->used_size;
	while (i)
	{
		stk->arr[i]->number = stk->arr[i - 1]->number;
		stk->arr[i]->correct_position = stk->arr[i - 1]->correct_position;
		i--;
	}
}

static void				stack_shift_up(t_psstk *stk)
{
	size_t				i;

	if (IS_EMPTY(stk))
		return ;
	i = 0;
	while (i < stk->used_size)
	{
		stk->arr[i]->number = stk->arr[i + 1]->number;
		stk->arr[i]->correct_position = stk->arr[i + 1]->correct_position;
		i++;
	}
	stk->arr[i]->number = 0;
	stk->arr[i]->correct_position = 0;
}

void					push_a(t_psstk *stack_a, t_psstk *stack_b)
{
	if (IS_EMPTY(stack_b))
		return ;
	stack_shift_down(stack_a);
	add_number_to_psstk(stack_a, 0, stack_b->arr[0]->number);
	stack_a->arr[0]->correct_position = stack_b->arr[0]->correct_position;
	stack_shift_up(stack_b);
	stack_b->used_size--;
}

void					push_b(t_psstk *stack_a, t_psstk *stack_b)
{
	if (IS_EMPTY(stack_a))
		return ;
	stack_shift_down(stack_b);
	add_number_to_psstk(stack_b, 0, stack_a->arr[0]->number);
	stack_b->arr[0]->correct_position = stack_a->arr[0]->correct_position;
	stack_shift_up(stack_a);
	stack_a->used_size--;
}
