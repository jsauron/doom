/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbwords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:09:20 by jsauron           #+#    #+#             */
/*   Updated: 2019/03/16 10:09:22 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbwords(char *line)
{
	int		c;

	c = 0;
	while (*line)
	{
		while (*line && (*line == ' ' || *line == '\t'))
			line++;
		if (*line)
		{
			while (*line && *line != ' ' && *line != '\t')
				line++;
			c++;
		}
	}
	return (c);
}
