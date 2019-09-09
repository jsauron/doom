/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_editor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 18:04:16 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/09 17:34:27 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	init_editor(t_editor *editor)
{
	editor->right_click = 0;
	editor->left_click = 0;
	editor->current_obj = WALL;
	editor->pos.x = 0;
	editor->pos.y = 0;
	return ;
}

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

	//	wn->icon =  IMG_Load("ressources/mechant.png");
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
	wn->menu = IMG_Load("ressources/menu/menu_back.tga");
	wn->pos_menu.x = 0;
	wn->pos_menu.y = 0;

	wn->pos_game.x = 0;
	wn->pos_game.y = 0;

	wn->pos_menu_mov.x = 120 + 80;
	wn->pos_menu_mov.y = 45;
	editor->nb_goal = 0;
	editor->menu[0] = IMG_Load("ressources/menu/1.tga");
	editor->menu[1] = IMG_Load("ressources/menu/2.tga");
	editor->menu[2] = IMG_Load("ressources/menu/3.tga");
	editor->menu[3] = IMG_Load("ressources/menu/4.tga");
	editor->menu[4] = IMG_Load("ressources/menu/5.tga");
	editor->menu[5] = IMG_Load("ressources/menu/6.tga");
	editor->menu[6] = IMG_Load("ressources/menu/7.tga");
	editor->menu[7] = IMG_Load("ressources/menu/8.tga");
	editor->menu[8] = IMG_Load("ressources/menu/9.tga");
	editor->menu[9] = IMG_Load("ressources/menu/10.tga");
	editor->obj.wall =  IMG_Load("ressources/editor/wall3.tga");
	editor->obj.mean =  IMG_Load("ressources/editor/enemy.png");
	editor->obj.goal =  IMG_Load("ressources/editor/exit.png");
	editor->obj.player =  IMG_Load("ressources/editor/player.png");
	editor->editor_surface =  IMG_Load("ressources/editor/editor_back.tga");
	editor->obj.key =  IMG_Load("ressources/editor/keys.png");
	editor->obj.door =  IMG_Load("ressources/editor/door_t.tga");
	editor->obj.poster =  IMG_Load("ressources/editor/poster.tga");

	return (1);
}
