/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:58:53 by mcathery          #+#    #+#             */
/*   Updated: 2020/08/11 16:10:11 by mcathery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int		ft_partition(int *buf, int start, int end)
{
	int pivot;
	int i;
	int j;
	int tmp;

	pivot = buf[end];
	i = start - 1;
	j = start;
	while (j < end)
	{
		if (buf[j] <= pivot)
		{
			i++;
			tmp = buf[i];
			buf[i] = buf[j];
			buf[j] = tmp;
		}
		j++;
	}
	tmp = buf[i + 1];
	buf[i + 1] = buf[end];
	buf[end] = tmp;
	return (i + 1);
}

void	ft_quicksort(int *buf, int start, int end)
{
	int pi;

	if (start < end)
	{
		pi = ft_partition(buf, start, end);
		ft_quicksort(buf, start, pi - 1);
		ft_quicksort(buf, pi + 1, end);
	}
}
