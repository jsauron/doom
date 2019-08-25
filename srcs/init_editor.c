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
	SDL_Init(SDL_INIT_VIDEO);

	wn->window = SDL_CreateWindow("DOOM", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, XSCREEN, YSCREEN, 0);
//	wn->icon =  load_tga("ressources/mechant.png");
	SDL_SetWindowIcon(wn->window, wn->icon);
	wn->render = SDL_CreateRenderer(wn->window, -1, 0);
	wn->screen = SDL_CreateRGBSurface(0, XSCREEN, YSCREEN, 32,
			0x00FF0000,
			0x0000FF00,
			0x000000FF,
			0xFF000000);
	wn->texture = SDL_CreateTexture(wn->render,
			SDL_PIXELFORMAT_ARGB8888,
			SDL_TEXTUREACCESS_STREAMING,
			XSCREEN, YSCREEN);
	return (1);
}

int  init_structure(t_win *wn, t_editor *editor)
{
	wn->menu = load_tga("ressources/menu/menu_4.tga");
	wn->pos_menu.x = 0;
	wn->pos_menu.y = 0;

	wn->pos_menu_mov.x = 83;
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
	editor->mean =  load_tga("ressources/editor/mean_t.tga");
	editor->goal =  load_tga("ressources/editor/exit.tga");
	editor->player =  load_tga("ressources/editor/player.tga");
	editor->editor_surface =  load_tga("ressources/editor/floor2.tga");
	editor->key =  load_tga("ressources/editor/key_t.tga");
	editor->door =  load_tga("ressources/editor/door_t.tga");

	/*  game->player_tab[LEFT] = IMG_Load("sprites_mario/mario_gauche.gif");
		game->player_tab[RIGHT] = IMG_Load("sprites_mario/mario_droite.gif");
		game->player_tab[DOWN] = IMG_Load("sprites_mario/mario_bas.gif");
		game->player_tab[UP] = IMG_Load("sprites_mario/mario_haut.gif");
		game->current_player = game->player_tab[RIGHT];*/
	return (1);
}
