/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <jsauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:34:01 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/17 15:20:22 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void init_minimap(t_game *game)
{
	game->minimap.origin.x = 10;
	game->minimap.origin.y = WIN_H - (WIN_H / 4) - 10;
	game->minimap.centre.x = (WIN_W / 4) / 2 + 10;
	game->minimap.centre.y = (WIN_H - (WIN_H / 4) / 2) - 10;
	game->minimap.map_size.w = game->minimap.mnp_size * MAP_SIZE;
	game->minimap.map_size.h = game->minimap.mnp_size * MAP_SIZE;
	game->minimap.pos_play.x = game->player.position.x * game->minimap.mnp_size;
	game->minimap.pos_play.y = game->player.position.y * game->minimap.mnp_size;
	game->minimap.diff.x = game->minimap.centre.x - game->minimap.pos_play.x;
	game->minimap.diff.y = game->minimap.centre.y - game->minimap.pos_play.y;
	game->minimap.limit.l = game->minimap.origin.x;
	game->minimap.limit.r = game->minimap.centre.x * 2 - 10;
	game->minimap.limit.t = WIN_H - (WIN_H - game->minimap.origin.y);
	game->minimap.limit.b = WIN_H - 10;
}

static void draw_background(t_win *wn, t_game *game)
{
	SDL_Rect rect;

	rect = (SDL_Rect){game->minimap.origin.x,
		game->minimap.origin.y, WIN_W / 4, WIN_H / 4};
	draw_border(wn, rect, 0xFFFFFFF);
	draw_rect(wn, rect, 0xFF000000, &(game->minimap.limit));
}

static void draw_ray(t_win *wn, t_game *game, int i, int j)
{
	double angle_r;
	t_pos step;
	t_vec vec;
	t_pos a;
	t_pos b;

	angle_r = (game->thread[i].ray[j].angle_d) * M_PI / 180;
	step.x = -cos(angle_r) * (game->thread[i].ray[j].dist_minimap) * game->minimap.mnp_size / BLOC_SIZE;
	step.y = -sin(angle_r) * (game->thread[i].ray[j].dist_minimap) * game->minimap.mnp_size / BLOC_SIZE;
	a = (t_pos){game->minimap.centre.x, game->minimap.centre.y};
	b.x = game->minimap.centre.x + step.x;
	b.y = game->minimap.centre.y + step.y;
	vec = (t_vec){a, b};
	if (game->dev_mode == 1)
		draw_line(wn, vec, get_color(game->thread[i].ray[j].axis, game->thread[i].ray[j].angle_d), &(game->minimap.limit));
	else
		draw_line(wn, vec, 0xFFFFFFFF, &(game->minimap.limit));
}

static void draw_player(t_win *wn, t_game *game)
{
	SDL_Rect player;
	int i;
	int j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < WIN_W / 8)
		{
			draw_ray(wn, game, i, j);
			j++;
		}
		i++;
	}
	player = (SDL_Rect){game->minimap.centre.x - 5,
		game->minimap.centre.y - 5, 10, 10};
	draw_rect(wn, player, 0x0, 0);
}

void minimap(t_win *wn, t_game *game)
{
	SDL_Rect rect;
	int i;
	int j;

	if (game->target == 0)
	{
		init_minimap(game);
		draw_background(wn, game);
		i = 0;
		while (i < MAP_SIZE)
		{
			j = 0;
			while (j < MAP_SIZE)
			{
				if (game->map[i][j] > 200 && game->sprite[search_sprite(game, game->map[i][j])].left_life == 0)
					game->map[i][j] = 0;
				rect = (SDL_Rect){game->minimap.diff.x + (j * game->minimap.mnp_size),
					game->minimap.diff.y + (i * game->minimap.mnp_size),
					game->minimap.mnp_size, game->minimap.mnp_size};
				if (game->map[i][j] == 1 || game->map[i][j] == 7)
					draw_rect(wn, rect, 0xFF306bb0, &(game->minimap.limit));
				else if (game->map[i][j] > 200)
					draw_rect(wn, rect, 0xFFDC143C, &(game->minimap.limit));
				else if (game->map[i][j] == 0 ||game->map[i][j] == 4)
					draw_rect(wn, rect, 0xFFffabe4, &(game->minimap.limit));
				else if (game->map[i][j] == 3)
					draw_rect(wn, rect, 0xFF2E8B57, &(game->minimap.limit));
				else if (game->map[i][j] > 100)
					draw_rect(wn, rect, 0xFFFFD700, &(game->minimap.limit));
				else if (game->map[i][j] == 6)
					draw_rect(wn, rect, 0xFF00BFFF  , &(game->minimap.limit));
				j++;
			}
			i++;
		}
		draw_player(wn, game);
	}
}
