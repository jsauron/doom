
#ifndef EDITOR_H
# define EDITOR_H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "doom.h"

/* constante */

#define SIZE_BLOC	50
#define XBLOC		15
#define YBLOC		15
#define	XSCREEN		SIZE_BLOC * XBLOC
#define YSCREEN		SIZE_BLOC * YBLOC

enum {UP, DOWN, LEFT, RIGHT};
enum {VIDE, WALL, BLOC, GOAL, PLAYER, BLOC_OK};

typedef struct s_win		t_win;

typedef	struct		s_mouse
{
	Uint32	mouse;
	int		x;
	int		y;
}					t_mouse;

typedef struct		s_game
{

	SDL_Surface		*editor;
	SDL_Surface		*menu[10];
	SDL_Surface		*player;
	SDL_Surface		*wall;
	SDL_Surface		*bloc;
	SDL_Surface		*bloc_OK;
	SDL_Surface		*goal;
	SDL_Surface		*current_player;
	int				**map;
	int				nb_goal;
}					t_game;

/* render.c*/
int     fill_screen(t_win *wn,t_game *game, SDL_Rect *pos, SDL_Rect *pos_player,int **map);
int     render(t_win *wn);
int     free_game(t_win *wn, t_game *game);  

/* input.c */

/* editor.c */
void	editor(t_win *wn, t_game *game);

/* file.c */
int		upload_map(int **level);
int		save_level(int **level);

/* jeu.c */
void    move_bloc(int   *first_case, int *second_case);
void    player_move(int **map, SDL_Rect *pos, int direction);
void    active_game(t_win *wn);
int     parse_map(int   **map, SDL_Rect *pos_player);
/* init.c*/
t_win   *init(t_win  *wn);
int			malloc_structure(t_win *wn);
int   init_sdl(t_win *win);
int   init_structure(t_win *wn, t_game *game);

/* main.c */
int		main();


#endif
