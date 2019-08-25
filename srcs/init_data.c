/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:02:56 by jsauron           #+#    #+#             */
/*   Updated: 2019/08/25 17:14:46 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void	ft_sdl_err_exit(char *msg, t_game *game)
{
	ft_putendl(SDL_GetError());
	ft_putendl(TTF_GetError());
	if (game->sdl.renderer)
		SDL_DestroyRenderer(game->sdl.renderer);
	if (game->sdl.window)
		SDL_DestroyWindow(game->sdl.window);
	if (game->font)
		TTF_CloseFont(game->font);
	TTF_Quit();
	SDL_Quit();
	ft_err_exit(msg, game);
}

static void	ft_init_sdl(t_game *game)
{
	game->sdl.window = 0;
	game->sdl.renderer = 0;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		ft_sdl_err_exit(0, game);
	if (TTF_Init() < 0)
		ft_sdl_err_exit(0, game);
	SDL_SetRelativeMouseMode(SDL_TRUE);
	if (!(game->sdl.window = SDL_CreateWindow("DOOM",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIN_W, WIN_H, 0)))
		ft_sdl_err_exit(0, game);
	if (!(game->sdl.renderer = SDL_CreateRenderer(game->sdl.window, -1,
	SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_SOFTWARE)))
		ft_sdl_err_exit(0, game);
	if (SDL_SetRenderDrawBlendMode(game->sdl.renderer, SDL_BLENDMODE_BLEND) < 0)
		ft_sdl_err_exit(0, game);
	SDL_RaiseWindow(game->sdl.window);
}

static void	ft_init_fonts(t_game *game)
{
	if (!(game->font = TTF_OpenFont("ressources/fonts/Arial.ttf", 100)))
		ft_err_exit("wolf3d: error: font failure", game);
}

static void	ft_make_texture(t_game *game)
{
	if (!(game->object[0].img_srf = load_tga("ressources/wall/blue.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->object[1].img_srf = load_tga("ressources/wall/pink.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->object[2].img_srf = load_tga("ressources/wall/green.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->object[3].img_srf = load_tga("ressources/wall/glue.tga")))
		ft_err_exit("doom: error: bad textures", game);
}

void		ft_init_game(char *map, t_game *game)
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
	ft_init_sdl(game);
	game->endinitsdl = 1;
	ft_init_fonts(game);
	ft_make_texture(game);
}
