/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:56:07 by mcathery          #+#    #+#             */
/*   Updated: 2019/09/19 19:48:07 by mcathery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count(int n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
		i++;
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*tmp;
	size_t	j;

	j = count(n);
	if (!(tmp = ft_strnew(j)))
		return (0);
	tmp[j--] = '\0';
	if (n == 0)
		tmp[0] = '0';
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n < 0)
	{
		tmp[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		tmp[j] = n % 10 + '0';
		n = n / 10;
		j--;
	}
	return (tmp);
}
