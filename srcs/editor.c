/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <jsauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:30:17 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/21 14:38:37 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	editor(t_win *wn, t_editor *editor, char *map)
{
	if (!upload_map(editor->map, map))
		exit(EXIT_FAILURE);
	init_editor(editor);
	play_editor(wn, editor, map);
}

void	set_obj(t_win *wn, SDL_Rect pos, int x, int y)
{
	if (wn->editor->map[y][x] == WALL)
		SDL_BlitSurface(wn->editor->obj.wall, NULL, wn->screen, &pos);
	else if (wn->editor->map[y][x] == MEAN)
		SDL_BlitSurface(wn->editor->obj.mean, NULL, wn->screen, &pos);
	else if (wn->editor->map[y][x] == GOAL)
		SDL_BlitSurface(wn->editor->obj.goal, NULL, wn->screen, &pos);
	else if (wn->editor->map[y][x] == KEY)
		SDL_BlitSurface(wn->editor->obj.key, NULL, wn->screen, &pos);
	else if (wn->editor->map[y][x] == DOOR)
		SDL_BlitSurface(wn->editor->obj.door, NULL, wn->screen, &pos);
	else if (wn->editor->map[y][x] == POSTER)
		SDL_BlitSurface(wn->editor->obj.poster, NULL, wn->screen, &pos);
	else if (wn->editor->map[y][x] == PLAYER)
	{
		SDL_BlitSurface(wn->editor->obj.player, NULL, wn->screen, &pos);
		wn->editor->player_placed = 1;
	}
}

void	display_editor(t_win *wn, t_editor *editor)
{
	int		y;
	int		x;

	y = 0;
	while (y < XBLOC)
	{
		x = 0;
		while (x < YBLOC)
		{
			editor->pos.x = x * SIZE_BLOC;
			editor->pos.y = y * SIZE_BLOC;
			set_obj(wn, editor->pos, x, y);
			x++;
		}
		y++;
	}
}

void	play_editor(t_win *wn, t_editor *editor, char *map)
{
	int		play;

	play = 1;
	SDL_PumpEvents();
	wn->state = (Uint8 *)SDL_GetKeyboardState(NULL);
	wn->input.mouse = (Uint32)SDL_GetMouseState(&wn->input.x, &wn->input.y);
	while (play)
	{
		SDL_WaitEvent(&(wn->event));
		if (wn->event.type == SDL_QUIT)
			play = 0;
		else if (wn->event.type == SDL_MOUSEBUTTONDOWN)
			button_down(wn, editor);
		else if (wn->event.type == SDL_MOUSEBUTTONUP)
			button_up(wn, editor);
		if (wn->event.type == SDL_MOUSEMOTION)
			mouse_motion(wn, editor);
		if (wn->event.type == SDL_KEYDOWN)
			play = key_down(wn, editor, map);
		editor->pos.x = 0;
		editor->pos.y = 0;
		SDL_BlitSurface(editor->editor_surface, NULL, wn->screen, &editor->pos);
		display_editor(wn, editor);
		render_editor(wn);
	}
}
