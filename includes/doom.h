/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 15:13:28 by jsauron           #+#    #+#             */
/*   Updated: 2019/08/25 17:58:10 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_H
# define DOOM_H

# include "libft.h"
# include <SDL2/SDL.h>
# include <SDL2/SDL_ttf.h>
# include <SDL2/SDL_image.h>
# include <pthread.h>
# include <time.h>
# include "editor.h"
# include "tga_reader.h"

# define H_GREEN 0x00FF00FF
# define H_RED 0xFF0000FF
# define WIN_H 750
# define WIN_W 1000
# define BLOC_SIZE 200

# define DIST_SCREEN 900
# define MAP_SIZE 15

# define ZOOM_P 1.1
# define ZOOM_L 0.9

# define VERTICAL_HIT 1
# define HORIZONTAL_HIT 2

typedef struct s_limit		t_limit;
typedef struct s_time		t_time;
typedef struct s_pos		t_pos;
typedef struct s_vec		t_vec;
typedef struct s_size		t_size;
typedef struct s_ray		t_ray;
typedef struct s_thread		t_thread;
typedef struct s_object		t_object;
typedef struct s_player		t_player;
typedef struct s_minimap	t_minimap;
typedef struct s_win			t_win;
typedef struct s_game		t_game;
typedef struct s_rgb		t_rgb;
typedef struct s_sprite	t_sprite;
typedef union  u_color		t_color;

struct        				s_rgb
{
    unsigned char 		    a;
    unsigned char		    r;
    unsigned char		    g;
    unsigned char 		    b;
}; 


union        				u_color
{
    t_rgb		      		rgb;
	int						all;
	unsigned char 			tab[4];
}; 


struct						s_limit
{
	int						t;
	int						b;
	int						l;
	int						r;
};

struct						s_pos
{
	double				x;
	double				y;
};

struct						s_vec
{
	t_pos				p1;
	t_pos				p2;
};

struct						s_size
{
	int					h;
	int					w;
};


struct						s_ray
{
	int					the_door;
	int					the_key;
	int					the_poster;
	int					x;
	int					y;
	int					axis;
	double				angle_d;
	double				distance;
	double				dist_minimap;
	double				wall_top;
	double				wall_bot;
};

struct						s_thread
{
	pthread_t			th;
	t_win				*wn;
	t_game				*game;
	int					x_start;
	t_ray				ray[WIN_W / 8];
};


struct						s_sprite
{

	SDL_Surface			*weapon[3];
//	SDL_Surface			*key_s[6];
	SDL_Surface			*enemy[4];

};

struct						s_player
{
	t_pos				position;
	double				direction;
	double				direction_up;
	int					cam_height;
	int					visual_field;
	int					sensibility;
	int					life;
	double				speed;
};

struct						s_minimap
{
	double				mnp_size;
	t_pos				origin;
	t_limit				limit;
	t_size				map_size;
	t_pos				pos_play;
	t_pos				centre;
	t_pos				diff;
};

struct						s_time
{
	int				current_time;
	int				old_time;

};

struct						s_game
{
	t_time				time;
	t_sprite			sprite;
	SDL_Surface			*wall[4];
	SDL_Surface			*sky;
	SDL_Surface			*heart[3];
	SDL_Surface			*door;
	SDL_Surface			*gameover;
	SDL_Surface			*weapon[2];
	SDL_Surface			*lunette[2];
	SDL_Surface			*keys[6];
	SDL_Surface			*key_s;
	SDL_Surface			*win[12];
	SDL_Surface			*mission_s;
	SDL_Surface			*poster[4];
	int					key;
	SDL_Event			event;
	Uint8				*state;
	int					endinitsdl;
	TTF_Font			*font;
	int					**map;
	t_size				map_sz;
	t_player			player;
	t_thread			thread[8];
	t_minimap			minimap;
//	int					texturing;
	int					lightshade;
	int					gamemode;
	int					setting;
	int					dev_mode;
	int					target;
	int					shot;
	t_mouse				mouse;
	Uint32				time_last;
	int					nb_frame;
	int					fps;
	int					exit;
	int					mission;
};

 struct					s_win
{
	t_game				game;
	SDL_Window			*window;
	SDL_Surface			*screen;
	SDL_Surface			*menu;
	SDL_Surface			*menu_back;
	SDL_Surface			*icon;
	SDL_Rect			pos_menu;
	SDL_Rect			pos_menu_mov;
	SDL_Rect			pos_game;
	SDL_Renderer		*render;
	SDL_Texture			*texture;
	SDL_Event			event;
	Uint8				*state;
	t_mouse				input;
	t_editor			*editor;
};


void						ft_exit(t_game *game);
void						ft_err_exit(char *msg, t_game *game);
void						ft_sdl_err_exit(char *msg, t_game *game);

void						ft_get_map(char *map, t_game *game);
void						ft_init_game(t_win *wn, t_game *game, char *map);

int							ft_movement(double angle_r, int dir,t_game *game);
int							ft_movement_gaming(const Uint8 *state,
	t_game *game);
int							ft_lateral_gaming(const Uint8 *state,
		t_game *game);
int							ft_movement_normal(const Uint8 *state,
		t_game *game);
int							ft_rotation_normal(const Uint8 *state,
		t_game *game);
int							ft_get_events(t_game *game);

int							ft_is_inwall(t_pos *pos, t_game *game, t_ray *ray);
Uint32						ft_get_color(int axis, int angle_d);
void						ft_assign_color(t_win *wn, int x, int y,
		int i, t_thread *thread);
void						ft_calc_distance(int i, int x, t_thread *thread);
void						ft_rc_wolfcalc(t_game *game);

void						ft_set_infos(t_win *wn, t_game *game);
void						ft_set_interface(t_win *wn, t_game *game);
void						ft_minimap(t_win *wn, t_game *game);

double						ft_pythagore(int a, int b);
void						ft_set_cursor(t_win *wn);
Uint32						ft_light_shade(double distance, Uint32 color);
void						ft_srfdel(void **ap);
SDL_Color					ft_hex_to_rgb(int hexa);
void						draw_line(t_win *wn, t_vec vec,
		Uint32 color, t_limit *limit);
void						ft_draw_rect(t_win *wn, SDL_Rect rect, Uint32 color,
		t_limit *limit);
void						ft_draw_border(t_win *wn,  SDL_Rect rect, Uint32 color);
SDL_Surface					*ft_new_surface(int height,
		int width, t_win *wn);
void						ft_set_string(t_win *wn, SDL_Rect rect, char *text,
		SDL_Color color);
void						ft_setpixel(SDL_Surface *surface,
		int x, int y, Uint32 pixel);
Uint32						ft_getpixel(t_win *wn, SDL_Surface *surface,
		int x, int y);
int     render_game(t_win *wn);
int     render_editor(t_win *wn);
void		ft_assign_sprite(t_win *wn, int x, int y, int i, t_thread *thread);
#endif
