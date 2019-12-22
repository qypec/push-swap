/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:16:10 by yquaro            #+#    #+#             */
/*   Updated: 2019/12/22 08:23:40 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

# define ERROR_MSG_BAD_OPERATION "ERROR: bad operation\n!!!EXIT!!!"
# define ERROR_MSG_BAD_NUMBER "Error"
# define ERROR_MSG_PAIR_OF_ELEMENTS "ERROR: pair of elements\n!!!EXIT!!!"
# define ERROR_MSG_BIGGER_THAN_INT "ERROR: bigger than int\n!!!EXIT!!!"

# define IS_EMPTY(stack) (stack->used_size == 0) ? 1 : 0

# define HEAD_ITEM(stack) stack->arr[0]
# define TAIL_ITEM(stack) stack->arr[stack->used_size - 1]

# define DELIMITER(num) ((IS_EVEN(num)) ? (num / 2) : ((num / 2) + 1))
#define SORTED 1
#define NO_RESULT 0

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

typedef struct			s_stack
{
	t_psstk				*a;
	t_psstk				*b;
	t_list				*operation;
}						t_stack;

/* debugging */

void					dbg_print_stack(t_psstk *stk);
void					dbg_print_stacks(t_stack *stack);

/* */

t_stack					*stack_init(size_t size);
void					stack_delete(t_stack **stack);
t_psstk					*psstk_init(int	size);
void					psstk_delete(t_psstk **psstk);
void					lst_content_del(void *content, size_t content_size);

void					add_number_to_psstk(t_psstk *stack_a, size_t index, int number);
void					add_correct_position(t_psstk *stack, int number, \
							size_t correct_position);
t_numb					*numb_init(void);
void					numb_delete(t_numb **numb);

t_stack					*get_input(int argc, char **argv);

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

void					*execute_operations(t_stack *stack, char **operations);

void					print_operations(t_list *operation);

void					add_operation(t_list **operation, const char *name);
int						median_search(t_psstk *stack, size_t size, \
							const char *rounding);
void					fill_correct_position(t_psstk *stack, size_t size);

size_t					nulling_static_variable(size_t *transfered_size);
void					rotate_down_b(t_stack *stack, size_t number_of_rotate);
void					rotate_top_b(t_stack *stack, size_t number_of_rotate);
void					rotate_down_a(t_stack *stack, size_t number_of_rotate);
void					rotate_top_a(t_stack *stack, size_t number_of_rotate);



void					remove_self_destruction_operations(t_list **operation);
void					combine_operations(t_list **operation);

#endif
