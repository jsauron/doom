/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:57:32 by hben-yah          #+#    #+#             */
/*   Updated: 2019/09/21 19:22:23 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		gameover(t_win *wn)
{
	SDL_Rect pos;

	pos.x = 0;
	pos.y = 0;
	SDL_BlitSurface(wn->game.gameover, NULL, wn->screen, &pos);
	return (0);
}
