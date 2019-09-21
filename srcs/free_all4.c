/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:50:21 by hben-yah          #+#    #+#             */
/*   Updated: 2019/09/21 18:51:51 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		free_sprite(t_game *game)
{
	SDL_FreeSurface(game->key_s);
	SDL_FreeSurface(game->exit_s);
	SDL_FreeSurface(game->mean_s);
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
