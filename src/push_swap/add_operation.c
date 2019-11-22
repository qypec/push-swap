/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:18:05 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/23 00:26:34 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void					add_operation(t_buff *operations, const char *name)
{
	if (operations->i != 0)
		ft_buffaddsymb(operations, '\n');
	ft_buffadd(operations, name);
}
