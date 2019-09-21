/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:32:07 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/21 18:57:07 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

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
