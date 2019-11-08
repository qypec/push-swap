/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:24:56 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/08 18:46:57 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void					input_check(int argc, char **argv, int **stack_a)
{
	size_t				i;
	int					*stk_a;

	stk_a = *stack_a;
	i = 0;
	while (i < argc - 1)
	{
		if (!ft_isdigit_str(argv[i + 1]))
		{
			ft_putendl(ERROR_MSG_BAD_NUMBER);
			exit(-1);
		}
		stk_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	*stack_a = stk_a;
}
