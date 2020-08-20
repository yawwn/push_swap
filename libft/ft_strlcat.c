/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:07:15 by mcathery          #+#    #+#             */
/*   Updated: 2019/09/19 19:23:46 by mcathery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;

	i = 0;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstlen >= size)
		return (size + srclen);
	while (dst[i] != '\0' && i < (size - 1))
		i++;
	while (*src != '\0' && i < (size - 1))
		dst[i++] = *src++;
	dst[i] = '\0';
	return (dstlen + srclen);
}
