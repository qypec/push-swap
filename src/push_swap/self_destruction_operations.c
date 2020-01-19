/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   self_destruction_oerations.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 22:42:53 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/17 16:33:22 by yquaro           ###   ########.fr       */
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

static int              destroy(t_list **oper, size_t counter)
{
    ft_lstdelthis(oper, counter, lst_content_del);
    ft_lstdelthis(oper, 0, lst_content_del);
    return (1);
}

static int				find_and_remove_pair(t_list **oper)
{
    t_list				*operation;
	const char			*pair;
	size_t				counter;

	pair = get_pair_name((const char *)((*oper)->content));
	operation = (*oper)->next;
	counter = 1;
	while (operation != NULL)
	{
		if (ft_strequ((const char *)operation->content, pair))
			return (destroy(oper, counter));
		else if (!ft_strequ(((const char *)operation->content), (const char *)((*oper)->content)))
			return (0);
		operation = operation->next;
		counter++;
	}
	return (0);
}

void					remove_self_destruction_operations(t_list **operation)
{
	int					ret;
	t_list				**tmp;

	tmp = operation;
	while (*operation != NULL)
	{
		ret = 0;
		if (IS_SELF_DESTRUCTION_OPERATIONS(((char *)((*operation)->content))))
			ret = find_and_remove_pair(operation);
		if (ret == 1)
			operation = tmp;
		else
			operation = &(*operation)->next;
	}
}
