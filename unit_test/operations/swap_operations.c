#include "unit_test_operations.h"

void				check_swap_operations(void)
{
	t_psstk 		*stack_a;
	t_psstk 		*stack_b;

	ft_printf("{yellow}Check swap operations:{reset}\n\n");

/* Case 01 basic */

	ft_printf("{blue}Case 01 [basic] -------------{reset}\n\n");
	stack_a = psstk_init(2);
	stack_b = psstk_init(2);
	create_stacks(stack_a, stack_b, "1|0 2|0", "0|0 0|0");
	SWAP_A(stack_a, stack_b);
	if (compare_this(stack_a, "2|0 1|0", "swap_a"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	psstk_delete(&stack_a);
	psstk_delete(&stack_b);

/* Case 02 basic */

	ft_printf("{blue}Case 02 [basic] -------------{reset}\n\n");
	stack_a = psstk_init(2);
	stack_b = psstk_init(2);
	create_stacks(stack_a, stack_b, "1|0 2|0", "0|0 0|0");
	SWAP_B(stack_a, stack_b);
	if (compare_this(stack_b, "0|0 0|0", "swap_b"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	psstk_delete(&stack_a);
	psstk_delete(&stack_b);

/* Case 03 basic */

	ft_printf("{blue}Case 03 [basic] -------------{reset}\n\n");
	stack_a = psstk_init(2);
	stack_b = psstk_init(2);
	create_stacks(stack_a, stack_b, "1|0 2|0", "0|0 0|0");
	SWAP_AB(stack_a, stack_b);
	if (compare_this(stack_a, "2|0 1|0", "swap_a") && compare_this(stack_b, "0|0 0|0", "swap_b"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	psstk_delete(&stack_a);
	psstk_delete(&stack_b);

/* Case 04 only one element */

	ft_printf("{blue}Case 04 [only one element (stack_a)] -------------{reset}\n\n");
	stack_a = psstk_init(1);
	stack_b = psstk_init(1);
	create_stacks(stack_a, stack_b, "1|0", "0|0");
	SWAP_A(stack_a, stack_b);
	if (compare_this(stack_a, "1|0", "swap_a"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	psstk_delete(&stack_a);
	psstk_delete(&stack_b);

/* Case 05 only one element */

	ft_printf("{blue}Case 05 [only one element (stack_b)] -------------{reset}\n\n");
	stack_a = psstk_init(1);
	stack_b = psstk_init(1);
	create_stacks(stack_a, stack_b, "1|28", "15|54");
	SWAP_B(stack_a, stack_b);
	if (compare_this(stack_b, "15|54", "swap_b"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	psstk_delete(&stack_a);
	psstk_delete(&stack_b);

/* Case 06 only one element */

	ft_printf("{blue}Case 06 [only one element (stack_a, stack_b)] -------------{reset}\n\n");
	stack_a = psstk_init(1);
	stack_b = psstk_init(1);
	create_stacks(stack_a, stack_b, "10|7", "15|6");
	SWAP_AB(stack_a, stack_b);
	if (compare_this(stack_a, "10|7", "swap_a") && compare_this(stack_b, "15|6", "swap_b"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	psstk_delete(&stack_a);
	psstk_delete(&stack_b);

/* Case 07 one element in stack_a and many in stack_b */

	ft_printf("{blue}Case 07 [one element in stack_a and many in stack_b] -------------{reset}\n\n");
	stack_a = psstk_init(5);
	stack_b = psstk_init(5);
	create_stacks(stack_a, stack_b, "10|7 0|0 0|0 0|0 0|0", "15|6 42|5 13|5 56|6 100|400");
	SWAP_AB(stack_a, stack_b);
	if (compare_this(stack_a, "10|7 0|0 0|0 0|0 0|0", "swap_a") && compare_this(stack_b, "42|5 15|6 13|5 56|6 100|400", "swap_b"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	psstk_delete(&stack_a);
	psstk_delete(&stack_b);
}
