/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:08:04 by jsauron           #+#    #+#             */
/*   Updated: 2019/03/16 10:08:06 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s2;

	s2 = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (s2[i] == (unsigned char)c)
			return ((void *)s2 + i);
		i++;
	}
	return (0);
}
