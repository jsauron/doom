/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_interface.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:04:03 by jsauron           #+#    #+#             */
/*   Updated: 2019/08/24 16:04:34 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void	ft_set_config(t_game*game)
{
	SDL_Rect	rect;
	rect = (SDL_Rect){200, 200, 560, 372};
	ft_draw_rect(rect, 0x10000000, 0, game);
	ft_draw_border(rect, 0xFFFFFFFF, game);
}

static void	ft_bloc_devmode(t_game*game)
{
	SDL_Rect	rect;

	rect = (SDL_Rect){15, 48, 220, 35};
	ft_draw_rect(rect, 0x10000000, 0, game);
	rect = (SDL_Rect){15, 98, 220, 35};
	ft_draw_rect(rect, 0x10000000, 0, game);
	rect = (SDL_Rect){15, 138, 220, 35};
	ft_draw_rect(rect, 0x10000000, 0, game);
	rect = (SDL_Rect){15, 178, 220, 35};
	ft_draw_rect(rect, 0x10000000, 0, game);
	rect = (SDL_Rect){15, 218, 220, 35};
	ft_draw_rect(rect, 0x10000000, 0, game);
}

void		ft_set_interface(t_game*game)
{
	SDL_Rect	rect;

	if (game->gamemode == 1 || game->dev_mode == 1)
		ft_minimap(game);
	rect = (SDL_Rect){15, 15, 138, 20};
	ft_draw_rect(rect, 0x00000000, 0, game);
	ft_draw_border(rect, 0xFFFFFFFF, game);
	rect = (SDL_Rect){170, 15, 60, 20};
	ft_draw_rect(rect, 0xFF000000, 0, game);
	ft_draw_border(rect, 0xFFFFFFFF, game);
	if (game->setting == 1)
		ft_set_config(game);
	if (game->gamemode == 1 && game->setting == 0)
		ft_set_cursor(game);
	if (game->dev_mode == 1 && game->setting == 0)
		ft_bloc_devmode(game);
}
