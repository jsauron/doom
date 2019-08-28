#include "doom.h"

int		gameover(t_win *wn)
{
	SDL_Rect	pos;

	pos.x = 250;
	pos.y = 350;
	SDL_BlitSurface(wn->game.gameover, NULL, wn->screen, &pos);
	return(0);
}

int		weapon(t_win *wn)
{	
	SDL_Rect	pos;
	
	pos.x = 0;
	pos.y = 0;
	SDL_BlitSurface(wn->game.weapon, NULL, wn->screen, &pos);
	return (0);
}

int		render_life(t_win *wn, int life)
{
	SDL_Rect	pos;
	int i;

	i = 0;
	pos.x = 0;
	pos.y = 20;
	while (life && i < life)
	{
		SDL_BlitSurface(wn->game.heart[i++], NULL, wn->screen, &pos);
		pos.x += 55;
	}
	if (life == 0)
		gameover(wn);
	return (0);
}

int		display_key(t_win *wn)
{
	SDL_Rect		pos;
	static 	int		i;
	int				k;
	
	k = 0;
	pos.x = 0;
	pos.y = 0;
		if (wn->game.time.current_time - wn->game.time.old_time > 170)
		{
			i++;
			wn->game.time.old_time = wn->game.time.current_time;
		}
		if (i == 6)
			i = 0;
	while (k < wn->game.key)
	{
		SDL_BlitSurface(wn->game.keys[i], NULL, wn->screen, &pos);
		pos.x -= 35;
		k++; 
	}
	return (0);
}

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
	SDL_BlitSurface(wn->screen, NULL, wn->screen, &(wn->pos_game));
	render_life(wn, wn->game.player.life);
	weapon(wn);
	 if (wn->game.key > 0)
	 	display_key(wn);
	SDL_UpdateTexture(wn->texture, NULL, wn->screen->pixels, wn->screen->pitch);
	SDL_RenderClear(wn->render);
	SDL_RenderCopy(wn->render, wn->texture, NULL, NULL);
	SDL_RenderPresent(wn->render);
	return (0);
}
