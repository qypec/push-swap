/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:44:33 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/30 18:40:31 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

#include <ncurses.h>

# define _GIVE_NUMOF_LIVE_ 1

# define RUNNING "RUNNING"
# define STOPPED "STOPPED"

# define IS_PAUSED		1
# define IS_RUNNING		-1
# define NODELAY_MACROS ((vm.visu->is_stopped == 1) ? TRUE : FALSE)
# define MAX_SPEED_POINT 10
# define MAX_DELAY 100000

# define WIN_STACK_LINES (64)
# define WIN_STACK_COLS (WIN_STACK_LINES * 2)
# define WIN_INFO_LINES (WIN_STACK_LINES)
# define WIN_INFO_COLS (WIN_STACK_COLS / 3)
# define WIN_HELP_LINES (WIN_STACK_LINES / 5)
# define WIN_HELP_COLS (WIN_STACK_COLS * 2)

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
# define GRAY_CARRY				10
# define GREEN_CARRY			11
# define YELLOW_CARRY			12
# define RED_CARRY				13
# define CYAN_CARRY				14

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
}                               t_visu;


t_visu					        *init_visu(void);
void					        delete_visu(t_visu **visu);

void					        init_win_stacks(t_visu *visu);
void					        init_win_info(t_visu *visu);
void					        init_win_help(t_visu *visu);
void					        init_colors(t_visu *visu);

void                            draw_stacks(t_stack *stack);

#endif