/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_best_move_finder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 14:30:09 by mcathery          #+#    #+#             */
/*   Updated: 2020/08/13 13:04:02 by mcathery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void		free_moves(t_moves *moves)
{
	free(moves->ar_type);
	free(moves->br_type);
	free(moves->cr_type);
	free(moves);
}

int			find_place_in_b(t_stack *b, int size, int element, char **rb_type)
{
	int		i;
	int		place;

	i = 0;
	place = 0;
	if (size == 2 && element > b->stack[0] && element < b->stack[size - 1])
		place = 0;
	else if (size == 2 && element < b->stack[0] && element > b->stack[size - 1])
		place = 1;
	else if (element > b->stack[ft_max_index(b)]\
	|| element < b->stack[ft_min_index(b)])
		place = ft_max_index(b);
	else
		while (i < size)
		{
			if (element < b->stack[i]\
			&& ((i + 1 < size && element > b->stack[i + 1])\
			|| (i + 1 == size && element > b->stack[0])))
			{
				place = i + 1;
				break ;
			}
			i++;
		}
	return (find_br_type(size, place, rb_type));
}

int			find_common(t_moves *moves)
{
	int		common;

	common = 0;
	if (((ft_strequ(moves->ar_type, "ra"))\
	&& (ft_strequ(moves->br_type, "rb")))\
	|| ((ft_strequ(moves->ar_type, "rra"))\
	&& (ft_strequ(moves->br_type, "rrb"))))
	{
		common = (moves->a_moves > moves->b_moves\
		? moves->b_moves : moves->a_moves);
		if (common)
		{
			moves->cr_type = ft_strcpy(moves->cr_type, moves->ar_type);
			moves->cr_type[ft_strlen(moves->cr_type) - 1] = 'r';
			moves->b_moves -= common;
			moves->a_moves -= common;
		}
	}
	return (common);
}

t_moves		*moves_from_a_to_b(t_stack *a, t_stack *b, int i)
{
	t_moves	*moves;

	moves = (t_moves *)malloc(sizeof(t_moves));
	moves->ar_type = ft_strnew(3);
	moves->br_type = ft_strnew(3);
	moves->cr_type = ft_strnew(3);
	moves->element = a->stack[i];
	moves->a_moves = find_ar_type(a->size, i, &(moves->ar_type));
	moves->b_moves = find_place_in_b(b, b->size,
			a->stack[i], &(moves->br_type));
	moves->c_moves = find_common(moves);
	moves->total = moves->a_moves + moves->b_moves + moves->c_moves + 1;
	return (moves);
}

t_moves		*calc_best_from_a_to_b(t_stack *a, t_stack *b)
{
	int		i;
	t_moves	*best_move;
	t_moves	*moves_helper;

	i = 0;
	while (i < a->size)
	{
		moves_helper = moves_from_a_to_b(a, b, i);
		if (i == 0)
			best_move = moves_helper;
		else if (best_move->total > moves_helper->total)
		{
			free_moves(best_move);
			best_move = moves_helper;
		}
		else
			free_moves(moves_helper);
		i++;
	}
	return (best_move);
}
