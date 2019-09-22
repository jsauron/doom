/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <jsauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:33:04 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/22 15:42:05 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	init_sprite(t_game *game)
{
	if (!(game->key_s = IMG_Load("ressources/wall/key_oo.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->exit_s = IMG_Load("ressources/wall/exit_oo.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->mean_s = IMG_Load("ressources/wall/mean_oo.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->key_l = IMG_Load("ressources/wall/key_l.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->exit_l = IMG_Load("ressources/wall/exit_l.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->mean_l = IMG_Load("ressources/wall/mean_l.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->bonus_s = IMG_Load("ressources/wall/bonus_oo.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->bonus_l = IMG_Load("ressources/wall/bonus_l.png")))
		ft_err_exit("doom: error: bad textures", game);
}

void	init_graphic(t_game *game)
{
	if (!(game->gameover = IMG_Load("ressources/gameover.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->sky = IMG_Load("ressources/skybox.tga")))
		ft_err_exit("doom: error: bad textures ciel", game);
	if (!(game->mission_s = IMG_Load("ressources/Mission.tga")))
		ft_err_exit("doom: error: bad textures", game);
}

void	init_thread(t_win *wn, t_game *game)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		game->thread[i].wn = wn;
		i++;
	}
}

void	init_player(t_player *player)
{
	player->position.x = -1;
	player->position.y = -1;
	player->direction = 90;
	player->direction_up = 0;
	player->sensibility = 1;
	player->speed = 0.12;
	player->life = 3;
}

void	init_game(t_win *wn, t_game *game, char *map)
{
	int		i;

	i = 0;
	SDL_SetRelativeMouseMode(SDL_TRUE);
	ft_bzero(game, sizeof(t_game));
	init_thread(wn, game);
	init_player(&game->player);
	init_surface_game(game);
	game->minimap.mnp_size = 20;
	game->mission = 1;
	if (!(game->map = malloc(sizeof(int *) * XBLOC)))
		ft_exit(game);
	while (i < XBLOC)
	{
		if (!(game->map[i++] = malloc(sizeof(int) * YBLOC)))
			ft_exit(game);
	}
	get_map(map, game);
	init_sdl_game(game);
	init_fonts(game);
	game->endinitsdl = 1;
}
