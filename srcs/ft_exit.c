/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:01:03 by jsauron           #+#    #+#             */
/*   Updated: 2019/03/16 10:01:07 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		ft_sdl_quit(t_data *data)
{
	SDL_DestroyRenderer(data->sdl.renderer);
	SDL_DestroyWindow(data->sdl.window);
	TTF_CloseFont(data->font);
	TTF_Quit();
	SDL_Quit();
}

void			ft_err_exit(char *msg, t_data *data)
{
	if (msg)
		ft_putendl_fd(msg, 2);
	lt_destroy();
	if (data->endinitsdl)
		ft_sdl_quit(data);
	exit(EXIT_FAILURE);
}

void			ft_exit(t_data *data)
{
	lt_destroy();
	ft_sdl_quit(data);
	exit(EXIT_SUCCESS);
}
