/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 00:56:32 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/13 18:49:50 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t		get_num_of_chunks(size_t size) // temp
{
    if (size <= 5)
        return (1);
	else if (size <= 15)
		return (2);
	else if (size <= 25)
		return (3);
	else if (size <= 50)
		return (4);
    else if (size <= 100)
        return (5);
    else
        return (11);    
}

t_stack					*stack_init(size_t size)
{
	t_stack				*stack;

	if ((stack = (t_stack *)malloc(sizeof(t_stack))) == NULL)
		exit(-1);
	stack->a = psstk_init(size);
	stack->b = psstk_init(size);
	stack->operation = NULL;
	stack->num_of_chunks = get_num_of_chunks(size);
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
