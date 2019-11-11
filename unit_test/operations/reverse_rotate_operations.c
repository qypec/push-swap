#include "unit_test_operations.h"

void				check_reverse_rotate_operations(void)
{
	t_psstk 		*stack_a;
	t_psstk 		*stack_b;

	ft_printf("{yellow}Check reverse rotate operations:{reset}\n\n");

/* Case 01 basic */

	ft_printf("{blue}Case 01 [basic] -------------{reset}\n\n");
	stack_a = psstk_init(3);
	stack_b = psstk_init(3);
	create_stacks(stack_a, stack_b, "1|0 2|0 3|0", "0|0 0|0 0|0");
	REVERSE_ROTATE_A(stack_a, stack_b);
	if (compare_this(stack_a, "3|0 1|0 2|0", "reverse_rotate_a"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	psstk_delete(&stack_a);
	psstk_delete(&stack_b);

/* Case 02 basic */

	ft_printf("{blue}Case 02 [basic] -------------{reset}\n\n");
	stack_a = psstk_init(3);
	stack_b = psstk_init(3);
	create_stacks(stack_a, stack_b, "0|0 0|0 0|0", "1|0 2|0 3|0");
	REVERSE_ROTATE_B(stack_a, stack_b);
	if (compare_this(stack_b, "3|0 1|0 2|0", "reverse_rotate_b"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	psstk_delete(&stack_a);
	psstk_delete(&stack_b);

/* Case 03 basic */

	ft_printf("{blue}Case 03 [basic] -------------{reset}\n\n");
	stack_a = psstk_init(3);
	stack_b = psstk_init(3);
	create_stacks(stack_a, stack_b, "5|0 6|0 7|0", "1|0 2|0 3|0");
	REVERSE_ROTATE_AB(stack_a, stack_b);
	if (compare_this(stack_a, "7|0 5|0 6|0", "reverse_rotate_ab") && compare_this(stack_a, "3|0 1|0 2|0", "reverse_rotate_ab"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	psstk_delete(&stack_a);
	psstk_delete(&stack_b);

/* Case 04 reverse rotate stacks with only one element */

	ft_printf("{blue}Case 04 [reverse rotate stacks with only one element] -------------{reset}\n\n");
	stack_a = psstk_init(3);
	stack_b = psstk_init(3);
	create_stacks(stack_a, stack_b, "5|0 0|0 0|0", "1|0 0|0 0|0");
	REVERSE_ROTATE_AB(stack_a, stack_b);
	if (compare_this(stack_a, "5|0 0|0 0|0", "reverse_rotate_ab") && compare_this(stack_b, "1|0 0|0 0|0", "reverse_rotate_ab"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	psstk_delete(&stack_a);
	psstk_delete(&stack_b);
}
