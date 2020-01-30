/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 00:56:32 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/30 18:15:47 by yquaro           ###   ########.fr       */
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
	stack->operation = NULL;
	stack->visu = NULL;
	chunk_init(stack);
	return (stack);
}

void					lst_content_del(void *content, size_t content_size)
{
	ft_strdel((char **)&content);
	content_size = 0;
}

void					stack_delete(t_stack **stack)
{
	psstk_delete(&((*stack)->a));
	psstk_delete(&((*stack)->b));
	ft_lstdel(&((*stack)->operation), lst_content_del);
	free((*stack)->chunk);
	(*stack)->chunk = NULL;
	free(*stack);
	*stack = NULL;
}
