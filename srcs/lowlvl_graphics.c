/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowlvl_graphics.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:03:08 by jsauron           #+#    #+#             */
/*   Updated: 2019/08/25 17:53:35 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			ft_set_string(t_win *wn, SDL_Rect rect, char *text,
				SDL_Color color)
{
	SDL_Rect			sdl_rect;
	SDL_Surface			*surface;

	sdl_rect = (SDL_Rect){rect.x, rect.y, rect.w, rect.h};
	if (!(surface = TTF_RenderText_Blended(wn->game.font, text, color)))
		ft_err_exit("Doom: Error while making surface", &wn->game);
	sdl_rect.w = (sdl_rect.h * surface->w) / surface->h;
	if ((SDL_BlitScaled(surface, 0, wn->screen, &sdl_rect)) == -1)
		ft_err_exit("Doom: Error can't blit surface", &wn->game);
	SDL_FreeSurface(surface);
}

void			ft_setpixel(SDL_Surface *surface, int x, int y, Uint32 color)
{
	int			bpp;
	Uint8		*p;
//	Uint32 tmp;	
//	t_color    col;

//	tmp = 0;
	if (x < 0 || x > WIN_W || y < 0 || y > WIN_H)
		return ;
//	col.all = color;
	//printf("color = %u\n", color);
	//exit(EXIT_FAILURE);
	/*while ()
	{
		tmp2 = col.all & 1;
		tmp = tmp & tmp2;
		col.all >>= 1;
		tmp <<= 1;
	}*/
//	tmp = col.tab[1];
//	col.tab[1] = col.tab[3];
//	col.tab[3] = tmp;
//	tmp = col.tab[1];
	//col.tab[1] = col.tab[2];
//	col.tab[2] = tmp;
//	color = col.all;
	//color = tmp;
	//col.all <<= 8;
	//col.tab[3] = tmp;
	//color = col.all;

bpp = surface->format->BytesPerPixel;
	p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
	(bpp == 1) ? *p = color : 0;
	(bpp == 2) ? *(Uint16 *)p = color : 0;
	(bpp == 4) ? *(Uint32 *)p = color : 0;
	if (bpp == 3)
	{
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
		{
			p[0] = (color >> 16) & 0xff;
			p[1] = (color >> 8) & 0xff;
			p[2] = color & 0xff;
		}
		else
		{
			p[0] = color & 0xff;
			p[1] = (color >> 8) & 0xff;
			p[2] = (color >> 16) & 0xff;
		}
	}
}

Uint32			ft_getpixel(t_win *wn, SDL_Surface *surface, int x, int y)
{
	int				bpp;
	Uint8			*p;
	Uint32			ret;

	if ((SDL_LockSurface(surface)) != 0)
		ft_err_exit("doom: error: SDL_LockSurface() failure", &wn->game);
	x = ft_abs(--x);
	y = ft_abs(--y);
	bpp = surface->format->BytesPerPixel;
	p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
	if (bpp == 1)
		ret = *p;
	else if (bpp == 2)
		ret = *(Uint16 *)p;
	else if (bpp == 3)
	{
		ret = (SDL_BYTEORDER == SDL_BIG_ENDIAN) ?
		(p[0] << 16 | p[1] << 8 | p[2]) : (p[0] | p[1] << 8 | p[2] << 16);
	}
	else if (bpp == 4)
		ret = *(Uint32 *)p;
	else
		ret = 0;
	SDL_UnlockSurface(surface);
	return (ret);
}
