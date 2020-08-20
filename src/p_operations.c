/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 16:28:11 by mcathery          #+#    #+#             */
/*   Updated: 2020/08/12 18:49:31 by mcathery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	p_reverse(t_stack *z, char *str)
{
	int temp;
	int i;

	i = z->size - 1;
	temp = z->stack[i];
	while (i > 0)
	{
		z->stack[i] = z->stack[i - 1];
		i--;
	}
	z->stack[0] = temp;
	i = 0;
	if (!ft_strequ(str, "rrr"))
	{
		while (str[i])
			write(1, &str[i++], 1);
		write(1, "\n", 1);
	}
}

void	p_rotate(t_stack *z, char *str)
{
	int i;
	int temp;

	i = 1;
	temp = z->stack[0];
	while (i < z->size)
	{
		z->stack[i - 1] = z->stack[i];
		i++;
	}
	z->stack[i - 1] = temp;
	i = 0;
	if (!ft_strequ(str, "rr"))
	{
		while (str[i])
			write(1, &str[i++], 1);
		write(1, "\n", 1);
	}
}

void	p_swap(t_stack *z, char *str)
{
	int	temp;
	int i;

	i = 0;
	temp = 0;
	if (z->size <= 1)
		return ;
	temp = z->stack[0];
	z->stack[0] = z->stack[1];
	z->stack[1] = temp;
	if (!ft_strequ(str, "ss"))
	{
		while (str[i])
			write(1, &str[i++], 1);
		write(1, "\n", 1);
	}
}

void	p_push(t_stack *from, t_stack *to, char *str)
{
	int i;
	int j;

	i = to->size;
	j = 0;
	if (from->size == 0)
		return ;
	while (i-- > 0)
		to->stack[i + 1] = to->stack[i];
	to->stack[0] = from->stack[0];
	i = 0;
	while (i++ <= from->size - 1)
		from->stack[i - 1] = from->stack[i];
	to->size++;
	from->size--;
	while (str[j])
		write(1, &str[j++], 1);
	write(1, "\n", 1);
}
