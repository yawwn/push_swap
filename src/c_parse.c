/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:12:36 by mcathery          #+#    #+#             */
/*   Updated: 2020/08/12 16:22:50 by mcathery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	double_check(t_stack *a, int counter, char c)
{
	int i;
	int j;

	i = a->stack[counter];
	j = 0;
	if (c == 's')
	{
		while (++counter < a->size)
			if (a->stack[counter] == i)
			{
				free(a->stack);
				free(a);
				ft_error();
			}
	}
	else if (c == 'a')
	{
		while (j < counter)
			if (a->stack[j++] == i)
			{
				free(a->stack);
				free(a);
				ft_error();
			}
	}
}

int		ft_count(char *av)
{
	int		res;
	int		i;

	res = 0;
	i = 0;
	while (av[i])
	{
		if (av[i] == '-' && (av[i - 1] == ' ' || i == 0))
			i++;
		if ((av[i] < '0' || av[i] > '9') && av[i] != ' ')
			ft_error();
		if ((av[i] >= '0' && av[i] <= '9')\
		&& (av[i + 1] == ' ' || av[i + 1] == '\0'))
			res++;
		i++;
	}
	if (res == 1)
		exit(1);
	return (res);
}

t_stack	*p_string(char *av)
{
	t_stack		*a;
	int			arg_counter;
	int			i;

	i = 0;
	arg_counter = ft_count(av);
	if (!(a = (t_stack *)malloc(sizeof(t_stack))))
		exit(1);
	a->size = arg_counter;
	if (!(a->stack = (int *)malloc(sizeof(int) * arg_counter)))
		exit(1);
	while (av[i])
	{
		if ((av[i] >= '0' && av[i] <= '9') || av[i] == '-')
		{
			a->stack[--arg_counter] = ft_ps_atoi(&av[i]);
			double_check(a, arg_counter, 's');
			while (av[i] != ' ' && av[i] != '\0')
				i++;
		}
		if (av[i] == ' ')
			i++;
	}
	return (a);
}

t_stack	*p_args(char **av, int ac)
{
	t_stack		*a;
	int			i;
	int			j;

	i = 0;
	while (i < ac)
	{
		j = -1;
		if (av[i][j + 1] == '-')
			j++;
		while (av[i][++j])
			if (av[i][j] < '0' || av[i][j] > '9')
				ft_error();
		i++;
	}
	i = 0;
	a = (t_stack *)malloc(sizeof(t_stack));
	a->size = ac;
	a->stack = (int *)malloc(sizeof(int) * ac);
	while (--ac >= 0)
	{
		a->stack[i++] = ft_ps_atoi(av[ac]);
		double_check(a, i - 1, 'a');
	}
	return (a);
}
