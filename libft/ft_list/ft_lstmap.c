/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:56:42 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/17 15:49:35 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list			*newlst;

	while (lst != NULL)
	{
		if ((newlst = f(lst)) == NULL)
			return (NULL);
		ft_lstpushback(&newlst, f(lst));
		lst = lst->next;
	}
	return (newlst);
}
