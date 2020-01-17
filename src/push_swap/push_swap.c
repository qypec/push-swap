/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:55:39 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/17 12:01:31 by yquaro           ###   ########.fr       */
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

static void				sort_triplet_a(t_stack *stack)
{
	if (HEAD_ITEM(stack->a).correct_position == 1 && \
		TAIL_ITEM(stack->a).correct_position != STACK_SIZE)
	{
		reverse_rotate_a(stack);
		swap_a(stack);
	}
	else if (HEAD_ITEM(stack->a).correct_position == STACK_SIZE)
	{
		if (TAIL_ITEM(stack->a).correct_position == 1)
		{
			rotate_a(stack);
			swap_a(stack);
		}
		else
			rotate_a(stack);
	}
	else if (HEAD_ITEM(stack->a).correct_position != STACK_SIZE && \
			HEAD_ITEM(stack->a).correct_position != 1)
	{
		if (TAIL_ITEM(stack->a).correct_position == 1)
			reverse_rotate_a(stack);
		else if (TAIL_ITEM(stack->a).correct_position == STACK_SIZE)
			swap_a(stack);
	}
}

int						main(int argc, char **argv)
{
	t_stack				*stack;

	stack = get_input(argc, argv);

// debug

	// dbg_print_stacks(stack);

//

	move_to_stack_b(stack);
	sort_triplet_a(stack);

// debug

	// dbg_print_stacks(stack);

//

	move_to_stack_a(stack);

// debug

	// dbg_print_stacks(stack);

//

	rotate_to_sorting_state(stack);
	combine_operations(&(stack->operation));
	print_operations(stack->operation);

// debug

	// dbg_print_stacks(stack);

//

	stack_delete(&stack);
}
