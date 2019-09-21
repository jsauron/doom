/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <jsauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:57:00 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/21 23:27:09 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		free_structure_obj(t_editor *editor)
{
	SDL_FreeSurface(editor->editor_surface);
	SDL_FreeSurface(editor->obj.wall);
	SDL_FreeSurface(editor->obj.mean);
	SDL_FreeSurface(editor->obj.goal);
	SDL_FreeSurface(editor->obj.player);
	SDL_FreeSurface(editor->obj.key);
	SDL_FreeSurface(editor->obj.door);
	SDL_FreeSurface(editor->obj.poster);
	SDL_FreeSurface(editor->obj.bonus);
	SDL_FreeSurface(editor->obj.button);
}

void		free_editor(t_win *wn)
{
	int	i;

	i = 0;
	while (i < XBLOC)
		free(wn->editor->map[i++]);
	free(wn->editor->map);
	free(wn->editor);
}

void		free_sdl(t_win *wn)
{
	SDL_DestroyTexture(wn->texture);
	SDL_FreeSurface(wn->screen);
	SDL_DestroyRenderer(wn->render);
	SDL_DestroyWindow(wn->window);
	SDL_Quit();
}

void		free_all(t_win *wn)
{
	if (wn->game.sky)
		free_game(&wn->game);
	if (wn->editor)
		free_structure(wn, wn->editor);
	free_sdl(wn);
}

void		free_structure(t_win *wn, t_editor *editor)
{
	free_surface_editor(editor);
	free_editor(wn);
}

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

void		free_keys(t_game *game)
{
	SDL_FreeSurface(game->keys[0]);
	SDL_FreeSurface(game->keys[1]);
	SDL_FreeSurface(game->keys[2]);
	SDL_FreeSurface(game->keys[3]);
	SDL_FreeSurface(game->keys[4]);
	SDL_FreeSurface(game->keys[5]);
}

void		free_hud(t_game *game)
{
	SDL_FreeSurface(game->heart[0]);
	SDL_FreeSurface(game->heart[1]);
	SDL_FreeSurface(game->heart[2]);
	SDL_FreeSurface(game->hit_contact);
}

void		free_win_menu(t_game *game)
{
	SDL_FreeSurface(game->win[0]);
	SDL_FreeSurface(game->win[1]);
	SDL_FreeSurface(game->win[2]);
	SDL_FreeSurface(game->win[3]);
	SDL_FreeSurface(game->win[4]);
	SDL_FreeSurface(game->win[5]);
	SDL_FreeSurface(game->win[6]);
	SDL_FreeSurface(game->win[7]);
	SDL_FreeSurface(game->win[8]);
	SDL_FreeSurface(game->win[9]);
	SDL_FreeSurface(game->win[10]);
	SDL_FreeSurface(game->win[11]);
}

void		free_weapon(t_game *game)
{
	SDL_FreeSurface(game->weapon[0]);
	SDL_FreeSurface(game->weapon[1]);
	SDL_FreeSurface(game->lunette[0]);
	SDL_FreeSurface(game->lunette[1]);
}

void		free_poster(t_game *game)
{
	SDL_FreeSurface(game->poster[0]);
	SDL_FreeSurface(game->poster[1]);
	SDL_FreeSurface(game->poster[2]);
	SDL_FreeSurface(game->poster[3]);
	SDL_FreeSurface(game->button[0]);
	SDL_FreeSurface(game->button[1]);
	SDL_FreeSurface(game->button[2]);
	SDL_FreeSurface(game->button[3]);
}

void		free_sprite(t_game *game)
{
	SDL_FreeSurface(game->key_s);
	SDL_FreeSurface(game->exit_s);
	SDL_FreeSurface(game->mean_s);
	SDL_FreeSurface(game->key_l);
	SDL_FreeSurface(game->exit_l);
	SDL_FreeSurface(game->mean_l);
	SDL_FreeSurface(game->bonus_s);
	SDL_FreeSurface(game->bonus_l);
}

void		free_graphic(t_game *game)
{
	SDL_FreeSurface(game->gameover);
	SDL_FreeSurface(game->sky);
	SDL_FreeSurface(game->mission_s);
}

void		free_music(t_music *music)
{
	Mix_HaltChannel(-1);
	Mix_FreeMusic(music->mood);
	Mix_FreeChunk(music->shot);
	Mix_FreeChunk(music->dead);
	Mix_FreeChunk(music->gameover);
	Mix_FreeChunk(music->key);
	Mix_FreeChunk(music->open_door);
	Mix_FreeChunk(music->youwin);
	Mix_CloseAudio();
}
