/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <jsauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:32:07 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/21 23:18:00 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		range_sprite(t_sprite *sprite, int n)
{
	int			i;
	t_sprite	tmp;

	i = 0;
	while (i + 1 < n)
	{
		if (sprite[i].new_distance < sprite[i + 1].new_distance)
		{
			tmp = sprite[i];
			sprite[i] = sprite[i + 1];
			sprite[i + 1] = tmp;
			i = 0;
		}
		i++;
	}
	return (0);
}

double	calc_dist_sprite(t_game *game, t_ray *ray, int n)
{
	t_pos	player_pos;
	t_pos	pos;
	double	a;
	double	b;

	player_pos.x = game->player.position.x;
	player_pos.y = game->player.position.y;
	pos.x = game->sprite[n].pos_map.x;
	pos.y = game->sprite[n].pos_map.y;
	a = (ray->axis == 1)
		? pos.x - player_pos.x : (int)pos.x - player_pos.x;
	b = (ray->axis == 1)
		? (int)pos.y - player_pos.y : pos.y - player_pos.y;
	return (fabs(pythagore(a, b)));
}

void	set_zoom(t_game *game, double zoom, int n)
{
	if (game->sprite[n].id > 200)
	{
		game->sprite[n].sprite =
		rotozoomSurface(game->mean_s, 0.0, zoom, 1);
	}
	else if (game->sprite[n].id > 100)
	{
		game->sprite[n].sprite =
		rotozoomSurface(game->key_s, 0.0, zoom, 1);
	}
	else if (game->sprite[n].id == 3)
	{
		game->sprite[n].sprite =
		rotozoomSurface(game->exit_s, 0.0, zoom, 1);
	}
	else if (game->sprite[n].id == 8)
	{
		game->sprite[n].sprite =
		rotozoomSurface(game->bonus_s, 0.0, zoom, 1);
	}
}

void	set_zoom_light(t_game *game, double zoom, int n)
{
	if (game->sprite[n].id > 200)
	{
		game->sprite[n].sprite =
		rotozoomSurface(game->mean_l, 0.0, zoom, 1);
	}
	else if (game->sprite[n].id > 100)
	{
		game->sprite[n].sprite =
		rotozoomSurface(game->key_l, 0.0, zoom, 1);
	}
	else if (game->sprite[n].id == 3)
	{
		game->sprite[n].sprite =
		rotozoomSurface(game->exit_l, 0.0, zoom, 1);
	}
	else if (game->sprite[n].id == 8)
	{
		game->sprite[n].sprite =
		rotozoomSurface(game->bonus_l, 0.0, zoom, 1);
	}
}

int		set_distance_sprite(t_game *game, t_ray *ray, int n, int x)
{
	double	zoom;

	zoom = 1.0;
	if (game->sprite[n].actif == 1)
		return (0);
	game->sprite[n].new_distance = calc_dist_sprite(game, ray, n);
	if (game->sprite[n].new_distance != 0)
		zoom = (5 / game->sprite[n].new_distance);
	if (game->lightshade == 0)
		set_zoom(game, zoom, n);
	if (game->lightshade == 1)
		set_zoom_light(game, zoom, n);
	game->sprite[n].pos.x = x;
	game->touch = 0;
	game->sprite[n].pos.y =
		((WIN_H - ((BLOC_SIZE / (game->sprite[n].new_distance * BLOC_SIZE))
		* DIST_SCREEN)) / 2) - game->crouch + game->jump + game->visu;
	if ((WIN_W / 2 >= x && WIN_W / 2 <= x + game->sprite[n].sprite->w)
		&& (WIN_H / 2 >= game->sprite[n].pos.y
		&& WIN_H / 2 <= game->sprite[n].pos.y + game->sprite[n].sprite->h)
		&& game->sprite[n].id > 200)
		game->touch = game->sprite[n].id;
	game->sprite[n].actif = 1;
	return (0);
}

int		set_key_sprite(t_game *game, int x, int y)
{
	static int c;

	c++;
	game->sprite[game->n].sprite = game->key_s;
	game->sprite[game->n].id = 100 + c;
	game->map[y][x] = 100 + c;
	game->sprite[game->n].pos_map.x = x;
	game->sprite[game->n].pos_map.y = y;
	game->sprite[game->n].left_life = 1;
	game->sprite[game->n].new_distance = 0;
	game->n++;
	return (0);
}

int		set_bonus_sprite(t_game *game, int x, int y)
{
	static int c;

	c++;
	game->sprite[game->n].sprite = game->bonus_s;
	game->sprite[game->n].id = 8;
	game->map[y][x] = 8;
	game->sprite[game->n].pos_map.x = x;
	game->sprite[game->n].pos_map.y = y;
	game->sprite[game->n].left_life = 1;
	game->sprite[game->n].new_distance = 0;
	game->n++;
	return (0);
}

int		set_exit_sprite(t_game *game, int x, int y)
{
	game->sprite[game->n].sprite = game->exit_s;
	game->sprite[game->n].id = 3;
	game->sprite[game->n].pos_map.x = x;
	game->sprite[game->n].pos_map.y = y;
	game->sprite[game->n].left_life = 1;
	game->sprite[game->n].new_distance = 0;
	game->n++;
	return (0);
}

int		set_mean_sprite(t_game *game, int x, int y)
{
	static int c;

	c++;
	game->sprite[game->n].sprite = game->mean_s;
	game->sprite[game->n].id = 200 + c;
	game->map[y][x] = 200 + c;
	game->sprite[game->n].pos_map.x = x;
	game->sprite[game->n].pos_map.y = y;
	game->sprite[game->n].left_life = 3;
	game->sprite[game->n].new_distance = 0;
	game->n++;
	return (0);
}

int		search_sprite(t_game *game, int id)
{
	int n;

	n = 0;
	while (n <= game->n)
	{
		if (game->sprite[n].id == id)
			break ;
		n++;
	}
	return (n);
}

void	action_each_sprite(t_game *game, int n, int i, int j)
{
	if (game->thread[i].ray[j].the_mean > 0)
	{
		n = search_sprite(game, game->thread[i].ray[j].the_mean);
		set_distance_sprite(game, &game->thread[i].ray[j],
		n, i * (WIN_W / 8) + j);
	}
	if (game->thread[i].ray[j].the_key > 0)
	{
		n = search_sprite(game, game->thread[i].ray[j].the_key);
		set_distance_sprite(game, &game->thread[i].ray[j],
		n, i * (WIN_W / 8) + j);
	}
	if (game->thread[i].ray[j].the_exit == 3)
	{
		n = search_sprite(game, game->thread[i].ray[j].the_exit);
		set_distance_sprite(game, &game->thread[i].ray[j], n,
		i * (WIN_W / 8) + j);
	}
	if (game->thread[i].ray[j].the_bonus == 8)
	{
		n = search_sprite(game, game->thread[i].ray[j].the_bonus);
		set_distance_sprite(game, &game->thread[i].ray[j], n,
		i * (WIN_W / 8) + j);
	}
}

int		check_sprite(t_game *game)
{
	int i;
	int j;
	int n;
	int	k;

	n = 0;
	k = 0;
	while (k < game->n)
	{
		game->sprite[k].actif = 0;
		k++;
	}
	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < WIN_W / 8)
		{
			action_each_sprite(game, n, i, j);
			j++;
		}
		i++;
	}
	return (1);
}
