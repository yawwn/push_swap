/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:43:16 by mcathery          #+#    #+#             */
/*   Updated: 2019/09/18 22:22:21 by mcathery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long long	n;
	long long	ex;
	int			flag;

	n = 0;
	flag = 1;
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
		ex = n;
		n = ex * 10 + (*str - '0');
		if (ex > n)
			return (flag == -1 ? 0 : -1);
		str++;
	}
	return ((int)(n * flag));
}
