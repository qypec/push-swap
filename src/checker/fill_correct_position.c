/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_correct_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:03:56 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/09 16:04:37 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int				*create_temp_array(t_psstk *stack, size_t size)
{
	int					*num;
	size_t				i;

	if ((num = (int *)malloc(sizeof(int) * size)) == NULL)
		exit(-1);
	i = 0;
	while (i < size)
	{
		num[i] = stack->num[i];
		i++;
	}
	return (num);
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
			if (stack->num[j] == arr[i])
			{
				stack->num[j] = i + 1;
				break ;
			}
			j++;
		}
		i++;
	}
	ft_memdel((void **)&arr);
}
