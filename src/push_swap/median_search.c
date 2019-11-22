/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:51:37 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/22 05:16:24 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define MORE(rounding) (rounding[0] == 'm') ? 1 : 0
#define LESS(rounding) (rounding[0] == 'l') ? 1 : 0

static int				is_median(int large_counter, int less_counter, \
							size_t stack_size, const char *rounding)
{
	if (IS_EVEN(stack_size))
	{
		if (MORE(rounding))
		{
			if ((less_counter - 1) == large_counter)
				return (1);
		}
		if (LESS(rounding))
		{
			if ((large_counter - 1) == less_counter)
				return (1);
		}
	}
	else if (large_counter == less_counter)
		return (1);
	return (0);
}

int						median_search(t_psstk *stack_a, size_t size, \
							const char *rounding)
{
	size_t				i;
	size_t				j;
	int					large_counter;
	int					less_counter;

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
		if (is_median(large_counter, less_counter, size, rounding))
			break ;
		i++;
	}
	return (stack_a->arr[i]->number);
}
