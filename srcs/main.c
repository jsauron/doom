/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:04:23 by jsauron           #+#    #+#             */
/*   Updated: 2019/08/25 17:52:15 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void		ft_make_frame(t_game *game)
{
	game->nb_frame++;
	game->time_last = clock();

	ft_rc_wolfcalc(game);
	ft_set_interface(game);
	game->fps = 1000 / (clock() / 10000 - game->time_last / 10000);
	ft_set_infos(game);

	game->texture = SDL_CreateTextureFromSurface(
			game->sdl.renderer, game->surface);
	if ((SDL_RenderCopy(game->sdl.renderer, game->texture, 0, 0)) != 0)
		ft_err_exit("doom: error: RenderCopy failure", game);
	SDL_DestroyTexture(game->texture);
	SDL_RenderPresent(game->sdl.renderer);
}

static void		ft_game_loop(t_game *game)
{
	ft_make_frame(game);
	while (1)
	{
		if (ft_get_events(game))
		{
			if ((SDL_RenderClear(game->sdl.renderer)) != 0)
				ft_err_exit("doom: error: RenderClear failure", game);
			ft_make_frame(game);
		}
		SDL_FlushEvent(SDL_KEYDOWN | SDL_MOUSEMOTION);
	}
}

int			ft_start(char **argv, t_game *game)
{
	t_win			*wn;
	int				play;
	int				current_time;
	int				old_time;
	int				i;
	int				c;

	wn = NULL;
	play = 1;
	i = 0;
	c = 0;
	current_time = 0;
	old_time = 0;

	wn = init(wn);
	wn->state = (Uint8*)SDL_GetKeyboardState(NULL);
	while (play)
	{
		SDL_PollEvent(&(wn->event));
		if (wn->event.type == SDL_QUIT || wn->state[SDL_SCANCODE_ESCAPE])
			play = 0;
		else if (wn->state[SDL_SCANCODE_1] && argv[1])
		{
			ft_init_game(argv[1], game);
			ft_game_loop(game);
			SDL_WaitEvent(&(wn->event));
		}
		else if (wn->state[SDL_SCANCODE_2])
		{
			editor(wn, wn->editor, argv[1]);
			SDL_WaitEvent(&(wn->event));
		}
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
		SDL_BlitSurface(wn->editor->menu[i], NULL, wn->screen, &(wn->pos_menu_mov));
			render(wn);
	}
	free_surface_editor(wn, wn->editor);
	SDL_Quit();

	return (0);
}

int				main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putendl_fd("[->] usage: ./doom [map]", 2);
		ft_err_exit("[->] README for more informations", &game);
	}
	ft_start(argv, &game);
	return (0);
}
