/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psstk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:03:56 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/30 14:08:51 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void					add_correct_position(t_psstk *stack, int number, \
							size_t correct_position)
{
	size_t				i;

	i = 0;
	while (i < stack->used_size - 1)
	{
		if (stack->arr[i]->number == number)
		{
			stack->arr[i]->correct_position = correct_position;
			return ;	
		}
		i++;
	}
}

void					add_number_to_psstk(t_psstk *stack, size_t index, int number)
{
	stack->arr[index]->number = number;
	stack->used_size++;
}

t_psstk					*psstk_init(int	size)
{
	size_t				i;
	t_psstk				*psstk;

	if ((psstk = (t_psstk *)malloc(sizeof(t_psstk))) == NULL)
		exit(-1);
	psstk->size = size;
	psstk->used_size = 0;
	if ((psstk->arr = (t_numb **)malloc(sizeof(t_numb *) * size)) == NULL)
		exit(-1);
	i = 0;
	while (i < psstk->size)
		psstk->arr[i++] = numb_init();
	return (psstk);
}

void					psstk_delete(t_psstk **psstk)
{
	size_t				i;

	i = 0;
	while (i < (*psstk)->size)
		numb_delete(&((*psstk)->arr[i++]));
	free((*psstk)->arr);
	(*psstk)->arr = NULL;
	(*psstk)->size = 0;
	(*psstk)->used_size = 0;
	free(*psstk);
	*psstk = NULL;
}
