/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:49:33 by mcathery          #+#    #+#             */
/*   Updated: 2019/09/19 19:42:09 by mcathery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;

	if (len + 1 == 0)
		return (NULL);
	i = 0;
	tmp = ft_strnew(len);
	if (tmp == NULL || !s || start > ft_strlen(s))
		return (NULL);
	while (i < len && s[i + start] != '\0')
	{
		tmp[i] = s[i + start];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
