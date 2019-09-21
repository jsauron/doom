/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:57:32 by hben-yah          #+#    #+#             */
/*   Updated: 2019/09/21 19:19:44 by hben-yah         ###   ########.fr       */
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

int		hit_contact(t_win *wn, SDL_Rect pos_alert, int old_time, int k)
{
	if (wn->game.time.current_time - old_time > 170)
	{
		k++;
		old_time = wn->game.time.current_time;
	}
	if (k % 2 == 0)
		SDL_BlitSurface(wn->game.hit_contact, NULL, wn->screen, &pos_alert);
	return (old_time);
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
		old_time = hit_contact(wn, pos_alert, old_time, k);
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

int		simple_shot(t_win *wn, SDL_Rect pos, int old_time, int i)
{
	if (wn->game.time.current_time - old_time > 100)
	{
		i++;
		old_time = wn->game.time.current_time;
	}
	if (i == 2)
		i = 1;
	SDL_BlitSurface(wn->game.weapon[i], NULL, wn->screen, &pos);
	return (old_time);
}

int		shot(t_win *wn)
{
	SDL_Rect	pos;
	static int	i;
	static int	old_time;

	pos.x = 0;
	pos.y = 0;
	if (wn->game.shot == 1 && wn->game.target == 0)
		old_time = simple_shot(wn, pos, old_time, i);
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
