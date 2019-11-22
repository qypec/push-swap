/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 20:29:28 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/23 02:17:11 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void					dbg_print_stack(t_psstk *stk)
{
	size_t				i;

	i = 0;
	while (i < stk->size)
	{
		ft_printf("[%zu] %d | %zu\n", i, stk->arr[i]->number, stk->arr[i]->correct_position);
		i++;
	}
}

void					dbg_print_stacks(t_stack *stack)
{
	ft_printf("\nstack_a:\n");
	dbg_print_stack(stack->a);
	ft_printf("\nstack_b:\n");
	dbg_print_stack(stack->b);
}
