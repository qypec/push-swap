#include "unit_test_operations.h"

void				check_push_operations(void)
{
	t_stack			*stack;

	ft_printf("{yellow}Check push operations:{reset}\n\n");

/* Case 01 basic */

	ft_printf("{blue}Case 01 [basic (stack->a)] -------------{reset}\n\n");
	stack = stack_init(3);
	create_stacks(stack, "1|3 2|15 0|0", "15|69 70|16 0|0");
	PUSH_A(stack);
	if (compare_this(stack->a, "15|69 1|3 2|15", "push_a") && compare_this(stack->b, "70|16 0|0 0|0", "push_a"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	stack_delete(&stack);

/* Case 02 basic */

	ft_printf("{blue}Case 02 [basic (stack->b)] -------------{reset}\n\n");
	stack = stack_init(3);
	create_stacks(stack, "1|3 2|15 0|0", "15|69 70|16 0|0");
	PUSH_B(stack);
	if (compare_this(stack->a, "2|15 0|0 0|0", "push_b") && compare_this(stack->b, "1|3 15|69 70|16", "push_b"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	stack_delete(&stack);

/* Case 03 stack->b is empty */

	ft_printf("{blue}Case 03 [stack->b is empty] -------------{reset}\n\n");
	stack = stack_init(3);
	create_stacks(stack, "1|3 2|15 0|0", "0|0 0|0 0|0");
	PUSH_A(stack);
	if (compare_this(stack->a, "1|3 2|15 0|0", "push_a") && compare_this(stack->b, "0|0 0|0 0|0", "push_a"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	stack_delete(&stack);

/* Case 04 stack->b is empty */

	ft_printf("{blue}Case 04 [stack->b is empty] -------------{reset}\n\n");
	stack = stack_init(3);
	create_stacks(stack, "1|3 2|15 0|0", "0|0 0|0 0|0");
	PUSH_B(stack);
	if (compare_this(stack->a, "2|15 0|0 0|0", "push_b") && compare_this(stack->b, "1|3 0|0 0|0", "push_b"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	stack_delete(&stack);

/* Case 05 stack->a is empty */

	ft_printf("{blue}Case 05 [stack->a is empty] -------------{reset}\n\n");
	stack = stack_init(3);
	create_stacks(stack, "0|0 0|0 0|0", "1|3 2|15 0|0");
	PUSH_B(stack);
	if (compare_this(stack->a, "0|0 0|0 0|0", "push_b") && compare_this(stack->b, "1|3 2|15 0|0", "push_b"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	stack_delete(&stack);

/* Case 06 stack->a is empty */

	ft_printf("{blue}Case 06 [stack->a is empty] -------------{reset}\n\n");
	stack = stack_init(3);
	create_stacks(stack, "0|0 0|0 0|0", "1|3 2|15 0|0");
	PUSH_A(stack);
	if (compare_this(stack->a, "1|3 0|0 0|0", "push_a") && compare_this(stack->b, "2|15 0|0 0|0", "push_a"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	stack_delete(&stack);

/* Case 07 stack->a and stack->b are empty */

	ft_printf("{blue}Case 07 [stack->a and stack->b are empty] -------------{reset}\n\n");
	stack = stack_init(3);
	create_stacks(stack, "0|0 0|0 0|0", "0|0 0|0 0|0");
	PUSH_A(stack);
	if (compare_this(stack->a, "0|0 0|0 0|0", "push_a") && compare_this(stack->b, "0|0 0|0 0|0", "push_a"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	stack_delete(&stack);

/* Case 08 stack->a and stack->b are empty */

	ft_printf("{blue}Case 08 [stack->a and stack->b are empty] -------------{reset}\n\n");
	stack = stack_init(3);
	create_stacks(stack, "0|0 0|0 0|0", "0|0 0|0 0|0");
	PUSH_B(stack);
	if (compare_this(stack->a, "0|0 0|0 0|0", "push_b") && compare_this(stack->b, "0|0 0|0 0|0", "push_b"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	stack_delete(&stack);

/* Case 09 stack->a is full */

	ft_printf("{blue}Case 09 [stack->a is full] -------------{reset}\n\n");
	stack = stack_init(6);
	create_stacks(stack, "2|0 1|0 3|0 6|0 5|0 8|0", "0|0 0|0 0|0 0|0 0|0 0|0");
	PUSH_B(stack);
	if (compare_this(stack->a, "1|0 3|0 6|0 5|0 8|0 0|0", "push_b") && compare_this(stack->b, "2|0 0|0 0|0 0|0 0|0 0|0", "push_b"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	stack_delete(&stack);
}
