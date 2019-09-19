/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <jsauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:30:38 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/19 23:10:38 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	sdl_err_exit(char *msg, t_game *game)
{
	ft_putendl(SDL_GetError());
	ft_putendl(TTF_GetError());
	if (game->font)
		TTF_CloseFont(game->font);
	TTF_Quit();
	SDL_Quit();
	ft_err_exit(msg, game);
}

static void		ft_sdl_quit(t_game *game)
{
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
