/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:55:00 by mcathery          #+#    #+#             */
/*   Updated: 2019/09/18 20:58:49 by mcathery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t min;
	size_t max;
	size_t len;

	if (!s)
		return (NULL);
	min = 0;
	max = 0;
	while (s[min] != '\0'
			&& (s[min] == ' '
			|| s[min] == '\t'
			|| s[min] == '\n'))
		min++;
	max = ft_strlen(s);
	while (min < max
			&& (s[max - 1] == ' '
			|| s[max - 1] == '\t'
			|| s[max - 1] == '\n'))
		max--;
	if (min == max)
		return (ft_strnew(1));
	len = max - min;
	return (ft_strsub(s, min, len));
}
