/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:51:45 by mcathery          #+#    #+#             */
/*   Updated: 2019/09/19 19:48:07 by mcathery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*tmp;

	if (size + 1 == 0)
		return (NULL);
	if (!(tmp = (char *)malloc(size + 1)))
		return (NULL);
	tmp[size] = '\0';
	while (size--)
		tmp[size] = '\0';
	return (tmp);
}
