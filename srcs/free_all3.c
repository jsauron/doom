/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <jsauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:50:11 by hben-yah          #+#    #+#             */
/*   Updated: 2019/09/21 23:54:08 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

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
