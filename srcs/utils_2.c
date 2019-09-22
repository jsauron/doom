/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <jsauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 00:17:34 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/22 14:06:23 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

Uint32			light_shade(double distance, Uint32 hexa)
{
	SDL_Color	color;
	double		delta;

	delta = distance / 300;
	delta > 0.9 ? delta = 0.9 : 0;
	delta /= 1.50;
	hexa |= 0xFF000000;
	color = (SDL_Color){hexa >> 24, hexa >> 16, hexa >> 8, hexa};
	ft_remove_light(&color.r, delta, 24);
	ft_remove_light(&color.g, delta, 16);
	ft_remove_light(&color.b, delta, 8);
	ft_remove_light(&color.a, delta, 0);
	return ((color.r << 24) + (color.g << 16) + (color.b << 8) + (color.a));
}

static int		is_inwall_ret(int x, int y, t_game *game)
{
	if (game->map[y][x] == 1)
		return (1);
	if (game->map[y][x] > 200)
		return (2);
	if (game->map[y][x] == 3)
		return (3);
	if (game->map[y][x] > 100)
		return (5);
	if (game->map[y][x] == 6)
		return (6);
	if (game->map[y][x] == 7)
		return (7);
	if (game->map[y][x] == 8)
		return (8);
	if (game->map[y][x] == 9)
		return (9);
	return (0);
}

int				is_inwall(t_pos *pos, t_game *game, t_ray *ray)
{
	int		x2;
	int		y2;
	int		n;

	n = 0;
	x2 = pos->x / BLOC_SIZE;
	y2 = pos->y / BLOC_SIZE;
	if (x2 < 0 || x2 >= MAP_SIZE || y2 < 0 || y2 >= MAP_SIZE)
		return (0);
	if (ray != NULL && game->map[y2][x2] == 3)
		ray->the_exit = 3;
	if (ray != NULL && game->map[y2][x2] > 200)
		ray->the_mean = game->map[y2][x2];
	if (ray != NULL && game->map[y2][x2] == 6)
		ray->the_door = 1;
	if (ray != NULL && game->map[y2][x2] > 100)
		ray->the_key = game->map[y2][x2];
	if (ray != NULL && game->map[y2][x2] == 7)
		ray->the_poster = 1;
	if (ray != NULL && game->map[y2][x2] == 8)
		ray->the_bonus = 8;
	if (ray != NULL && game->map[y2][x2] == 9)
		ray->the_button = 1;
	return (is_inwall_ret(x2, y2, game));
}
