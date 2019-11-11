/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shifts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 21:31:15 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/10 21:31:28 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void					stack_shift_down(t_psstk *stk)
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

void					stack_shift_up(t_psstk *stk)
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