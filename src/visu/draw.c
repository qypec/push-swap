/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:41:30 by yquaro            #+#    #+#             */
/*   Updated: 2020/02/09 20:51:23 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "visu.h"

int						is_visu(t_stack *stack)
{
	if (g_visuflag)
	{
		if (STACK_SIZE > 80)
		{
			ft_putendl("Visualization is possible for up to 80 operations");
			exit(1);
		}
		return (1);
	}
	return (0);
}

void					draw(t_stack *stack, const char *operation)
{
	if (stack->visu->is_next_cycle == 1 || stack->visu->is_stopped != 1)
	{
		draw_stacks(stack);
		draw_operation(stack, operation);
	}
	draw_help(stack->visu);
	handle_buttons(stack);
}

void					visu(t_stack *stack, t_list *operation)
{
	t_list				*tmp_oper;
	void				(*exec)(t_stack *stack);
	const char			*tmp_content;

	stack->visu = init_visu();
	tmp_oper = operation;
	draw(stack, (char *)(tmp_oper->content));
	while (tmp_oper != NULL)
	{
		if (stack->visu->is_next_cycle == 1 || stack->visu->is_stopped != 1)
		{
			exec = get_pointer_to_operation((char *)(tmp_oper->content));
			exec(stack);
			tmp_content = (const char *)(tmp_oper->content);
			tmp_oper = tmp_oper->next;
		}
		draw(stack, tmp_content);
	}
}
