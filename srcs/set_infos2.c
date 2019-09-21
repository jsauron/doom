/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_infos2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:00:39 by hben-yah          #+#    #+#             */
/*   Updated: 2019/09/21 19:16:23 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		set_quote_screen(t_win *wn)
{
	SDL_Rect	rect_dead;
	SDL_Rect	rect_open;

	rect_dead = (SDL_Rect){400, 10, 500, 35};
	rect_open = (SDL_Rect){400, 33, 500, 35};
	if (wn->game.count_frame_dead > 0)
	{
		set_string(wn, rect_dead, "You killed an enemy", hex_to_rgb(0xFFFFFFFF));	
		wn->game.count_frame_dead--;
	}
	if (wn->game.count_frame_open> 0)
	{
		set_string(wn, rect_open, "You opened a door", hex_to_rgb(0xFFFFFFFF));
		wn->game.count_frame_open--;
	}
}