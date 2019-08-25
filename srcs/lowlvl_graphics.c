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

/*SDL_Surface		*ft_new_surface(int height, int width, t_game *game)
{
	SDL_Surface		*surface;
	Uint32			color[4];

	color[0] = 0x00ff0000;
	color[1] = 0x0000ff00;
	color[2] = 0x000000ff;
	color[3] = 0xff000000;
	if (!(surface = lt_push(SDL_CreateRGBSurface(
	0, width, height, 32, color[0], color[1], color[2], color[3]), ft_srfdel)))
		ft_err_exit("wolf3d: error: SDL_CreateRGBSurface() failed", game);
	return (surface);
}*/

void			ft_set_string(SDL_Rect rect, char *text,
				SDL_Color color, t_game *game)
{
	SDL_Rect			sdl_rect;
	SDL_Surface			*surface;

	sdl_rect = (SDL_Rect){rect.x, rect.y, rect.w, rect.h};
	if (!(surface = TTF_RenderText_Blended(game->font, text, color)))
		ft_err_exit("Doom: Error while making surface", game);
	sdl_rect.w = (sdl_rect.h * surface->w) / surface->h;
	if ((SDL_BlitScaled(surface, 0, game->screen, &sdl_rect)) == -1)
		ft_err_exit("Doom: Error can't blit surface", game);
	SDL_FreeSurface(surface);
}

void			ft_setpixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
	int			bpp;
	Uint8		*p;

	if (x < 0 || x > WIN_W || y < 0 || y > WIN_H)
		return ;
	bpp = surface->format->BytesPerPixel;
	p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
	(bpp == 1) ? *p = pixel : 0;
	(bpp == 2) ? *(Uint16 *)p = pixel : 0;
	(bpp == 4) ? *(Uint32 *)p = pixel : 0;
	if (bpp == 3)
	{
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
		{
			p[0] = (pixel >> 16) & 0xff;
			p[1] = (pixel >> 8) & 0xff;
			p[2] = pixel & 0xff;
		}
		else
		{
			p[0] = pixel & 0xff;
			p[1] = (pixel >> 8) & 0xff;
			p[2] = (pixel >> 16) & 0xff;
		}
	}
}

Uint32			ft_getpixel(SDL_Surface *surface, int x, int y, t_game *game)
{
	int				bpp;
	Uint8			*p;
	Uint32			ret;

	if ((SDL_LockSurface(surface)) != 0)
		ft_err_exit("wolf3d: error: SDL_LockSurface() failure", game);
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
