#include "doom.h"

int     free_surface_editor(t_win *wn, t_editor *editor)
{
	(void)wn;
	SDL_FreeSurface(editor->wall);
	SDL_FreeSurface(editor->mean);
	SDL_FreeSurface(editor->door);
	SDL_FreeSurface(editor->key);
	SDL_FreeSurface(editor->goal);
	SDL_FreeSurface(editor->player);
	SDL_FreeSurface(editor->editor_surface);
	int i = 0;
	while (i < 9)
		SDL_FreeSurface(editor->menu[i++]);
	return (1);
}
int     render_editor(t_win *wn)
{
	SDL_UpdateTexture(wn->texture, NULL, wn->screen->pixels, wn->screen->pitch);
	SDL_RenderClear(wn->render);
	SDL_RenderCopy(wn->render, wn->texture, NULL, NULL);
	SDL_RenderPresent(wn->render);
	return (0);
}

int     render_game(t_win *wn)
{
	SDL_UpdateTexture(wn->texture, NULL, wn->game->screen->pixels, wn->game->screen->pitch);
	SDL_RenderClear(wn->render);
	SDL_RenderCopy(wn->render, wn->texture, NULL, NULL);
	SDL_RenderPresent(wn->render);
	return (0);
}
