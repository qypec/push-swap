/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:33:48 by yquaro            #+#    #+#             */
/*   Updated: 2020/02/06 20:40:51 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void					error_processing_operations(t_stack **stack)
{
	stack_delete(stack);
	ft_putendl(ERROR_MSG_BAD_OPERATION);
	exit(-1);
}

void					error_processing_numbers(const char *msg, char *str_num)
{
	ft_printf("%s : %s\n", msg, str_num);
	exit(-1);
}
