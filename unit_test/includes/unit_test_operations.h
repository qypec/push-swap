#ifndef UNIT_TEST_OPERATIONS_H
# define UNIT_TEST_OPERATIONS_H

# include "../../libft/includes/libft.h"
# include "../../includes/push_swap.h"

# define SWAP_A swap_a
# define SWAP_B swap_b
# define SWAP_AB swap_ab
# define PUSH_A push_a
# define PUSH_B push_b
# define ROTATE_A rotate_a
# define ROTATE_B rotate_b
# define ROTATE_AB rotate_ab
# define REVERSE_ROTATE_A reverse_rotate_a
# define REVERSE_ROTATE_B reverse_rotate_b
# define REVERSE_ROTATE_AB reverse_rotate_ab

void				create_stacks(t_stack *stack, const char *a, \
						const char *b);
int					compare_this(t_psstk *stack, \
						const char *expected_result, const char *operation);

void				check_swap_operations(void);
void				check_push_operations(void);
void				check_rotate_operations(void);
void				check_reverse_rotate_operations(void);

#endif