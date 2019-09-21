/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_event_editor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <jsauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:31:08 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/21 19:35:49 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		key_down(t_win *wn, t_editor *editor, char *map)
{
	if (wn->state[SDL_SCANCODE_ESCAPE])
		return (0);
	else if (wn->state[SDL_SCANCODE_1])
		editor->current_obj = WALL;
	else if (wn->state[SDL_SCANCODE_2])
		editor->current_obj = MEAN;
	else if (wn->state[SDL_SCANCODE_3])
		editor->current_obj = GOAL;
	else if (wn->state[SDL_SCANCODE_4])
		editor->current_obj = PLAYER;
	else if (wn->state[SDL_SCANCODE_5])
		editor->current_obj = KEY;
	else if (wn->state[SDL_SCANCODE_6])
		editor->current_obj = DOOR;
	else if (wn->state[SDL_SCANCODE_7])
		editor->current_obj = POSTER;
	else if (wn->state[SDL_SCANCODE_8])
		editor->current_obj = BONUS;
	else if (wn->state[SDL_SCANCODE_S])
		save_map(editor->map, map);
	else if (wn->state[SDL_SCANCODE_C])
		upload_map(editor->map, map);
	return (1);
}

void	mouse_motion(t_win *wn, t_editor *editor)
{
	if (editor->left_click)
		editor->map[wn->event.motion.y / SIZE_BLOC][wn->event.motion.x
			/ SIZE_BLOC] = editor->current_obj;
	else if (editor->right_click)
		editor->map[wn->event.motion.y / SIZE_BLOC][wn->event.motion.x
			/ SIZE_BLOC] = VIDE;
}

void	button_up(t_win *wn, t_editor *editor)
{
	if (wn->event.button.button == SDL_BUTTON_LEFT)
		editor->left_click = 0;
	else if (wn->event.button.button == SDL_BUTTON_RIGHT)
		editor->right_click = 0;
}

void	button_down(t_win *wn, t_editor *editor)
{
	if (wn->event.button.button == SDL_BUTTON_LEFT)
	{
		if ((editor->current_obj == PLAYER && editor->player_placed == 0)
		|| editor->current_obj != PLAYER)
		{
			editor->map[wn->event.button.y / SIZE_BLOC][wn->event.button.x
				/ SIZE_BLOC] = editor->current_obj;
			editor->left_click = 1;
		}
	}
	if (wn->event.button.button == SDL_BUTTON_RIGHT)
	{
		if (editor->map[wn->event.button.y / SIZE_BLOC][wn->event.button.x
			/ SIZE_BLOC] == PLAYER)
			editor->player_placed = 0;
		editor->map[wn->event.button.y / SIZE_BLOC][wn->event.button.x
			/ SIZE_BLOC] = VIDE;
		editor->right_click = 1;
	}
}
