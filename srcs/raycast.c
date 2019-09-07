/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:03:31 by jsauron           #+#    #+#             */
/*   Updated: 2019/08/25 13:34:53 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int				ft_is_inwall(t_pos *pos, t_game*game, t_ray *ray)
{
	int		x2;
	int		y2;

	x2 = pos->x / BLOC_SIZE;
	y2 = pos->y / BLOC_SIZE;
		
	if (x2 < 0 || x2 >= MAP_SIZE || y2 < 0 || y2 >= MAP_SIZE)
		return (0);
	if (ray != NULL && game->map[y2][x2] == 3)
		ray->the_exit = 1;
	if (ray != NULL && game->map[y2][x2] == 2)
		ray->the_mean = 1;
	if (ray != NULL && game->map[y2][x2] == 6)
		ray->the_door = 1;
	if (ray != NULL && game->map[y2][x2] == 5)
		ray->the_key = 1;
	if (ray != NULL && game->map[y2][x2] == 7)
		ray->the_poster = 1;
	if (game->map[y2][x2] == 1) 
		return (1);
	if (game->map[y2][x2] == 2) 
		return (2);
	if (game->map[y2][x2] == 6)
		return (6);
	if (game->map[y2][x2] == 7)
		return (7);
	if (game->map[y2][x2] == 3)
		return (3);
	if (game->map[y2][x2] == 5)
		return (5);
	return (0);
}

static void		ft_get_raygame(t_pos pos,
				double alpha_r, int i, t_thread *thread)
{
	t_pos	player_pos;
	double	distance_x;
	double	distance_y;

	player_pos.x = thread->game->player.position.x * BLOC_SIZE;
	player_pos.y = thread->game->player.position.y * BLOC_SIZE;
	
	distance_x = (thread->ray[i].axis == 1)
	? pos.x - player_pos.x : (int)pos.x - player_pos.x;
	distance_y = (thread->ray[i].axis == 1)
	? (int)pos.y - player_pos.y : pos.y - player_pos.y;
	thread->ray[i].dist_minimap = ft_pythagore(distance_x, distance_y);
	thread->ray[i].distance = thread->ray[i].dist_minimap * cos(alpha_r);
	thread->ray[i].x = pos.x * 8;
	thread->ray[i].y = pos.y * 8;
}

static int		ft_iterate_ray(int i, t_pos *pos, t_thread *thread)
{
	double	angle_r;
	double	alpha_r;

	alpha_r = (fabs(thread->game->player.direction
	- thread->ray[i].angle_d)) * M_PI / 180;
	angle_r = thread->ray[i].angle_d * M_PI / 180;
	if ((ft_is_inwall(pos, thread->game, &thread->ray[i])) == 1
	|| ft_is_inwall(pos, thread->game, &thread->ray[i]) == 6
	|| ft_is_inwall(pos, thread->game, &thread->ray[i]) == 7)
	{
		thread->ray[i].axis = 1;
			ft_get_raygame(*pos, alpha_r, i, thread);
		return (0);
	}
	pos->x += -cos(angle_r) * 1;
	if ((ft_is_inwall(pos, thread->game, &thread->ray[i])) == 1
		|| ft_is_inwall(pos, thread->game, &thread->ray[i]) == 6
		|| ft_is_inwall(pos, thread->game, &thread->ray[i]) == 7)
	{
		thread->ray[i].axis = 2;
		ft_get_raygame(*pos, alpha_r, i, thread);
		return (0);
	}
	pos->y += -sin(angle_r) * 1;
	return (1);
}

void			ft_calc_distance(int i, int x, t_thread *thread)
{
	t_pos	pos;

	thread->ray[i].angle_d =
	(thread->game->player.direction - 30) + (x * (60.0 / WIN_W));
	pos.x = thread->game->player.position.x * BLOC_SIZE;
	pos.y = thread->game->player.position.y * BLOC_SIZE;
	while (pos.x > 0 && pos.x < MAP_SIZE * BLOC_SIZE
	&& pos.y > 0 && pos.y < MAP_SIZE * BLOC_SIZE)
	{
		if (!ft_iterate_ray(i, &pos, thread))
			return ;
	}
	thread->ray[i].distance = -1;
}
