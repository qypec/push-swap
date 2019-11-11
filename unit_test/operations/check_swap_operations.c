#include "unit_test_operations.h"

void				check_swap_operations(void)
{
	t_psstk 		*stack_a;
	t_psstk 		*stack_b;

	ft_printf("{yellow}Check swap operations:{reset}\n\n");

/* Case 01 */

	ft_printf("{blue}Case 01 -------------{reset}\n\n");
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

/* Case 02 */

	ft_printf("{blue}Case 02 -------------{reset}\n\n");
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

/* Case 03 */

	ft_printf("{blue}Case 03 -------------{reset}\n\n");
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

}
