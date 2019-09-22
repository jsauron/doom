/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <jsauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:34:37 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/22 13:38:01 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		display_key(t_win *wn)
{
	SDL_Rect	pos;
	int			k;
	static int	i;
	static int	old_time;

	k = 0;
	pos.x = 0;
	pos.y = 0;
	if (wn->game.time.current_time - old_time > 170)
	{
		i++;
		old_time = wn->game.time.current_time;
	}
	if (i == 6)
		i = 0;
	while (k < wn->game.key)
	{
		SDL_BlitSurface(wn->game.keys[i], NULL, wn->screen, &pos);
		k++;
		pos.x -= 35 * k;
	}
	return (0);
}

int		render_editor(t_win *wn)
{
	SDL_UpdateTexture(wn->texture, NULL, wn->screen->pixels, wn->screen->pitch);
	SDL_RenderClear(wn->render);
	SDL_RenderCopy(wn->render, wn->texture, NULL, NULL);
	SDL_RenderPresent(wn->render);
	return (0);
}

int		render_sprite(t_win *wn)
{
	SDL_Texture	*texture;
	int			n;

	n = 0;
	texture = NULL;
	range_sprite(wn->game.sprite, wn->game.n);
	while (n < wn->game.n)
	{
		if (wn->game.sprite[n].actif == 1 && wn->game.sprite[n].left_life > 0)
			SDL_BlitSurface(wn->game.sprite[n].sprite, NULL,
										wn->screen, &(wn->game.sprite[n].pos));
		n++;
	}
	return (0);
}

int		render_game(t_win *wn)
{
	if (wn->game.exit == 1)
		you_win(wn);
	else if (wn->game.mission == 1)
		SDL_BlitSurface(wn->game.mission_s, NULL, wn->screen, &(wn->pos_game));
	else
	{
		SDL_BlitSurface(wn->screen, NULL, wn->screen, &(wn->pos_game));
		render_sprite(wn);
		shot(wn);
		render_life(wn, wn->game.player.life);
		if (wn->game.key > 0)
			display_key(wn);
		set_interface(wn, &wn->game);
		set_infos(wn, &wn->game);
		set_quote_screen(wn);
	}
	render(wn);
	return (0);
}

int		render(t_win *wn)
{
	SDL_UpdateTexture(wn->texture, NULL, wn->screen->pixels, wn->screen->pitch);
	SDL_RenderClear(wn->render);
	SDL_RenderCopy(wn->render, wn->texture, NULL, NULL);
	SDL_RenderPresent(wn->render);
	return (0);
}
