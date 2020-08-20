/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:47:35 by mcathery          #+#    #+#             */
/*   Updated: 2019/09/19 19:45:47 by mcathery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*tmp;
	size_t	i;

	if (s && f)
	{
		i = 0;
		tmp = ft_strnew(ft_strlen(s));
		if (tmp == NULL)
			return (0);
		while (s[i] != '\0')
		{
			tmp[i] = f(s[i]);
			i++;
		}
		tmp[i] = '\0';
		return (tmp);
	}
	return (NULL);
}
