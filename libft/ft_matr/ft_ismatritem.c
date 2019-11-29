/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ismatritem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 23:58:37 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/28 23:58:44 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_ismatritem(char **matr, const char *item)
{
	size_t			i;

	i = 0;
	while (matr[i] != NULL)
	{
		if (ft_strequ(matr[i], item))
			return (1);
		i++;
	}
	return (0);
}
