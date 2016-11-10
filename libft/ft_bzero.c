/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 10:19:23 by wasman            #+#    #+#             */
/*   Updated: 2016/09/28 18:09:50 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ns;

	ns = (unsigned char *)s;
	i = 0;
	if (n == 0)
		;
	while (i < n)
	{
		ns[i] = 0;
		i++;
	}
}
