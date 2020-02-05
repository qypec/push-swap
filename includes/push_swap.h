/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:16:10 by yquaro            #+#    #+#             */
/*   Updated: 2020/02/05 18:05:30 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "visu.h"

# define ERROR_MSG_BAD_OPERATION "ERROR: bad operation"
# define ERROR_MSG_BAD_NUMBER "ERROR: bad number"
# define ERROR_MSG_PAIR_OF_ELEMENTS "ERROR: pair of elements"
# define ERROR_MSG_BIGGER_THAN_INT "ERROR: bigger than int"

# define STACK_SIZE stack->a->size
# define U_SIZE(stack) (stack->used_size)

# define IS_EMPTY(stack) (stack->used_size == 0) ? 1 : 0

# define HEAD_ITEM(stack) stack->num[0]
# define TAIL_ITEM(stack) stack->num[stack->used_size - 1]

# define NUM_OF_CHUNKS 3

// visu



// visu end


typedef struct			s_chunk
{
	size_t				size;
	int					fixed_item;
}						t_chunk;

typedef struct			s_psstk
{
	int					*num;
	size_t				size;
	size_t				used_size;
}						t_psstk;

//visu 



// visu end

typedef struct			s_stack
{
	t_psstk				*a;
	t_psstk				*b;
	t_list				*operation;
	t_chunk				*chunk;
	t_visu				*visu;
}						t_stack;



void					dbg_print_stacks(t_stack *stack);

void					error_processing_numbers(const char *msg, \
							char *str_num);
void					error_processing_operations(t_stack **stack, \
							char ***operations);

t_stack					*stack_init(size_t size);
void					stack_delete(t_stack **stack);
t_psstk					*psstk_init(int	size);
void					psstk_delete(t_psstk **psstk);
void					lst_content_del(void *content, size_t content_size);
void					chunk_init(t_stack *stack);

void					add_number_to_psstk(t_psstk *stack_a, size_t index, \
							int number);

t_stack					*get_input(int argc, char **argv);
void					print_man(void);

void					swap_a(t_stack *stack);
void					swap_b(t_stack *stack);
void					swap_ab(t_stack *stack);
void					push_a(t_stack *stack);
void					push_b(t_stack *stack);
void					rotate_a(t_stack *stack);
void					rotate_b(t_stack *stack);
void					rotate_ab(t_stack *stack);
void					reverse_rotate_a(t_stack *stack);
void					reverse_rotate_b(t_stack *stack);
void					reverse_rotate_ab(t_stack *stack);

void					rotate_down_b(t_stack *stack, size_t number_of_rotate);
void					rotate_top_b(t_stack *stack, size_t number_of_rotate);
void					rotate_down_a(t_stack *stack, size_t number_of_rotate);
void					rotate_top_a(t_stack *stack, size_t number_of_rotate);

void					*execute_operations(t_stack *stack, char **operations);

void					print_operations(t_list *operation);
void					add_operation(t_list **operation, const char *name);

void					move_to_stack_b(t_stack *stack);
void					move_to_stack_a(t_stack *stack);

void					remove_self_destruction_operations(t_list **operation);
void					combine_operations(t_list **operation);

int						*create_temp_array(size_t size, char **nums_str, \
							int *unsorted_arr);

// visu

void						draw_stacks(t_stack *stack);

// visu end

#endif
