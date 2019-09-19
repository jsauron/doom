/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_editor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <jsauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:33:18 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/19 22:04:37 by jsauron          ###   ########.fr       */
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
}

t_win	*init(t_win *wn)
{
	int i;

	i = 0;
	if (!(wn->editor = malloc(sizeof(t_editor ))))
		exit(1);
	if (!(wn->editor->map = malloc(sizeof(int *) * XBLOC)))
		exit(1);
	while (i < XBLOC)
		wn->editor->map[i++] = malloc(sizeof(int) * YBLOC);
	init_structure(wn, wn->editor);
	init_sdl(wn);
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
		sdl_err_exit(0, NULL);
	
	return (wn);
}

int		init_sdl(t_win *wn)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		sdl_err_exit(0, &wn->game);
	if (!(wn->window = SDL_CreateWindow("DOOM", SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED, WIN_W, WIN_H, 0)))
		sdl_err_exit(0, &wn->game);
	if (!(wn->render = SDL_CreateRenderer(wn->window, -1, 0)))
		sdl_err_exit(0, &wn->game);
	if (!(wn->screen = SDL_CreateRGBSurface(0, WIN_W, WIN_H, 32,
					0x00FF0000,
					0x0000FF00,
					0x000000FF,
					0xFF000000)))
		sdl_err_exit(0, &wn->game);
	if (!(wn->texture = SDL_CreateTexture(wn->render,
					SDL_PIXELFORMAT_ARGB8888,
					SDL_TEXTUREACCESS_STREAMING,
					WIN_W, WIN_H)))
		sdl_err_exit(0, &wn->game);
	return (1);
}

void	init_surface_menu(t_editor *editor)
{
	if (!(editor->menu[0] = IMG_Load("ressources/menu/1.tga")))
		ft_err_exit("doom: error: bad textures init_surface_menu", NULL);
	if (!(editor->menu[1] = IMG_Load("ressources/menu/2.tga")))
		ft_err_exit("doom: error: bad textures init_surface_menu", NULL);
	if (!(editor->menu[2] = IMG_Load("ressources/menu/3.tga")))
		ft_err_exit("doom: error: bad textures init_surface_menu", NULL);
	if (!(editor->menu[3] = IMG_Load("ressources/menu/4.tga")))
		ft_err_exit("doom: error: bad textures init_surface_menu", NULL);
	if (!(editor->menu[4] = IMG_Load("ressources/menu/5.tga")))
		ft_err_exit("doom: error: bad textures init_surface_menu", NULL);
	if (!(editor->menu[5] = IMG_Load("ressources/menu/6.tga")))
		ft_err_exit("doom: error: bad textures init_surface_menu", NULL);
	if (!(editor->menu[6] = IMG_Load("ressources/menu/7.tga")))
		ft_err_exit("doom: error: bad textures init_surface_menu", NULL);
	if (!(editor->menu[7] = IMG_Load("ressources/menu/8.tga")))
		ft_err_exit("doom: error: bad textures init_surface_menu", NULL);
	if (!(editor->menu[8] = IMG_Load("ressources/menu/9.tga")))
		ft_err_exit("doom: error: bad textures init_surface_menu", NULL);
	if (!(editor->menu[9] = IMG_Load("ressources/menu/10.tga")))
		ft_err_exit("doom: error: bad textures init_surface_menu", NULL);
}

void	init_structure_obj(t_editor *editor)
{
	if (!(editor->editor_surface = IMG_Load("ressources/editor/editor_back.tga")))
		ft_err_exit("doom: error: bad textures init_structure_obj", NULL);
	if (!(editor->obj.wall = IMG_Load("ressources/editor/wall3.tga")))
		ft_err_exit("doom: error: bad textures init_structure_obj", NULL);
	if (!(editor->obj.mean = IMG_Load("ressources/editor/enemy.png")))
		ft_err_exit("doom: error: bad textures init_structure_obj", NULL);
	if (!(editor->obj.goal = IMG_Load("ressources/editor/exit.png")))
		ft_err_exit("doom: error: bad textures init_structure_obj", NULL);
	if (!(editor->obj.player = IMG_Load("ressources/editor/player.png")))
		ft_err_exit("doom: error: bad textures init_structure_obj", NULL);
	if (!(editor->obj.key = IMG_Load("ressources/editor/keys.png")))
		ft_err_exit("doom: error: bad textures init_structure_obj", NULL);
	if (!(editor->obj.door = IMG_Load("ressources/editor/door_t.tga")))
		ft_err_exit("doom: error: bad textures init_structure_obj", NULL);
	if (!(editor->obj.poster = IMG_Load("ressources/editor/poster.tga")))
		ft_err_exit("doom: error: bad textures init_structure_obj", NULL);
}

int		init_structure(t_win *wn, t_editor *editor)
{
	if (!(wn->menu = IMG_Load("ressources/menu/menu_back.tga")))
		ft_err_exit("doom: error: bad textures init_menu_back", NULL);
	wn->pos_menu.x = 0;
	wn->pos_menu.y = 0;
	wn->pos_game.x = 0;
	wn->pos_game.y = 0;
	wn->pos_menu_mov.x = 120 + 80;
	wn->pos_menu_mov.y = 45;
	editor->nb_goal = 0;
	init_surface_menu(editor);
	init_structure_obj(editor);
	return (1);
}
