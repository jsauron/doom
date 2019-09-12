/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <jsauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:32:07 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/12 19:17:46 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int store_sprite(t_sprite **sprite, int n)
{
	int i;
	t_sprite *tmp;

	i = 0;
	tmp = NULL;
	while (i + 1 < n)
	{
		if (sprite[i]->distance > sprite[i + 1]->distance)
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
/*
int	set_key_sprite(t_game *game, t_ray *ray, int x)
{
	game->sprite[game->n].sprite = game->mean_s;
	game->sprite[game->n].distance = ray->distance;
	game->sprite[game->n].size.x =
	game->key_s->w / game->sprite[0].distance;
	game->sprite[game->n].size.y =
	game->key_s->h / game->sprite[0].distance;
	game->sprite[game->n].pos.x = x;
	game->sprite[game->n].pos.y =
		(WIN_H - ((BLOC_SIZE / ray->distance) * DIST_SCREEN)) / 2;
	game->n++;
	return (0);
}

int	set_exit_sprite(t_game *game, t_ray *ray, int x)
{
	game->sprite[game->n].sprite = game->exit_s;
	game->sprite[game->n].distance = ray->distance;
	game->sprite[game->n].size.x =
	game->exit_s->w / game->sprite[0].distance;
	game->sprite[game->n].size.y =
	game->exit_s->h / game->sprite[0].distance;
	game->sprite[game->n].pos.x = x;
	game->sprite[game->n].pos.y =
		(WIN_H - ((BLOC_SIZE / ray->distance) * DIST_SCREEN)) / 2;
	game->n++;
	return (0);
}
*/
int	set_mean_sprite(t_game *game, t_ray *ray, int x)
{
	game->sprite[game->n].sprite = game->mean_s;
	game->sprite[game->n].distance = ray->distance;
	game->sprite[game->n].size.x =
	game->mean_s->w / game->sprite[0].distance;
	game->sprite[game->n].size.y =
	game->mean_s->h / game->sprite[0].distance;
	game->sprite[game->n].pos.x = x;
	game->sprite[game->n].pos.y =
		(WIN_H - ((BLOC_SIZE / ray->distance) * DIST_SCREEN)) / 2;
	return (0);
}

int	check_sprite(t_game *game)
{
	int i;
	int j;

	i = 0;
	game->n = 0;
	while (i < 8)
	{
		j = 0;
		while (j < WIN_W / 8)
		{
			if (game->thread[i].ray[j].the_mean > 0)
			{
				set_mean_sprite(game, &game->thread[i].ray[j], i * (WIN_W / 8) + j);
				game->sprite[game->n].actif = 1;
				game->n++;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
