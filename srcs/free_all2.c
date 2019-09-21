/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:50:01 by hben-yah          #+#    #+#             */
/*   Updated: 2019/09/21 18:51:58 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int			free_surface_editor(t_editor *editor)
{
	int i;

	i = 0;
	free_structure_obj(editor);
	while (i < 9)
		SDL_FreeSurface(editor->menu[i++]);
	return (1);
}

void		free_game(t_game *game)
{
	int i;

	i = 0;
	free_fonts(game);
	while (i < XBLOC)
		free(game->map[i++]);
	free(game->map);
	free_surface_game(game);
}

void		free_fonts(t_game *game)
{
	TTF_CloseFont(game->font);
}

void		free_surface_game(t_game *game)
{
	free_graphic(game);
	free_sprite(game);
	free_weapon(game);
	free_poster(game);
	free_win_menu(game);
	free_hud(game);
	free_keys(game);
	free_wall(game);
}

void		free_wall(t_game *game)
{
	SDL_FreeSurface(game->wall[0]);
	SDL_FreeSurface(game->wall[1]);
	SDL_FreeSurface(game->wall[2]);
	SDL_FreeSurface(game->wall[3]);
	SDL_FreeSurface(game->door);
}
