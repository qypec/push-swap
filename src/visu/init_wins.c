/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:51:33 by yquaro            #+#    #+#             */
/*   Updated: 2020/02/05 18:21:02 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "visu.h"

void					        init_win_stacks(t_visu *visu)
{
	visu->win_stack_a = newwin(WIN_STACK_LINES, WIN_STACK_COLS, 0, 0);
	// box(visu->win_stack_a, 0, 0);
	wrefresh(visu->win_stack_a);
    visu->win_stack_b = newwin(WIN_STACK_LINES, WIN_STACK_COLS, 0, WIN_STACK_COLS);
    // box(visu->win_stack_b, 0, 0);
	wrefresh(visu->win_stack_b);
}

void					        init_win_info(t_visu *visu)
{
	visu->win_info = newwin(WIN_INFO_LINES, WIN_INFO_COLS, 0, WIN_STACK_COLS * 2);
	box(visu->win_info, 0, 0);
	wrefresh(visu->win_info);
}

void					        init_win_help(t_visu *visu)
{
	visu->win_help = newwin(WIN_HELP_LINES, WIN_HELP_COLS, WIN_STACK_LINES * 0.75, WIN_STACK_COLS * 2);
	box(visu->win_help, 0, 0);
	wrefresh(visu->win_help);
}
