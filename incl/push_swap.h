/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 14:58:23 by mcathery          #+#    #+#             */
/*   Updated: 2020/08/13 12:20:21 by mcathery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct		s_stack
{
	int				*stack;
	int				size;
	int				v;
	int				steps;
}					t_stack;

typedef struct		s_sort
{
	int				min;
	int				max;
}					t_sort;

typedef struct		s_moves
{
	int				element;
	char			*ar_type;
	char			*br_type;
	char			*cr_type;
	int				a_moves;
	int				b_moves;
	int				c_moves;
	int				total;
}					t_moves;

t_stack				*p_string(char *av);
t_stack				*p_args(char **av, int ac);
t_stack				*parse_arg(int ac, char **av, t_stack *a);
void				ft_error();
void				push(t_stack *from, t_stack *to);
void				swap(t_stack *z);
void				rotate(t_stack *z);
void				reverse(t_stack *z);
void				commands(t_stack *a, t_stack *b, char *buf);
void				ft_visual(t_stack *a, t_stack *b);
void				free_all(t_stack *a, t_stack *b);
long				ft_ps_atoi(const char *str);
void				ft_check_function(t_stack *a, t_stack *b);
void				ft_check(t_stack *a, t_stack *b);
int					*ft_intcpy(int *dst, int *src, int len);
void				ft_quicksort(int *buf, int start, int end);
void				ft_sort_5_elements(t_stack *a, t_stack *b, t_sort *sort);
void				ft_sort_3_elements(t_stack *a);
void				p_reverse(t_stack *z, char *str);
void				p_rotate(t_stack *z, char *str);
void				p_swap(t_stack *z, char *str);
void				p_push(t_stack *from, t_stack *to, char *str);
void				p_rreverse(t_stack *a, t_stack *b);
void				p_rrotate(t_stack *a, t_stack *b);
void				p_sswap(t_stack *a, t_stack *b);
void				ft_global_sort(t_stack *a, t_stack *b);
t_moves				*calc_best_from_a_to_b(t_stack *a, t_stack *b);
int					ft_min_index(t_stack *a);
int					ft_max_index(t_stack *a);
int					find_ar_type(int size, int pos, char **ar_type);
int					find_br_type(int size, int pos, char **br_type);
void				free_moves(t_moves *moves);
t_stack				*parse_string(char *av, t_stack *a);

#endif
