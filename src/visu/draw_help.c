/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:12:44 by yquaro            #+#    #+#             */
/*   Updated: 2020/02/06 20:00:46 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define MARGIN_LEFT (3)
#define MARGIN_TOP (6)

#define SPEED "SPEED "
#define SPEED_POINT_ACTIVE (' ' | A_STANDOUT | COLOR_PAIR(CYAN))
#define SPEED_POINT ('_' | COLOR_PAIR(CYAN))

#define BUTTON_NAME_EXIT "Exit - "
#define BUTTON_EXIT "\'Esc\'"

#define BUTTON_NAME_PAUSE "Pause / Unpause - "
#define BUTTON_PAUSE "\'Space\'"

#define BUTTON_NAME_NEXT_CYCLE "Next cycle - "
#define BUTTON_NEXT_CYCLE "\'Right arrow\'"

#define BUTTON_NAME_DEFAULT_SPEED "Default speed - "
#define BUTTON_DEFAULT_SPEED "\'Left arrow\'"

#define BUTTON_NAME_SPEED_UP "Speed UP - "
#define BUTTON_SPEED_UP "\'Top arrow\'"

#define BUTTON_NAME_SPEED_DOWN "Speed DOWN - "
#define BUTTON_SPEED_DOWN "\'Down arrow\'"

void				draw_speed_bar(t_visu *visu)
{
	size_t			i;

	mvwprintw(visu->win_help, MARGIN_TOP, MARGIN_LEFT, SPEED);
	i = 0;
	while (i < visu->speed * 2)
	{
		wmove(visu->win_help, MARGIN_TOP, MARGIN_LEFT + ft_strlen(SPEED) + i);
		waddch(visu->win_help, SPEED_POINT_ACTIVE);
		waddch(visu->win_help, SPEED_POINT_ACTIVE);
		i += 2;
	}
	while (i < MAX_SPEED_POINT * 2)
	{
		wmove(visu->win_help, MARGIN_TOP, MARGIN_LEFT + ft_strlen(SPEED) + i);
		waddch(visu->win_help, SPEED_POINT);
		waddch(visu->win_help, SPEED_POINT);
		i += 2;
	}
}

void					draw_help(t_visu *visu)
{
	size_t				margin_top;

	draw_speed_bar(visu);
	margin_top = MARGIN_TOP + 2;
	mvwprintw(visu->win_help, margin_top, MARGIN_LEFT, BUTTON_NAME_EXIT);
	margin_top += 2;
	mvwprintw(visu->win_help, margin_top, MARGIN_LEFT, BUTTON_NAME_PAUSE);
	margin_top += 2;
	mvwprintw(visu->win_help, margin_top, MARGIN_LEFT, BUTTON_NAME_NEXT_CYCLE);
	margin_top += 2;
	mvwprintw(visu->win_help, margin_top, MARGIN_LEFT, BUTTON_NAME_DEFAULT_SPEED);
	margin_top += 2;
	mvwprintw(visu->win_help, margin_top, MARGIN_LEFT, BUTTON_NAME_SPEED_UP);
	margin_top += 2;
	mvwprintw(visu->win_help, margin_top, MARGIN_LEFT, BUTTON_NAME_SPEED_DOWN);
	wcolor_set(visu->win_help, CYAN, NULL);
	mvwprintw(visu->win_help, margin_top, MARGIN_LEFT + ft_strlen(BUTTON_NAME_SPEED_DOWN), BUTTON_SPEED_DOWN);
	margin_top -= 2;
	mvwprintw(visu->win_help, margin_top, MARGIN_LEFT + ft_strlen(BUTTON_NAME_SPEED_UP), BUTTON_SPEED_UP);
	margin_top -= 2;
	mvwprintw(visu->win_help, margin_top, MARGIN_LEFT + ft_strlen(BUTTON_NAME_DEFAULT_SPEED), BUTTON_DEFAULT_SPEED);
	margin_top -= 2;
	mvwprintw(visu->win_help, margin_top, MARGIN_LEFT + ft_strlen(BUTTON_NAME_NEXT_CYCLE), BUTTON_NEXT_CYCLE);
	margin_top -= 2;
	mvwprintw(visu->win_help, margin_top, MARGIN_LEFT + ft_strlen(BUTTON_NAME_PAUSE), BUTTON_PAUSE);
	margin_top -= 2;
	mvwprintw(visu->win_help, margin_top, MARGIN_LEFT + ft_strlen(BUTTON_NAME_EXIT), BUTTON_EXIT);
	wcolor_set(visu->win_help, 0, NULL);
	wrefresh(visu->win_help);
}