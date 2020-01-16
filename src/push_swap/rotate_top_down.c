/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_top_down.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:49:53 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/17 02:06:30 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void					rotate_down_b(t_stack *stack, size_t number_of_rotate)
{
	while (number_of_rotate--)
		reverse_rotate_b(stack);
}

void					rotate_top_b(t_stack *stack, size_t number_of_rotate)
{
	while (number_of_rotate--)
		rotate_b(stack);
}

void					rotate_down_a(t_stack *stack, size_t number_of_rotate)
{
	while (number_of_rotate--)
		reverse_rotate_a(stack);
}

void					rotate_top_a(t_stack *stack, size_t number_of_rotate)
{
	while (number_of_rotate--)
		rotate_a(stack);
}
