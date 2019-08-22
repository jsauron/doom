/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:13:47 by jsauron           #+#    #+#             */
/*   Updated: 2019/03/16 10:13:50 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	temp = 0;
	if (haystack[0] == '\0' && needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		temp = i;
		while (needle[j] && haystack[temp] == needle[j])
		{
			temp++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
