/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:21:56 by yquaro            #+#    #+#             */
/*   Updated: 2020/02/05 18:37:04 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "visu.h"

#define LINE_CHAR ('_' | A_BOLD | COLOR_PAIR(GREEN))

#define MARGIN_TOP 3

static void				clear_line(WINDOW *win, size_t line)
{
	size_t				i;

	i = 0;
	while (i < WIN_STACK_COLS - 2)
	{
		mvwaddch(win, line, 1 + i, ' ');
		i++;
	}
}

static void				draw_line(WINDOW *win, size_t line, \
							size_t numof_char)
{
	size_t				i;

	i = 0;
	while (i < numof_char)
	{
		mvwaddch(win, line, 10 + i, LINE_CHAR);
		i++;
	}
}

static void             draw_stack(WINDOW *win, t_psstk *stk)
{
    size_t              i;

    wcolor_set(win, GREEN, NULL);
    i = 0;
    while (i < stk->used_size)
    {
		clear_line(win, MARGIN_TOP + i);
		wcolor_set(win, CYAN, NULL);
		mvwprintw(win, MARGIN_TOP + i, 5, "%d", stk->num[i]);
		wcolor_set(win, GREEN, NULL);
		draw_line(win, MARGIN_TOP + i, stk->num[i]);
		i++;
    }
    wcolor_set(win, 0, NULL);
	while (i < stk->size)
	{
		clear_line(win, MARGIN_TOP + i);
		i++;
	}
}

void                    draw_stacks(t_stack *stack)
{
	mvwprintw(stack->visu->win_stack_a, 1, (WIN_STACK_COLS - ft_strlen("STACK A")) / 2, "STACK A");
	mvwprintw(stack->visu->win_stack_b, 1, (WIN_STACK_COLS - ft_strlen("STACK B")) / 2, "STACK B");
    draw_stack(stack->visu->win_stack_a, stack->a);
    draw_stack(stack->visu->win_stack_b, stack->b);
	wrefresh(stack->visu->win_stack_a);
	wrefresh(stack->visu->win_stack_b);
	usleep(5000);
}
