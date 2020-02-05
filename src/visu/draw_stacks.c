/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:21:56 by yquaro            #+#    #+#             */
/*   Updated: 2020/02/05 18:19:32 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "visu.h"

# define LINE_CHAR '_'

#define MARGIN_TOP 3

static void				draw_line(WINDOW *win, size_t line, \
							size_t numof_char, char ch)
{
	size_t				i;

	i = 0;
	while (i < numof_char)
	{
		mvwaddch(win, line, 10 + i, ch);
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
		draw_line(win, MARGIN_TOP + i, stk->size, ' '); // clear line
		draw_line(win, MARGIN_TOP + i, stk->num[i], LINE_CHAR);
		i++;
    }
    wcolor_set(win, 0, NULL);
	while (i < stk->size)
	{
		draw_line(win, MARGIN_TOP + i, stk->size, ' ');
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
