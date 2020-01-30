/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:55:01 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/30 18:47:46 by yquaro           ###   ########.fr       */
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

void					reverse_rotate_a(t_stack *stack)
{
	size_t				i;
	size_t				tmp;

	if (IS_EMPTY(stack->a))
		return ;
	i = 0;
	tmp = stack->a->num[stack->a->used_size - 1];
	stack_shift_down(stack->a);
	stack->a->num[0] = tmp;
	add_operation(&(stack->operation), "rra");
	draw_stacks(stack);
}

void					reverse_rotate_b(t_stack *stack)
{
	size_t				i;
	size_t				tmp;

	if (IS_EMPTY(stack->b))
		return ;
	i = 0;
	tmp = stack->b->num[stack->b->used_size - 1];
	stack_shift_down(stack->b);
	stack->b->num[0] = tmp;
	add_operation(&(stack->operation), "rrb");
	draw_stacks(stack);
}

void					reverse_rotate_ab(t_stack *stack)
{
	reverse_rotate_a(stack);
	reverse_rotate_b(stack);
}
