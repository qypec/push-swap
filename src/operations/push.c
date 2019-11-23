/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 20:15:05 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/23 02:24:54 by yquaro           ###   ########.fr       */
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
	while (i < stk->used_size - 1)
	{
		stk->arr[i]->number = stk->arr[i + 1]->number;
		stk->arr[i]->correct_position = stk->arr[i + 1]->correct_position;
		i++;
	}
	stk->arr[i]->number = 0;
	stk->arr[i]->correct_position = 0;
}

void					push_a(t_stack *stack)
{
	if (IS_EMPTY(stack->b))
		return ;
	stack_shift_down(stack->a);
	add_number_to_psstk(stack->a, 0, stack->b->arr[0]->number);
	stack->a->arr[0]->correct_position = stack->b->arr[0]->correct_position;
	stack_shift_up(stack->b);
	stack->b->used_size--;
	add_operation(stack->operations, "pa");
}

void					push_b(t_stack *stack)
{
	if (IS_EMPTY(stack->a))
		return ;
	stack_shift_down(stack->b);
	add_number_to_psstk(stack->b, 0, stack->a->arr[0]->number);
	stack->b->arr[0]->correct_position = stack->a->arr[0]->correct_position;
	stack_shift_up(stack->a);
	stack->a->used_size--;
	add_operation(stack->operations, "pb");
}
