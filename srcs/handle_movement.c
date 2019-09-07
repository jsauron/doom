/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_movement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:02:08 by jsauron           #+#    #+#             */
/*   Updated: 2019/08/25 17:07:06 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static int		ft_is_inmap(t_pos *pos, t_game *game)
{
	(void)game;
	return (pos->x > 0 && pos->x < MAP_SIZE * BLOC_SIZE
	&& pos->y > 0 && pos->y < MAP_SIZE * BLOC_SIZE);
}

int				ft_movement(double angle_r, int dir, t_game *game)
{
	t_pos		move;
	t_pos		pos;
	int		x;
	int		y;


	move.y = sin(angle_r) * game->player.speed;
	move.x = cos(angle_r) * game->player.speed;
	pos.y = (game->player.position.y * BLOC_SIZE);
	pos.x = (game->player.position.x * BLOC_SIZE);

	if (dir == 1)
	{
		pos.x = (game->player.position.x * BLOC_SIZE) - move.x * 150;
		pos.y = (game->player.position.y * BLOC_SIZE) - move.y * 150;
		move.y = -move.y;
		move.x = -move.x;
	}
	else
	{
		pos.x = (game->player.position.x * BLOC_SIZE) + move.x * 150;
		pos.y = (game->player.position.y * BLOC_SIZE) + move.y * 150;
	}

	y = (int)pos.y / BLOC_SIZE;
	x = (int)pos.x / BLOC_SIZE;
	if ((ft_is_inmap(&pos, game) && (ft_is_inwall(&pos, game, NULL) == 6) && game->key > 0))
	{
		game->key--;
		game->map[y][x] = 0;
	}
	else if ((ft_is_inmap(&pos, game) && (ft_is_inwall(&pos, game, NULL) == 5)))
	{
		game->key++;
		game->map[y][x] = 0;
	}
	else if ((ft_is_inmap(&pos, game) && (ft_is_inwall(&pos, game, NULL) == 2)))
	{
		printf("lfe = %d\n", game->player.life);
		if (game->player.life > 0)
		game->player.life--;
	//	pos.x = (game->player.position.x * BLOC_SIZE) - move.x * 150;
		//pos.y  = (game->player.position.y * BLOC_SIZE )- move.y * 150;
	}
	else if ((ft_is_inmap(&pos, game) && (ft_is_inwall(&pos, game, NULL) == 3)))
		game->exit = 1;
	if (ft_is_inmap(&pos, game) && !(ft_is_inwall(&pos, game, NULL)))
		game->player.position.y += move.y;
	if (ft_is_inmap(&pos, game) && !(ft_is_inwall(&pos, game, NULL)))
		game->player.position.x += move.x;
	return (1);
}
