/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:24:56 by yquaro            #+#    #+#             */
/*   Updated: 2020/02/09 21:39:11 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define ERR_BAD_FLAG_NAME "error: bad flag name"

static void				mapvalue_del(void **value)
{
	*value = 0;
}

int						*create_temp_array(size_t size, char **nums_str, \
							int *unsorted_arr)
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

static t_stack			*change_nums_to_correct_position(char **nums, \
							size_t stack_size)
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
	while (++i < (int)stack_size)
	{
		j = -1;
		while (++j < (int)stack_size)
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

static void				validate_input_string(char *argv, t_map **nums_map, \
							t_buff *nums_buff)
{
	long long int		int_num;
	char				**input_string;
	int					i;

	if ((input_string = ft_strsplit(argv, ' ')) == NULL)
		input_string = ft_matrnew(argv, NULL);
	i = -1;
	while (input_string[++i] != NULL)
	{
		if (skip_flags(input_string, &i))
			continue ;
		if (!ft_is_digitline(input_string[i]))
			error_processing_numbers(ERROR_MSG_BAD_NUMBER, input_string[i]);
		int_num = ft_atoi(input_string[i]);
		if (IS_INT_OVERFLOW(int_num))
			error_processing_numbers(ERROR_MSG_BIGGER_THAN_INT, \
				input_string[i]);
		if (ft_ismapitem(*nums_map, input_string[i]))
			error_processing_numbers(ERROR_MSG_PAIR_OF_ELEMENTS, \
				input_string[i]);
		ft_mapinsert(nums_map, input_string[i], (void *)0);
		ft_buffadd(nums_buff, input_string[i]);
		ft_buffaddsymb(nums_buff, ' ');
	}
	ft_matrdel(&input_string);
}

t_stack					*get_input(int argc, char **argv)
{
	t_stack				*stack;
	t_map				*nums_map;
	t_buff				*nums_buff;
	size_t				i;

	if (argc == 1)
		print_usage();
	nums_map = ft_mapinit(500, NULL, &mapvalue_del);
	nums_buff = ft_buffinit(100);
	parse_flags(argc, argv);
	i = 1;
	while (argv[i] != NULL)
	{
		validate_input_string(argv[i], &nums_map, nums_buff);
		i++;
	}
	stack = change_nums_to_correct_position(ft_strsplit(nums_buff->line, ' '), \
		nums_map->numof_items);
	ft_mapdel(&nums_map);
	ft_buffdel(&nums_buff);
	return (stack);
}
