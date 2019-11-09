/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:14:08 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/09 17:32:42 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_numb					*numb_init(void)
{
	t_numb				*numb;

	if ((numb = (t_numb *)malloc(sizeof(t_numb))) == NULL)
		exit(-1);
	numb->correct_position = 0;
	numb->number= 0;
	return (numb);
}

void					numb_delete(t_numb **numb)
{
	(*numb)->correct_position = 0;
	(*numb)->number = 0;
	free(*numb);
	*numb = NULL;
}
