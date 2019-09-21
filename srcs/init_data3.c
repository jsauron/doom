/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:01:39 by hben-yah          #+#    #+#             */
/*   Updated: 2019/09/21 19:03:03 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	init_sdl_game(t_game *game)
{
	if (game)
		;
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
