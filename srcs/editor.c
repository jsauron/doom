/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 19:30:15 by jsauron           #+#    #+#             */
/*   Updated: 2019/08/24 16:56:20 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	editor(t_win *wn, t_game *game)
{
	SDL_Rect pos;

	int play = 1;
	int left_click = 0;
	int right_click = 0;
	int current_obj = WALL;
	int x = 0;
	int y = 0;

	game->wall = IMG_Load("ressources/wall.tga");
	game->bloc = IMG_Load("ressources/mean.tga");
	game->goal = IMG_Load("ressources/exit.tga");
	game->player = IMG_Load("ressources/player.tga");
	game->editor = IMG_Load("ressources/floor_editor2.tga");

//	if(!upload_map(game->map))
//		exit(EXIT_FAILURE);

	SDL_PumpEvents();
	wn->state = (Uint8*)SDL_GetKeyboardState(NULL);
	wn->input.mouse = (Uint32)SDL_GetMouseState(&wn->input.x, &wn->input.y);
	while (play)
	{
		SDL_WaitEvent(&(wn->event));
		if (wn->event.type == SDL_QUIT)
			play = 0;
		else if (wn->event.type ==  SDL_MOUSEBUTTONDOWN)
		{
			if (wn->event.button.button == SDL_BUTTON_LEFT)
			{
				game->map[wn->event.button.y / SIZE_BLOC][wn->event.button.x / SIZE_BLOC] = current_obj;
				left_click = 1;
			}
			if (wn->event.button.button == SDL_BUTTON_RIGHT)
			{
				game->map[wn->event.button.y / SIZE_BLOC][wn->event.button.x / SIZE_BLOC] = VIDE;
				right_click = 1;
			}
		}
		else if (wn->event.type ==  SDL_MOUSEBUTTONUP)
		{
			if (wn->event.button.button == SDL_BUTTON_LEFT)
				left_click = 0;
			else if (wn->event.button.button == SDL_BUTTON_RIGHT)
				right_click = 0;
		}
		if (wn->event.type ==  SDL_MOUSEMOTION)
		{
			if (left_click)
				game->map[wn->event.motion.y / SIZE_BLOC][wn->event.motion.x / SIZE_BLOC] = current_obj;
			else if (right_click)
				game->map[wn->event.motion.y / SIZE_BLOC][wn->event.motion.x / SIZE_BLOC] = VIDE;
		}
		if (wn->event.type == SDL_KEYDOWN)
		{
			if (wn->state[SDL_SCANCODE_ESCAPE])
				play= 0;
			else if (wn->state[SDL_SCANCODE_1])
				current_obj = WALL;
			else if (wn->state[SDL_SCANCODE_2])
				current_obj = BLOC;
			else if (wn->state[SDL_SCANCODE_3])
				current_obj = GOAL;
			else if (wn->state[SDL_SCANCODE_4])
				current_obj = PLAYER;
			else if (wn->state[SDL_SCANCODE_S])
				save_level(game->map);
			else if (wn->state[SDL_SCANCODE_C])
				upload_map(game->map);
	}
		pos.x = 0;
		pos.y = 0;
		SDL_BlitSurface(game->editor, NULL, wn->screen, &pos);
		//SDL_FillRect(wn->screen ,NULL, SDL_MapRGB(wn->screen->format, 0, 255, 255));
		y = 0;
		int c = 0;
		while (y < XBLOC)
		{
			x = 0;
			while (x < YBLOC)
			{
				pos.x = x * SIZE_BLOC;
				pos.y = y * SIZE_BLOC;
				if (game->map[y][x] == WALL)
						SDL_BlitSurface(game->wall, NULL, wn->screen, &pos);
				else if (game->map[y][x] == BLOC)
						SDL_BlitSurface(game->bloc, NULL, wn->screen, &pos);
				else if (game->map[y][x] == GOAL)
						SDL_BlitSurface(game->goal, NULL, wn->screen, &pos);
				else if (game->map[y][x] == PLAYER && c == 0)
				{
						SDL_BlitSurface(game->player, NULL, wn->screen, &pos);
						c++;
				}
				x++;
			}
			y++;
		}
		SDL_UpdateTexture(wn->texture, NULL, wn->screen->pixels, wn->screen->pitch);
		SDL_RenderClear(wn->render);
		SDL_RenderCopy(wn->render, wn->texture, NULL, NULL);
		
		SDL_RenderPresent(wn->render);
		}
		SDL_FreeSurface(game->wall);
		SDL_FreeSurface(game->bloc);
		SDL_FreeSurface(game->goal);
		SDL_FreeSurface(game->player);
}
