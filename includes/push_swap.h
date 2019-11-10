/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:16:10 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/10 21:32:15 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

# define ERROR_MSG_BAD_OPERATION "ERROR: bad operation\n!!!EXIT!!!"
# define ERROR_MSG_BAD_NUMBER "Error"

# define IS_EMPTY(stack) (stack->used_size == 0) ? 1 : 0

typedef struct			s_numb
{
	size_t				correct_position;
	int					number;
}						t_numb;

typedef struct			s_psstk
{
	t_numb				**arr;
	size_t				size;
	size_t				used_size;
}						t_psstk;


/* debugging */

void					dbg_print_stack(t_psstk *stk);
void					dbg_print_stacks(t_psstk *stk_a, t_psstk *stk_b);

/* */

t_psstk					*psstk_init(int	size);
void					psstk_delete(t_psstk **psstk);
void					add_to_psstk(t_psstk *stack_a, size_t index, int number);
t_numb					*numb_init(void);
void					numb_delete(t_numb **numb);

t_psstk					*get_input(int argc, char **argv);

void					stack_shift_down(t_psstk *stk);
void					stack_shift_up(t_psstk *stk);

void					swap_a(t_psstk *stack_a, t_psstk *stack_b);
void					swap_b(t_psstk *stack_a, t_psstk *stack_b);
void					swap_ab(t_psstk *stack_a, t_psstk *stack_b);
void					push_a(t_psstk *stack_a, t_psstk *stack_b);
void					push_b(t_psstk *stack_a, t_psstk *stack_b);
void					rotate_a(t_psstk *stack_a, t_psstk *stack_b);
void					rotate_b(t_psstk *stack_a, t_psstk *stack_b);
void					rotate_ab(t_psstk *stack_a, t_psstk *stack_b);

#endif
