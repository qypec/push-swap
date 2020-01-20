/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psstk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:03:56 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/20 14:07:08 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void					add_number_to_psstk(t_psstk *stack, size_t index, \
							int number)
{
	stack->num[index] = number;
	stack->used_size++;
}

t_psstk					*psstk_init(int size)
{
	t_psstk				*psstk;

	if ((psstk = (t_psstk *)malloc(sizeof(t_psstk))) == NULL)
		exit(-1);
	psstk->size = size;
	psstk->used_size = 0;
	if ((psstk->num = (int *)ft_memalloc(sizeof(int) * size)) == NULL)
		exit(-1);
	return (psstk);
}

void					psstk_delete(t_psstk **psstk)
{
	size_t				i;

	i = 0;
	free((*psstk)->num);
	(*psstk)->num = NULL;
	(*psstk)->size = 0;
	(*psstk)->used_size = 0;
	free(*psstk);
	*psstk = NULL;
}
