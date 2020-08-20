/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:23:34 by mcathery          #+#    #+#             */
/*   Updated: 2020/08/13 12:20:21 by mcathery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	ft_bs_initializator(t_stack *a, t_stack *b, t_sort *sort)
{
	int *buf;

	b->size = 0;
	b->stack = (int*)malloc(sizeof(int) * a->size);
	buf = (int *)malloc(sizeof(int) * (a->size));
	buf = ft_intcpy(buf, a->stack, a->size);
	ft_quicksort(buf, 0, a->size - 1);
	sort->min = buf[0];
	sort->max = buf[a->size - 1];
	free(buf);
}

void	ft_to_sort(t_stack *a, t_stack *b, t_sort *sort)
{
	if (a->size <= 3)
		ft_sort_3_elements(a);
	else if (a->size <= 5)
		ft_sort_5_elements(a, b, sort);
	else
		ft_global_sort(a, b);
}

int		ft_sort(t_stack *a)
{
	int i;

	i = -1;
	while (++i < a->size - 1)
	{
		if (a->stack[i] > a->stack[i + 1])
			return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	t_sort	*sort;

	(ac-- == 1) ? exit(1) : av++;
	a = (t_stack *)malloc(sizeof(t_stack));
	if (ac == 1)
		a = parse_string(*av, a);
	else
		a = parse_arg(ac, av, a);
	b = (t_stack *)malloc(sizeof(t_stack));
	sort = (t_sort *)malloc(sizeof(t_sort));
	ft_bs_initializator(a, b, sort);
	if (ft_sort(a))
		ft_to_sort(a, b, sort);
	free_all(a, b);
	free(sort);
	return (0);
}
