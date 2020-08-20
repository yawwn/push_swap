/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:37:31 by mcathery          #+#    #+#             */
/*   Updated: 2020/08/12 18:32:16 by mcathery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int		ft_max(t_stack *a)
{
	int max;
	int i;

	i = 0;
	max = a->stack[i];
	while (i < a->size)
	{
		if (a->stack[i] > max)
			max = a->stack[i];
		i++;
	}
	return (max);
}

void	ft_sort_3_elements(t_stack *a)
{
	int max;

	max = ft_max(a);
	if (a->size == 1)
		return ;
	else if (a->size == 2)
	{
		if (a->stack[0] > a->stack[1])
			p_swap(a, "sa");
		return ;
	}
	else if (a->size == 3)
	{
		if (a->stack[0] == max)
			p_rotate(a, "ra");
		if (a->stack[1] == max)
			p_reverse(a, "rra");
		if (a->stack[0] > a->stack[1])
			p_swap(a, "sa");
	}
}

void	ft_sort_5_elements(t_stack *a, t_stack *b, t_sort *sort)
{
	while (b->size < 2)
	{
		if (a->stack[0] == sort->min || a->stack[0] == sort->max)
			p_push(a, b, "pb");
		else
			p_rotate(a, "ra");
	}
	ft_sort_3_elements(a);
	p_push(b, a, "pa");
	p_push(b, a, "pa");
	if (a->stack[0] == sort->max)
		p_rotate(a, "ra");
	else
	{
		p_swap(a, "sa");
		p_rotate(a, "ra");
	}
}
