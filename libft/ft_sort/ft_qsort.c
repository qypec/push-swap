/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:08:01 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/14 16:43:40 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void				qs(int **array, size_t first, size_t last)
{
	int l = b, r = e;
	int					piv = arr[(l + r) / 2];
  while (l <= r)
  {
    while (arr[l] < piv)
      l++;
    while (arr[r] > piv)
      r--;
    if (l <= r)
      swap (arr[l++], arr[r--]);
  }
  if (b < r)
    qsort (b, r);
  if (e > l)
    qsort (l, e);
}

void				ft_qsort(int **array, size_t size)
{
	qs(array, 0, size - 1);
}
