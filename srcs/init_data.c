/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:02:56 by jsauron           #+#    #+#             */
/*   Updated: 2019/08/24 19:42:06 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void	ft_sdl_err_exit(char *msg, t_data *data)
{
	ft_putendl(SDL_GetError());
	ft_putendl(TTF_GetError());
	if (data->sdl.renderer)
		SDL_DestroyRenderer(data->sdl.renderer);
	if (data->sdl.window)
		SDL_DestroyWindow(data->sdl.window);
	if (data->font)
		TTF_CloseFont(data->font);
	TTF_Quit();
	SDL_Quit();
	ft_err_exit(msg, data);
}

static void	ft_init_sdl(t_data *data)
{
	data->sdl.window = 0;
	data->sdl.renderer = 0;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		ft_sdl_err_exit(0, data);
	if (TTF_Init() < 0)
		ft_sdl_err_exit(0, data);
	SDL_SetRelativeMouseMode(SDL_TRUE);
	if (!(data->sdl.window = SDL_CreateWindow("DOOM",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIN_W, WIN_H, 0)))
		ft_sdl_err_exit(0, data);
	if (!(data->sdl.renderer = SDL_CreateRenderer(data->sdl.window, -1,
	SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_SOFTWARE)))
		ft_sdl_err_exit(0, data);
	if (SDL_SetRenderDrawBlendMode(data->sdl.renderer, SDL_BLENDMODE_BLEND) < 0)
		ft_sdl_err_exit(0, data);
	SDL_RaiseWindow(data->sdl.window);
}

static void	ft_init_fonts(t_data *data)
{
	if (!(data->font = TTF_OpenFont("ressources/fonts/Arial.ttf", 100)))
		ft_err_exit("wolf3d: error: font failure", data);
}

static void	ft_make_texture(t_data *data)
{
	if (!(data->object[0].img_srf =
	lt_push(IMG_Load("ressources/wall/blue.tga"), ft_srfdel)))
		ft_err_exit("doom: error: bad textures", data);
	if (!(data->object[1].img_srf =
	lt_push(IMG_Load("ressources/wall/pink.tga"), ft_srfdel)))
		ft_err_exit("doom: error: bad textures", data);
	if (!(data->object[2].img_srf =
	lt_push(IMG_Load("ressources/wall/green.tga"), ft_srfdel)))
		ft_err_exit("doom: error: bad textures", data);
	if (!(data->object[3].img_srf =
	lt_push(IMG_Load("ressources/wall/glue.tga"), ft_srfdel)))
		ft_err_exit("doom: error: bad textures", data);
}

void		ft_init_data(char *map, t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->player.position.x = -1;
	data->player.position.y = -1;
	data->player.direction = 90;
	data->player.direction_up = 0;
	data->player.sensibility = 3;
	data->player.speed = 0.12;
	data->minimap.mnp_size = 20;
	ft_get_map(map, data);
	ft_init_sdl(data);
	data->endinitsdl = 1;
	ft_init_fonts(data);
	ft_make_texture(data);
}
