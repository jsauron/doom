/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_event2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:53:52 by hben-yah          #+#    #+#             */
/*   Updated: 2019/09/21 19:15:33 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		get_target_shot(t_game *game)
{
	int			n;

	if (game->event.button.button == SDL_BUTTON_LEFT)
	{
		game->shot = 1;
		Mix_PlayChannel(-1, game->music.shot, 0);
		if (game->touch > 0)
		{
			n = search_sprite(game, game->touch);
			game->sprite[n].left_life--;
			if (game->sprite[n].left_life == 0)
			{
				game->count_frame_dead = 75;
				Mix_PlayChannel(-1, game->music.dead, 0);
			}
		}
	}
	if (game->event.button.button == SDL_BUTTON_RIGHT)
		game->target = (game->target % 2 == 0) ? 1 : 0;
}

void		mouse_motion_x(t_game *game)
{
	if (game->mouse.x > 0.0)
	{
		game->player.direction =
			(int)(game->player.direction + abs(game->mouse.x)
					/ game->player.sensibility) % 360;
	}
	else if (game->mouse.x < 0.0)
	{
		game->player.direction =
			(int)(game->player.direction - abs(game->mouse.x) /
					game->player.sensibility) % 360;
		if (game->player.direction < 0)
			game->player.direction = 360 + game->player.direction;
	}
}

void		mouse_motion_y(t_game *game)
{
	if (game->mouse.y > 0.0 || game->mouse.y < 0.0)
	{
		game->visu -= game->mouse.y;
		if (game->visu < -(WIN_H / 4))
			game->visu = -(WIN_H / 4);
		else if (game->visu > WIN_H / 4)
			game->visu = WIN_H / 4;
	}
}

int			get_events(t_game *game)
{
	SDL_PollEvent(&(game->event));
	game->state = (Uint8 *)SDL_GetKeyboardState(NULL);
	SDL_GetRelativeMouseState(&(game->mouse.x), &(game->mouse.y));
	if (game->mission == 1 && game->state[SDL_SCANCODE_SPACE])
		game->mission = 0;
	else if (game->player.life == 0)
		Mix_PlayChannel(-1, game->music.gameover, 0);
	if (game->state[SDL_SCANCODE_ESCAPE])
		return (0);
	else if (game->event.type == SDL_QUIT)
		ft_exit(game);
	if (game->player.life != 0)
		event_with_life(game);
	return (1);
}
