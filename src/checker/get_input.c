/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:24:56 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/20 10:50:43 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void				mapvalue_del(void **value)
{
	*value = 0;
}

static void				error_processing(const char *msg, char *str_num)
{
	ft_printf("%s : %s\n", msg, str_num);
	exit(-1);
}

static void				validate_input_string(t_stack *stack, char *argv, t_map **nums_map, t_buff *nums_buff)
{
	long long int		int_num;
	char				**input_string;
	size_t				i;

	if ((input_string = ft_strsplit(argv, ' ')) == NULL)
		input_string = ft_matrnew(argv, NULL);
	i = 0;
	while (input_string[i] != NULL)
	{
		if (!ft_is_digitline(input_string[i]))
			error_processing(ERROR_MSG_BAD_NUMBER, input_string[i]);
		int_num = ft_atoi(input_string[i]);
		if (IS_INT_OVERFLOW(int_num))
			error_processing(ERROR_MSG_BIGGER_THAN_INT, input_string[i]);
		if (ft_ismapitem(*nums_map, input_string[i]))
			error_processing(ERROR_MSG_PAIR_OF_ELEMENTS, input_string[i]);
		ft_mapinsert(nums_map, input_string[i], (void *)0);
		ft_buffadd(nums_buff, input_string[i]);
		ft_buffaddsymb(nums_buff, ' ');
		i++;
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
		print_man();
	nums_map = ft_mapinit(500, NULL, &mapvalue_del);
	nums_buff = ft_buffinit(100);
	i = 1;
	while (i != argc)
	{
		validate_input_string(stack, argv[i], &nums_map, nums_buff);
		i++;
	}
	stack = change_nums_to_correct_position(ft_strsplit(nums_buff->line, ' '), nums_map->numof_items);
	ft_mapdel(&nums_map);
	ft_buffdel(&nums_buff);
	return (stack);
}
