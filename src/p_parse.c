/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:28:46 by mcathery          #+#    #+#             */
/*   Updated: 2020/08/13 12:58:14 by mcathery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int		validate_arg(char **av, char *arg, int ac, int start)
{
	int i;
	int j;

	i = 0;
	while (i < ac)
	{
		j = 0;
		if ((av[i][j] == '-' || av[i][j] == '+') && ft_isdigit(av[i][j + 1]))
			j++;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	while (av[start] && av && arg)
	{
		if (ft_strequ(av[start], arg))
			return (0);
		start++;
	}
	return (1);
}

t_stack	*parse_arg(int ac, char **av, t_stack *a)
{
	int	i;

	i = 0;
	a->size = ac;
	a->stack = (int *)malloc(sizeof(int) * ac);
	while (i < ac)
	{
		if (validate_arg(av, av[i], ac, i + 1))
			a->stack[i] = ft_ps_atoi(av[i]);
		else
		{
			free(a->stack);
			free(a);
			ft_error();
		}
		i++;
	}
	return (a);
}

void	ft_check_double(t_stack *a, int index)
{
	int j;

	j = 0;
	while (j < index)
	{
		if (a->stack[j] == a->stack[index])
		{
			free(a->stack);
			free(a);
			ft_error();
		}
		j++;
	}
}

int		ft_p_count(char *av)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (av[i])
	{
		if ((av[i] == '-' || av[i] == '+') && (av[i - 1] == ' ' || i == 0)\
		&& (ft_isdigit(av[i + 1]) && av[i + 1] != '\0'))
			i++;
		if ((av[i] < '0' || av[i] > '9') && av[i] != ' ')
			ft_error();
		if ((av[i] >= '0' && av[i] <= '9')
			&& (av[i + 1] == ' ' || av[i + 1] == '\0'))
			res++;
		i++;
	}
	if (res == 1)
		exit(1);
	return (res);
}

t_stack	*parse_string(char *av, t_stack *a)
{
	int arg_counter;
	int i;
	int j;

	i = 0;
	j = 0;
	arg_counter = ft_p_count(av);
	a->size = arg_counter;
	a->stack = (int *)malloc(sizeof(int) * arg_counter);
	while (av[i])
	{
		if ((av[i] >= '0' && av[i] <= '9') || (av[i] == '-' || av[i] == '+'))
		{
			a->stack[j++] = ft_ps_atoi(&av[i]);
			ft_check_double(a, j - 1);
			while (av[i] != ' ' && av[i] != '\0')
				i++;
		}
		if (av[i] == ' ')
			i++;
	}
	return (a);
}
