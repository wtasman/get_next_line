/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 17:29:35 by wasman            #+#    #+#             */
/*   Updated: 2016/11/16 18:10:00 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_n(char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	read_in(int fd, char **buff)
{
	char	read_buff[BUFF_SIZE + 1];
	int		len;
	char	*str;

	len = read(fd, read_buff, BUFF_SIZE);
	if (len > 0)
	{
		read_buff[len] = '\0';
		if (!(*buff))
		{
			*buff = read_buff;
			return (len);
		}
		str = ft_strjoin(*buff, read_buff);
		if (!str)
			return (-1);
		free(*buff);
		*buff = str;
	}
	return (len);
}

int	get_next_line(const int fd, char **line)
{
	static char	*buff;
	int			len;
	int			n;

	len = 0;
	if (!line || fd <= 0)
		return (-1);
	if (!(buff = (char *)malloc(sizeof(char))))
		return (-1);
	n = find_n(buff, '\n');
	while (n == -1)
	{
		len = read_in(fd, &buff);
		if (n == -1 && find_n(buff, '\0') > 0)
		{
			*line = ft_strsub(buff, 0, n - 1);
			return (0);
		}	   
		else if (len < 0)
			return (-1);
		else
			n = find_n(buff, '\n');
	}
	*line = ft_strsub(buff, 0, n - 1);
	if (!line)
		return (-1);
	ft_putstr(*line);
	ft_putchar('\n');
	free(buff);
	buff = ft_strsub(*line, n, (ft_strlen(*line) - n));
	ft_putstr(buff);
	ft_putchar('\n');
	return (1);
}

int	main(int argc, char **argv)
{
	int fd;
	int	res;
	char	*line;

	res = 0;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	while(res <= 0)
		res = get_next_line(fd, &line); 
	return(0);
}
