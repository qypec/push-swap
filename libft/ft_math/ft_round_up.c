/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 07:23:57 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/23 07:26:12 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_round_up(float num)
{
	float				res;

	res = num - (int)num;
	if (res == 0.0)
		return ((int)num);
	else 
		return ((int)(num + 1));
}
