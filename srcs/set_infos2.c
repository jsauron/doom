/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_infos2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:00:39 by hben-yah          #+#    #+#             */
/*   Updated: 2019/09/21 19:01:06 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void				set_quote_screen(t_win *wn, int i)
{
	SDL_Rect	rect;

	rect = (SDL_Rect){230, 240, 500, 35};
	if (i == 1)
		set_string(wn, rect, "You opened a door", hex_to_rgb(0xFFFFFFFF));
	else if (i == 2)
		set_string(wn, rect, "You killed an enemy", hex_to_rgb(0xFFFFFFFF));
}
