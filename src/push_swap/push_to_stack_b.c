/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:47:28 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/20 18:15:56 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include <stdio.h>

/* dbg 
	j = 0;
	while (j < stack_a->size)
	{
		printf("%d ", arr[j]);
		j++;
	}
	printf("\n");

*/

int						*create_temp_array(t_psstk *stack, size_t size)
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

static int				find_third_largest_element(t_psstk *stack_a)
{
	int					*arr;
	int					third_largest_element;

	arr = create_temp_array(stack_a, stack_a->size);
	ft_qsort(arr, stack_a->size);
	third_largest_element = arr[stack_a->size - 3];
	ft_memdel((void **)&arr);
	return (third_largest_element);
}

void					push_to_stack_b(t_psstk *stack_a, t_psstk *stack_b, \
							t_buff *operations)
{
	int					third_largest_element;

	third_largest_element = find_third_largest_element(stack_a);
	while (stack_a->used_size > 3)
	{
		if (stack_a->arr[0]->number <= third_largest_element)
		{
			push_b(stack_a, stack_b);
			add_operation(operations, "pb");
		}
		else
		{
			rotate_a(stack_a, stack_b);
			add_operation(operations, "ra");
		}
	}
}
