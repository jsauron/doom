/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:33:44 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/21 16:35:07 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void		make_frame(t_win *wn, t_game *game)
{
	SDL_Rect	pos;
	int			i;

	i = (int)(((int)(game->player.direction)));
	pos.x = -(i * 3000 / 360);
	pos.y = 0;
	game->nb_frame++;
	game->time_last = clock();
	SDL_BlitSurface(wn->game.sky, NULL, wn->screen, &(pos));
	rc_wolfcalc(game);
	check_sprite(game);
	if (clock() != 0 && (1000 - game->time_last / 10000) != 0
			&& (clock() / 10000 - game->time_last / 10000))
		game->fps = 1000 / (clock() / 10000 - game->time_last / 10000);
	render_game(wn);
}

static void		game_loop(t_win *wn, t_game *game)
{
	int play;

	play = 1;
	Mix_PlayMusic(game->music.mood, -1);
	make_frame(wn, game);
	while (play)
	{
		play = get_events(game);
		if (play > 0)
		{
			game->time.current_time = SDL_GetTicks();
			if ((SDL_RenderClear(wn->render)) != 0)
				ft_err_exit("doom: error: RenderClear failure", game);
			make_frame(wn, game);
		}
		SDL_FlushEvent(SDL_KEYDOWN | SDL_MOUSEMOTION);
	}
	free_music(&game->music);
}

void			display_anim_menu(t_win *wn)
{
	int			current_time;
	static int	old_time;
	static int	c;
	static int	i;

	current_time = SDL_GetTicks();
	if (current_time - old_time > 200)
	{
		if (i == 9 || i == 0)
			c++;
		if (c % 2 == 0)
			i--;
		else if (c % 2 != 0)
			i++;
		old_time = current_time;
	}
	SDL_BlitSurface(wn->menu, NULL, wn->screen, &(wn->pos_menu));
	SDL_BlitSurface(wn->editor->menu[i], NULL,
			wn->screen, &(wn->pos_menu_mov));
}

int				start(t_win *wn, char **argv)
{
	SDL_SetRelativeMouseMode(SDL_TRUE);
	wn->state = (Uint8*)SDL_GetKeyboardState(NULL);
	while (1)
	{
		SDL_PollEvent(&(wn->event));
		if (wn->event.type == SDL_QUIT || wn->state[SDL_SCANCODE_ESCAPE])
			break ;
		else if (wn->state[SDL_SCANCODE_1] && argv[1])
		{
			init_game(wn, &wn->game, argv[1]);
			game_loop(wn, &wn->game);
			SDL_WaitEvent(&(wn->event));
		}
		else if (wn->state[SDL_SCANCODE_2])
		{
			SDL_SetRelativeMouseMode(SDL_FALSE);
			editor(wn, wn->editor, argv[1]);
			SDL_WaitEvent(&(wn->event));
		}
		display_anim_menu(wn);
		render_editor(wn);
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_win			wn;

	if (argc != 2)
	{
		ft_putendl_fd("[->] usage: ./doom [map]", 2);
		ft_putendl_fd("[->] README for more informations", 2);
	}
	else
	{
		wn = *init(&wn);
		start(&wn, argv);
		free_all(&wn);
	}
	return (0);
}
