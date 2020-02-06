/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 21:16:32 by yquaro            #+#    #+#             */
/*   Updated: 2020/02/06 20:56:59 by yquaro           ###   ########.fr       */
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

void					rotate_a(t_stack *stack)
{
	size_t				i;
	size_t				tmp;

	if (IS_EMPTY(stack->a))
		return ;
	i = 0;
	tmp = stack->a->num[0];
	stack_shift_up(stack->a);
	stack->a->num[stack->a->used_size - 1] = tmp;
	add_operation(&(stack->operation), "ra");
}

void					rotate_b(t_stack *stack)
{
	size_t				i;
	size_t				tmp;

	if (IS_EMPTY(stack->b))
		return ;
	i = 0;
	tmp = stack->b->num[0];
	stack_shift_up(stack->b);
	stack->b->num[stack->b->used_size - 1] = tmp;
	add_operation(&(stack->operation), "rb");
}

void					rotate_ab(t_stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
}
