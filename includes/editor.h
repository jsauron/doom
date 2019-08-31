
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
enum {VIDE, WALL, MEAN, GOAL, PLAYER, KEY, DOOR, POSTER};

typedef struct s_win		t_win;

typedef	struct		s_mouse
{
	Uint32	mouse;
	int		x;
	int		y;
}					t_mouse;

typedef struct		s_editor
{

	SDL_Surface		*editor_surface;
	SDL_Surface		*key;
	SDL_Surface		*door;
	SDL_Surface		*menu[10];
	SDL_Surface		*weapon[3];
	SDL_Surface		*player;
	SDL_Surface		*wall;
	SDL_Surface		*mean;
	SDL_Surface		*goal;
	SDL_Surface			*editor_back;
	SDL_Surface			*poster;
//	SDL_Surface		*current_player;
	int				**map;
	int				nb_goal;
}					t_editor;

/* render.c*/
int     fill_screen(t_win *wn, t_editor *editor, SDL_Rect *pos, SDL_Rect *pos_player,int **map);
int     render(t_win *wn);
int     free_surface_editor(t_win *wn, t_editor *editor);  

/* input.c */

/* editor.c */
void	editor(t_win *wn, t_editor *editor, char *map);

/* file.c */
int		upload_map(int **map, char *input_map);
int		save_map(int **map, char *input_map);

/* jeu.c */
void    move_bloc(int   *first_case, int *second_case);
void    player_move(int **map, SDL_Rect *pos, int direction);
void    active_game(t_win *wn);
int     parse_map(int   **map, SDL_Rect *pos_player);
/* init.c*/
t_win   *init(t_win  *wn);
int			malloc_structure(t_win *wn);
int   init_sdl(t_win *win);
int   init_structure(t_win *wn, t_editor *editor);

/* main.c */
int		main();


#endif
