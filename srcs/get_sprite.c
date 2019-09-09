/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:03:31 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/09 22:32:18 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		store_sprite(t_sprite **sprite, int n)
{
	int			i;
	t_sprite	*tmp;

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

int		check_sprite(t_thread *thread)
{
	int i;
	int n;
	int l;
	int k;
	int j;

	i = 0;
	l = 0;
	n = 0;
	k = 0;
	j = 0;
	while (i < WIN_W / 8)
	{
		if (thread->ray[i].the_key == 1 && l == 0)
		{
			thread->game->sprite[n] = malloc(sizeof(t_sprite));
			thread->game->sprite[n]->sprite = thread->game->key_s;
			thread->game->sprite[n]->distance = thread->ray[i].distance;
			thread->game->sprite[n]->size.x =
				thread->game->key_s->w / thread->ray[i].distance;
			thread->game->sprite[n]->size.y =
				thread->game->key_s->h / thread->ray[i].distance;
			thread->game->sprite[n]->pos.x = i * 8;
			thread->game->sprite[n]->pos.y =
				(WIN_H - ((BLOC_SIZE / thread->ray[i].distance)
						* DIST_SCREEN)) / 2;
			l++;
			n++;
		}
		else if (thread->ray[i].the_mean == 1 && k == 0)
		{
			thread->game->sprite[n] = malloc(sizeof(t_sprite));
			thread->game->sprite[n]->sprite = thread->game->mean_s;
			thread->game->sprite[n]->distance = thread->ray[i].distance;
			thread->game->sprite[n]->size.x =
				thread->game->mean_s->w / thread->ray[i].distance;
			thread->game->sprite[n]->size.y =
				thread->game->mean_s->h / thread->ray[i].distance;
			thread->game->sprite[n]->pos.x = i * 8;
			thread->game->sprite[n]->pos.y =
				(WIN_H - ((BLOC_SIZE / thread->ray[i].distance)
						* DIST_SCREEN)) / 2;
			k++;
			n++;
		}
		else if (thread->ray[i].the_exit == 1 && j < 2)
		{
			thread->game->sprite[n] = malloc(sizeof(t_sprite));
			thread->game->sprite[n]->sprite = thread->game->exit_s;
			thread->game->sprite[n]->distance = thread->ray[i].distance;
			thread->game->sprite[n]->size.x = thread->game->exit_s->w
				/ thread->ray[i].distance;
			thread->game->sprite[n]->size.y = thread->game->exit_s->h
				/ thread->ray[i].distance;
			thread->game->sprite[n]->pos.x = i * 8;
			thread->game->sprite[n]->pos.y =
				(WIN_H - ((BLOC_SIZE / thread->ray[i].distance)
						* DIST_SCREEN)) / 2;
			j++;
			n++;
		}
		i++;
	}
	thread->game->n = n;
	store_sprite(thread->game->sprite, thread->game->n);
	return (0);
}
