/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 17:29:35 by wasman            #+#    #+#             */
/*   Updated: 2016/10/26 10:34:08 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int	main (int argc, char **argv)
{
	char	line[BUFF_SIZE];
	int		fd;
	if (argc == 2)
	{
		fd = open(argv[1], ORD_ONLY)
		get_next_line(fd, *line);
		ft_putstr(line);
	}
	return (0);
}

/*int get_next_line(int fd, char **line)
{
	int	i;
	int	size;
	char	buff[BUFF_SIZE];
	int	len;
	
	i = 0;
	size = 0;
	if (fd = open(*line, O_RDONLY) == -1)
		return (-1);
	while (*buff != '\n')
	{
		if ((len = read(fd, buff, BUFF_SIZE)) != -1)
		{
			if (len == 0)
				return (0);
		}
		return (-1);
	}
	return (len);
	close(fd);
}*/
