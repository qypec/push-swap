/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:00:58 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/20 12:24:10 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void				*get_r_operation(char *operation)
{
	if (ft_strequ(operation, "ra"))
		return (&rotate_a);
	else if (ft_strequ(operation, "rb"))
		return (&rotate_b);
	else if (ft_strequ(operation, "rr"))
		return (&rotate_ab);
	else if (ft_strequ(operation, "rra"))
		return (&reverse_rotate_a);
	else if (ft_strequ(operation, "rrb"))
		return (&reverse_rotate_b);
	else if (ft_strequ(operation, "rrr"))
		return (&reverse_rotate_ab);
	else
		return (NULL);
}

static void				*get_p_operation(char *operation)
{
	if (ft_strequ(operation, "pa"))
		return (&push_a);
	else if (ft_strequ(operation, "pb"))
		return (&push_b);
	else
		return (NULL);
}

static void				*get_s_operation(char *operation)
{
	if (ft_strequ(operation, "sa"))
		return (&swap_a);
	else if (ft_strequ(operation, "sb"))
		return (&swap_b);
	else if (ft_strequ(operation, "ss"))
		return (&swap_ab);
	else
		return (NULL);
}

static void				*get_pointer_to_operation(char *operation)
{
	if (operation[0] == 's')
		return (get_s_operation(operation));
	else if (operation[0] == 'p')
		return (get_p_operation(operation));
	else if (operation[0] == 'r')
		return (get_r_operation(operation));
	else
		return (NULL);
}

void					*execute_operations(t_stack *stack, char **operations)
{
	size_t				i;
	void				(*exec)(t_stack *stack);

	i = 0;
	while (operations[i] != NULL)
	{
		if ((exec = get_pointer_to_operation(operations[i])) == NULL)
			return (NULL);
		exec(stack);
		i++;
	}
	return (exec);
}
