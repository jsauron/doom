/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc_lt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:07:45 by jsauron           #+#    #+#             */
/*   Updated: 2019/03/16 10:07:48 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc_lt(size_t size)
{
	void	*mem;

	if (!(mem = lt_push(malloc(size), ft_memdel)))
		return (0);
	ft_memset(mem, 0, size);
	return (mem);
}
