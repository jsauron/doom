/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:01:03 by jsauron           #+#    #+#             */
/*   Updated: 2019/08/25 16:12:17 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void		ft_sdl_quit(t_game *game)
{
	SDL_DestroyRenderer(game->sdl.renderer);
	SDL_DestroyWindow(game->sdl.window);
	TTF_CloseFont(game->font);
	TTF_Quit();
	SDL_Quit();
}

void			ft_err_exit(char *msg, t_game *game)
{
	if (msg)
		ft_putendl_fd(msg, 2);
	if (game->endinitsdl)
		ft_sdl_quit(game);
	exit(EXIT_FAILURE);
}

void			ft_exit(t_game *game)
{
	ft_sdl_quit(game);
	exit(EXIT_SUCCESS);
}
