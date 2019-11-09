/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:24:56 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/09 17:21:01 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_psstk					*get_input(int argc, char **argv)
{
	size_t				i;
	t_psstk				*stack_a;

	i = 0;
	stack_a = psstk_init(argc - 1);
	while (i < argc - 1)
	{
		if (!ft_isdigit_str(argv[i + 1]))
		{
			ft_putendl(ERROR_MSG_BAD_NUMBER);
			exit(-1);
		}
		add_to_psstk(stack_a, i, ft_atoi(argv[i + 1]));
		i++;
	}
	return (stack_a);
}
