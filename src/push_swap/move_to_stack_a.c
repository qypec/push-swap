/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 21:36:54 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/14 20:00:58 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define CALCULATE_OP(i_a, i_b) ((i_a >= i_b) ? i_a : i_b)

static size_t			calculate_optimum(t_stack *stk, size_t index_a, \
							size_t index_b)
{
	if ((index_a > U_SIZE(stk->a) / 2) && (index_b > U_SIZE(stk->b) / 2))
		return (CALCULATE_OP(U_SIZE(stk->a) - index_a, U_SIZE(stk->b) - index_b));
	else if ((index_a <= U_SIZE(stk->a) / 2) && (index_b <= U_SIZE(stk->b) / 2))
		return (CALCULATE_OP(index_a, index_b));
	else if ((index_a <= U_SIZE(stk->a) / 2) && (index_b > U_SIZE(stk->b) / 2))
		return (index_a + U_SIZE(stk->b) - index_b);
	else
		return (index_b + U_SIZE(stk->a) - index_a);
}

static size_t			get_optimum_operations(t_stack *stack, size_t index_b)
{
	size_t				index_a;
	size_t				correct_position_b;

	correct_position_b = stack->b->arr[index_b].correct_position;
	if (TAIL_ITEM(stack->a).correct_position + 1 == correct_position_b)
		return (((index_b <= U_SIZE(stack->b) ? index_b : U_SIZE(stack->b) - index_b)));
	index_a = 0;
	while (index_a < stack->a->used_size)
	{
		if (stack->a->arr[index_a].correct_position - 1 == correct_position_b)
			break ;
		if (index_a != 0 && \
				stack->a->arr[index_a - 1].correct_position + 1 == \
					correct_position_b)
			break;
		index_a++;
	}
	if (index_a == stack->a->used_size)
		return ((size_t)0 - 1);
	return (calculate_optimum(stack, index_a, index_b));
}

static void				rotate_a_for_min(t_stack *stack, size_t index_b)
{
	size_t				index_a;
	size_t				correct_position_b;

	correct_position_b = stack->b->arr[index_b].correct_position;
	if (TAIL_ITEM(stack->a).correct_position + 1 == correct_position_b)
		return ;
	index_a = 0;
	while (index_a < stack->a->used_size)
	{
		if (stack->a->arr[index_a].correct_position - 1 == correct_position_b)
			break ;
		if (index_a != 0 && \
				stack->a->arr[index_a - 1].correct_position + 1 == \
					correct_position_b)
			break;
		index_a++;
	}
	if (index_a <= U_SIZE(stack->a) / 2)
		rotate_top_a(stack, index_a);
	else
		rotate_down_a(stack, U_SIZE(stack->a) - index_a);
}

static void				move_optimum_to_top(t_stack *stack)
{
	size_t				num_of_op[stack->b->used_size];
	size_t				i;
	size_t				min_b;

	i = 0;
	while (i < stack->b->used_size)
	{
		num_of_op[i] = get_optimum_operations(stack, i);
		i++;
	}
	min_b = ft_arraymin((size_t *)&num_of_op, stack->b->used_size);
	rotate_a_for_min(stack, min_b);
	if (min_b <= U_SIZE(stack->b) / 2)
		rotate_top_b(stack, min_b);
	else
		rotate_down_b(stack, U_SIZE(stack->b) - min_b);
}

void                    move_to_stack_a(t_stack *stack)
{
	while (stack->b->used_size)
	{
		move_optimum_to_top(stack);
		push_a(stack);
// /* debugging */

	// dbg_print_stacks(stack);
	
// /* */
	}
}
