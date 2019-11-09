/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:25:43 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/09 18:34:58 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void					swap_a(t_psstk *stack_a, t_psstk *stack_b)
{
	size_t				tmp_correct_position;
	size_t				tmp_number;

	if (stack_a->size <= 1)
		return ;
	tmp_correct_position = stack_a->arr[0]->correct_position;
	tmp_number = stack_a->arr[0]->number;
	stack_a->arr[0]->correct_position = stack_a->arr[1]->correct_position;
	stack_a->arr[0]->number = stack_a->arr[1]->number;
	stack_a->arr[1]->correct_position = tmp_correct_position;
	stack_a->arr[1]->number = tmp_number;
}

void					swap_b(t_psstk *stack_a, t_psstk *stack_b)
{
	size_t				tmp_correct_position;
	size_t				tmp_number;

	if (stack_b->size <= 1)
		return ;
	tmp_correct_position = stack_b->arr[0]->correct_position;
	tmp_number = stack_b->arr[0]->number;
	stack_b->arr[0]->correct_position = stack_b->arr[1]->correct_position;
	stack_b->arr[0]->number = stack_b->arr[1]->number;
	stack_b->arr[1]->correct_position = tmp_correct_position;
	stack_b->arr[1]->number = tmp_number;
}

void					swap_ab(t_psstk *stack_a, t_psstk *stack_b)
{
	swap_a(stack_a, stack_b);
	swap_b(stack_a, stack_b);
}
