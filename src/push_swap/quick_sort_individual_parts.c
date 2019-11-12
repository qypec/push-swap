/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_individual_parts.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:49:09 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/12 18:04:43 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void				add_correct_positions(t_psstk *stack, \
							int **const_stack, size_t used_size_const_stack)
{
	size_t				i;
	int					*cnst_stack;

	cnst_stack = *const_stack;
	i = 0;
	while (i < used_size_const_stack - 1)
	{
		add_correct_position(stack, cnst_stack[i], i + 1);
		i++;
	}
}

static void				bubble_sort_const_stack(int **const_stack, \
							size_t used_size_const_stack)
{
	size_t				i;
	size_t				j;
	int					*cnst_stack;
	int					tmp;

	cnst_stack = *const_stack;
	i = 0;
	while (i < used_size_const_stack - 1)
	{
		j = used_size_const_stack - 1;
    	while (j > i)
    	{
	    	if (cnst_stack[j - 1] > cnst_stack[j])
	    	{
	        	tmp = cnst_stack[j - 1];
	        	cnst_stack[j - 1] = cnst_stack[j];
				cnst_stack[j] = tmp;
			}
			j--;
		}
		i++;
	}
	*const_stack = cnst_stack;
}

static int				copy_part_of_stack_to_const_stack(t_psstk *stack, \
							int **const_stack)
{
	static int			turn = 0;
	int					*cnst_stack;
	size_t				i;
	size_t				j;

	cnst_stack = *const_stack;
	if ((i = turn * 3) > stack->used_size)
	{
		turn = 0;
		return (0);
	}
	j = 0;
	while ((i < ((turn + 1) * 3)) && (i < stack->used_size))
		cnst_stack[j++] = stack->arr[i++]->number;
	*const_stack = cnst_stack;
	turn++;
	return (1);
}

static void				sort_part_of_stack_with_operations(t_psstk *stack, \
							t_buff *operations, int stack_orientation)
{
	static int			turn = 0;

	if (IS_FIRST_TRIPLET(turn))
	{
		
	}
	else if (IS_LAST_TRIPLET(turn, stack->used_size))
	{

	}
	else
	{

	}
}


void					quick_sort_individual_parts(t_psstk *stack, \
							t_buff *operations, int stack_orientation)
{
	int					const_stack[3];
	size_t				used_size_const_stack

	while ((used_size_const_stack = copy_part_of_stack_to_const_stack(stack, &const_stack)))
	{
		bubble_sort_const_stack(&const_stack, used_size_const_stack);
		add_correct_positions(stack, &const_stack, used_size_const_stack);
		sort_part_of_stack_with_operations(stack, operations, stack_orientation);
	}
}
