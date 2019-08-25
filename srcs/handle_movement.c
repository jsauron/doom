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
	t_pos		pos_h;
	t_pos		pos_v;


	move.y = sin(angle_r) * game->player.speed;
	move.x = cos(angle_r) * game->player.speed;
	pos_h.y = (game->player.position.y * BLOC_SIZE);
	pos_v.x = (game->player.position.x * BLOC_SIZE);
	if (dir == 1)
	{
		pos_h.x = (game->player.position.x * BLOC_SIZE) - move.x * 150;
		pos_v.y = (game->player.position.y * BLOC_SIZE) - move.y * 150;
		move.y = -move.y;
		move.x = -move.x;
	}
	else
	{
		pos_h.x = (game->player.position.x * BLOC_SIZE) + move.x * 150;
		pos_v.y = (game->player.position.y * BLOC_SIZE) + move.y * 150;
	}
	if (ft_is_inmap(&pos_v, game) && !(ft_is_inwall(&pos_v, game)))
		game->player.position.y += move.y;
	if (ft_is_inmap(&pos_h, game) && !(ft_is_inwall(&pos_h, game)))
		game->player.position.x += move.x;
	return (1);
}
