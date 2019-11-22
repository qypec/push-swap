/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:51:37 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/21 23:28:25 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



static int				is_median(size_t large_counter, size_t less_counter, \
							size_t stack_size)
{
	if (IS_EVEN(stack_size))
	{
		if (less_counter - 1 == large_counter)
			return (1);
	}
	else if (large_counter == less_counter)
		return (1);
	return (0);
}

int						median_search(t_psstk *stack_a, size_t size)
{
	size_t				i;
	size_t				j;
	size_t				large_counter;
	size_t				less_counter;

	i = 0;
	while (i < size)
	{
		large_counter = 0;
		less_counter = 0;
		j = 0;
		while (j < size)
		{
			if (stack_a->arr[j]->number > stack_a->arr[i]->number)
				large_counter++;
			else if (stack_a->arr[j]->number < stack_a->arr[i]->number)
				less_counter++;
			j++;
		}
		if (is_median(large_counter, less_counter, size))
			break ;
		i++;
	}
	return (stack_a->arr[i]->number);
}
