/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 17:29:35 by wasman            #+#    #+#             */
/*   Updated: 2016/11/12 18:14:28 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		find_n(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

char	*read_in(int fd, char **buff)
{
	char	read_buff[BUFF_SIZE + 1];
	int		len;

	if ((len = read(fd, read_buff, BUFF_SIZE)) > 0)
	{
		read_buff[len] = '\0';
		if (!buff)
			*buff = ft_strdup(read_buff);
		else
			*buff = ft_strjoin(*buff, read_buff);
		return (len);
	}
	return (len);
}

int	get_next_line(const int fd, char **line)
{
	static char	*buff;
	int			len;

	len = 0;
	if (!line || fd <= 0)
		return (-1);
	*line = NULL;
	if ((len = read_in(fd, &buff)) < 0)
		return (len);
}
