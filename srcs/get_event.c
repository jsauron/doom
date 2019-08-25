/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:01:21 by jsauron           #+#    #+#             */
/*   Updated: 2019/08/25 17:34:27 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static int		ft_keyboard1(const Uint8 *state, t_game *game)
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
	else
		return (0);
	return (1);
}

static int		ft_keyboard2(const Uint8 *state, t_game*game)
{
	if (state[SDL_SCANCODE_1])
		game->gamemode = 0;
	else if (state[SDL_SCANCODE_2])
		game->gamemode = 1;
	else if (state[SDL_SCANCODE_3])
		game->dev_mode = (game->dev_mode) ? 0 : 1;
	else if (state[SDL_SCANCODE_T])
		game->texturing = (game->texturing) ? 0 : 1;
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

static int		ft_mouse_motion(t_game *game)
{
	if (game->mouse.x > 0.0)
	{
		game->player.direction = (int)(game->player.direction
		+ abs(game->mouse.x) / game->player.sensibility) % 360;
		return (1);
	}
	else if (game->mouse.x < 0.0)
	{
		game->player.direction = (int)(game->player.direction
		- abs(game->mouse.x) / game->player.sensibility) % 360;
		if (game->player.direction < 0)
			game->player.direction = 360 + game->player.direction;
		return (1);
	}
/*	else if (game->mouse.y > 0.0)
	{
		printf("sdksjbd\n");
		game->player.direction = (int)(game->player.direction
				+ abs(game->mouse.y) / game->player.sensibility) %;
		return (1);
	}
	else if (game->mouse.y < 0.0)
	{
		game->player.direction = (int)(game->player.direction
		- abs(game->mouse.y) / game->player.sensibility) % ;
		if (game->player.direction < 0)
			game->player.direction = 360 + game->player.direction;
		return (1);
	}*/
	return (0);
}

static int		ft_move_events(const Uint8 *state, t_game *game)
{
	int		ok;

	ok = 0;
	if (game->gamemode == 0 && game->setting == 0)
	{
		if (state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_DOWN])
			ok = (ft_movement_normal(state, game)) ? 1 : ok;
		if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_RIGHT])
			ok = (ft_rotation_normal(state, game)) ? 1 : ok;
	}
	else if (game->setting == 0)
	{
		if (game->mouse.x || game->mouse.y)
			ok = (ft_mouse_motion(game)) ? 1 : ok;
		if (state[SDL_SCANCODE_W] || state[SDL_SCANCODE_S])
			ok = (ft_movement_gaming(state, game)) ? 1 : ok;
		if (state[SDL_SCANCODE_A] || state[SDL_SCANCODE_D])
			ok = (ft_lateral_gaming(state, game)) ? 1 : ok;
	}
	return (ok);
}

int				ft_get_events(t_game *game)
{
	const Uint8 *state;
	int			ok;

	ok = 0;
	SDL_PollEvent(&(game->sdl.event));
	state = SDL_GetKeyboardState(0);
	SDL_GetRelativeMouseState(&(game->mouse.x), &(game->mouse.y));
	if (state[SDL_SCANCODE_ESCAPE])
		ft_exit(game);
	if (game->sdl.event.type == SDL_QUIT)
		ft_exit(game);
	if (game->sdl.event.type == SDL_KEYDOWN)
		ok = (ft_keyboard1(state, game) || ft_keyboard2(state, game)) ? 1 : ok;
	ok = (ok) ? 1 : ft_move_events(state, game);
	return (ok);
}
