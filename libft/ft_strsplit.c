/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:58:46 by mcathery          #+#    #+#             */
/*   Updated: 2019/09/19 20:22:08 by mcathery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_word_num(char const *s, char c)
{
	size_t flag;
	size_t num;

	num = 0;
	flag = 0;
	while (*s != '\0')
	{
		if (flag == 1 && *s == c)
			flag = 0;
		else if (flag == 0 && *s != c)
		{
			flag = 1;
			num++;
		}
		s++;
	}
	return (num);
}

static void		ft_free(char **tmp, size_t i)
{
	while (i--)
		ft_strdel(&tmp[i]);
	free(*tmp);
	*tmp = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	start;
	size_t	num;
	size_t	j;
	size_t	i;
	char	**tmp;

	if (!s || !c)
		return (NULL);
	num = ft_word_num(s, c);
	if (!(tmp = (char **)malloc((sizeof(char *) * num + 1))))
		return (0);
	i = 0;
	j = -1;
	while (++j < num)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		start = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (!(tmp[j] = ft_strsub(s, start, i++ - start)))
			ft_free(tmp, i);
	}
	tmp[j] = NULL;
	return (tmp);
}
