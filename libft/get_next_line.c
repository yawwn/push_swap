/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 19:13:24 by mcathery          #+#    #+#             */
/*   Updated: 2020/07/22 15:27:09 by mcathery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_readline(char **stack, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*stack)[len] != '\n' && (*stack)[len] != '\0')
		len++;
	if ((*stack)[len] == '\n')
	{
		*line = ft_strsub(*stack, 0, len);
		tmp = ft_strdup(&((*stack)[len + 1]));
		free(*stack);
		*stack = tmp;
		if ((*stack)[0] == '\0')
			ft_strdel(stack);
	}
	else
	{
		*line = ft_strdup(*stack);
		ft_strdel(stack);
	}
	return (1);
}

int		ft_result(char **stack, int i, int fd, char **line)
{
	if (i < 0)
		return (-1);
	else if (i == 0 && (stack[fd] == NULL || stack[fd] == '\0'))
		return (0);
	else
		return (ft_readline(&stack[fd], line));
}

int		get_next_line(const int fd, char **line)
{
	static char	*stack[MAX_FD];
	char		*tmp;
	int			i;
	char		buffer[BUFF_SIZE + 1];

	if (fd < 0 || !line || BUFF_SIZE < 1 || fd > MAX_FD)
		return (-1);
	while ((i = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[i] = '\0';
		if (stack[fd] == NULL)
			stack[fd] = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(stack[fd], buffer);
			free(stack[fd]);
			stack[fd] = tmp;
		}
		if (ft_strchr(stack[fd], '\n'))
			break ;
	}
	return (ft_result(stack, i, fd, line));
}
