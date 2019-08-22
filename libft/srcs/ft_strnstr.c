/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:13:05 by jsauron           #+#    #+#             */
/*   Updated: 2019/03/16 10:13:07 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	temp;

	i = 0;
	while (haystack[i])
	{
		j = 0;
		temp = i;
		while (needle[j] && haystack[temp] == needle[j] && temp < len)
		{
			temp++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)haystack + temp - j);
		i++;
	}
	return (0);
}
