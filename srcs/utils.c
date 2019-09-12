/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <jsauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:36:00 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/12 15:36:03 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

double		pythagore(int a, int b)
{
	return (sqrt(a * a + b * b));
}

void		set_cursor(t_win *wn)
{
	t_vec	vec;

	vec = (t_vec){(t_pos){WIN_W / 2 - 10, WIN_H / 2},
	(t_pos){WIN_W / 2 + 10, WIN_H / 2}};
	draw_line(wn, vec, 0xFF5BE50B, 0);
	vec = (t_vec){(t_pos){WIN_W / 2, WIN_H / 2 - 10},
	(t_pos){WIN_W / 2, WIN_H / 2 + 10}};
	draw_line(wn, vec, 0xFF5BE50B, 0);
}

static void	ft_remove_light(Uint8 *component, double delta, int arg)
{
	if (*component > 0)
		*component = (*component * (1 - delta) + ((0x0 >> arg) * delta));
}

Uint32		light_shade(double distance, Uint32 hexa)
{
	SDL_Color	color;
	double		delta;

	delta = distance / 300;
	delta > 0.9 ? delta = 0.9 : 0;
	delta /= 1.50;
	hexa |= 0xFF000000;
	color = (SDL_Color){hexa >> 24, hexa >> 16, hexa >> 8, hexa};
	ft_remove_light(&color.r, delta, 24);
	ft_remove_light(&color.g, delta, 16);
	ft_remove_light(&color.b, delta, 8);
	ft_remove_light(&color.a, delta, 0);
	return ((color.r << 24) + (color.g << 16) + (color.b << 8) + (color.a));
	//return (hexa);
}

void		srfdel(void **ap)
{
	SDL_Surface		*surface;

	surface = (SDL_Surface *)(*ap);
	if (ap && *ap)
	{
		SDL_FreeSurface(surface);
		surface = 0;
	}
}
