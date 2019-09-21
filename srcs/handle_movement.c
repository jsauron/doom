/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <jsauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:32:41 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/21 18:57:37 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static int	is_inmap(t_pos *pos)
{
	return (pos->x > 0 && pos->x < MAP_SIZE * BLOC_SIZE
			&& pos->y > 0 && pos->y < MAP_SIZE * BLOC_SIZE);
}

void		hud_keys_life(t_game *game, t_pos pos, int old_time)
{
	if ((is_inmap(&pos)
		&& (is_inwall(&pos, game, NULL) == 6) && game->key > 0))
	{
		game->key--;
		game->count_frame_open = 75;
		Mix_PlayChannel(-1, game->music.open_door, 0);
		game->map[(int)pos.y / BLOC_SIZE][(int)pos.x / BLOC_SIZE] = 0;
	}
	else if ((is_inmap(&pos) && (is_inwall(&pos, game, NULL) == 5)))
	{
		game->key++;
		Mix_PlayChannel(-1, game->music.key, 0);
		game->map[(int)pos.y / BLOC_SIZE][(int)pos.x / BLOC_SIZE] = 0;
	}
	else if ((is_inmap(&pos) && (is_inwall(&pos, game, NULL) == 2))
		&& game->player.life > 0)
	{
		if (game->time.current_time - old_time > 100)
		{
			game->player.life--;
			old_time = game->time.current_time;
		}
	}
	else if ((is_inmap(&pos) && (is_inwall(&pos, game, NULL) == 3)))
		game->exit = 1;
}

void		hud_impact(t_game *game, t_pos move, t_pos pos)
{
	SDL_Rect	pos_contour;
	int			x;
	int			y;
	static int	old_time;

	pos_contour.x = 0;
	pos_contour.y = 0;
	y = (int)pos.y / BLOC_SIZE;
	x = (int)pos.x / BLOC_SIZE;
	hud_keys_life(game, pos, old_time);
	if (is_inmap(&pos) && !(is_inwall(&pos, game, NULL)))
		game->player.position.y += move.y;
	if (is_inmap(&pos) && !(is_inwall(&pos, game, NULL)))
		game->player.position.x += move.x;
}

int			movement(double angle_r, int dir, t_game *game)
{
	t_pos	move;
	t_pos	pos;

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
	hud_impact(game, move, pos);
	return (1);
}
