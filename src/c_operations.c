/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:05:14 by mcathery          #+#    #+#             */
/*   Updated: 2020/08/07 17:55:00 by mcathery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	reverse(t_stack *z)
{
	int temp;
	int i;

	i = 0;
	temp = 0;
	temp = z->stack[0];
	while (i++ < z->size - 1)
		z->stack[i - 1] = z->stack[i];
	z->stack[z->size - 1] = temp;
}

void	rotate(t_stack *z)
{
	int i;
	int temp;

	i = z->size - 1;
	temp = z->stack[z->size - 1];
	while (i > 0)
	{
		z->stack[i] = z->stack[i - 1];
		i--;
	}
	z->stack[i] = temp;
}

void	swap(t_stack *z)
{
	int	temp;

	temp = 0;
	if (z->size <= 1)
		return ;
	temp = z->stack[z->size - 1];
	z->stack[z->size - 1] = z->stack[z->size - 2];
	z->stack[z->size - 2] = temp;
}

void	push(t_stack *from, t_stack *to)
{
	if (from->size == 0)
		return ;
	to->stack[to->size] = from->stack[from->size - 1];
	from->stack[from->size - 1] = 0;
	to->size++;
	from->size--;
}
