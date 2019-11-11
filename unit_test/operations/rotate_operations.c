/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:29:12 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/11 17:41:52 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test_operations.h"

void				check_rotate_operations(void)
{
	t_psstk 		*stack_a;
	t_psstk 		*stack_b;

	ft_printf("{yellow}Check rotate operations:{reset}\n\n");

/* Case 01 basic */

	ft_printf("{blue}Case 01 [basic] -------------{reset}\n\n");
	stack_a = psstk_init(3);
	stack_b = psstk_init(3);
	create_stacks(stack_a, stack_b, "1|0 2|0 3|0", "0|0 0|0 0|0");
	ROTATE_A(stack_a, stack_b);
	if (compare_this(stack_a, "2|0 3|0 1|0", "rotate_a"))
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
	ROTATE_B(stack_a, stack_b);
	if (compare_this(stack_b, "2|0 3|0 1|0", "rotate_b"))
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
	ROTATE_AB(stack_a, stack_b);
	if (compare_this(stack_a, "6|0 7|0 5|0", "rotate_ab") && compare_this(stack_b, "2|0 3|0 1|0", "rotate_ab"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	psstk_delete(&stack_a);
	psstk_delete(&stack_b);

/* Case 04 basic */

	ft_printf("{blue}Case 04 [rotate stacks with only one element] -------------{reset}\n\n");
	stack_a = psstk_init(3);
	stack_b = psstk_init(3);
	create_stacks(stack_a, stack_b, "5|0 0|0 0|0", "1|0 0|0 0|0");
	ROTATE_AB(stack_a, stack_b);
	if (compare_this(stack_a, "5|0 0|0 0|0", "rotate_ab") && compare_this(stack_b, "1|0 0|0 0|0", "rotate_ab"))
		ft_printf("\t{green}OK{reset}\n\n");
	else
		ft_printf("\t{red}KO{reset}\n\n");
	psstk_delete(&stack_a);
	psstk_delete(&stack_b);
}
