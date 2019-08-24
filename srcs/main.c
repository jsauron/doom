/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:04:23 by jsauron           #+#    #+#             */
/*   Updated: 2019/08/24 15:14:10 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void		ft_make_frame(t_data *data)
{
	data->nb_frame++;
	data->time_last = clock();

	ft_rc_wolfcalc(data);
	ft_set_interface(data);
	data->fps = 1000 / (clock() / 10000 - data->time_last / 10000);
	ft_set_infos(data);

	data->texture = SDL_CreateTextureFromSurface(
			data->sdl.renderer, data->surface);
	lt_release(data->surface);
	if ((SDL_RenderCopy(data->sdl.renderer, data->texture, 0, 0)) != 0)
		ft_err_exit("doom: error: RenderCopy failure", data);
	SDL_DestroyTexture(data->texture);
	SDL_RenderPresent(data->sdl.renderer);
}

static void		ft_game_loop(t_data *data)
{
	ft_make_frame(data);
	while (1)
	{
		if (ft_get_events(data))
		{
			if ((SDL_RenderClear(data->sdl.renderer)) != 0)
				ft_err_exit("doom: error: RenderClear failure", data);
			ft_make_frame(data);
		}
		SDL_FlushEvent(SDL_KEYDOWN | SDL_MOUSEMOTION);
	}
}

int			ft_start(char **argv, t_data *data)
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
			ft_init_data(argv[1], data);
			ft_game_loop(data);
		}
		else if (wn->state[SDL_SCANCODE_2])
			editor(wn, wn->game);
		current_time = SDL_GetTicks();
		if (current_time - old_time > 250)
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
		SDL_BlitSurface(wn->game->menu[i], NULL, wn->screen, &(wn->pos_menu_mov));
			render(wn);
	}
	free_game(wn, wn->game);
	SDL_Quit();

	return (0);
}

int				main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_putendl_fd("[->] usage: ./doom [map]", 2);
		ft_err_exit("[->] README for more informations", &data);
	}
	ft_start(argv, &data);
	return (0);
}
