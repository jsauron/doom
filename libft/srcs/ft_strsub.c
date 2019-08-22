/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:13:55 by jsauron           #+#    #+#             */
/*   Updated: 2019/03/16 10:13:58 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (s)
	{
		i = 0;
		if (!(str = (char *)(ft_memalloc_lt(sizeof(char) * (len + 1)))))
			return (0);
		while (i < len)
		{
			str[i] = s[start];
			start++;
			i++;
		}
		return (str);
	}
	return (0);
}
