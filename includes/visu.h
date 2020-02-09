/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:44:33 by yquaro            #+#    #+#             */
/*   Updated: 2020/02/09 20:31:15 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include <ncurses.h>

# define RUNNING "RUNNING"
# define STOPPED "STOPPED"

# define IS_PAUSED		1
# define IS_RUNNING		-1
# define NODELAY_MACROS ((stack->visu->is_stopped == 1) ? TRUE : FALSE)
# define MAX_SPEED_POINT 10
# define MAX_DELAY 100000

# define WIN_STACK_LINES (82)
# define WIN_STACK_COLS (WIN_STACK_LINES * 1.5)
# define WIN_INFO_LINES (WIN_STACK_LINES * 0.75)
# define WIN_INFO_COLS (WIN_STACK_COLS / 3)
# define WIN_HELP_LINES (WIN_STACK_LINES * 0.25)
# define WIN_HELP_COLS (WIN_INFO_COLS)

/*
** Color
*/

# define COLOR_GRAY				8

/*
** Color pairs
*/

# define GRAY					5
# define GREEN					6
# define YELLOW					7
# define RED					8
# define CYAN					9
# define GRAY_BACKGROUND		10
# define GREEN_BACKGROUND		11
# define YELLOW_BACKGROUND		12
# define RED_BACKGROUND			13
# define CYAN_BACKGROUND		14

/*
** Buttons
*/

# define ESC_BUTTON				27
# define SPACE_BUTTON			' '

typedef struct                  s_visu
{
    WINDOW                      *win_stack_a;
    WINDOW                      *win_stack_b;
    WINDOW                      *win_info;
    WINDOW                      *win_help;
    int                         is_stopped;
    size_t                      speed;
    float						delay;
	int							is_next_cycle;
}                               t_visu;

int                             g_visuflag;

t_visu					        *init_visu(void);
void				        	delete_visu(t_visu *visu);

void					        init_win_stacks(t_visu *visu);
void					        init_win_info(t_visu *visu);
void					        init_win_help(t_visu *visu);
void					        init_colors(t_visu *visu);

void	        				pause_before_termination(void);

#endif
