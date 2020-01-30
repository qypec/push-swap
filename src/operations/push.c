/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 20:15:05 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/30 18:47:37 by yquaro           ###   ########.fr       */
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
		stk->num[i] = stk->num[i - 1];
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
		stk->num[i] = stk->num[i + 1];
		i++;
	}
	stk->num[i] = 0;
}

void					push_a(t_stack *stack)
{
	if (IS_EMPTY(stack->b))
		return ;
	stack_shift_down(stack->a);
	add_number_to_psstk(stack->a, 0, stack->b->num[0]);
	stack->a->num[0] = stack->b->num[0];
	stack_shift_up(stack->b);
	stack->b->used_size--;
	add_operation(&(stack->operation), "pa");
	draw_stacks(stack);
}

void					push_b(t_stack *stack)
{
	if (IS_EMPTY(stack->a))
		return ;
	stack_shift_down(stack->b);
	add_number_to_psstk(stack->b, 0, stack->a->num[0]);
	stack->b->num[0] = stack->a->num[0];
	stack_shift_up(stack->a);
	stack->a->used_size--;
	add_operation(&(stack->operation), "pb");
	draw_stacks(stack);
}
