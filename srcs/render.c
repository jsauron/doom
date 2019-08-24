#include "doom.h"

int     free_surface_editor(t_win *wn, t_game *game)
{
	(void)wn;
	SDL_FreeSurface(game->wall);
	SDL_FreeSurface(game->mean);
	SDL_FreeSurface(game->door);
	SDL_FreeSurface(game->key);
	SDL_FreeSurface(game->goal);
	SDL_FreeSurface(game->player);
	SDL_FreeSurface(game->editor);
	int i = 0;
	while (i < 9)
		SDL_FreeSurface(game->menu[i++]);
	return (1);
}
int     render(t_win *wn)
{
	SDL_UpdateTexture(wn->texture, NULL, wn->screen->pixels, wn->screen->pitch);
	SDL_RenderClear(wn->render);
	SDL_RenderCopy(wn->render, wn->texture, NULL, NULL);
	SDL_RenderPresent(wn->render);
	return (0);
}
