/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:16:10 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/09 17:02:47 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

# define ERROR_MSG_BAD_OPERATION "ERROR: bad operation\n!!!EXIT!!!"
# define ERROR_MSG_BAD_NUMBER "Error"

typedef struct			s_numb
{
	size_t				correct_position;
	int					number;
}						t_numb;

typedef struct			s_psstk
{
	t_numb				**arr;
	size_t				size;
	size_t				used_size;
}						t_psstk;

t_psstk					*get_input(int argc, char **argv);

#endif
