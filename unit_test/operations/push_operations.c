#include "unit_test_operations.h"

void				check_push_operations(void)
{
	t_psstk 		*stack_a;
	t_psstk 		*stack_b;

	ft_printf("{yellow}Check push operations:{reset}\n\n");

/* Case 01 basic */

	ft_printf("{blue}Case 01 [basic (stack_a)] -------------{reset}\n\n");
	stack_a = psstk_init(3);
	stack_b = psstk_init(3);
	create_stacks(stack_a, stack_b, "1|3 2|15 0|0", "15|69 70|16 0|0");
	PUSH_A(stack_a, stack_b);
	if (compare_this(stack_a, "15|69 1|3 2|15", "push_a") && compare_this(stack_b, "70|16 0|0 0|0", "push_a"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	psstk_delete(&stack_a);
	psstk_delete(&stack_b);

/* Case 02 basic */

	ft_printf("{blue}Case 02 [basic (stack_b)] -------------{reset}\n\n");
	stack_a = psstk_init(3);
	stack_b = psstk_init(3);
	create_stacks(stack_a, stack_b, "1|3 2|15 0|0", "15|69 70|16 0|0");
	PUSH_B(stack_a, stack_b);
	if (compare_this(stack_a, "2|15 0|0 0|0", "push_b") && compare_this(stack_b, "1|3 15|69 70|16", "push_b"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	psstk_delete(&stack_a);
	psstk_delete(&stack_b);

/* Case 03 stack_b is empty */

	ft_printf("{blue}Case 03 [stack_b is empty] -------------{reset}\n\n");
	stack_a = psstk_init(3);
	stack_b = psstk_init(3);
	create_stacks(stack_a, stack_b, "1|3 2|15 0|0", "0|0 0|0 0|0");
	PUSH_A(stack_a, stack_b);
	if (compare_this(stack_a, "1|3 2|15 0|0", "push_a") && compare_this(stack_b, "0|0 0|0 0|0", "push_a"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	psstk_delete(&stack_a);
	psstk_delete(&stack_b);

/* Case 04 stack_b is empty */

	ft_printf("{blue}Case 04 [stack_b is empty] -------------{reset}\n\n");
	stack_a = psstk_init(3);
	stack_b = psstk_init(3);
	create_stacks(stack_a, stack_b, "1|3 2|15 0|0", "0|0 0|0 0|0");
	PUSH_B(stack_a, stack_b);
	if (compare_this(stack_a, "2|15 0|0 0|0", "push_b") && compare_this(stack_b, "1|3 0|0 0|0", "push_b"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	psstk_delete(&stack_a);
	psstk_delete(&stack_b);

/* Case 05 stack_a is empty */

	ft_printf("{blue}Case 05 [stack_a is empty] -------------{reset}\n\n");
	stack_a = psstk_init(3);
	stack_b = psstk_init(3);
	create_stacks(stack_a, stack_b, "0|0 0|0 0|0", "1|3 2|15 0|0");
	PUSH_B(stack_a, stack_b);
	if (compare_this(stack_a, "0|0 0|0 0|0", "push_b") && compare_this(stack_b, "1|3 2|15 0|0", "push_b"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	psstk_delete(&stack_a);
	psstk_delete(&stack_b);

/* Case 06 stack_a is empty */

	ft_printf("{blue}Case 06 [stack_a is empty] -------------{reset}\n\n");
	stack_a = psstk_init(3);
	stack_b = psstk_init(3);
	create_stacks(stack_a, stack_b, "0|0 0|0 0|0", "1|3 2|15 0|0");
	PUSH_A(stack_a, stack_b);
	if (compare_this(stack_a, "1|3 0|0 0|0", "push_a") && compare_this(stack_b, "2|15 0|0 0|0", "push_a"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	psstk_delete(&stack_a);
	psstk_delete(&stack_b);

/* Case 07 stack_a and stack_b are empty */

	ft_printf("{blue}Case 07 [stack_a and stack_b are empty] -------------{reset}\n\n");
	stack_a = psstk_init(3);
	stack_b = psstk_init(3);
	create_stacks(stack_a, stack_b, "0|0 0|0 0|0", "0|0 0|0 0|0");
	PUSH_A(stack_a, stack_b);
	if (compare_this(stack_a, "0|0 0|0 0|0", "push_a") && compare_this(stack_b, "0|0 0|0 0|0", "push_a"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	psstk_delete(&stack_a);
	psstk_delete(&stack_b);

/* Case 08 stack_a and stack_b are empty */

	ft_printf("{blue}Case 08 [stack_a and stack_b are empty] -------------{reset}\n\n");
	stack_a = psstk_init(3);
	stack_b = psstk_init(3);
	create_stacks(stack_a, stack_b, "0|0 0|0 0|0", "0|0 0|0 0|0");
	PUSH_B(stack_a, stack_b);
	if (compare_this(stack_a, "0|0 0|0 0|0", "push_b") && compare_this(stack_b, "0|0 0|0 0|0", "push_b"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	psstk_delete(&stack_a);
	psstk_delete(&stack_b);

/* Case 09 stack_a is full */

	ft_printf("{blue}Case 09 [stack_a is full] -------------{reset}\n\n");
	stack_a = psstk_init(6);
	stack_b = psstk_init(6);
	create_stacks(stack_a, stack_b, "2|0 1|0 3|0 6|0 5|0 8|0", "0|0 0|0 0|0 0|0 0|0 0|0");
	PUSH_B(stack_a, stack_b);
	if (compare_this(stack_a, "1|0 3|0 6|0 5|0 8|0 0|0", "push_b") && compare_this(stack_b, "2|0 0|0 0|0 0|0 0|0 0|0", "push_b"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	psstk_delete(&stack_a);
	psstk_delete(&stack_b);
}
