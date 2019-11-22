/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:55:39 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/23 02:17:52 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int						main(int argc, char **argv)
{
	t_stack				*stack;

	stack = stack_init(argc - 1);
	get_input(stack->a, argc, argv);

	sorting_stack_a(stack, stack->a->used_size, 0);
	ft_putendl(stack->operations->str);
	// dbg_print_stacks(stack);

	stack_delete(&stack);
}
