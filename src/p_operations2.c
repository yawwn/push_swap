/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_operations2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 18:41:54 by mcathery          #+#    #+#             */
/*   Updated: 2020/08/12 19:01:18 by mcathery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	p_rreverse(t_stack *a, t_stack *b)
{
	p_reverse(a, "rrr");
	p_reverse(b, "rrr");
	write(1, "rrr\n", 4);
}

void	p_rrotate(t_stack *a, t_stack *b)
{
	p_rotate(a, "rr");
	p_rotate(b, "rr");
	write(1, "rr\n", 3);
}

void	p_sswap(t_stack *a, t_stack *b)
{
	p_swap(a, "ss");
	p_swap(b, "ss");
	write(1, "ss\n", 3);
}
