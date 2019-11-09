/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:48:56 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/09 17:28:09 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void				error_processing(char ***operations)
{
	ft_matrdel(operations);
	ft_putendl(ERROR_MSG_BAD_OPERATION);
	exit(-1);
}

static void				validate_stacks(t_psstk *stack_a, t_psstk *stack_b)
{
	size_t				i;

	if (stack_b->used_size != 0)
	{
		ft_putendl("KO");
		return ;
	}
	i = 0;
	while (i < stack_a->size)
	{
		if (stack_a->arr[i + 1]->number < stack_a->arr[i]->number)
		{
			ft_putendl("KO");
			return ;
		}
		i++:
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
	t_psstk				*stack_a;
	t_psstk				*stack_b;
	char				**operations;

	stack_a = input_check(argc, argv);
	stack_b = psstk_init(argc - 1);
	operations = get_operations();
	// if ((execute_operations(&stack_a, &stack_b, operations)) == NULL)
	// 	error_processing(&operations);
	validate_stacks(stack_a, stack_b);
	ft_matrdel(&operations);
}
