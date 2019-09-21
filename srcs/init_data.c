/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <jsauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:33:04 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/21 16:15:47 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	init_sdl_game(t_game *game)
{
	(void)game;
	if (TTF_Init() < 0)
		SDL_SetRelativeMouseMode(SDL_TRUE);
}

void	init_fonts(t_game *game)
{
	if (!(game->font = TTF_OpenFont("ressources/fonts/Arial.ttf", 100)))
		ft_err_exit("Doom: error: font failure", game);
}

void	init_surface_game(t_game *game)
{
	init_wall(game);
	init_keys(game);
	init_hud(game);
	init_win_menu(game);
	init_poster(game);
	init_weapon(game);
	init_sprite(game);
	init_graphic(game);
}

void	init_music(t_game *game)
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS,
	1024) == -1)
		sdl_err_exit(0, NULL);
	Mix_AllocateChannels(5);
	if (!(game->music.mood = Mix_LoadMUS("ressources/music/makeba.wav")))
		ft_err_exit("Doom: error: mood music fail", game);
	if (!(game->music.youwin = Mix_LoadWAV("ressources/music/winner.wav")))
		ft_err_exit("Doom: error: mood music win", game);
	if (!(game->music.shot = Mix_LoadWAV("ressources/music/shot.wav")))
		ft_err_exit("Doom: error: shot music fail", game);
	if (!(game->music.dead = Mix_LoadWAV("ressources/music/dead.wav")))
		ft_err_exit("Doom: error: dead music fail", game);
	if (!(game->music.gameover = Mix_LoadWAV("ressources/music/gameover.wav")))
		ft_err_exit("Doom: error: gameover music fail", game);
	if (!(game->music.key = Mix_LoadWAV("ressources/music/coins.wav")))
		ft_err_exit("Doom: error: key music fail", game);
	if (!(game->music.open_door = Mix_LoadWAV("ressources/music/door.wav")))
		ft_err_exit("Doom: error: open_door music fail", game);
}

void	init_wall(t_game *game)
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
}

void	init_keys(t_game *game)
{
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
}

void	init_hud(t_game *game)
{
	if (!(game->heart[0] = IMG_Load("ressources/heart.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->heart[1] = IMG_Load("ressources/heart.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->heart[2] = IMG_Load("ressources/heart.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->hit_contact = IMG_Load("ressources/coutour_hit.png")))
		ft_err_exit("doom: error: bad textures hit contact", game);
}

void	init_win_menu(t_game *game)
{
	if (!(game->win[0] = IMG_Load("ressources/win2.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[1] = IMG_Load("ressources/win3.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[2] = IMG_Load("ressources/win4.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[3] = IMG_Load("ressources/win5.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[4] = IMG_Load("ressources/win6.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[5] = IMG_Load("ressources/win7.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[6] = IMG_Load("ressources/win8.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[7] = IMG_Load("ressources/win9.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[8] = IMG_Load("ressources/win10.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[9] = IMG_Load("ressources/win11.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[10] = IMG_Load("ressources/win12.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[11] = IMG_Load("ressources/win13.tga")))
		ft_err_exit("doom: error: bad textures", game);
}

void	init_poster(t_game *game)
{
	if (!(game->poster[0] = IMG_Load("ressources/wall/poster1.tga")))
		ft_err_exit("doom: error: bad textures p1", game);
	if (!(game->poster[1] = IMG_Load("ressources/wall/poster2.tga")))
		ft_err_exit("doom: error: bad textures p2", game);
	if (!(game->poster[2] = IMG_Load("ressources/wall/poster3.tga")))
		ft_err_exit("doom: error: bad textures p3", game);
	if (!(game->poster[3] = IMG_Load("ressources/wall/poster4.tga")))
		ft_err_exit("doom: error: bad textures p4", game);
}

void	init_weapon(t_game *game)
{
	if (!(game->weapon[0] = IMG_Load("ressources/arme_3.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->weapon[1] = IMG_Load("ressources/arme_tir.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->lunette[0] = IMG_Load("ressources/lunette.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->lunette[1] = IMG_Load("ressources/lunette_tir.png")))
		ft_err_exit("doom: error: bad textures", game);
}

void	init_sprite(t_game *game)
{
	if (!(game->key_s = IMG_Load("ressources/wall/key_oo.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->exit_s = IMG_Load("ressources/wall/exit_oo.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->mean_s = IMG_Load("ressources/wall/mean_oo.png")))
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
		exit(1);
	while (i < XBLOC)
		game->map[i++] = malloc(sizeof(int) * YBLOC);
	get_map(map, game);
	init_sdl_game(game);
	init_music(game);
	init_fonts(game);
	init_wall(game);
	game->endinitsdl = 1;
}
