/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:18:05 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/23 04:30:35 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void					add_operation(t_list **operation, const char *name)
{
	ft_lstpushback(operation, ft_lstnew(ft_strdup(name), sizeof(char *)));
}
