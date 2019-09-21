/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:29:59 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/21 18:18:43 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static SDL_Surface	*choose_texture(int i, t_thread *thread)
{
	const SDL_Surface *surface[8] = {
		thread->game->wall[0], thread->game->wall[1],
		thread->game->wall[2], thread->game->wall[3],
		thread->game->poster[0], thread->game->poster[1],
		thread->game->poster[2], thread->game->poster[3]};

	if (thread->ray[i].the_door == 1)
		return (thread->game->door);
	if (thread->ray[i].axis == VERTICAL_HIT && thread->ray[i].the_poster == 1)
	{
		return (((thread->ray[i].angle_d >= 0 && thread->ray[i].angle_d <= 180)
		|| thread->ray[i].angle_d >= 360) ? surface[4] : surface[5]);
	}
	if (thread->ray[i].axis == VERTICAL_HIT)
	{
		return (((thread->ray[i].angle_d >= 0 && thread->ray[i].angle_d <= 180)
		|| thread->ray[i].angle_d >= 360) ? surface[0] : surface[1]);
	}
	if (thread->ray[i].axis == HORIZONTAL_HIT && thread->ray[i].the_poster == 1)
	{
		return ((thread->ray[i].angle_d >= 90 && thread->ray[i].angle_d <= 270)
			? surface[6] : surface[7]);
	}
	return ((thread->ray[i].angle_d >= 90 && thread->ray[i].angle_d <= 270)
				? surface[2] : surface[3]);
}

static Uint32		calc__col(t_win *wn, int y, int i, t_thread *thread)
{
	const SDL_Surface	*surface = choose_texture(i, thread);
	double				h_wall;
	t_mouse				textr;
	double				ywall;

	ywall = (y - thread->ray[i].wall_top);
	h_wall = thread->ray[i].wall_bot - thread->ray[i].wall_top;
	if (thread->ray[i].axis == VERTICAL_HIT)
		textr.x = ((int)(thread->ray[i].x / 8) % BLOC_SIZE)
		* surface->w / BLOC_SIZE;
	else if (thread->ray[i].axis == HORIZONTAL_HIT)
		textr.x = ((int)(thread->ray[i].y / 8) % BLOC_SIZE)
		* surface->w / BLOC_SIZE;
	textr.y = surface->h * ywall / h_wall;
	return (ft_getpixel(wn, (SDL_Surface *)surface,
						(int)textr.x % (int)surface->w,
						(int)textr.y % (int)surface->w));
}

Uint32				get_color(int axis, int angle_d)
{
	const Uint32 tab[4] = {0xFF0c97b3, 0xFFdb9ac5, 0xFF262b63, 0xFF94bdcf};

	if (axis == VERTICAL_HIT)
	{
		return (((angle_d >= 0 && angle_d <= 180) || angle_d >= 360)
					? tab[0]
					: tab[1]);
	}
	return ((angle_d >= 90 && angle_d <= 270) ? tab[2] : tab[3]);
}

void				assign_color(t_thread *thread, int x, int y, int i)
{
	Uint32		color;

	color = 0x0;
	if (!(y < thread->ray[i].wall_top))
	{
		if (y >= thread->ray[i].wall_top && y <= thread->ray[i].wall_bot)
		{
			color = calc__col(thread->wn, y, i, thread);
			if (thread->game->lightshade == 1)
				color = light_shade(thread->ray[i].distance, color);
		}
		setpixel(thread->wn->screen, x, y, color);
	}
}
