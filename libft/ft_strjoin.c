/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:42:32 by mcathery          #+#    #+#             */
/*   Updated: 2019/09/17 17:44:08 by mcathery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	tmp = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (tmp == NULL)
		return (NULL);
	while (*s1 != '\0')
		tmp[i++] = *s1++;
	while (*s2 != '\0')
		tmp[i++] = *s2++;
	tmp[i] = '\0';
	return (tmp);
}
