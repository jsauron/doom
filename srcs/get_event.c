/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:01:21 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/09 22:25:47 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static int	ft_keyboard1(const Uint8 *state, t_game *game)
{
	if (state[SDL_SCANCODE_I] && game->setting == 1)
	{
		SDL_SetRelativeMouseMode(SDL_TRUE);
		game->setting = 0;
	}
	else if (state[SDL_SCANCODE_I] && game->setting == 0)
	{
		SDL_SetRelativeMouseMode(SDL_FALSE);
		game->setting = 1;
	}
	else if (state[SDL_SCANCODE_KP_8])
		game->player.speed -= (game->player.speed > 0.04) ? 0.02 : 0;
	else if (state[SDL_SCANCODE_KP_9])
		game->player.speed += (game->player.speed < 0.3) ? 0.02 : 0;
	else if (state[SDL_SCANCODE_KP_MULTIPLY])
		game->player.sensibility -= (game->player.sensibility > 1) ? 1 : 0;
	else if (state[SDL_SCANCODE_KP_DIVIDE])
		game->player.sensibility += (game->player.sensibility < 10) ? 1 : 0;
	else if (state[SDL_SCANCODE_SPACE])
		game->player.cam_height++;
	else
		return (0);
	return (1);
}

static int	ft_keyboard2(Uint8 *state, t_game *game)
{
	if (state[SDL_SCANCODE_1])
		game->gamemode = 0;
	else if (state[SDL_SCANCODE_2])
		game->gamemode = 1;
	else if (state[SDL_SCANCODE_3])
		game->dev_mode = (game->dev_mode) ? 0 : 1;
	else if (state[SDL_SCANCODE_L])
		game->lightshade = (game->lightshade) ? 0 : 1;
	else if (state[SDL_SCANCODE_KP_PLUS]
			&& game->minimap.mnp_size * ZOOM_P < 50)
		game->minimap.mnp_size *= ZOOM_P;
	else if (state[SDL_SCANCODE_KP_MINUS]
			&& game->minimap.mnp_size * ZOOM_L > 10)
		game->minimap.mnp_size *= ZOOM_L;
	else
		return (0);
	return (1);
}

static int	ft_mouse_motion(t_game *game)
{
	if (game->mouse.x > 0.0)
	{
		game->player.direction =
			(int)(game->player.direction + abs(game->mouse.x)
					/ game->player.sensibility) % 360;
		return (1);
	}
	else if (game->mouse.x < 0.0)
	{
		game->player.direction =
			(int)(game->player.direction - abs(game->mouse.x) /
					game->player.sensibility) % 360;
		if (game->player.direction < 0)
			game->player.direction = 360 + game->player.direction;
		return (1);
	}
	return (0);
}

void		get_target_shot(t_game *game)
{
	static int	c;

	if (game->event.button.button == SDL_BUTTON_LEFT)
		game->shot = 1;
	if (game->event.button.button == SDL_BUTTON_RIGHT)
	{
		game->target = (c % 2 == 0) ? 1 : 0;
		c++;
	}
}

static int	ft_move_events(const Uint8 *state, t_game *game)
{
	int			move;

	move = 0;
	if (game->gamemode == 0 && game->setting == 0)
	{
		if (state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_DOWN])
			move = (ft_movement_normal(state, game)) ? 1 : 0;
		if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_RIGHT])
			move = (ft_rotation_normal(state, game)) ? 1 : 0;
	}
	else if (game->setting == 0)
	{
		if (game->mouse.x || game->mouse.y)
			move = (ft_mouse_motion(game)) ? 1 : 0;
		if (state[SDL_SCANCODE_W] || state[SDL_SCANCODE_S])
			move = (ft_movement_gaming(state, game)) ? 1 : 0;
		if (state[SDL_SCANCODE_A] || state[SDL_SCANCODE_D])
			move = (ft_lateral_gaming(state, game)) ? 1 : 0;
		if (game->event.type == SDL_MOUSEBUTTONDOWN)
			get_target_shot(game);
		if (game->event.type == SDL_MOUSEBUTTONUP
				&& game->event.button.button == SDL_BUTTON_LEFT)
			game->shot = 0;
	}
	return (move);
}

int		ft_get_events(t_game *game)
{
	int	move;

	move = 0;
	SDL_PollEvent(&(game->event));
	game->state = (Uint8 *)SDL_GetKeyboardState(NULL);
	SDL_GetRelativeMouseState(&(game->mouse.x), &(game->mouse.y));
	if (game->player.life == 0)
	{
		if (game->state[SDL_SCANCODE_ESCAPE])
			return (0);
	}
	if (game->state[SDL_SCANCODE_ESCAPE])
		return (0);
	else if (game->event.type == SDL_QUIT)
		ft_exit(game);
	else if (game->event.type == SDL_KEYDOWN)
		move = (ft_keyboard1(game->state, game)
				|| ft_keyboard2(game->state, game)) ? 1 : move;
	move = (move) ? 1 : ft_move_events(game->state, game);
	return (1);
}
