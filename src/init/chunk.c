/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:59:20 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/02 18:11:35 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define CHUNK_SIZE (STACK_SIZE / stack->num_of_chunks)
#define REMAINDER_SIZE (STACK_SIZE - (CHUNK_SIZE * (stack->num_of_chunks - 1)))

void				chunk_init(t_stack *stack)
{
	size_t			i;
	
	if ((stack->chunk = (t_chunk *)malloc(sizeof(t_chunk) * \
			stack->num_of_chunks)) == NULL)
		exit(-1);
	i = 0;
	while (i < stack->num_of_chunks - 1)
		stack->chunk[i++].size = CHUNK_SIZE;
	stack->chunk[i].size = REMAINDER_SIZE;
}

// void				chunk_delete(t_chunk **chunk)
// {
// 	free((*chunk)->size);
// 	(*chunk)->size = NULL;
// 	free(*chunk);
// 	*chunk = NULL;
// }
