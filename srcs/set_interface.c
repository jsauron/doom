/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_interface.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <jsauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:34:57 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/12 15:35:00 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void	set_config(t_win *wn, t_game *game)
{
	(void)game;
	SDL_Rect	rect;
	rect = (SDL_Rect){200, 200, 560, 372};
	draw_rect(wn, rect, 0x10000000, 0);
	draw_border(wn, rect, 0xFFFFFFFF);
}

static void	ft_bloc_devmode(t_win *wn, t_game *game)
{
	SDL_Rect	rect;
	(void)game;
	rect = (SDL_Rect){370, 28, 220, 35};
	draw_rect(wn, rect, 0x10000000, 0);
	rect = (SDL_Rect){370, 78, 220, 35};
	draw_rect(wn, rect, 0x10000000, 0);
	rect = (SDL_Rect){370, 118, 220, 35};
	draw_rect(wn, rect, 0x10000000, 0);
	rect = (SDL_Rect){370, 158, 220, 35};
	draw_rect(wn, rect, 0x10000000, 0);
	rect = (SDL_Rect){370, 198, 220, 35};
	draw_rect(wn, rect, 0x10000000, 0);
}

void		set_interface(t_win *wn, t_game *game)
{
	SDL_Rect	rect;

	if (game->gamemode == 1 || game->dev_mode == 1)
		minimap(wn, game);
	rect = (SDL_Rect){15, 15, 138, 20};
	draw_rect(wn, rect, 0x00000000, 0);
	draw_border(wn, rect, 0xFFFFFFFF);
	rect = (SDL_Rect){170, 15, 60, 20};
	draw_rect(wn, rect, 0xFF000000, 0);
	draw_border(wn, rect, 0xFFFFFFFF);
	if (game->setting == 1)
		set_config(wn, game);
	if (game->gamemode == 1 && game->setting == 0 && game->target == 0)
		set_cursor(wn);
	if (game->dev_mode == 1 && game->setting == 0)
		ft_bloc_devmode(wn, game);
}
