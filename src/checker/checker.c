/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:48:56 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/08 16:57:32 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void				error_processing(char ***operations)
{
	ft_matrdel(operations);
	ft_putendl(ERROR_MSG_BAD_OPERATION);
	exit(-1);
}

static void				validate(int **stack_a, int **stack_b)
{
	// check validity
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
	while (i < argc - 1)
	{
		stack_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	operations = get_operations();
	if ((execute_operations(&stack_a, &stack_b, operations)) == NULL)
		error_processing(&operations);
	validate_stacks(&stack_a, s&tack_b);
	ft_matrdel(&operations);
}
