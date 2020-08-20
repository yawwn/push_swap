/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_rotation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 14:47:45 by mcathery          #+#    #+#             */
/*   Updated: 2020/08/12 14:47:45 by mcathery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int		find_ar_type(int size, int pos, char **ar_type)
{
	if (pos > size / 2)
	{
		*ar_type = ft_strcpy(*ar_type, "rra");
		if (size > 2)
			pos = size - pos;
	}
	else
		*ar_type = ft_strcpy(*ar_type, "ra");
	return (pos);
}

int		find_br_type(int size, int pos, char **br_type)
{
	if (pos > size / 2)
	{
		*br_type = ft_strcpy(*br_type, "rrb");
		if (size > 2)
			pos = size - pos;
	}
	else
		*br_type = ft_strcpy(*br_type, "rb");
	return (pos);
}
