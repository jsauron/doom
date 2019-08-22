/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:08:53 by jsauron           #+#    #+#             */
/*   Updated: 2019/03/16 10:08:55 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*src2;
	unsigned char	*dst2;

	src2 = (unsigned char *)src;
	dst2 = (unsigned char *)dst;
	if (dst2 > src2)
	{
		dst2 = dst2 + len;
		src2 = src2 + len;
		while (len--)
			*--dst2 = *--src2;
	}
	else
		ft_memcpy(dst, src, len);
	return ((void *)dst);
}
