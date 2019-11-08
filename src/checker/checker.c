/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:48:56 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/08 18:46:39 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void				error_processing(char ***operations)
{
	ft_matrdel(operations);
	ft_putendl(ERROR_MSG_BAD_OPERATION);
	exit(-1);
}

static void				validate_stacks(int **stack_a, int **stack_b)
{
	size_t				i;
	int					prev_elem;
	int					*stk_a;
	int					*stk_b;

	stk_a = *stack_a;
	stk_b = *stack_b;
	prev_elem = stk_a[0];
	i = 0;
	while (i < g_stack_size)
	{
		if (stk_b[i] != 0 && prev_elem > stk_a[i])
		{
			ft_putendl("KO");
			return ;
		}
		prev_elem = stk_a[i++];
	}
	ft_putendl("OK");
}

static char				**get_operations(void)
{
	t_buff				*buffer;
	char				symb;
	char				**operations;

	buffer = ft_buffinit(100);
	while (read(0, &symb, 1) > 0)
		ft_buffaddsymb(buffer, symb);
	operations = ft_strsplit(buffer->str, '\n');
	ft_buffdel(&buffer);
	return (operations);
}

int						main(int argc, char **argv)
{
	size_t				i;
	int					stack_a[argc];
	int					stack_b[argc];
	char				**operations;

	i = 0;
	g_stack_size = argc;
	input_check(argc, argv, (int **)&stack_a);
	operations = get_operations();
	// if ((execute_operations(&stack_a, &stack_b, operations)) == NULL)
	// 	error_processing(&operations);
	validate_stacks((int **)&stack_a, (int **)&stack_b);
	ft_matrdel(&operations);
}
