/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <jsauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:34:37 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/13 18:10:44 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

/*int target(t_win *wn)
  {
  SDL_Rect pos;

  pos.x = 0;
  pos.y = 0;
  if (wn->game.target == 1)
  SDL_BlitSurface(wn->game.lunette[0], NULL, wn->screen, &pos);
  return (0);
  }
  */

int gameover(t_win *wn)
{
	SDL_Rect pos;

	pos.x = 0;
	pos.y = 0;
	SDL_BlitSurface(wn->game.gameover, NULL, wn->screen, &pos);

	return (0);
}

/*int weapon(t_win *wn)
  {
  SDL_Rect pos;

  pos.x = 0;
  pos.y = 0;
  SDL_BlitSurface(wn->game.weapon, NULL, wn->screen, &pos);
  return (0);
  }
  */
int render_life(t_win *wn, int life)
{
	SDL_Rect pos;
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

int you_win(t_win *wn)
{
	SDL_Rect pos;
	static int i;

	pos.x = 0;
	pos.y = 0;
	if (wn->game.time.current_time - wn->game.time.old_time > 100)
	{
		i++;
		wn->game.time.old_time = wn->game.time.current_time;
	}
	if (i == 12)
		i = 0;

	SDL_BlitSurface(wn->game.win[i], NULL, wn->screen, &pos);
	return (0);
}

int shot(t_win *wn)
{
	SDL_Rect pos;
	static int i;

	pos.x = 0;
	pos.y = 0;
	if (wn->game.shot == 1 && wn->game.target == 0)
	{
		if (wn->game.time.current_time - wn->game.time.old_time > 100)
		{
			i++;
			wn->game.time.old_time = wn->game.time.current_time;
		}
		if (i == 2)
			i = 0;

		SDL_BlitSurface(wn->game.weapon[i], NULL, wn->screen, &pos);
	}
	else if (wn->game.shot == 1 && wn->game.target == 1)
	{
		if (wn->game.time.current_time - wn->game.time.old_time > 100)
		{
			i++;
			wn->game.time.old_time = wn->game.time.current_time;
		}
		if (i == 2)
			i = 0;

		SDL_BlitSurface(wn->game.lunette[i], NULL, wn->screen, &pos);
	}
	else if (wn->game.shot == 0 && wn->game.target == 0)
		SDL_BlitSurface(wn->game.weapon[0], NULL, wn->screen, &pos);
	else if (wn->game.shot == 0 && wn->game.target == 1)
		SDL_BlitSurface(wn->game.lunette[0], NULL, wn->screen, &pos);

	return (0);
}

int display_key(t_win *wn)
{
	SDL_Rect pos;
	static int i;
	int k;

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
		k++;
		pos.x -= 35 * k;
	}
	return (0);
}

int free_surface_editor(t_win *wn, t_editor *editor)
{
	(void)wn;
	SDL_FreeSurface(editor->obj.wall);
	SDL_FreeSurface(editor->obj.mean);
	SDL_FreeSurface(editor->obj.door);
	SDL_FreeSurface(editor->obj.key);
	SDL_FreeSurface(editor->obj.goal);
	SDL_FreeSurface(editor->obj.player);
	SDL_FreeSurface(editor->editor_surface);
	int i = 0;
	while (i < 9)
		SDL_FreeSurface(editor->menu[i++]);
	return (1);
}
int render_editor(t_win *wn)
{
	SDL_UpdateTexture(wn->texture, NULL, wn->screen->pixels, wn->screen->pitch);
	SDL_RenderClear(wn->render);
	SDL_RenderCopy(wn->render, wn->texture, NULL, NULL);
	SDL_RenderPresent(wn->render);
	return (0);
}



int	display_mission(t_win *wn)
{
	int i;

	i = 1;
	wn->game.state = (Uint8 *)SDL_GetKeyboardState(NULL);
	while (i)
	{
		SDL_BlitSurface(wn->game.mission_s, NULL, wn->screen, &(wn->pos_game));	
		render(wn);
		if (wn->game.state[SDL_SCANCODE_ESCAPE])
			i = 0;	
	}
	wn->game.mission = 0;	
	return (0);
}

int	render_sprite(t_win *wn)
{
	SDL_Texture *texture;
	int n;

	n = 0;
	texture = NULL;
	//range_sprite(wn->game.sprite, wn->game.n);
	while (n < wn->game.n)
	{
		if (wn->game.sprite[n].actif == 1)	
		{
			SDL_BlitSurface(wn->game.sprite[n].sprite, NULL, wn->screen, &(wn->game.sprite[n].pos));
		}
		n++;
	}
	return (0);
}

int render_game(t_win *wn)
{
	if (wn->game.exit == 1)
		you_win(wn);
	//else if (wn->game.mission == 1)
	//display_mission(wn);
	else
	{
		SDL_BlitSurface(wn->screen, NULL, wn->screen, &(wn->pos_game));
		render_sprite(wn);
		render_life(wn, wn->game.player.life);
		//	weapon(wn);
		shot(wn);
		//	target(wn);
		if (wn->game.key > 0)
			display_key(wn);
	}
	render(wn);
	return (0);
}

int	render(t_win *wn)
{
	SDL_UpdateTexture(wn->texture, NULL, wn->screen->pixels, wn->screen->pitch);
	SDL_RenderClear(wn->render);
	SDL_RenderCopy(wn->render, wn->texture, NULL, NULL);
	SDL_RenderPresent(wn->render);
	return (0);
}
