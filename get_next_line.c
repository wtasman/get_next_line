/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 17:29:35 by wasman            #+#    #+#             */
/*   Updated: 2016/11/09 16:18:58 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_in(int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		len;

	buff = memset(buff, 0, BUFF_SIZE);
	len = read(fd, buff, BUFF_SIZE);
	if (len <= 0)
		return (0);
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
	if (!(new_line = strnew(BUFF_SIZE)))
		return (0);
	if (!(buff = read_in(fd)))
		return (0);
	while ((buff[i] != '\n') || (buff[i] != '\0'))
	{
		new_line[i] = buff[i];
		i++;
	}
}
