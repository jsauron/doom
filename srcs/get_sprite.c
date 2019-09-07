#include "doom.h"
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


int				display_sprite(SDL_Rect *pos, SDL_Surface *surface, double distance, int i)
{
	pos->x = i * 8 - (surface->w) ;	
	pos->y = (WIN_H - ((BLOC_SIZE / distance) * DIST_SCREEN)) / 2;	
	return (0);
}

int				set_sprite(t_thread *thread)
{
	int i;

	i = 0;
	while (i < WIN_H / 8)
	{
		if (thread->game->s_key == 1 && thread->ray[i].the_key == 1)
			display_sprite(&thread->wn->game.key_pos, thread->game->key_s, thread->ray[i].distance, i);
		if (thread->game->s_mean == 1 && thread->ray[i].the_mean == 1)
			display_sprite(&thread->wn->game.mean_pos, thread->game->mean_s, thread->ray[i].distance, i);
		if (thread->ray[i].the_exit == 1 && thread->ray[i].the_exit == 1)
			display_sprite(&thread->wn->game.exit_pos, thread->game->exit_s, thread->ray[i].distance, i);
		i++;
	}
	return (0);
}

int		check_sprite(t_thread *thread)
{
	int i;
	int c = 0;
	int k = 0;
	int j = 0;
	i = 0;
	while (i < WIN_W / 8)
	{
		if (thread->ray[i].the_key == 1)
			c++;
		if (thread->ray[i].the_mean == 1)
			k++;
		if (thread->ray[i].the_exit == 1)
			j++;
		i++;

	}
	thread->game->s_key = (c == 0) ? 0 : 1;
	thread->game->s_mean = (k == 0) ? 0 : 1;
	thread->game->s_exit = (j == 0) ? 0 : 1;
	set_sprite(thread);
	return (0);
}

