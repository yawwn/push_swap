/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_check_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:43:50 by mcathery          #+#    #+#             */
/*   Updated: 2020/08/13 13:13:31 by mcathery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	commands_2(t_stack *a, t_stack *b, char *buf)
{
	char c;

	c = 1;
	if (ft_strcmp(buf, "rr") == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strcmp(buf, "rrr") == 0)
	{
		reverse(a);
		reverse(b);
	}
	else
	{
		free_all(a, b);
		write(2, "Error\n", 6);
		if (buf[0] != '\0' && buf[1] != '\0'
			&& buf[2] != '\0' && buf[3] != '\0')
			while (c != '\n')
				read(1, &c, 1);
		exit(1);
	}
}

void	commands(t_stack *a, t_stack *b, char *buf)
{
	if (ft_strcmp(buf, "pa") == 0)
		push(b, a);
	else if (ft_strcmp(buf, "pb") == 0)
		push(a, b);
	else if (ft_strcmp(buf, "sa") == 0)
		swap(a);
	else if (ft_strcmp(buf, "sb") == 0)
		swap(b);
	else if (ft_strcmp(buf, "ra") == 0)
		rotate(a);
	else if (ft_strcmp(buf, "rb") == 0)
		rotate(b);
	else if (ft_strcmp(buf, "rra") == 0)
		reverse(a);
	else if (ft_strcmp(buf, "rrb") == 0)
		reverse(b);
	else if (ft_strcmp(buf, "ss") == 0)
	{
		swap(a);
		swap(b);
	}
	else
		commands_2(a, b, buf);
	if (a->v == 1)
		ft_visual(a, b);
}

int		ft_sorted(t_stack *a, t_stack *b)
{
	int i;

	i = -1;
	if (b->size > 0)
		return (0);
	while (++i < a->size - 1)
	{
		if (a->stack[i] < a->stack[i + 1])
			return (0);
	}
	return (1);
}

void	ft_check(t_stack *a, t_stack *b)
{
	char	c;
	char	buf[4];
	int		i;

	c = 0;
	i = 0;
	buf[3] = '\0';
	while (read(0, &c, 1))
	{
		if (c == '\n')
			buf[i++] = '\0';
		else
			buf[i++] = c;
		if (c == '\n' || i == 4)
		{
			a->steps++;
			commands(a, b, buf);
			i = 0;
		}
	}
}

void	ft_check_function(t_stack *a, t_stack *b)
{
	a->steps = 0;
	if (a->v == 1)
		ft_visual(a, b);
	ft_check(a, b);
	if (ft_sorted(a, b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
