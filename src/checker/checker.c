/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:48:56 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/06 19:22:42 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int						main(int argc, char **argv)
{
	size_t				i;
	int					number[argc];
	char				**operations;
	t_buff				*buffer;
	char				symb;

	i = 0;
	while (i < argc - 1)
	{
		number[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	buffer = ft_buffinit(100);
	while (read(0, &symb, 1) > 0)
		ft_buffaddsymb(buffer, symb);
	operations = ft_strsplit(buffer->str, '\n');
}
