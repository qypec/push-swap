/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_correct_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 23:54:59 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/23 04:19:28 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int				*create_temp_array(t_psstk *stack, size_t size)
{
	int					*arr;
	size_t				i;

	if ((arr = (int *)malloc(sizeof(int) * size)) == NULL)
		exit(-1);
	i = 0;
	while (i < size)
	{
		arr[i] = stack->arr[i]->number;
		i++;
	}
	return (arr);
}

void					fill_correct_position(t_psstk *stack, size_t size)
{
	int					*arr;
	size_t				i;
	size_t				j;

	arr = create_temp_array(stack, size);
	ft_qsort(arr, size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < stack->used_size)
		{
			if (stack->arr[j]->number == arr[i])
			{
				stack->arr[j]->correct_position = i + 1;
				break ;
			}
			j++;
		}
		i++;
	}
	ft_memdel((void **)&arr);
}
