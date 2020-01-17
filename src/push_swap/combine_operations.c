/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 10:17:24 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/17 10:56:29 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define IS_COMBINE_OPERATIONS(str) ((str[0] == 'r') ? 1 : 0)

static void				rename_operation(t_list **oper, const char *name)
{
	char				*new_operation;

	if (ft_strequ(name, "sa") || ft_strequ(name, "sb"))
		new_operation = ft_strdup("ss");
	else if (ft_strequ(name, "ra") || ft_strequ(name, "rb"))
		new_operation = ft_strdup("rr");
	else if (ft_strequ(name, "rra") || ft_strequ(name, "rrb"))
		new_operation = ft_strdup("rrr");
	ft_strdel((char **)&((*oper)->content));
	(*oper)->content = new_operation;
}

static t_list			**combine(t_list **oper, size_t counter)
{
	rename_operation(oper, (const char *)((*oper)->content));
	ft_lstdelthis(oper, counter, lst_content_del);
	return (&(*oper)->next);
}

static const char		*get_pair_name(const char *name)
{
	if (ft_strequ(name, "ra"))
		return ("rb");
	else if (ft_strequ(name, "rb"))
		return ("ra");
	else if (ft_strequ(name, "rra"))
		return ("rrb");
	else if (ft_strequ(name, "rrb"))
		return ("rra");
	return (NULL);
}

static t_list           **find_and_combine_pair(t_list **oper)
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
			return (combine(oper, counter));
		else if (!ft_strequ(((const char *)operation->content), (const char *)((*oper)->content)))
			return (&(*oper)->next);
		operation = operation->next;
		counter++;
	}
	return (&(*oper)->next);
}

void					combine_operations(t_list **operation)
{
    while (*operation != NULL)
    {
		if (IS_COMBINE_OPERATIONS(((char *)((*operation)->content))))
			operation = find_and_combine_pair(operation);
		else
			operation = &(*operation)->next;
    }
}
