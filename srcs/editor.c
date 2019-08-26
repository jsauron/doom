/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 19:30:15 by jsauron           #+#    #+#             */
/*   Updated: 2019/08/25 16:00:22 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	editor(t_win *wn, t_editor *editor, char *map)
{
	SDL_Rect pos;

	int play = 1;
	int left_click = 0;
	int right_click = 0;
	int current_obj = WALL;
	int x = 0;
	int y = 0;

	if(!upload_map(editor->map, map))
		exit(EXIT_FAILURE);

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
				printf("1\n");
			if (wn->event.button.button == SDL_BUTTON_LEFT)
			{
				editor->map[wn->event.button.y / SIZE_BLOC][wn->event.button.x / SIZE_BLOC] = current_obj;
				left_click = 1;
				printf("2\n");
			}
			if (wn->event.button.button == SDL_BUTTON_RIGHT)
			{
				editor->map[wn->event.button.y / SIZE_BLOC][wn->event.button.x / SIZE_BLOC] = VIDE;
				right_click = 1;
				printf("3\n");
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
				editor->map[wn->event.motion.y / SIZE_BLOC][wn->event.motion.x / SIZE_BLOC] = current_obj;
			else if (right_click)
				editor->map[wn->event.motion.y / SIZE_BLOC][wn->event.motion.x / SIZE_BLOC] = VIDE;
		}
		if (wn->event.type == SDL_KEYDOWN)
		{
			if (wn->state[SDL_SCANCODE_ESCAPE])
				play = 0;
			else if (wn->state[SDL_SCANCODE_1])
				current_obj = WALL;
			else if (wn->state[SDL_SCANCODE_2])
				current_obj = MEAN;
			else if (wn->state[SDL_SCANCODE_3])
				current_obj = GOAL;
			else if (wn->state[SDL_SCANCODE_4])
				current_obj = PLAYER;
			else if (wn->state[SDL_SCANCODE_5])
				current_obj = KEY;
			else if (wn->state[SDL_SCANCODE_6])
				current_obj = DOOR;
			else if (wn->state[SDL_SCANCODE_S])
				save_map(editor->map, map);
			else if (wn->state[SDL_SCANCODE_C])
				upload_map(editor->map, map );
	}
		pos.x = 0;
		pos.y = 0;
		SDL_BlitSurface(editor->editor_surface, NULL, wn->screen, &pos);
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
				if (editor->map[y][x] == WALL)
						SDL_BlitSurface(editor->wall, NULL, wn->screen, &pos);
				else if (editor->map[y][x] == MEAN)
						SDL_BlitSurface(editor->mean, NULL, wn->screen, &pos);
				else if (editor->map[y][x] == GOAL)
						SDL_BlitSurface(editor->goal, NULL, wn->screen, &pos);
				else if (editor->map[y][x] == KEY)
						SDL_BlitSurface(editor->key, NULL, wn->screen, &pos);
				else if (editor->map[y][x] == DOOR)
						SDL_BlitSurface(editor->door, NULL, wn->screen, &pos);
				else if (editor->map[y][x] == PLAYER && c == 0)
				{
						SDL_BlitSurface(editor->player, NULL, wn->screen, &pos);
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
}
