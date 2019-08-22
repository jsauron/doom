/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:11:47 by jsauron           #+#    #+#             */
/*   Updated: 2019/03/16 10:11:49 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cpy;

	if (!(cpy = (char *)ft_memalloc_lt(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	return (ft_strcpy(cpy, s));
}
