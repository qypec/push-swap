#include "unit_test_operations.h"

void				check_rotate_operations(void)
{
	t_stack			*stack;

	ft_printf("{yellow}Check rotate operations:{reset}\n\n");

/* Case 01 basic */

	ft_printf("{blue}Case 01 [basic] -------------{reset}\n\n");
	stack = stack_init(3);
	create_stacks(stack, "1|0 2|0 3|0", "0|0 0|0 0|0");
	ROTATE_A(stack);
	if (compare_this(stack->a, "2|0 3|0 1|0", "rotate_a"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	stack_delete(&stack);

/* Case 02 basic */

	ft_printf("{blue}Case 02 [basic] -------------{reset}\n\n");
	stack = stack_init(3);
	create_stacks(stack, "0|0 0|0 0|0", "1|0 2|0 3|0");
	ROTATE_B(stack);
	if (compare_this(stack->b, "2|0 3|0 1|0", "rotate_b"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	stack_delete(&stack);

/* Case 03 basic */

	ft_printf("{blue}Case 03 [basic] -------------{reset}\n\n");
	stack = stack_init(3);
	create_stacks(stack, "5|0 6|0 7|0", "1|0 2|0 3|0");
	ROTATE_AB(stack);
	if (compare_this(stack->a, "6|0 7|0 5|0", "rotate_ab") && compare_this(stack->b, "2|0 3|0 1|0", "rotate_ab"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	stack_delete(&stack);

/* Case 04 rotate stacks with only one element */

	ft_printf("{blue}Case 04 [rotate stacks with only one element] -------------{reset}\n\n");
	stack = stack_init(3);
	create_stacks(stack, "5|0 0|0 0|0", "1|0 0|0 0|0");
	ROTATE_AB(stack);
	if (compare_this(stack->a, "5|0 0|0 0|0", "rotate_ab") && compare_this(stack->b, "1|0 0|0 0|0", "rotate_ab"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	stack_delete(&stack);
}
