/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_addit_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:49:20 by mcathery          #+#    #+#             */
/*   Updated: 2020/08/13 14:16:50 by mcathery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int		*ft_intcpy(int *dst, int *src, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

int		ft_min_index(t_stack *a)
{
	int min;
	int i;
	int index;

	i = 0;
	index = 0;
	min = a->stack[i];
	while (i < a->size)
	{
		if (min > a->stack[i])
		{
			min = a->stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int		ft_max_index(t_stack *a)
{
	int max;
	int i;
	int index;

	i = 0;
	index = 0;
	max = a->stack[i];
	while (i < a->size)
	{
		if (a->stack[i] > max)
		{
			max = a->stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}
