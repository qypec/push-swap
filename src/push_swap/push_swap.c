/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:55:39 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/13 20:40:01 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void					print_operations(t_list *operation)
{
	if (operation == NULL) // delete
		ft_putchar('\n'); 
	while (operation != NULL)
	{
		ft_putendl((char *)(operation->content));
		operation = operation->next;
	}
}

static void				rotate_to_sorting_state(t_stack *stack)
{
	size_t				i;

	i = 0;
	while (i < stack->a->used_size)
	{
		if (stack->a->arr[i].correct_position == 1)
			break ;
		i++;
	}
	if (i <= stack->a->used_size / 2)
		rotate_top_a(stack, i);
	else
		rotate_down_a(stack, stack->a->used_size - i);	
}

int						main(int argc, char **argv)
{
	t_stack				*stack;

	stack = get_input(argc, argv);

/* debugging */

	// dbg_print_stacks(stack);
	
/* */

/* debugging */

	// size_t i;

	// i = 0;
	// while (i < stack->num_of_chunks)
	// {
	// 	ft_printf("[%zu] size: %zu\n", i, stack->chunk[i].size);
	// 	i++;
	// }
	// ft_putchar('\n');
/* */
	
	move_to_stack_b(stack);
	
// /* debugging */

	// dbg_print_stacks(stack);
	
// /* */

	move_to_stack_a(stack);
	rotate_to_sorting_state(stack);
	remove_self_destruction_operations(&(stack->operation));
	combine_operations(&(stack->operation));
	print_operations(stack->operation);

// /* debugging */

	// dbg_print_stacks(stack);
	
// /* */
	stack_delete(&stack);
}
