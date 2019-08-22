/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:07:53 by jsauron           #+#    #+#             */
/*   Updated: 2019/03/16 10:07:55 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*src2;
	unsigned char	*dst2;
	size_t			i;

	src2 = (unsigned char *)src;
	dst2 = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		dst2[i] = src2[i];
		if (src2[i] == (unsigned char)c)
			return ((void *)&dst2[i + 1]);
		i++;
	}
	return ((void *)0);
}
