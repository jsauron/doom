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
	if (game->renderer)
		SDL_DestroyRenderer(game->renderer);
	if (game->window)
		SDL_DestroyWindow(game->window);
	if (game->font)
		TTF_CloseFont(game->font);
	TTF_Quit();
	SDL_Quit();
	ft_err_exit(msg, game);
}

static void	init_sdl_game(t_game *game)
{
	game->window = 0;
	game->renderer = 0;
	if (TTF_Init() < 0)
		ft_sdl_err_exit(0, game);

//	SDL_SetRelativeMouseMode(SDL_TRUE);

	if (!(game->window = SDL_CreateWindow("DOOM",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIN_W, WIN_H, 0)))
		ft_sdl_err_exit(0, game);

	if (!(game->renderer = SDL_CreateRenderer(game->window, -1,
	/*SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_SOFTWARE*/ 0)))
		ft_sdl_err_exit(0, game);

	if (!(game->screen = SDL_CreateRGBSurface(0, WIN_W, WIN_H, 32,
			0x00FF0000,
			0x0000FF00,
			0x000000FF,
			0xFF000000)))
		ft_sdl_err_exit(0, game);

		if (!(game->texture = SDL_CreateTexture(game->renderer,
			SDL_PIXELFORMAT_ARGB8888,
			SDL_TEXTUREACCESS_STREAMING,
			WIN_W, WIN_H)))
		ft_sdl_err_exit(0, game);

//	if (SDL_SetRenderDrawBlendMode(game->renderer, SDL_BLENDMODE_BLEND) < 0)
	//	ft_sdl_err_exit(0, game);
	//SDL_RaiseWindow(game->window);
}

static void	init_fonts(t_game *game)
{
	if (!(game->font = TTF_OpenFont("ressources/fonts/Arial.ttf", 100)))
		ft_err_exit("wolf3d: error: font failure", game);
}

static void	init_wall(t_game *game)
{
	if (!(game->wall[0] = load_tga("ressources/wall/blue.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->wall[1] = load_tga("ressources/wall/pink.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->wall[2] = load_tga("ressources/wall/green.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->wall[3] = load_tga("ressources/wall/glue.tga")))
		ft_err_exit("doom: error: bad textures", game);
}

void		ft_init_game( t_game *game , char *map)
{
  int i = 0; 

	ft_bzero(game, sizeof(t_game));
	game->player.position.x = -1;
	game->player.position.y = -1;
	game->player.direction = 90;
	game->player.direction_up = 0;
	game->player.sensibility = 3;
	game->player.speed = 0.12;
	game->minimap.mnp_size = 20;
  if (!(game->map = malloc(sizeof(int *) * XBLOC)))
      exit (1);
  while (i < XBLOC)
        game->map[i++] = malloc(sizeof(int) * YBLOC);
	ft_get_map(map, game);
	init_sdl_game(game);
	game->endinitsdl = 1;
	init_fonts(game);
	init_wall(game);
}
