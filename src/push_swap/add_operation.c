/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:18:05 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/20 17:22:32 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void					add_operation(t_buff *operations, const char *name)
{
	if (operations->i != 0)
		ft_buffaddsymb(operations, ' ');
	ft_buffadd(operations, name);
}
