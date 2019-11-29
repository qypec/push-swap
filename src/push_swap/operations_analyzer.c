/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_analyzer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 22:42:53 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/29 08:50:55 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define IS_SELF_DESTRUCTION_OPERATIONS(str) ((str[0] == 's') ? 0 : 1)

static const char		*get_pair_name(const char *name)
{
	if (ft_strequ(name, "pa"))
		return ("pb");
	else if (ft_strequ(name, "pb"))
		return ("pa");
	else if (ft_strequ(name, "ra"))
		return ("rra");
	else if (ft_strequ(name, "rb"))
		return ("rrb");
	else if (ft_strequ(name, "rra"))
		return ("ra");
	else if (ft_strequ(name, "rrb"))
		return ("rb");
	return (NULL);
}

static char				**get_changing_operations_matr(const char *name)
{
	char				**changing_operations;

	if (ft_strequ(name, "pa"))
		return (ft_matrnew("pb", "ra", "rra", "rb", "rrb", "sa", "sb", NULL));
	else if (ft_strequ(name, "pb"))
		return (ft_matrnew("pa", "ra", "rra", "rb", "rrb", "sa", "sb", NULL));
	else if (ft_strequ(name, "ra"))
		return (ft_matrnew("sa", "pa", "pb", NULL));
	else if (ft_strequ(name, "rb"))
		return (ft_matrnew("sb", "pa", "pb", NULL));
	else if (ft_strequ(name, "rra"))
		return (ft_matrnew("sa", "pa", "pb", NULL));
	else if (ft_strequ(name, "rrb"))
		return (ft_matrnew("sb", "pa", "pb", NULL));
	return (NULL);
}


static int				find_and_remove_pair(t_list **oper)
{
	t_list				*operation;
	char				**changing;
	const char			*pair;
	const char			*name;
	size_t				counter;

	name = (const char *)((*oper)->content);
	pair = get_pair_name(name);
	changing = get_changing_operations_matr(name);
	operation = (*oper)->next;
	counter = 1;
	while (operation != NULL)
	{
		if (ft_strequ((const char *)operation->content, pair))
			break ;
		else if (ft_ismatritem(changing, (const char *)operation->content))
			return (0);
		operation = operation->next;
		counter++;
	}
	if (operation == NULL)
		return (0);
	// ft_printf("before operation:\n");
	// ft_lstprint(*oper, ft_putstr);
	ft_lstdelthis(oper, counter, lst_content_del);
	// ft_printf("after operation:\n");
	// ft_lstprint(*oper, ft_putstr);

	// ft_printf("before:\n");
	// ft_lstprint(*oper, ft_putstr);
	ft_lstdelthis(oper, 0, lst_content_del);
	// ft_printf("after:\n");
	// ft_lstprint(*oper, ft_putstr);
	return (1);
}

void					remove_self_destruction_operations(t_list **operation)
{
	t_list				*oper;
	int					ret;

	while (*operation != NULL)
	{
		ret = 0;
		if (IS_SELF_DESTRUCTION_OPERATIONS(((char *)((*operation)->content))))
			ret = find_and_remove_pair(operation);
		// print_operations(*operation);
		// ft_putchar('\n');
		if (ret != 1)
			operation = &(*operation)->next;
	}
}
