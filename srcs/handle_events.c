/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:01:58 by jsauron           #+#    #+#             */
/*   Updated: 2019/08/25 17:05:43 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int				ft_movement_normal(const Uint8 *state, t_game  *game)
{
	double		angle_r;

	angle_r = game->player.direction * M_PI / 180;
	if (state[SDL_SCANCODE_UP])
		return (ft_movement(angle_r, 1, game));
	else if (state[SDL_SCANCODE_DOWN])
		return (ft_movement(angle_r, 0, game));
	return (0);
}

int				ft_rotation_normal(const Uint8 *state, t_game *game)
{
	if (state[SDL_SCANCODE_RIGHT])
	{
		game->player.direction = (int)(game->player.direction + 5) % 360;
		return (1);
	}
	else if (state[SDL_SCANCODE_LEFT])
	{
		if (game->player.direction - 5 > 0)
			game->player.direction = (int)(game->player.direction - 5);
		else
			game->player.direction = 360;
		return (1);
	}
	return (0);
}

int				ft_movement_gaming(const Uint8 *state, t_game *game)
{
	double		angle_r;

	angle_r = game->player.direction * M_PI / 180;
	if (state[SDL_SCANCODE_W])
		return (ft_movement(angle_r, 1, game));
	else if (state[SDL_SCANCODE_S])
		return (ft_movement(angle_r, 0, game));
	return (0);
}

int				ft_lateral_gaming(const Uint8 *state, t_game *game)
{
	double		angle_r;

	angle_r = (game->player.direction + 90) * M_PI / 180;
	if (state[SDL_SCANCODE_D])
		return (ft_movement(angle_r, 1, game));
	else if (state[SDL_SCANCODE_A])
		return (ft_movement(angle_r, 0, game));
	return (0);
}
