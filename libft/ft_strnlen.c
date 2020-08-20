/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:56:43 by mcathery          #+#    #+#             */
/*   Updated: 2019/09/15 14:26:25 by mcathery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strnlen(const char *s, size_t maxlen)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	if (maxlen < i)
		return (maxlen);
	else
		return (i);
}
