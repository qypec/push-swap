/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:59:20 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/17 02:01:29 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define CHUNK_SIZE ((STACK_SIZE - 2) / stack->num_of_chunks)

void				chunk_init(t_stack *stack)
{
	size_t			i;

	if ((stack->chunk = (t_chunk *)malloc(sizeof(t_chunk) * \
			stack->num_of_chunks)) == NULL)
		exit(-1);
	i = 0;
	while (i < stack->num_of_chunks - 1)
		stack->chunk[i++].size = CHUNK_SIZE;
	stack->chunk[i].size = ((STACK_SIZE - 2) - \
		(CHUNK_SIZE * (stack->num_of_chunks - 1)));
}
