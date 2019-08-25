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

static void			ft_set_nbrstring(int value, SDL_Rect rect,
					Uint32 color, t_game*game)
{
	char	*str;

	if (!(str = ft_itoa(value)))
		ft_err_exit("wolf3d: error: itoa, out of memory", game);
	ft_set_string(rect, str, ft_hex_to_rgb(color), game);
	lt_release(str);
}

static void			ft_set_menu_config(t_game*game)
{
	SDL_Rect	rect;

	rect = (SDL_Rect){230, 240, 500, 35};
	ft_set_string(rect, "SETTINGS", ft_hex_to_rgb(H_GREEN), game);
	rect = (SDL_Rect){230, 300, 500, 25};
	ft_set_string(rect, "[ 8 9 ]  Speed", ft_hex_to_rgb(H_GREEN), game);
	rect = (SDL_Rect){500, 300, 500, 25};
	ft_set_nbrstring((int)(game->player.speed * 100), rect, H_GREEN, game);
	rect = (SDL_Rect){230, 340, 500, 25};
	ft_set_string(rect, "[ * / ]  Sensibility", ft_hex_to_rgb(H_GREEN), game);
	rect = (SDL_Rect){500, 340, 500, 25};
	ft_set_nbrstring(game->player.sensibility, rect, H_GREEN, game);
	rect = (SDL_Rect){230, 380, 500, 25};
	ft_set_string(rect, "[ l ]  Light shading", ft_hex_to_rgb(H_GREEN), game);
	rect = (SDL_Rect){500, 380, 500, 25};
	ft_set_nbrstring(game->lightshade, rect, H_GREEN, game);
	rect = (SDL_Rect){230, 420, 500, 25};
	ft_set_string(rect, "[ t ]  Texturing", ft_hex_to_rgb(H_GREEN), game);
	rect = (SDL_Rect){500, 420, 500, 25};
	ft_set_nbrstring(game->texturing, rect, H_GREEN, game);
	rect = (SDL_Rect){230, 460, 500, 25};
	ft_set_string(rect, "[ + - ]  Minimap zoom", ft_hex_to_rgb(H_GREEN), game);
	rect = (SDL_Rect){500, 460, 500, 25};
	ft_set_nbrstring(game->minimap.mnp_size, rect, H_GREEN, game);
}

static void			ft_dev_mode(t_game*game)
{
	SDL_Rect	rect;

	rect = (SDL_Rect){20, 18, 150, 15};
	ft_set_string(rect, "1 normal", ft_set_color(game, 0), game);
	rect = (SDL_Rect){20, 50, 150, 30};
	ft_set_string(rect, "fps : ", ft_hex_to_rgb(H_GREEN), game);
	rect = (SDL_Rect){160, 50, 150, 30};
	ft_set_nbrstring(game->fps, rect, H_GREEN, game);
	rect = (SDL_Rect){20, 100, 150, 30};
	ft_set_string(rect, "frames : ", ft_hex_to_rgb(H_GREEN), game);
	rect = (SDL_Rect){160, 100, 150, 30};
	ft_set_nbrstring(game->nb_frame, rect, H_GREEN, game);
	rect = (SDL_Rect){20, 140, 150, 30};
	ft_set_string(rect, "position.x : ", ft_hex_to_rgb(H_GREEN), game);
	rect = (SDL_Rect){160, 140, 150, 30};
	ft_set_nbrstring(game->player.position.x * BLOC_SIZE, rect, H_GREEN, game);
	rect = (SDL_Rect){20, 180, 150, 30};
	ft_set_string(rect, "position.y : ", ft_hex_to_rgb(H_GREEN), game);
	rect = (SDL_Rect){160, 180, 150, 30};
	ft_set_nbrstring(game->player.position.y * BLOC_SIZE, rect, H_GREEN, game);
	rect = (SDL_Rect){20, 220, 150, 30};
	ft_set_string(rect, "direction : ", ft_hex_to_rgb(H_GREEN), game);
	rect = (SDL_Rect){160, 220, 150, 30};
	ft_set_nbrstring(game->player.direction, rect, H_GREEN, game);
}

void				ft_set_infos(t_game*game)
{
	SDL_Rect	rect;

	rect = (SDL_Rect){20, 18, 150, 15};
	ft_set_string(rect, "1 normal", ft_set_color(game, 0), game);
	rect = (SDL_Rect){87, 18, 150, 15};
	ft_set_string(rect, "2 gaming", ft_set_color(game, 1), game);
	rect = (SDL_Rect){184, 18, 150, 15};
	ft_set_string(rect, "3 dev", ft_set_color(game, 2), game);
	rect = (SDL_Rect){WIN_W / 2 - 75, 660, 150, 20};
	ft_set_string(rect, "SETTINGS : [ i ]", ft_set_color(game, 3), game);
	if (game->setting == 1)
		ft_set_menu_config(game);
	else if (game->dev_mode == 1)
		ft_dev_mode(game);
}
