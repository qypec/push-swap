/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 21:16:32 by yquaro            #+#    #+#             */
/*   Updated: 2019/12/25 15:26:58 by yquaro           ###   ########.fr       */
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
		stk->arr[i].number = stk->arr[i - 1].number;
		stk->arr[i].correct_position = stk->arr[i - 1].correct_position;
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
		stk->arr[i].number = stk->arr[i + 1].number;
		stk->arr[i].correct_position = stk->arr[i + 1].correct_position;
		i++;
	}
	stk->arr[i].number = 0;
	stk->arr[i].correct_position = 0;
}

void					rotate_a(t_stack *stack)
{
	size_t				i;
	int					tmp_number;
	size_t				tmp_correct_position;

	if (IS_EMPTY(stack->a))
		return ;
	i = 0;
	tmp_number = stack->a->arr[0].number;
	tmp_correct_position = stack->a->arr[0].correct_position;
	stack_shift_up(stack->a);
	stack->a->arr[stack->a->used_size - 1].number = tmp_number;
	stack->a->arr[stack->a->used_size - 1].correct_position = tmp_correct_position;
	add_operation(&(stack->operation), "ra");
}

void					rotate_b(t_stack *stack)
{
	size_t				i;
	int					tmp_number;
	size_t				tmp_correct_position;

	if (IS_EMPTY(stack->b))
		return ;
	i = 0;
	tmp_number = stack->b->arr[0].number;
	tmp_correct_position = stack->b->arr[0].correct_position;
	stack_shift_up(stack->b);
	stack->b->arr[stack->b->used_size - 1].number = tmp_number;
	stack->b->arr[stack->b->used_size - 1].correct_position = tmp_correct_position;
	add_operation(&(stack->operation), "rb");
}

void					rotate_ab(t_stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
}
