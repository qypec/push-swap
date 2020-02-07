/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:05:53 by yquaro            #+#    #+#             */
/*   Updated: 2020/02/07 19:50:08 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void				init_pairs(void)
{
	init_color(COLOR_GRAY, 355, 355, 355);
	init_pair(GRAY, COLOR_GRAY, 0);
	init_pair(GREEN, COLOR_GREEN, 0);
	init_pair(YELLOW, COLOR_YELLOW, 0);
	init_pair(RED, COLOR_RED, 0);
	init_pair(CYAN, COLOR_CYAN, 0);
	init_pair(GRAY_BACKGROUND, COLOR_BLACK, COLOR_GRAY);
	init_pair(GREEN_BACKGROUND, COLOR_BLACK, COLOR_GREEN);
	init_pair(YELLOW_BACKGROUND, COLOR_BLACK, COLOR_YELLOW);
	init_pair(RED_BACKGROUND, COLOR_BLACK, COLOR_RED);
	init_pair(CYAN_BACKGROUND, COLOR_BLACK, COLOR_CYAN);
}

void					init_colors(t_visu *visu)
{
	if (!has_colors())
	{
		delete_visu(visu);
		ft_putendl("Your terminal does not support color");
		exit(1);
	}
	start_color();
	init_pairs();
}
