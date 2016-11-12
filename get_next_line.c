/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 17:29:35 by wasman            #+#    #+#             */
/*   Updated: 2016/11/12 09:56:45 by wasman           ###   ########.fr       */
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

char	*read_in(int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		len;

	buff = memset(buff, 0, BUFF_SIZE);
	len = read(fd, buff, BUFF_SIZE);
	if (len <= 0)
		return (NULL);
	buff[BUFF_SIZE] = '\0';
	return (buff);
}

int	get_next_line(const int fd, char **line)
{
	static char	*new_line;
	char		buff[BUFF_SIZE];
	int			len;
	int			i;

	i = 0;
	if (!line || fd <= 0)
		return (-1);
	if (!(new_line = strnew(BUFF_SIZE)))
		return (-1);
	if (!(buff = read_in(fd)))
		return (0);
	while ((buff[i] != '\n') || (buff[i] != '\0'))
	{
		new_line[i] = buff[i];
		i++;
	}
}
