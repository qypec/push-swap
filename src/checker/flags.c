/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 22:54:57 by yquaro            #+#    #+#             */
/*   Updated: 2020/02/09 21:50:51 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define ERR_BAD_FLAG_NAME "error: bad flag name"

int						skip_flags(char **input_string, int *i)
{
	if (!ft_is_digitline(input_string[*i]) && input_string[*i][0] == '-')
	{
		(*i)++;
		return (1);
	}
	return (0);
}

size_t					parse_flags(int argc, char **argv)
{
	size_t				i;

	g_visuflag = 0;
	i = 1;
	while ((int)i != argc && argv[i][0] == '-')
	{
		if (argv[i][1] == 'v')
		{
			if (argv[i][2] != '\0' && argv[i][2] != ' ')
			{
				ft_putendl(ERR_BAD_FLAG_NAME);
				exit(-1);
			}
			g_visuflag = 1;
		}
		i++;
	}
	return (i);
}
