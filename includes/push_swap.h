/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:16:10 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/20 19:39:39 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

# define ERROR_MSG_BAD_OPERATION "ERROR: bad operation\n!!!EXIT!!!"
# define ERROR_MSG_BAD_NUMBER "Error"

# define IS_EMPTY(stack) (stack->used_size == 0) ? 1 : 0

# define A_ORIENTATION 1
# define B_ORIENTATION 2

// # define IS_FIRST_TRIPLET(turn) (turn == 0) ? 1 : 0 
// # define IS_LAST_TRIPLET(turn, size) (((turn + 1) * 3) >= size) ? 1 : 0

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
void					add_number_to_psstk(t_psstk *stack_a, size_t index, int number);
void					add_correct_position(t_psstk *stack, int number, \
							size_t correct_position);
t_numb					*numb_init(void);
void					numb_delete(t_numb **numb);

t_psstk					*get_input(int argc, char **argv);

void					swap_a(t_psstk *stack_a, t_psstk *stack_b);
void					swap_b(t_psstk *stack_a, t_psstk *stack_b);
void					swap_ab(t_psstk *stack_a, t_psstk *stack_b);
void					push_a(t_psstk *stack_a, t_psstk *stack_b);
void					push_b(t_psstk *stack_a, t_psstk *stack_b);
void					rotate_a(t_psstk *stack_a, t_psstk *stack_b);
void					rotate_b(t_psstk *stack_a, t_psstk *stack_b);
void					rotate_ab(t_psstk *stack_a, t_psstk *stack_b);
void					reverse_rotate_a(t_psstk *stack_a, t_psstk *stack_b);
void					reverse_rotate_b(t_psstk *stack_a, t_psstk *stack_b);
void					reverse_rotate_ab(t_psstk *stack_a, t_psstk *stack_b);

void					*execute_operations(t_psstk *stack_a, t_psstk *stack_b, \
							char **operations);

void					add_operation(t_buff *operations, const char *name);
int						*create_temp_array(t_psstk *stack, size_t size);

void					push_to_stack_b(t_psstk *stack_a, t_psstk *stack_b, \
							t_buff *operations);
void					sort_triplet_stack_a(t_psstk *stack_a, \
							t_psstk *stack_b, t_buff *operations);
void					sort_stack_b(t_psstk *stack_a, t_psstk *stack_b, \
							t_buff *operations);

#endif
