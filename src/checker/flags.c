/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 22:54:57 by yquaro            #+#    #+#             */
/*   Updated: 2020/02/18 10:07:54 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define ERR_BAD_FLAG_NAME "error: bad flag name"

// int						skip_flags(char **input_string, int *i)
// {
// 	if (*input_string == NULL)
// 		return (0);
// 	if (!ft_is_digitline(input_string[*i]) && input_string[*i][0] == '-')
// 	{
// 		(*i)++;
// 		return (1);
// 	}
// 	return (0);
// }

int						parse_flags(char *str)
{
	if (str[0] != '-')
		return (0);
	if (str[1] == 'v' && (str[2] != '\0' && str[2] != ' '))
		ft_putendl(ERR_BAD_FLAG_NAME);
	else if (str[1] == 'v')
	{
		g_visuflag = 1;
		return (1);
	}
	return (0);
}
