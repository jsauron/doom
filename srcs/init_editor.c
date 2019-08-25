#include "doom.h"

t_win   *init(t_win  *wn)
{
	int i;

	i = 0;
	if (!(wn = malloc(sizeof(t_win ))))
		exit (1);
	if (!(wn->game = malloc(sizeof(t_game ))))
		exit (1);
	if (!(wn->game->map = malloc(sizeof(int *) * XBLOC)))
		exit (1);
	while (i < XBLOC)
		wn->game->map[i++] = malloc(sizeof(int) * YBLOC);
	init_structure(wn, wn->game);
	init_sdl(wn);
	return (wn);
}

int init_sdl(t_win *wn)
{
	SDL_Init(SDL_INIT_VIDEO);

	wn->window = SDL_CreateWindow("DOOM", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, XSCREEN, YSCREEN, 0);
	wn->icon =  load_tga("ressources/mechant.png");
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

int  init_structure(t_win *wn, t_game *game)
{
	wn->menu = load_tga("ressources/menu/menu_4.tga");
	wn->pos_menu.x = 0;
	wn->pos_menu.y = 0;

	wn->pos_menu_mov.x = 83;
	wn->pos_menu_mov.y = 45;
	game->nb_goal = 0;
	game->menu[0] = load_tga("ressources/menu/1.tga");
	game->menu[1] = load_tga("ressources/menu/2.tga");
	game->menu[2] = load_tga("ressources/menu/3.tga");
	game->menu[3] = load_tga("ressources/menu/4.tga");
	game->menu[4] = load_tga("ressources/menu/5.tga");
	game->menu[5] = load_tga("ressources/menu/6.tga");
	game->menu[6] = load_tga("ressources/menu/7.tga");
	game->menu[7] = load_tga("ressources/menu/8.tga");
	game->menu[8] = load_tga("ressources/menu/9.tga");
	game->menu[9] = load_tga("ressources/menu/10.tga");
	game->wall =  load_tga("ressources/editor/wall3.tga");
	game->mean =  load_tga("ressources/editor/mean_t.tga");
	game->goal =  load_tga("ressources/editor/exit.tga");
	game->player =  load_tga("ressources/editor/player.tga");
	game->editor =  load_tga("ressources/editor/floor2.tga");
	game->key =  load_tga("ressources/editor/key_t.tga");
	game->door =  load_tga("ressources/editor/door_t.tga");

	/*  game->player_tab[LEFT] = IMG_Load("sprites_mario/mario_gauche.gif");
		game->player_tab[RIGHT] = IMG_Load("sprites_mario/mario_droite.gif");
		game->player_tab[DOWN] = IMG_Load("sprites_mario/mario_bas.gif");
		game->player_tab[UP] = IMG_Load("sprites_mario/mario_haut.gif");
		game->current_player = game->player_tab[RIGHT];*/
	return (1);
}
