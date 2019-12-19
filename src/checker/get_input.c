/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:24:56 by yquaro            #+#    #+#             */
/*   Updated: 2019/12/19 13:52:18 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define COUNTER_I ((argc == 2) ? i : (i + 1))

static  void			mapvalue_del(void **value)
{
	*value = 0;
}

static void				error_processing(const char *msg)
{
	ft_putendl(msg);
	exit (-1);
}

static void				check_errors(char *item, long num, t_map **map)
{
	if (!ft_is_digitline(item))
		error_processing(ERROR_MSG_BAD_NUMBER);
	if (ft_ismapitem(*map, item))
		error_processing(ERROR_MSG_PAIR_OF_ELEMENTS);
	if (IS_INT_OVERFLOW(num))
		error_processing(ERROR_MSG_BIGGER_THAN_INT);
	ft_mapinsert(map, item, (void *)&num);
}

static void				add_numbers_to_stack(t_stack *stack, char **matr, int argc)
{
	t_map				*map;
	long				num;
	size_t				i;

	map = ft_mapinit(stack->a->size * 4, NULL, mapvalue_del);
	i = 0;
	while (i < stack->a->size)
	{
		num = ft_atoi(matr[COUNTER_I]);
		check_errors(matr[COUNTER_I], num, &map);
		add_number_to_psstk(stack->a, i, num);
		i++;
	}
	ft_mapdel(&map);
}

t_stack					*get_input(int argc, char **argv)
{
	t_stack				*stack;
	char				**matr;
	size_t				stacks_size;

	if (argc == 1)
		exit(1);
	if (argc == 2)
	{
		matr = ft_strsplit(argv[1], ' ');
		stacks_size = ft_matrlen((const char **)matr);
	}
	else
	{
		matr = argv;
		stacks_size = argc - 1;
	}
	stack = stack_init(stacks_size);
	add_numbers_to_stack(stack, matr, argc);
	if (argc == 2)
		ft_matrdel(&matr);
	return (stack);
}
