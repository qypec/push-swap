/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:25:43 by yquaro            #+#    #+#             */
/*   Updated: 2020/02/05 18:07:30 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void					swap_a(t_stack *stack)
{
	size_t				tmp;

	if (stack->a->used_size < 2)
		return ;
	tmp = stack->a->num[0];
	stack->a->num[0] = stack->a->num[1];
	stack->a->num[1] = tmp;
	add_operation(&(stack->operation), "sa");
	draw_stacks(stack);
}

void					swap_b(t_stack *stack)
{
	size_t				tmp;

	if (stack->b->used_size < 2)
		return ;
	tmp = stack->b->num[0];
	stack->b->num[0] = stack->b->num[1];
	stack->b->num[1] = tmp;
	add_operation(&(stack->operation), "sb");
	draw_stacks(stack);
}

void					swap_ab(t_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
}
