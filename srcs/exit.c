/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <jsauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:30:38 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/21 16:21:43 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	sdl_err_exit(char *msg, t_game *game)
{
	ft_putendl(SDL_GetError());
	ft_putendl(TTF_GetError());
	ft_err_exit(msg, game);
}

void			ft_err_exit(char *msg, t_game *game)
{
	if (msg)
		ft_putendl_fd(msg, 2);
	ft_exit(game);
}

void			ft_exit(t_game *game)
{
	free_all(game->thread->wn);
	exit(EXIT_SUCCESS);
}
