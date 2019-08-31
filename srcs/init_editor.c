/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_editor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 18:04:16 by jsauron           #+#    #+#             */
/*   Updated: 2019/08/25 18:05:09 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

t_win   *init(t_win  *wn)
{
	int i;

	i = 0;
	if (!(wn = malloc(sizeof(t_win ))))
		exit (1);
	if (!(wn->editor = malloc(sizeof(t_editor ))))
		exit (1);
	if (!(wn->editor->map = malloc(sizeof(int *) * XBLOC)))
		exit (1);
	while (i < XBLOC)
		wn->editor->map[i++] = malloc(sizeof(int) * YBLOC);
	init_structure(wn, wn->editor);
	init_sdl(wn);
	return (wn);
}

int init_sdl(t_win *wn)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		ft_sdl_err_exit(0, &wn->game);

	if (!(wn->window = SDL_CreateWindow("DOOM", SDL_WINDOWPOS_UNDEFINED,
	 SDL_WINDOWPOS_UNDEFINED, WIN_W, WIN_H, 0)))
		ft_sdl_err_exit(0, &wn->game);

//	wn->icon =  load_tga("ressources/mechant.png");
//	SDL_SetWindowIcon(wn->window, wn->icon);
	if (!(wn->render = SDL_CreateRenderer(wn->window, -1, 0)))
		ft_sdl_err_exit(0, &wn->game);

	if (!(wn->screen = SDL_CreateRGBSurface(0, WIN_W, WIN_H, 32,
			0x00FF0000,
			0x0000FF00,
			0x000000FF,
			0xFF000000)))
		ft_sdl_err_exit(0, &wn->game);

	if (!(wn->texture = SDL_CreateTexture(wn->render,
			SDL_PIXELFORMAT_ARGB8888,
			SDL_TEXTUREACCESS_STREAMING,
			WIN_W, WIN_H)))
		ft_sdl_err_exit(0, &wn->game);
	return (1);
}

int  init_structure(t_win *wn, t_editor *editor)
{
	wn->menu = load_tga("ressources/menu/menu_back.tga");
	wn->pos_menu.x = 0;
	wn->pos_menu.y = 0;

	wn->pos_game.x = 0;
	wn->pos_game.y = 0;

	wn->pos_menu_mov.x = 120 + 80;
	wn->pos_menu_mov.y = 45;
	editor->nb_goal = 0;
	editor->menu[0] = load_tga("ressources/menu/1.tga");
	editor->menu[1] = load_tga("ressources/menu/2.tga");
	editor->menu[2] = load_tga("ressources/menu/3.tga");
	editor->menu[3] = load_tga("ressources/menu/4.tga");
	editor->menu[4] = load_tga("ressources/menu/5.tga");
	editor->menu[5] = load_tga("ressources/menu/6.tga");
	editor->menu[6] = load_tga("ressources/menu/7.tga");
	editor->menu[7] = load_tga("ressources/menu/8.tga");
	editor->menu[8] = load_tga("ressources/menu/9.tga");
	editor->menu[9] = load_tga("ressources/menu/10.tga");
	editor->wall =  load_tga("ressources/editor/wall3.tga");
	editor->mean =  IMG_Load("ressources/editor/enemy.png");
	editor->goal =  IMG_Load("ressources/editor/exit.png");
	editor->player =  IMG_Load("ressources/editor/player.png");
	editor->editor_surface =  load_tga("ressources/editor/editor_back.tga");
	editor->key =  IMG_Load("ressources/editor/keys.png");
	editor->door =  load_tga("ressources/editor/door_t.tga");
	editor->poster =  load_tga("ressources/editor/poster.tga");

	return (1);
}
