/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:57:00 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/21 18:52:02 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		free_structure_obj(t_editor *editor)
{
	SDL_FreeSurface(editor->editor_surface);
	SDL_FreeSurface(editor->obj.wall);
	SDL_FreeSurface(editor->obj.mean);
	SDL_FreeSurface(editor->obj.goal);
	SDL_FreeSurface(editor->obj.player);
	SDL_FreeSurface(editor->obj.key);
	SDL_FreeSurface(editor->obj.door);
	SDL_FreeSurface(editor->obj.poster);
}

void		free_editor(t_win *wn)
{
	int	i;

	i = 0;
	while (i < XBLOC)
		free(wn->editor->map[i++]);
	free(wn->editor->map);
	free(wn->editor);
}

void		free_sdl(t_win *wn)
{
	SDL_DestroyTexture(wn->texture);
	SDL_FreeSurface(wn->screen);
	SDL_DestroyRenderer(wn->render);
	SDL_DestroyWindow(wn->window);
	SDL_Quit();
}

void		free_all(t_win *wn)
{
	if (wn->game.sky)
		free_game(&wn->game);
	if (wn->editor)
		free_structure(wn, wn->editor);
	free_sdl(wn);
}

void		free_structure(t_win *wn, t_editor *editor)
{
	free_surface_editor(editor);
	free_editor(wn);
}
