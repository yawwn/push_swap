/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_checker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:06:10 by mcathery          #+#    #+#             */
/*   Updated: 2020/08/13 14:16:50 by mcathery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int		main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	int			i;

	if (ac < 2 || (ac == 2 && ft_strcmp(av[1], "-v") == 0))
		exit(1);
	i = ft_strcmp(av[1], "-v") == 0 ? 2 : 1;
	if (ac == 2 || (ac == 3 && ft_strcmp(av[1], "-v") == 0))
		a = p_string(av[i]);
	else
		a = p_args(&av[i], ac - i);
	a->v = ft_strcmp(av[1], "-v") == 0 ? 1 : 0;
	b = (t_stack*)malloc(sizeof(t_stack));
	b->size = 0;
	b->stack = (int *)malloc(sizeof(int) * a->size);
	ft_check_function(a, b);
	free_all(a, b);
	exit(0);
}
