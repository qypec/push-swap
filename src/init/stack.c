/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 00:56:32 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/23 01:56:33 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack					*stack_init(size_t size)
{
	t_stack				*stack;

	if ((stack = (t_stack *)malloc(sizeof(t_stack))) == NULL)
		exit(-1);
	stack->a = psstk_init(size);
	stack->b = psstk_init(size);
	stack->operations = ft_buffinit(100);
	return (stack);
}

void					stack_delete(t_stack **stack)
{
	psstk_delete(&((*stack)->a));
	psstk_delete(&((*stack)->b));
	ft_buffdel(&((*stack)->operations));
	free(*stack);
	*stack = NULL;
}
