/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:47:28 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/14 16:13:22 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int						find_third_largest_element(t_psstk *stack_a)
{
	int					arr[stack_a->size];
	size_t				i;

	i = 0;
	while (i < stack_a->size - 1)
	{
		arr[i] = stack_a->arr[i]->number;
		i++;
	}
	ft_qsort(&arr, stack_a->size);
	return (arr[stack_a->size - 3]);
}

void					push_to_stack_b(t_psstk *stack_a, t_psstk *stack_b, \
							t_buff *operations)
{
	


}
