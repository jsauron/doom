/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:05:32 by jsauron           #+#    #+#             */
/*   Updated: 2019/08/21 20:10:32 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include <SDL2/SDL.h>
# include <SDL2/SDL_ttf.h>
# include <SDL2/SDL_image.h>
# include <pthread.h>
# include <time.h>

# define H_GREEN 0x00FF00FF
# define H_RED 0xFF0000FF

# define WIN_H 700
# define WIN_W 1000
# define BLOC_SIZE 200
# define DIST_SCREEN 900

# define ZOOM_P 1.1
# define ZOOM_L 0.9

# define VERTICAL_HIT 1
# define HORIZONTAL_HIT 2

typedef struct s_limit		t_limit;
typedef struct s_pos		t_pos;
typedef struct s_vec		t_vec;
typedef struct s_size		t_size;
typedef struct s_coef		t_coef;
typedef struct s_ray		t_ray;
typedef struct s_thread		t_thread;
typedef struct s_object		t_object;
typedef struct s_sdl		t_sdl;
typedef struct s_player		t_player;
typedef struct s_minimap	t_minimap;
typedef struct s_wn			t_wn;

struct						s_limit
{
	int					t;
	int					b;
	int					l;
	int					r;
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

struct						s_coef
{
	int					x;
	int					y;
};

struct						s_sdl
{
	SDL_Event			event;
	SDL_Window			*window;
	SDL_Renderer		*renderer;
};

struct						s_ray
{
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
	t_data				*data;
	int					x_start;
	t_ray				ray[WIN_W / 8];
};

struct						s_object
{
	SDL_Surface			*img_srf;
};

struct						s_player
{
	t_pos				position;
	double				direction;
	double				direction_up;
	int					cam_height;
	int					visual_field;
	int					sensibility;
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

struct						s_wn
{
	t_sdl				sdl;
	int					endinitsdl;
	TTF_Font			*font;
	int					**map;
	t_object			object[4];
	t_size				map_sz;
	t_player			player;
	t_thread			thread[8];
	SDL_Surface			*surface;
	SDL_Texture			*texture;
	t_minimap			minimap;
	int					texturing;
	int					lightshade;
	int					gamemode;
	int					setting;
	int					dev_mode;
	t_coef				mouse;
	Uint32				time_last;
	int					nb_frame;
	int					fps;

};

void						ft_exit(t_wn *wn);
void						ft_err_exit(char *msg, t_wn *wn);

void						ft_get_map(char *map, t_wn *wn);
void						ft_init_data(char *map, t_wn *wn);

int							ft_movement(double angle_r, int dir, t_wn *wn);
int							ft_movement_gaming(const Uint8 *state,
							t_wn *wn);
int							ft_lateral_gaming(const Uint8 *state,
							t_wn *wn);
int							ft_movement_normal(const Uint8 *state,
							t_wn *wn);
int							ft_rotation_normal(const Uint8 *state,
							t_wn *wn);
int							ft_get_events(t_wn *wn);

int							ft_is_inwall(t_pos *pos, t_wn *wn);
Uint32						ft_get_color(int axis, int angle_d);
void						ft_assign_color(int x, int y,
							int i, t_thread *thread);
void						ft_calc_distance(int i, int x, t_thread *thread);
void						ft_rc_wolfcalc(t_wn *wn);

void						ft_set_infos(t_wn *wn);
void						ft_set_interface(t_wn *wn);
void						ft_minimap(t_wn *wn);

double						ft_pythagore(int a, int b);
void						ft_set_cursor(t_wn *wn);
Uint32						ft_light_shade(double distance, Uint32 color);
void						ft_srfdel(void **ap);
SDL_Color					ft_hex_to_rgb(int hexa);
void						draw_line(t_data *wn, t_vec vec,
							Uint32 color, t_limit *limit);
void						ft_draw_rect(SDL_Rect rect, Uint32 color,
							t_limit *limit, t_wn *wn);
void						ft_draw_border(SDL_Rect rect, Uint32 color,
							t_wn *wn);
SDL_Surface					*ft_new_surface(int height,
							int width, t_wn *wn);
void						ft_set_string(SDL_Rect rect, char *text,
							SDL_Color color, t_wn *wn);
void						ft_setpixel(SDL_Surface *surface,
							int x, int y, Uint32 pixel);
Uint32						ft_getpixel(SDL_Surface *surface,
							int x, int y, t_wn *wn);

#endif
