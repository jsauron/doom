/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:12:05 by jsauron           #+#    #+#             */
/*   Updated: 2019/03/16 10:12:08 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (0);
	if (!(str = (char *)(ft_memalloc_lt(sizeof(char)
	* (ft_strlen(s1) + ft_strlen(s2) + 1)))))
		return (0);
	str = ft_strcat(str, (char *)s1);
	str = ft_strcat(str, s2);
	return (str);
}
