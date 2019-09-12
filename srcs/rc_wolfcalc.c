/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_wolfcalc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <jsauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:34:22 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/12 15:34:26 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"


static void		calc__walls(int i, int x, t_thread *thread)
{
	double	height;

	height = 0;
	calc__distance(i, x, thread);
	if (thread->ray[i].distance >= 0)
		height = (BLOC_SIZE / thread->ray[i].distance) * DIST_SCREEN;

	thread->ray[i].wall_top = (WIN_H - height) / 2;
	thread->ray[i].wall_bot = WIN_H - ((WIN_H - height) / 2);
}

static void		*calc__frame(void *arg)
{
	t_thread	*thread;
	int			x;
	int			y;
	int			i;

	i = -1;
	thread = (t_thread *)arg;
	x = thread->x_start;
	while (x < WIN_W)
	{
		y = 0;
		++i;
		calc__walls(i, x, thread);
		while (y < WIN_H)
		{
			assign_color(thread, x, y, i);
			y++;
		}
		x += 8;
	}
	check_sprite(thread);
	pthread_exit(0);
}

void			rc_wolfcalc(t_game *game)
{
	int i;

	i = 0;
	while (i < 8)
	{
		game->thread[i].x_start = i;
		game->thread[i].game = game;
		ft_bzero(game->thread[i].ray, sizeof(t_ray) * (WIN_W / 8));
		if ((pthread_create(&(game->thread[i].th), 0,
						calc__frame,  (void *)&(game->thread[i]))) != 0)
			ft_err_exit("wolf3d: error: pthread_create failed", game);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		if ((pthread_join(game->thread[i++].th, 0)) != 0)
			ft_err_exit("wolf3d: error: pthread_create failed", game);
	}
}
