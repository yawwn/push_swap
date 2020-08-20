/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 14:58:33 by mcathery          #+#    #+#             */
/*   Updated: 2019/09/19 19:03:56 by mcathery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t n;

	n = ft_strlen(s);
	while (n != 0 && s[n] != (char)c)
		n--;
	if (s[n] == (char)c)
		return ((char *)s + n);
	else
		return (0);
}
