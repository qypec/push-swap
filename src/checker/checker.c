/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:48:56 by yquaro            #+#    #+#             */
/*   Updated: 2020/02/06 20:47:27 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void				validate_stacks(t_psstk *stack_a, t_psstk *stack_b)
{
	size_t				i;

	if (stack_b->used_size != 0)
	{
		ft_putendl("KO\nStack B is not empty");
		return ;
	}
	i = 0;
	while (stack_a->size != 0 && i < stack_a->size - 1)
	{
		if (stack_a->num[i + 1] < stack_a->num[i])
		{
			ft_putendl("KO\nStack A is incorrectly sort");
			return ;
		}
		i++;
	}
	ft_putendl("OK");
}

static void				get_operations(t_stack *stack)
{
	t_buff				*buffer;
	char				symb;
	char				**operations;
	size_t				i;

	buffer = ft_buffinit(100);
	while (read(0, &symb, 1) > 0)
		ft_buffaddsymb(buffer, symb);
	operations = ft_strsplit(buffer->line, '\n');
	i = 0;
	while (operations[i] != NULL)
		ft_lstpushback(&(stack->operation), \
			ft_lstnew(operations[i++], sizeof(char *)));
	ft_buffdel(&buffer);
	free(operations);
	operations = NULL;
}

int						main(int argc, char **argv)
{
	t_stack				*stack;

	stack = get_input(argc, argv);
	get_operations(stack);
	if (stack->operation != NULL && (execute_operations(stack)) == NULL)
		error_processing_operations(&stack);
	validate_stacks(stack->a, stack->b);
	stack_delete(&stack);
}
