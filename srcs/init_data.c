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
	if (!(game->door = IMG_Load("ressources/wall/door.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->heart[0] = IMG_Load("ressources/heart.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->heart[1] = IMG_Load("ressources/heart.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->heart[2] = IMG_Load("ressources/heart.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->gameover = IMG_Load("ressources/gameover.png")))
		ft_err_exit("doom: error: bad textures", game);
//	if (!(game->weapon[0] = IMG_Load("ressources/arme_1.png")))
		//ft_err_exit("doom: error: bad textures", game);
	if (!(game->sky = load_tga("ressources/skybox.tga")))
		ft_err_exit("doom: error: bad textures ciel", game);
	if (!(game->weapon[0] = IMG_Load("ressources/arme_3.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->weapon[1] = IMG_Load("ressources/arme_tir.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->keys[0] = IMG_Load("ressources/key.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->keys[1] = IMG_Load("ressources/key2.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->keys[2] = IMG_Load("ressources/key3.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->keys[3] = IMG_Load("ressources/key6.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->keys[4] = IMG_Load("ressources/key7.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->keys[5] = IMG_Load("ressources/key8.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->key_s = IMG_Load("ressources/wall/key_oo.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->exit_s = IMG_Load("ressources/wall/exit_oo.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->mean_s = IMG_Load("ressources/wall/mean_oo.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->lunette[0] = IMG_Load("ressources/lunette.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->lunette[1] = IMG_Load("ressources/lunette_tir.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[0] = load_tga("ressources/win2.tga")))
		 ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[1] = load_tga("ressources/win3.tga")))
		 ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[2] = load_tga("ressources/win4.tga")))
		 ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[3] = load_tga("ressources/win5.tga")))
		 ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[4] = load_tga("ressources/win6.tga")))
		 ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[5] = load_tga("ressources/win7.tga")))
		 ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[6] = load_tga("ressources/win8.tga")))
		 ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[7] = load_tga("ressources/win9.tga")))
		 ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[8] = load_tga("ressources/win10.tga")))
		 ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[9] = load_tga("ressources/win11.tga")))
		 ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[10] = load_tga("ressources/win12.tga")))
		 ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[11] = load_tga("ressources/win13.tga")))
		 ft_err_exit("doom: error: bad textures", game);
	if (!(game->mission_s = IMG_Load("ressources/Mission.tga")))
		 ft_err_exit("doom: error: bad textures", game);
	if (!(game->poster[0]= IMG_Load("ressources/wall/poster1.tga")))
		 ft_err_exit("doom: error: bad textures p1", game);
	if (!(game->poster[1] = IMG_Load("ressources/wall/poster2.tga")))
		 ft_err_exit("doom: error: bad textures p2", game);
	if (!(game->poster[2] = IMG_Load("ressources/wall/poster3.tga")))
		 ft_err_exit("doom: error: bad textures p3", game);
	if (!(game->poster[3] = IMG_Load("ressources/wall/poster4.tga")))
		 ft_err_exit("doom: error: bad textures p4", game);
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
	game->player.sensibility = 1;
	game->player.speed = 0.12;
	game->minimap.mnp_size = 20;
	game->player.life = 3;
	game->key = 0;
	game->mission = 1;
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
