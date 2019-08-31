/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_infos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:03:50 by jsauron           #+#    #+#             */
/*   Updated: 2019/08/22 20:01:13 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static SDL_Color	ft_set_color(t_game*game, int i)
{
	if ((game->gamemode == 0 && i == 0)
	|| (game->gamemode == 1 && i == 1)
	|| (game->dev_mode == 1 && i == 2))
		return (ft_hex_to_rgb(H_RED));
	return (ft_hex_to_rgb(H_GREEN));
}

static void			ft_set_nbrstring(t_win *wn, int value, SDL_Rect rect,
					Uint32 color)
{
	char	*str;

	if (!(str = ft_itoa(value)))
		ft_err_exit("doom: error: itoa, out of memory", &wn->game);
	ft_set_string(wn, rect, str, ft_hex_to_rgb(color));
//	lt_release(str);
}

static void			ft_set_menu_config(t_win *wn, t_game *game)
{
	SDL_Rect	rect;

	rect = (SDL_Rect){230, 240, 500, 35};
	ft_set_string(wn, rect, "SETTINGS", ft_hex_to_rgb(H_GREEN));
	rect = (SDL_Rect){230, 300, 500, 25};
	ft_set_string(wn,  rect, "[ 8 9 ]  Speed", ft_hex_to_rgb(H_GREEN));
	rect = (SDL_Rect){500, 300, 500, 25};
	ft_set_nbrstring(wn,  (int)(game->player.speed * 100), rect, H_GREEN);
	rect = (SDL_Rect){230, 340, 500, 25};
	ft_set_string(wn,  rect, "[ * / ]  Sensibility", ft_hex_to_rgb(H_GREEN));
	rect = (SDL_Rect){500, 340, 500, 25};
	ft_set_nbrstring(wn, game->player.sensibility, rect, H_GREEN);
	rect = (SDL_Rect){230, 380, 500, 25};
	ft_set_string(wn,  rect, "[ l ]  Light shading", ft_hex_to_rgb(H_GREEN));
	rect = (SDL_Rect){500, 380, 500, 25};
	ft_set_nbrstring(wn,  game->lightshade, rect, H_GREEN);
	rect = (SDL_Rect){230, 420, 500, 25};
	ft_set_string(wn, rect, "[ t ]  Texturing", ft_hex_to_rgb(H_GREEN));
	rect = (SDL_Rect){500, 420, 500, 25};
	ft_set_nbrstring(wn,  game->texturing, rect, H_GREEN);
	rect = (SDL_Rect){230, 460, 500, 25};
	ft_set_string(wn, rect, "[ + - ]  Minimap zoom", ft_hex_to_rgb(H_GREEN));
	rect = (SDL_Rect){500, 460, 500, 25};
	ft_set_nbrstring(wn, game->minimap.mnp_size, rect, H_GREEN);
}

static void			ft_dev_mode(t_win *wn, t_game *game)
{
	SDL_Rect	rect;

	rect = (SDL_Rect){375, 30, 150, 30};
	ft_set_string(wn, rect, "fps : ", ft_hex_to_rgb(H_GREEN));
	rect = (SDL_Rect){520, 30, 150, 30};
	ft_set_nbrstring(wn, game->fps, rect, H_GREEN);
	rect = (SDL_Rect){375, 80, 150, 30};
	ft_set_string(wn, rect, "frames : ", ft_hex_to_rgb(H_GREEN));
	rect = (SDL_Rect){520, 80, 150, 30};
	ft_set_nbrstring(wn, game->nb_frame, rect, H_GREEN);
	rect = (SDL_Rect){375, 120, 150, 30};
	ft_set_string(wn, rect, "position.x : ", ft_hex_to_rgb(H_GREEN));
	rect = (SDL_Rect){520, 120, 150, 30};
	ft_set_nbrstring(wn, game->player.position.x * BLOC_SIZE, rect, H_GREEN);
	rect = (SDL_Rect){375, 160, 150, 30};
	ft_set_string(wn, rect, "position.y : ", ft_hex_to_rgb(H_GREEN));
	rect = (SDL_Rect){520, 160, 150, 30};
	ft_set_nbrstring(wn, game->player.position.y * BLOC_SIZE, rect, H_GREEN);
	rect = (SDL_Rect){375, 200, 150, 30};
	ft_set_string(wn, rect, "direction : ", ft_hex_to_rgb(H_GREEN));
	rect = (SDL_Rect){520, 200, 150, 30};
	ft_set_nbrstring(wn, game->player.direction, rect, H_GREEN);
}

void				ft_set_infos(t_win *wn, t_game *game)
{
	SDL_Rect	rect;

	rect = (SDL_Rect){20, 18, 150, 15};
	ft_set_string(wn, rect, "1 normal", ft_set_color(game, 0));
	rect = (SDL_Rect){87, 18, 150, 15};
	ft_set_string(wn, rect, "2 gaming", ft_set_color(game, 1));
	rect = (SDL_Rect){184, 18, 150, 15};
	ft_set_string(wn, rect, "3 dev", ft_set_color(game, 2));
	rect = (SDL_Rect){WIN_W / 2 - 75, 660, 150, 20};
	if (wn->game.target == 0)
		ft_set_string(wn, rect, "SETTINGS : [ i ]", ft_set_color(game, 3));
	if (game->setting == 1)
		ft_set_menu_config(wn, game);
	else if (game->dev_mode == 1)
		ft_dev_mode(wn, game);
}
