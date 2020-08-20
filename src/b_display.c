/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_display.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:51:20 by mcathery          #+#    #+#             */
/*   Updated: 2020/08/11 18:15:14 by mcathery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int		ft_strlen_upd(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != ' ')
		i++;
	return (i);
}

long	ft_ps_atoi(const char *str)
{
	long	n;
	int		flag;
	int		i;

	n = 0;
	flag = 1;
	i = ft_strlen_upd(str);
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = -1;
		str++;
	}
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	if (flag == -1)
		n *= -1;
	if (n > INT_MAX || n < INT_MIN || i > 11)
		ft_error();
	return (n);
}

void	free_all(t_stack *a, t_stack *b)
{
	free(a->stack);
	free(a);
	free(b->stack);
	free(b);
}

void	ft_visual(t_stack *a, t_stack *b)
{
	int i;
	int j;

	i = a->size - 1;
	j = b->size - 1;
	ft_printf("\033[0;36mSTACK A\t\tSTACK B\033[0m\n");
	while (i >= 0 || j >= 0)
	{
		if (i >= 0)
		{
			ft_printf("%s", ft_itoa(a->stack[i]));
			if (j < 0)
				ft_printf("\n");
		}
		if (j >= 0)
			ft_printf("\t\t%s\n", ft_itoa(b->stack[j]));
		i--;
		j--;
	}
	ft_printf("\033[0;36mSTEPS: \033[0m%d\n", a->steps);
}
