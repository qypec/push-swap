/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 01:44:16 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/17 01:44:17 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_TEST_H
# define UNIT_TEST_H

# include "../../includes/libft.h"
# include "../../ft_map/ft_map.h"

void					del_strcontent(void *content, size_t content_size);

t_list					*create_list(const char *str_items);
void					delete_list(t_list **alst, void (*del)(void *, size_t));

int						compare_this(t_list *actual, const char *str_expected);

void					test_ft_list(void);

void					test_ft_map(void);

void					create_map(t_map **map, const char *input);
int						compare_maps(t_map **map, const char *expected);
void					delete_map(t_map **map);

#endif
