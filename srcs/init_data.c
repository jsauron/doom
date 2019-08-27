/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:02:56 by jsauron           #+#    #+#             */
/*   Updated: 2019/08/25 18:01:52 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

 void	ft_sdl_err_exit(char *msg, t_game *game)
{
	ft_putendl(SDL_GetError());
	ft_putendl(TTF_GetError());
	//if (game->renderer)
		//SDL_DestroyRenderer(game->renderer);
	//if (game->window)
		//SDL_DestroyWindow(game->window);
	if (game->font)
		TTF_CloseFont(game->font);
	TTF_Quit();
	SDL_Quit();
	ft_err_exit(msg, game);
}

static void	init_sdl_game(t_game *game)
{
	if (TTF_Init() < 0)
		ft_sdl_err_exit(0, game);

	SDL_SetRelativeMouseMode(SDL_TRUE);

/*	if (!(wn->screen = SDL_CreateRGBSurface(0, WIN_W, WIN_H, 32,
			0x00FF0000,
			0x0000FF00,
			0x000000FF,
			0xFF000000)))
		ft_sdl_err_exit(0, game);
*/
}

static void	init_fonts(t_game *game)
{
	if (!(game->font = TTF_OpenFont("ressources/fonts/Arial.ttf", 100)))
		ft_err_exit("wolf3d: error: font failure", game);
}

static void	init_wall(t_game *game)
{
	if (!(game->wall[0] = IMG_Load("ressources/wall/blue.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->wall[1] = IMG_Load("ressources/wall/pink.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->wall[2] = IMG_Load("ressources/wall/croco.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->wall[3] = IMG_Load("ressources/wall/glue.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->door[0] = IMG_Load("ressources/wall/door.tga")))
		ft_err_exit("doom: error: bad textures", game);

}

void		ft_init_game(t_win *wn,  t_game *game , char *map)
{
  int i = 0; 

	ft_bzero(game, sizeof(t_game));
	while (i < 8)
	{
		game->thread[i].wn = wn;
		i++;
	}
	game->player.position.x = -1;
	game->player.position.y = -1;
	game->player.direction = 90;
	game->player.direction_up = 0;
	game->player.sensibility = 3;
	game->player.speed = 0.12;
	game->minimap.mnp_size = 20;
	game->door_in = 0;
  if (!(game->map = malloc(sizeof(int *) * XBLOC)))
      exit (1);
	  i = 0;
  while (i < XBLOC)
        game->map[i++] = malloc(sizeof(int) * YBLOC);
	ft_get_map(map, game);
	init_sdl_game(game);
	game->endinitsdl = 1;
	init_fonts(game);
	init_wall(game);
}
