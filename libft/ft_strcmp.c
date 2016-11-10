/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 18:21:18 by wasman            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/10/28 16:24:08 by wasman           ###   ########.fr       */
=======
/*   Updated: 2016/09/28 01:25:22 by wasman           ###   ########.fr       */
>>>>>>> 4d646f5833219314aaf04df7f2a0e9c6a1de6154
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
