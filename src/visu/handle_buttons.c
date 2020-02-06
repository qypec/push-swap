/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_buttons.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:45:48 by yquaro            #+#    #+#             */
/*   Updated: 2020/02/06 16:56:19 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		speed_up(t_visu *visu)
{
	if (visu->delay != 0.0 && visu->speed != MAX_SPEED_POINT)
	{
		visu->speed++;
		visu->delay -= 0.1;
	}
}

static void		speed_down(t_visu *visu)
{
	if (visu->delay != 1.0 && visu->speed != 1)
	{
		visu->speed--;
		visu->delay += 0.1;
	}
}

static void		default_speed(t_visu *visu)
{
	visu->delay = 0.0;
	visu->speed = MAX_SPEED_POINT;
}

void			handle_buttons(t_stack *stack)
{
	int			key;

	if ((key = getch()) == SPACE_BUTTON)
	{
		nodelay(stdscr, NODELAY_MACROS);
		stack->visu->is_stopped *= (-1);
	}
	else if (key == ESC_BUTTON)
	{
		delete_visu(&(stack->visu));
		stack_delete(&stack);
		exit(1);
	}
	else if (key == KEY_DOWN)
		speed_down(stack->visu);
	else if (key == KEY_UP)
		speed_up(stack->visu);
	else if (key == KEY_LEFT)
		default_speed(stack->visu);
	else if (key == KEY_RIGHT && stack->visu->is_stopped != -1)
		stack->visu->is_next_cycle = 1;
	usleep(stack->visu->delay * MAX_DELAY);
}