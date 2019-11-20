/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 21:16:32 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/20 16:14:30 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void				stack_shift_down(t_psstk *stk)
{
	size_t				i;

	if (IS_EMPTY(stk))
		return ;
	i = stk->used_size - 1;
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
	while (i < stk->used_size - 1)
	{
		stk->arr[i]->number = stk->arr[i + 1]->number;
		stk->arr[i]->correct_position = stk->arr[i + 1]->correct_position;
		i++;
	}
	stk->arr[i]->number = 0;
	stk->arr[i]->correct_position = 0;
}

void					rotate_a(t_psstk *stack_a, t_psstk *stack_b)
{
	size_t				i;
	int					tmp_number;
	size_t				tmp_correct_position;

	if (IS_EMPTY(stack_a))
		return ;
	i = 0;
	tmp_number = stack_a->arr[0]->number;
	tmp_correct_position = stack_a->arr[0]->correct_position;
	stack_shift_up(stack_a);
	stack_a->arr[stack_a->used_size - 1]->number = tmp_number;
	stack_a->arr[stack_a->used_size - 1]->correct_position = tmp_correct_position;
}

void					rotate_b(t_psstk *stack_a, t_psstk *stack_b)
{
	size_t				i;
	int					tmp_number;
	size_t				tmp_correct_position;

	if (IS_EMPTY(stack_b))
		return ;
	i = 0;
	tmp_number = stack_b->arr[0]->number;
	tmp_correct_position = stack_b->arr[0]->correct_position;
	stack_shift_up(stack_b);
	stack_b->arr[stack_b->used_size - 1]->number = tmp_number;
	stack_b->arr[stack_b->used_size - 1]->correct_position = tmp_correct_position;
}

void					rotate_ab(t_psstk *stack_a, t_psstk *stack_b)
{
	rotate_a(stack_a, stack_b);
	rotate_b(stack_a, stack_b);
}
