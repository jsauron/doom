/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <jsauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:57:00 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/19 19:19:59 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		srfdel(void **ap)
{
	SDL_Surface		*surface;

	surface = (SDL_Surface *)(*ap);
	if (ap && *ap)
	{
		SDL_FreeSurface(surface);
		surface = 0;
	}
}

void	free_editor(t_win *wn, t_editor editor)
{

}

void	free_menu(t_win *wn)
{

}

void	free_game(t_win *wn, t_game *game)
{

}

void	free_music(t_music *music)
{
	Mix_HaltChannel(-1);
	Mix_FreeMusic(music->mood);
	Mix_FreeChunk(music->shot);
	Mix_FreeChunk(music->dead);
	Mix_FreeChunk(music->gameover);
	Mix_FreeChunk(music->key);
	Mix_FreeChunk(music->open_door);
	Mix_CloseAudio();
	//Mix_FreeChunk(music->youwin);
}
