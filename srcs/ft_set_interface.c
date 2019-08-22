/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_interface.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:04:03 by jsauron           #+#    #+#             */
/*   Updated: 2019/03/16 10:04:06 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_set_config(t_data *data)
{
	SDL_Rect	rect;

	rect = (SDL_Rect){200, 200, 560, 372};
	ft_draw_rect(rect, 0x10000000, 0, data);
	ft_draw_border(rect, 0xFFFFFFFF, data);
}

static void	ft_bloc_devmode(t_data *data)
{
	SDL_Rect	rect;

	rect = (SDL_Rect){15, 48, 220, 35};
	ft_draw_rect(rect, 0x10000000, 0, data);
	rect = (SDL_Rect){15, 98, 220, 35};
	ft_draw_rect(rect, 0x10000000, 0, data);
	rect = (SDL_Rect){15, 138, 220, 35};
	ft_draw_rect(rect, 0x10000000, 0, data);
	rect = (SDL_Rect){15, 178, 220, 35};
	ft_draw_rect(rect, 0x10000000, 0, data);
	rect = (SDL_Rect){15, 218, 220, 35};
	ft_draw_rect(rect, 0x10000000, 0, data);
}

void		ft_set_interface(t_data *data)
{
	SDL_Rect	rect;

	if (data->gamemode == 1 || data->dev_mode == 1)
		ft_minimap(data);
	rect = (SDL_Rect){15, 15, 138, 20};
	ft_draw_rect(rect, 0x00000000, 0, data);
	ft_draw_border(rect, 0xFFFFFFFF, data);
	rect = (SDL_Rect){170, 15, 60, 20};
	ft_draw_rect(rect, 0xFF000000, 0, data);
	ft_draw_border(rect, 0xFFFFFFFF, data);
	if (data->setting == 1)
		ft_set_config(data);
	if (data->gamemode == 1 && data->setting == 0)
		ft_set_cursor(data);
	if (data->dev_mode == 1 && data->setting == 0)
		ft_bloc_devmode(data);
}
