/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <jsauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:32:07 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/17 17:42:54 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int range_sprite(t_sprite *sprite, int n)
{
	int i;
	t_sprite *tmp;

	i = 0;
	tmp = NULL;
	while (i + 1 < n)
	{
		if (sprite[i].distance > sprite[i + 1].distance)
		{
			tmp = &sprite[i];
			sprite[i] = sprite[i + 1];
			sprite[i + 1] = *tmp;
			i = 0;
		}
		i++;
	}
	return (0);
}

int	set_distance_sprite(t_game *game, t_ray *ray, int n, int x)
{
	/*t_pos	player_pos;
	t_pos	pos;
	double	distance_x;
	double	distance_y;
	double	distance;
alpha_r = (fabs(game->player.direction
				- ray->angle_d)) * M_PI / 180;
	angle_r = ray->angle_d * M_PI / 180;

	pos.x += -cos(angle_r) * 1;
	pos.y += -sin(angle_r) * 1;

	player_pos.x = game->player.position.x * BLOC_SIZE;
	player_pos.y = game->player.position.y * BLOC_SIZE;
	pos.x = game->sprite[n].pos.x * BLOC_SIZE;
	pos.y = game->sprite[n].pos.y * BLOC_SIZE;

	distance_x = (ray->axis == 1)
		? pos.x - player_pos.x : (int)pos.x - player_pos.x;
	distance_y = (ray->axis == 1)
		? (int)pos.y - player_pos.y : pos.y - player_pos.y;
	distance = pythagore(distance_x, distance_y);
//	distance = thread->ray[i].dist_minimap * cos(alpha_r);
//	x = pos.x * 8;
//	y =pos.y * 8;
*/
	if (game->sprite[n].actif == 1)
		return (0);
	game->sprite[n].distance = ray->distance;
				//	game->key_s->w / game->sprite[n].distance,
					//game->key_s->h / game->sprite[n].distance);
	//game->mean_s->w = 500/*game->mean_s->w / game->sprite[n].distance*/;
	//game->sprite[n].sprite->h =
	//game->mean_s->h = 500/* game->mean_s->h / game->sprite[n].distance*/;
	//game->sprite[n].sprite = game->mean_s;
	game->sprite[n].pos.x = x;
	game->touch = 0;
	game->sprite[n].pos.y =
		((WIN_H - ((BLOC_SIZE / ray->distance) * DIST_SCREEN)) / 2) - game->crouch + game->jump + game->visu;
	if ((WIN_W / 2 >= x && WIN_W / 2 <= x + game->sprite[n].sprite->w)
		&& (WIN_H / 2 >= game->sprite[n].pos.y && WIN_H / 2 <= game->sprite[n].pos.y + game->sprite[n].sprite->h)
	&& game->sprite[n].id > 200)
		game->touch = game->sprite[n].id;
	game->sprite[n].actif = 1;
/*	color = calc__col(thread->wn, (WIN_H - ((BLOC_SIZE / ray->distance) * DIST_SCREEN)) / 2, i, thread);
	if (thread->game->lightshade == 1)
		color = light_shade(ray->distance, color);
	setpixel(thread->wn->screen, x, (WIN_H - ((BLOC_SIZE / ray->distance) * DIST_SCREEN)) / 2, color);
*/	return (0);
}

int	set_key_sprite(t_game *game, int x, int y)
{
	static int c;

	c++;
	game->sprite[game->n].sprite = game->key_s;
	game->sprite[game->n].id = 100 + c;
	game->map[y][x] = 100 + c;
	game->sprite[game->n].pos_map.x = x;	
	game->sprite[game->n].pos_map.y = y;	
	game->sprite[game->n].left_life = 1;
	game->n++;
	return (0);
}

int	set_exit_sprite(t_game *game, int x, int y)
{
	(void)x;
	(void)y;

	game->sprite[game->n].sprite = game->exit_s;
	game->sprite[game->n].id = 3;
	game->sprite[game->n].pos_map.x = x;	
	game->sprite[game->n].pos_map.y = y;	
	game->sprite[game->n].left_life = 1;
	game->n++;
	return (0);
}

int	set_mean_sprite(t_game *game, int x, int y)
{
	static int c;
	
	c++;
	game->sprite[game->n].sprite = game->mean_s;
	game->sprite[game->n].id = 200 + c;
	game->map[y][x] = 200 + c;
	game->sprite[game->n].pos_map.x = x;	
	game->sprite[game->n].pos_map.y = y;	
	game->sprite[game->n].left_life = 3;
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
			break;
		n++;
	}
	return (n);
}

int	check_sprite(t_game *game)
{
	int i;
	int j;
	int n;

	n = 0;
	int k = 0;
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
			 if (game->thread[i].ray[j].the_mean > 0)
			 {
				n = search_sprite(game, game->thread[i].ray[j].the_mean);
				set_distance_sprite(game, &game->thread[i].ray[j],
				 n, i * (WIN_W / 8) + j); // a debug -1 em plus
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
				i  * (WIN_W / 8) + j);
		}
			j++;
		}
		i++;
	}
	return (1);
}
