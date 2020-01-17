/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:59:20 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/17 08:38:05 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define CHUNK_SIZE (STACK_SIZE / 3)
#define REMAINING_SIZE (STACK_SIZE - CHUNK_SIZE * 2)

void				chunk_init(t_stack *stack)
{
	size_t			i;

	if ((stack->chunk = (t_chunk *)malloc(sizeof(t_chunk) * \
			NUM_OF_CHUNKS)) == NULL)
		exit(-1);
	stack->chunk[0].size = CHUNK_SIZE;
	stack->chunk[0].fixed_item = 1;
	stack->chunk[1].size = CHUNK_SIZE;
	stack->chunk[1].fixed_item = CHUNK_SIZE + (CHUNK_SIZE / 2);
	stack->chunk[2].size = REMAINING_SIZE;
	stack->chunk[2].fixed_item = STACK_SIZE;
}
