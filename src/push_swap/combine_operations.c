/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 08:58:13 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/30 13:07:43 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define IS_COMBINE_OPERATIONS(str) ((str[0] == 'p') ? 0 : 1)
#define IS_CHANGING_OPERATION(str) ((str[0] == 'p') ? 1 : 0)
#define IS_A_OPERATION(name) ((name[ft_strlen(name) - 1] == 'a') ? 1 : 0)

static void				rename_operation(t_list **oper, size_t number_of_move, \
							const char *name)
{
	char				*new_operation;

	while (number_of_move--)
		oper = &(*oper)->next;
	if (ft_strequ(name, "sa") || ft_strequ(name, "sb"))
		new_operation = ft_strdup("ss");
	else if (ft_strequ(name, "ra") || ft_strequ(name, "rb"))
		new_operation = ft_strdup("rr");
	else if (ft_strequ(name, "rra") || ft_strequ(name, "rrb"))
		new_operation = ft_strdup("rrr");
	ft_strdel((char **)&((*oper)->content));
	(*oper)->content = new_operation;
}

static int				is_different_stack_operation(const char *name, \
							size_t *numof_a, size_t *numof_b)
{
	if (IS_A_OPERATION(name))
		(*numof_a)++;
	else
		(*numof_b)++;
	if (*numof_b != 0 && *numof_a != 0)
		return (1);
	return (0);
}

static const char		*get_pair_name(const char *name)
{
	if (ft_strequ(name, "sa"))
		return ("sb");
	else if (ft_strequ(name, "sb"))
		return ("sa");
	else if (ft_strequ(name, "ra"))
		return ("rb");
	else if (ft_strequ(name, "rb"))
		return ("ra");
	else if (ft_strequ(name, "rra"))
		return ("rrb");
	else if (ft_strequ(name, "rrb"))
		return ("rra");
	return (NULL);
}

static t_list			**combine(t_list **oper, size_t numof_a, size_t numof_b)
{
	const char			*name;
	size_t				number_of_move;

	name = (const char *)((*oper)->content);
	number_of_move = 0;
	if (numof_a == 0 && numof_b == 0)
	{
		rename_operation(oper, 0, name);
		ft_lstdelthis(oper, 1, lst_content_del);
		return (&(*oper)->next);
	}
	if (numof_a != 0)
	{
		number_of_move = numof_a;
		if (IS_A_OPERATION(name))
		{
			rename_operation(oper, 0, name);
			ft_lstdelthis(oper, numof_a + 1, lst_content_del);
		}
		else
		{
			rename_operation(oper, numof_a + 1, name);
			ft_lstdelthis(oper, 0, lst_content_del);
		}
	}
	else if (numof_b != 0)
	{
		number_of_move = numof_b;
		if (IS_A_OPERATION(name))
		{
			rename_operation(oper, numof_b + 1, name);
			ft_lstdelthis(oper, 0, lst_content_del);
		}
		else
		{
			rename_operation(oper, 0, name);
			ft_lstdelthis(oper, numof_b + 1, lst_content_del);
		}
	}
	while (*oper != NULL && number_of_move--)
		oper = &(*oper)->next;
	return (&(*oper)->next);
}

static t_list			**find_and_combine_pair(t_list **oper)
{
	t_list				*operation;
	const char			*pair;
	size_t				numof_a;
	size_t				numof_b;

	pair = get_pair_name((const char *)((*oper)->content));
	operation = (*oper)->next;
	numof_a = 0;
	numof_b = 0;
	while (operation != NULL)
	{
		if (IS_CHANGING_OPERATION(((const char *)operation->content)))
			return (&(*oper)->next);
		else if (ft_strequ((const char *)operation->content, pair))
			return (combine(oper, numof_a, numof_b));
		else if (is_different_stack_operation((const char *)operation->content, \
				&numof_a, &numof_b))
			return (&(*oper)->next);
		operation = operation->next;
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
