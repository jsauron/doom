/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:01:48 by jsauron           #+#    #+#             */
/*   Updated: 2019/08/24 15:40:09 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static SDL_Surface	*choose_texture(int i, t_thread *thread)
{
	SDL_Surface	*surface[4] = {
	thread->game->object[0].img_srf, thread->game->object[1].img_srf,
	thread->game->object[2].img_srf, thread->game->object[3].img_srf};

	if (thread->ray[i].axis == VERTICAL_HIT)
	{
		return (((thread->ray[i].angle_d >= 0 && thread->ray[i].angle_d <= 180)
		|| thread->ray[i].angle_d >= 360) ? surface[0] : surface[1]);
	}
	return ((thread->ray[i].angle_d >= 90 && thread->ray[i].angle_d <= 270)
	? surface[2] : surface[3]);
}

static Uint32		ft_calc_col(int y, int i, t_thread *thread)
{
	const SDL_Surface	*surface = choose_texture(i, thread);
	double				h_wall;
	t_coef				textr;
	double				ywall;
	Uint32				color;
	double				h_txtr;
	double				w_txtr;

	ywall = (y - thread->ray[i].wall_top);
	w_txtr = surface->w;
	h_txtr = surface->h;
	h_wall = thread->ray[i].wall_bot - thread->ray[i].wall_top;
	if (thread->ray[i].axis == VERTICAL_HIT)
		textr.x = ((int)(thread->ray[i].x / 8) % BLOC_SIZE) * w_txtr / BLOC_SIZE;
	else if (thread->ray[i].axis == HORIZONTAL_HIT)
		textr.x = ((int)(thread->ray[i].y / 8) % BLOC_SIZE) * w_txtr / BLOC_SIZE;
	textr.y = h_txtr * ywall / h_wall;
	color = ft_getpixel((SDL_Surface *)surface,
	(int)textr.x % (int)surface->w,
	(int)textr.y % (int)surface->w, thread->game) | 0xFF000000;
	return (color);
}

Uint32				ft_get_color(int axis, int angle_d)
{
	const Uint32	tab[4] = {0xFF5454E5, 0xFF86D865, 0xFFD8815F, 0xFF89EFFF};

	if (axis == VERTICAL_HIT)
	{
		return (((angle_d >= 0 && angle_d <= 180) || angle_d >= 360)
		? tab[0] : tab[1]);
	}
	return ((angle_d >= 90 && angle_d <= 270) ? tab[2] : tab[3]);
}

void				ft_assign_color(int x, int y, int i, t_thread *thread)
{
	Uint32		color;

	color = 0x0;
	if (y < thread->ray[i].wall_top)
		color = (thread->game->lightshade) ? 0xFF46463B : 0xFFFFFED6;
	else if (y >= thread->ray[i].wall_top && y <= thread->ray[i].wall_bot)
	{
		color = (thread->game->texturing) ? ft_calc_col(y, i, thread)
		: ft_get_color(thread->ray[i].axis, thread->ray[i].angle_d);

		// lightshading
		if (thread->game->lightshade == 1)
			color = ft_light_shade(thread->ray[i].distance, color);
	}
	ft_setpixel(thread->game->surface, x, y, color);
}
