/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:34:37 by jsauron           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/09/21 18:21:18 by jsauron          ###   ########.fr       */
=======
/*   Updated: 2019/09/21 18:03:48 by hben-yah         ###   ########.fr       */
>>>>>>> 60dff4789abc3dc2c21c15ebf908f7252bc1164a
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		gameover(t_win *wn)
{
	SDL_Rect pos;

	pos.x = 0;
	pos.y = 0;
	SDL_BlitSurface(wn->game.gameover, NULL, wn->screen, &pos);
	return (0);
}

int		render_life(t_win *wn, int life)
{
	SDL_Rect	pos;
	SDL_Rect	pos_alert;
	int			i;
	static int	k;
	static int	old_time;

	i = 0;
	pos.x = 0;
	pos.y = 20;
	pos_alert.x = 0;
	pos_alert.y = 0;
	if (life == 1)
	{
		if (wn->game.time.current_time - old_time > 170)
		{
			k++;
			old_time = wn->game.time.current_time;
		}
		if (k % 2 == 0)
			SDL_BlitSurface(wn->game.hit_contact, NULL, wn->screen, &pos_alert);
	}
	while (life > 0 && i < life)
	{
		SDL_BlitSurface(wn->game.heart[i++], NULL, wn->screen, &pos);
		pos.x += 55;
	}
	if (life == 0)
		gameover(wn);
	return (0);
}

int		you_win(t_win *wn)
{
	SDL_Rect	pos;
	static int	i;

	pos.x = 0;
	pos.y = 0;
	Mix_PlayChannel(-1, wn->game.music.youwin, 0);
	if (wn->game.time.current_time - wn->game.time.old_time > 100)
		i++;
	if (i == 12)
		i = 0;
	SDL_BlitSurface(wn->game.win[i], NULL, wn->screen, &pos);
	return (0);
}

int		shot(t_win *wn)
{
	SDL_Rect	pos;
	static int	i;
	static int	old_time;

	pos.x = 0;
	pos.y = 0;
	if (wn->game.shot == 1 && wn->game.target == 0)
	{
		if (wn->game.time.current_time - old_time > 100)
		{
			i++;
			old_time = wn->game.time.current_time;
		}
		if (i == 2)
			i = 1;
		SDL_BlitSurface(wn->game.weapon[i], NULL, wn->screen, &pos);
	}
	else if (wn->game.shot == 1 && wn->game.target == 1)
	{
		if (wn->game.time.current_time - old_time > 100)
		{
			i++;
			old_time = wn->game.time.current_time;
		}
		if (i == 2)
			i = 1;
		SDL_BlitSurface(wn->game.lunette[i], NULL, wn->screen, &pos);
	}
	else if (wn->game.shot == 0 && wn->game.target == 0)
		SDL_BlitSurface(wn->game.weapon[0], NULL, wn->screen, &pos);
	else if (wn->game.shot == 0 && wn->game.target == 1)
		SDL_BlitSurface(wn->game.lunette[0], NULL, wn->screen, &pos);
	return (0);
}

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
