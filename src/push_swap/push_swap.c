/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:55:39 by yquaro            #+#    #+#             */
/*   Updated: 2020/02/07 22:10:36 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void					print_operations(t_list *operation)
{
	if (operation == NULL)
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
		if (stack->a->num[i] == 1)
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
	if (STACK_SIZE < 3)
		return ;
	if (HEAD_ITEM(stack->a) == 1 && TAIL_ITEM(stack->a) != STACK_SIZE)
	{
		reverse_rotate_a(stack);
		swap_a(stack);
	}
	else if (HEAD_ITEM(stack->a) == STACK_SIZE)
	{
		if (TAIL_ITEM(stack->a) == 1)
		{
			rotate_a(stack);
			swap_a(stack);
		}
		else
			rotate_a(stack);
	}
	else if (HEAD_ITEM(stack->a) != STACK_SIZE && HEAD_ITEM(stack->a) != 1)
	{
		if (TAIL_ITEM(stack->a) == 1)
			reverse_rotate_a(stack);
		else if (TAIL_ITEM(stack->a) == STACK_SIZE)
			swap_a(stack);
	}
}

static void				sort_pair_a(t_stack *stack)
{
	if (HEAD_ITEM(stack->a) == 1)
		return ;
	else
		swap_a(stack);
}

int						main(int argc, char **argv)
{
	t_stack				*stack;
	t_stack				*stack_cpy;

	stack = get_input(argc, argv);
	if (STACK_SIZE == 0)
		return (0);
	if (g_visuflag)
		stack_cpy = get_input(argc, argv);
	if (STACK_SIZE < 3)
		sort_pair_a(stack);
	move_to_stack_b(stack);
	sort_triplet_a(stack);
	move_to_stack_a(stack);
	rotate_to_sorting_state(stack);
	remove_self_destruction_operations(&(stack->operation));
	combine_operations(&(stack->operation));
	if (g_visuflag)
	{
		visu(stack_cpy, stack->operation);
		pause_before_termination();
	}
	else
		print_operations(stack->operation);
	stack_delete(&stack);
	if (g_visuflag)
		stack_delete(&stack_cpy);
}
