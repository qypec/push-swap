/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:24:56 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/23 08:53:46 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static  void			mapvalue_del(void **value)
{
	*value = 0;
}

static void				error_processing(const char *msg)
{
	ft_putendl(msg);
	exit (-1);
}

void					get_input(t_psstk *stack_a, int argc, char **argv)
{
	size_t				i;
	long				num;
	t_map				*map;

	map = ft_mapinit(argc * 4, mapvalue_del);
	i = 0;
	while (i < argc - 1)
	{
		if (!ft_isdigit_str(argv[i + 1]))
			error_processing(ERROR_MSG_BAD_NUMBER);
		if (ft_ismapitem(map, argv[i + 1]))
			error_processing(ERROR_MSG_PAIR_OF_ELEMENTS);
		if ((num = ft_atoi(argv[i + 1])) == - 1)
			error_processing(ERROR_MSG_BIGGER_THAN_LONG);
		if (IS_INT_OVERFLOW(num))
			error_processing(ERROR_MSG_BIGGER_THAN_INT);
		add_number_to_psstk(stack_a, i, num);
		ft_mapinsert(&map, argv[i + 1], (void *)&num);
		i++;
	}
	ft_mapdel(&map);
}
