/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:08:01 by yquaro            #+#    #+#             */
/*   Updated: 2019/11/20 15:50:29 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void				swap(int *first, int *second)
{
	int					tmp;

	if (first == second)
		return ;
	tmp = *first;
	*first = *second;
	*second = tmp;
}

static void				qs(int *arr, size_t first, size_t last)
{
	size_t				left;
	size_t				right;
	int					piv;

	left = first;
	right = last;
	piv = arr[(left + right) / 2];
	while (left <= right)
	{
		while (arr[left] < piv)
			left++;
		while (arr[right] > piv)
			right--;
		if (left <= right)
			swap(&arr[left++], &arr[right--]);
	}
	if (first < right)
		qs(arr, first, right);
	if (last > left)
		qs(arr, left, last);
}

void				ft_qsort(int *array, size_t size)
{
	qs(array, 0, size - 1);
}
