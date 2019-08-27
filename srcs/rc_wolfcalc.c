/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rc_wolfcalc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:03:40 by jsauron           #+#    #+#             */
/*   Updated: 2019/08/22 20:01:01 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void		ft_calc_walls(int i, int x, t_thread *thread)
{
	double	height;

	height = 0;
	ft_calc_distance(i, x, thread);
	if (thread->ray[i].distance >= 0)
		height = (BLOC_SIZE / thread->ray[i].distance) * DIST_SCREEN;
	thread->ray[i].wall_top = (WIN_H - height) / 2;
	thread->ray[i].wall_bot = WIN_H - ((WIN_H - height) / 2);
}

static void		*ft_calc_frame(void *arg)
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
		ft_calc_walls(++i, x, thread);
		while (y < WIN_H)
		{
			ft_assign_color(thread->wn, x, y, i, thread);
			y++;
		}
		x += 8;
	}
	pthread_exit(0);
}

void			ft_rc_wolfcalc(t_game *game)
{
	int i;

	i = 0;
	while (i < 8)
	{
		game->thread[i].x_start = i;
		game->thread[i].game = game;
		ft_bzero(game->thread[i].ray, sizeof(t_ray) * (WIN_W / 8));
		if ((pthread_create(&(game->thread[i].th), 0,
		ft_calc_frame,  (void *)&(game->thread[i]))) != 0)
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
