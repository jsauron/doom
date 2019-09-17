/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <jsauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 15:13:28 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/17 14:59:09 by jsauron          ###   ########.fr       */
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

# define N_VIDE '0'
# define N_WALL '1'
# define N_MEAN '2'
# define N_EXIT '3'
# define N_PLAYER '4'
# define N_KEY '5'
# define N_DOOR '6'
# define N_POSTER '7'


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


typedef enum   e_entity		t_entity;
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

enum  e_entity {SP_KEY, SP_MEAN, SP_EXIT};

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
	int					the_mean;
	int					the_exit;
	int					x;
	int					y;
	int					a;
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
	t_entity			entity;
	SDL_Surface				*sprite;
	SDL_Rect				pos;
	SDL_Rect				pos_map;
	SDL_Rect				size;
	double					distance;
	int						actif;
	int					id;
	int					left_life;
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
	int					n;
	t_time				time;
	t_sprite			*sprite;
	SDL_Surface			*wall[4];
	SDL_Surface			*sky;
	SDL_Surface			*heart[3];
	SDL_Surface			*hit_contact;
	SDL_Surface			*door;
	SDL_Surface			*gameover;
	SDL_Surface			*weapon[2];
	SDL_Surface			*lunette[2];
	SDL_Surface			*keys[6];
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
	int					map_exit;
	int					mission;
	SDL_Surface			*exit_s;
	SDL_Surface			*key_s;
	SDL_Surface			*mean_s;
	int					touch;
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

int							set_sprites(t_win *wn);
void						ft_exit(t_game *game);
void						ft_err_exit(char *msg, t_game *game);
void						ft_sdl_err_exit(char *msg, t_game *game);

void						get_map(char *map, t_game *game);
void						init_game(t_win *wn, t_game *game, char *map);

int							movement(double angle_r, int dir,t_game *game);
int							movement_gaming(const Uint8 *state,
	t_game *game);
int							lateral_gaming(const Uint8 *state,
		t_game *game);
int							movement_normal(const Uint8 *state,
		t_game *game);
int							ft_rotation_normal(const Uint8 *state,
		t_game *game);
int							get_events(t_game *game);

int							is_inwall(t_pos *pos, t_game *game, t_ray *ray);
Uint32						get_color(int axis, int angle_d);
void						assign_color(t_thread *thread, int x, int y,
		int i);
void						calc__distance(int i, int x, t_thread *thread);
void						rc_wolfcalc(t_game *game);

void						set_infos(t_win *wn, t_game *game);
void						set_interface(t_win *wn, t_game *game);
void						minimap(t_win *wn, t_game *game);

double						pythagore(int a, int b);
void						set_cursor(t_win *wn);
Uint32						light_shade(double distance, Uint32 color);
void						srfdel(void **ap);
SDL_Color					hex_to_rgb(int hexa);
void						draw_line(t_win *wn, t_vec vec,
		Uint32 color, t_limit *limit);
void						draw_rect(t_win *wn, SDL_Rect rect, Uint32 color,
		t_limit *limit);
void						draw_border(t_win *wn,  SDL_Rect rect, Uint32 color);
SDL_Surface					*ft_new_surface(int height,
		int width, t_win *wn);
void						set_string(t_win *wn, SDL_Rect rect, char *text,
		SDL_Color color);
void						setpixel(SDL_Surface *surface,
		int x, int y, Uint32 pixel);
Uint32						ft_getpixel(t_win *wn, SDL_Surface *surface,
		int x, int y);
int     render_game(t_win *wn);
int     render_editor(t_win *wn);
int		check_sprite(t_game *game);
int	set_key_sprite(t_game *game, int x, int y);
int	set_exit_sprite(t_game *game, int x, int y);
int	set_mean_sprite(t_game *game, int x, int y);
/* init_data.c */
void	sdl_err_exit(char *msg, t_game *game);
void	init_sdl_game(t_game *game);
void	init_fonts(t_game *game);
void	init_surface_game(t_game *game);
void	init_wall(t_game *game);
void	init_keys(t_game *game);
void	init_hud(t_game *game);
void	init_win_menu(t_game *game);
void	init_poster(t_game *game);
void	init_weapon(t_game *game);
void	init_sprite(t_game *game);
void	init_graphic(t_game *game);
void	init_thread(t_win *wn, t_game *game);
void	init_player(t_player *player);
void	init_game(t_win *wn,  t_game *game , char *map);
int		search_sprite(t_game *game, int id);
int		range_sprite(t_sprite *sprite, int n);
int	set_distance_sprite(t_game *game, t_ray *ray, int n, int x);
#endif
