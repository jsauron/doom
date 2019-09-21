/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <jsauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:34:47 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/21 18:01:37 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static SDL_Color	set_color(t_game *game, int i)
{
	if ((game->gamemode == 0 && i == 0) || (game->gamemode == 1 && i == 1)
	|| (game->dev_mode == 1 && i == 2))
		return (hex_to_rgb(H_RED));
	return (hex_to_rgb(H_GREEN));
}

static void	set_nbrstring(t_win *wn, int value, SDL_Rect rect,
						Uint32 color)
{
	char	*str;

	if (!(str = ft_itoa(value)))
		ft_err_exit("doom: error: itoa, out of memory", &wn->game);
	set_string(wn, rect, str, hex_to_rgb(color));
}

void		set_quote_screen(t_win *wn, int i)
{
	SDL_Rect	rect;

	rect = (SDL_Rect){230, 240, 500, 35};
	if (i == 1)
		set_string(wn, rect, "You opened a door", hex_to_rgb(0xFFFFFFFF));
	else if (i == 2)
		set_string(wn, rect, "You killed an enemy", hex_to_rgb(0xFFFFFFFF));
}

static void	set_menu_config(t_win *wn, t_game *game)
{
	SDL_Rect	rect;

	rect = (SDL_Rect){230, 240, 500, 35};
	set_string(wn, rect, "SETTINGS", hex_to_rgb(H_GREEN));
	rect = (SDL_Rect){230, 300, 500, 25};
	set_string(wn, rect, "[ 8 9 ]  Speed", hex_to_rgb(H_GREEN));
	rect = (SDL_Rect){500, 300, 500, 25};
	set_nbrstring(wn, (int)(game->player.speed * 100), rect, H_GREEN);
	rect = (SDL_Rect){230, 340, 500, 25};
	set_string(wn, rect, "[ * / ]  Sensibility", hex_to_rgb(H_GREEN));
	rect = (SDL_Rect){500, 340, 500, 25};
	set_nbrstring(wn, game->player.sensibility, rect, H_GREEN);
	rect = (SDL_Rect){230, 380, 500, 25};
	set_string(wn, rect, "[ l ]  Light shading", hex_to_rgb(H_GREEN));
	rect = (SDL_Rect){500, 380, 500, 25};
	set_nbrstring(wn, game->lightshade, rect, H_GREEN);
	rect = (SDL_Rect){230, 420, 500, 25};
	set_string(wn, rect, "[ + - ]  Minimap zoom", hex_to_rgb(H_GREEN));
	rect = (SDL_Rect){500, 420, 500, 25};
	set_nbrstring(wn, game->minimap.mnp_size, rect, H_GREEN);
}

static void	ft_dev_mode(t_win *wn, t_game *game)
{
	SDL_Rect rect;

	rect = (SDL_Rect){375, 30, 150, 30};
	set_string(wn, rect, "fps : ", hex_to_rgb(H_GREEN));
	rect = (SDL_Rect){520, 30, 150, 30};
	set_nbrstring(wn, game->fps, rect, H_GREEN);
	rect = (SDL_Rect){375, 80, 150, 30};
	set_string(wn, rect, "frames : ", hex_to_rgb(H_GREEN));
	rect = (SDL_Rect){520, 80, 150, 30};
	set_nbrstring(wn, game->nb_frame, rect, H_GREEN);
	rect = (SDL_Rect){375, 120, 150, 30};
	set_string(wn, rect, "position.x : ", hex_to_rgb(H_GREEN));
	rect = (SDL_Rect){520, 120, 150, 30};
	set_nbrstring(wn, game->player.position.x * BLOC_SIZE, rect, H_GREEN);
	rect = (SDL_Rect){375, 160, 150, 30};
	set_string(wn, rect, "position.y : ", hex_to_rgb(H_GREEN));
	rect = (SDL_Rect){520, 160, 150, 30};
	set_nbrstring(wn, game->player.position.y * BLOC_SIZE, rect, H_GREEN);
	rect = (SDL_Rect){375, 200, 150, 30};
	set_string(wn, rect, "direction : ", hex_to_rgb(H_GREEN));
	rect = (SDL_Rect){520, 200, 150, 30};
	set_nbrstring(wn, game->player.direction, rect, H_GREEN);
}

void	set_infos(t_win *wn, t_game *game)
{
	SDL_Rect rect;

	rect = (SDL_Rect){20, 18, 150, 15};
	set_string(wn, rect, "1 normal", set_color(game, 0));
	rect = (SDL_Rect){87, 18, 150, 15};
	set_string(wn, rect, "2 gaming", set_color(game, 1));
	rect = (SDL_Rect){184, 18, 150, 15};
	set_string(wn, rect, "3 dev", set_color(game, 2));
	rect = (SDL_Rect){WIN_W / 2 - 75, 660, 150, 20};
	if (wn->game.target == 0)
		set_string(wn, rect, "SETTINGS : [ i ]", set_color(game, 3));
	if (game->setting == 1)
		set_menu_config(wn, game);
	else if (game->dev_mode == 1)
		ft_dev_mode(wn, game);
}
