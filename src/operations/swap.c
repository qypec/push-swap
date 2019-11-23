/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:25:43 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/23 02:26:14 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void					swap_a(t_stack *stack)
{
	size_t				tmp_correct_position;
	size_t				tmp_number;

	if (stack->a->used_size <= 1)
		return ;
	tmp_correct_position = stack->a->arr[0]->correct_position;
	tmp_number = stack->a->arr[0]->number;
	stack->a->arr[0]->correct_position = stack->a->arr[1]->correct_position;
	stack->a->arr[0]->number = stack->a->arr[1]->number;
	stack->a->arr[1]->correct_position = tmp_correct_position;
	stack->a->arr[1]->number = tmp_number;
	add_operation(stack->operations, "sa");
}

void					swap_b(t_stack *stack)
{
	size_t				tmp_correct_position;
	size_t				tmp_number;

	if (stack->b->used_size <= 1)
		return ;
	tmp_correct_position = stack->b->arr[0]->correct_position;
	tmp_number = stack->b->arr[0]->number;
	stack->b->arr[0]->correct_position = stack->b->arr[1]->correct_position;
	stack->b->arr[0]->number = stack->b->arr[1]->number;
	stack->b->arr[1]->correct_position = tmp_correct_position;
	stack->b->arr[1]->number = tmp_number;
	add_operation(stack->operations, "sb");
}

void					swap_ab(t_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
}
