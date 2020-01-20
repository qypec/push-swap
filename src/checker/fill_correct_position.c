/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_correct_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:03:56 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/20 11:01:18 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int				*create_temp_array(size_t size, char **nums_str, int *unsorted_arr)
{
	int					*sorted_arr;
	int					number;
	size_t				i;

	if ((sorted_arr = (int *)malloc(sizeof(int) * size)) == NULL)
		exit(-1);
	i = 0;
	while (nums_str[i] != NULL)
	{
		number = ft_atoi(nums_str[i]);
		sorted_arr[i] = number;
		unsorted_arr[i] = number;
		i++;
	}
	return (sorted_arr);
}

t_stack					*change_nums_to_correct_position(char **nums, size_t stack_size)
{
	t_stack				*stack;
	int					*sorted_arr;
	int					unsorted_arr[stack_size];
	int					i;
	int					j;

	stack = stack_init(stack_size);
	sorted_arr = create_temp_array(stack_size, nums, (int *)&unsorted_arr);
	ft_qsort(sorted_arr, stack_size);
	i = -1;
	while (++i < stack_size)
	{
		j = -1;
		while (++j < stack_size)
		{
			if (unsorted_arr[j] == sorted_arr[i])
			{
				add_number_to_psstk(stack->a, j, i + 1);
				break ;
			}
		}
	}
	ft_memdel((void **)&sorted_arr);
	ft_matrdel(&nums);
	return (stack);
}
