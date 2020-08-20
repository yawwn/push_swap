/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_global_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 18:55:29 by mcathery          #+#    #+#             */
/*   Updated: 2020/08/12 19:57:30 by mcathery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void		finish_a(t_stack *a)
{
	int	index;

	index = ft_min_index(a);
	if (index <= a->size / 2)
		while (index--)
			p_rotate(a, "ra");
	else
		while ((a->size - index) > 0)
		{
			p_reverse(a, "rra");
			index++;
		}
}

int			find_place_in_a(t_stack *a, int size, int element, char **ra_type)
{
	int		i;
	int		place;

	i = 0;
	place = 0;
	if (size == 2 && element > a->stack[0] && element < a->stack[size - 1])
		place = 1;
	else if (size == 2 && element < a->stack[0] && element > a->stack[size - 1])
		place = 0;
	else if (element > a->stack[ft_max_index(a)]
		|| element < a->stack[ft_min_index(a)])
		place = ft_min_index(a);
	else
		while (i < size)
		{
			if (element > a->stack[i]
				&& ((i + 1 < size && element < a->stack[i + 1])
					|| (i + 1 == size && element < a->stack[0])))
			{
				place = i + 1;
				break ;
			}
			i++;
		}
	return (find_ar_type(size, place, ra_type));
}

void		final_moves_to_a(t_stack *a, t_stack *b)
{
	int		r_count;
	char	*r_type;

	r_count = 0;
	r_type = ft_strnew(3);
	while (b->size)
	{
		r_count = find_place_in_a(a, a->size, b->stack[0], &r_type);
		while (r_count > 0)
		{
			if (ft_strequ(r_type, "ra"))
				p_rotate(a, "ra");
			else
				p_reverse(a, "rra");
			r_count--;
		}
		p_push(b, a, "pa");
	}
	finish_a(a);
	free(r_type);
}

void		do_separate(t_stack *a, t_stack *b, t_moves *best_move)
{
	while (best_move->a_moves)
	{
		if (ft_strequ(best_move->ar_type, "ra"))
			p_rotate(a, "ra");
		else
			p_reverse(a, "rra");
		best_move->a_moves--;
	}
	while (best_move->b_moves)
	{
		if (ft_strequ(best_move->br_type, "rb"))
			p_rotate(b, "rb");
		else
			p_reverse(b, "rrb");
		best_move->b_moves--;
	}
}

void		ft_global_sort(t_stack *a, t_stack *b)
{
	t_moves	*best_move;

	while (b->size != 2)
		p_push(a, b, "pb");
	while (a->size > 2)
	{
		best_move = calc_best_from_a_to_b(a, b);
		while (best_move->c_moves)
		{
			if (ft_strequ(best_move->cr_type, "rr"))
				p_rrotate(a, b);
			else
				p_rreverse(a, b);
			best_move->c_moves--;
		}
		do_separate(a, b, best_move);
		p_push(a, b, "pb");
		free_moves(best_move);
	}
	final_moves_to_a(a, b);
}
