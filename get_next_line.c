/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 17:29:35 by wasman            #+#    #+#             */
/*   Updated: 2016/11/15 20:33:00 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_in(int fd, char **buff)
{
	char	read_buff[BUFF_SIZE + 1];
	int		len;
	char	*str;

	len = read(fd, read_buff, BUFF_SIZE);
	if (len > 0)
	{
		read_buff[len] = '\0';
		str = ft_strjoin(*buff, read_buff);
		if (!str)
			return (-1);
		free(*buff);
		*buff = str;
	}
	return (len);
}

/*void	new_line(**buff, **line)
{
	int n;
	int len;

	len = ft_strlen(buff);
	if ((n = find_n(buff)) >= 0)
	{
		
	}

}*/

int	get_next_line(const int fd, char **line)
{
	static char	*buff;
	int			len;
	char		*n;

	len = 0;
	if (!(buff = (char *)malloc(sizeof(char))))
		return (-1);
	if (!line || fd <= 0)
		return (-1);
	*line = NULL;
	n = ft_strchr(buff, '\n');
	while (n == NULL)
	{
		len = read_in(fd, &buff);
		if (len == 0)
		{
			if ((n = ft_strchr(buff, '\0')) == NULL)
			   return (0);	
		}
		else if (len < 0)
			return (-1);
		else
			n = ft_strchr(buff, '\n');
	}
	*line = ft_strsub(buff, 0, n - buff);
	if (!line)
		return (-1);
	n = strdup(n + 1);
	ft_putstr(buff);
	free(buff);
	buff = n;
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
