#include "unit_test_operations.h"

void				check_swap_operations(void)
{
	t_stack			*stack;

	ft_printf("{yellow}Check swap operations:{reset}\n\n");

/* Case 01 basic */

	ft_printf("{blue}Case 01 [basic] -------------{reset}\n\n");
	stack = stack_init(2);
	create_stacks(stack, "1|0 2|0", "0|0 0|0");
	SWAP_A(stack);
	if (compare_this(stack->a, "2|0 1|0", "swap_a"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	stack_delete(&stack);


/* Case 02 basic */

	ft_printf("{blue}Case 02 [basic] -------------{reset}\n\n");
	stack = stack_init(2);
	create_stacks(stack, "1|0 2|0", "0|0 0|0");
	SWAP_B(stack);
	if (compare_this(stack->b, "0|0 0|0", "swap_b"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	stack_delete(&stack);


/* Case 03 basic */

	ft_printf("{blue}Case 03 [basic] -------------{reset}\n\n");
	stack = stack_init(2);
	create_stacks(stack, "1|0 2|0", "0|0 0|0");
	SWAP_AB(stack);
	if (compare_this(stack->a, "2|0 1|0", "swap_a") && compare_this(stack->b, "0|0 0|0", "swap_b"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	stack_delete(&stack);


/* Case 04 only one element */

	ft_printf("{blue}Case 04 [only one element (stack->a)] -------------{reset}\n\n");
	stack = stack_init(1);
	create_stacks(stack, "1|0", "0|0");
	SWAP_A(stack);
	if (compare_this(stack->a, "1|0", "swap_a"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	stack_delete(&stack);


/* Case 05 only one element */

	ft_printf("{blue}Case 05 [only one element (stack->b)] -------------{reset}\n\n");
	stack = stack_init(1);
	create_stacks(stack, "1|28", "15|54");
	SWAP_B(stack);
	if (compare_this(stack->b, "15|54", "swap_b"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	stack_delete(&stack);


/* Case 06 only one element */

	ft_printf("{blue}Case 06 [only one element (stack->a, stack->b)] -------------{reset}\n\n");
	stack = stack_init(1);
	create_stacks(stack, "10|7", "15|6");
	SWAP_AB(stack);
	if (compare_this(stack->a, "10|7", "swap_a") && compare_this(stack->b, "15|6", "swap_b"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	stack_delete(&stack);


/* Case 07 one element in stack->a and many in stack->b */

	ft_printf("{blue}Case 07 [one element in stack->a and many in stack->b] -------------{reset}\n\n");
	stack = stack_init(5);
	create_stacks(stack, "10|7 0|0 0|0 0|0 0|0", "15|6 42|5 13|5 56|6 100|400");
	SWAP_AB(stack);
	if (compare_this(stack->a, "10|7 0|0 0|0 0|0 0|0", "swap_a") && compare_this(stack->b, "42|5 15|6 13|5 56|6 100|400", "swap_b"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	stack_delete(&stack);

}
