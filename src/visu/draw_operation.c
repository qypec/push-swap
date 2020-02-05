/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:51:41 by yquaro            #+#    #+#             */
/*   Updated: 2020/02/05 21:14:59 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "visu.h"

#define MARGIN_LEFT (3)
#define BASE_MARGIN_TOP (3)
#define MAX_CONTENT ((int)(WIN_INFO_LINES - BASE_MARGIN_TOP - 2))

#define CURRENT_POS_SYMB ('>' | COLOR_PAIR(GRAY))

static void				del_lst_content(void *content, size_t content_size)
{
	ft_strdel((char **)&content);
	content_size = 0;
}

static void				clear_bar(WINDOW *win)
{
	size_t				i;
	size_t				j;

	i = BASE_MARGIN_TOP;
	while (i < WIN_INFO_LINES - 1)
	{
		j = 0;
		while (j < WIN_INFO_COLS - 1)
		{
			mvwaddch(win, i, j, ' ');
			j++;
		}
		i++;
	}
}

static void				draw_current_operation(WINDOW *win, size_t margin_top, char *operation)
{
	mvwprintw(win, margin_top, 1, "%c  ", CURRENT_POS_SYMB);
	wattron(win, A_STANDOUT | COLOR_PAIR(CYAN));
	mvwprintw(win, margin_top, MARGIN_LEFT, operation);
	wattroff(win, A_STANDOUT | COLOR_PAIR(CYAN));
}

static void				draw_bar(WINDOW *win, t_list *operations_on_screen)
{
	size_t				margin_top;

	clear_bar(win);
	margin_top = BASE_MARGIN_TOP;
	while (operations_on_screen != NULL)
	{
		if (operations_on_screen->next != NULL)
			mvwprintw(win, margin_top, MARGIN_LEFT, (char *)(operations_on_screen->content));
		else
			draw_current_operation(win, margin_top, (char *)(operations_on_screen->content));
		margin_top++;
		operations_on_screen = operations_on_screen->next;
	}
}

void					draw_operation(t_stack *stack, const char *operation)
{
	static size_t		numof_oper = 0;
	static t_list		*operations_on_screen = NULL;

	mvwprintw(stack->visu->win_info, 1, \
		(WIN_INFO_COLS - ft_strlen("OPERATIONS")) / 2, "OPERATIONS");
	ft_lstpushback(&operations_on_screen, ft_lstnew(ft_strdup(operation), sizeof(char *)));
	if ((++numof_oper) == MAX_CONTENT)
	{
		ft_lstdelhead(&operations_on_screen, del_lst_content);
		numof_oper--;
	}
	draw_bar(stack->visu->win_info, operations_on_screen);
	box(stack->visu->win_info, 0, 0);
	wrefresh(stack->visu->win_info);
}
