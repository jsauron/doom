/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:36:00 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/21 16:12:19 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

double		pythagore(double a, double b)
{
	return (sqrt(a * a + b * b));
}

void		set_cursor(t_win *wn)
{
	t_vec	vec;

	vec = (t_vec){(t_pos){WIN_W / 2 - 10, WIN_H / 2},
	(t_pos){WIN_W / 2 + 10, WIN_H / 2}};
	if (wn->game.touch == 0)
		draw_line(wn, vec, 0xFF5BE50B, 0);
	else
		draw_line(wn, vec, 0x00FF00FF, 0);
	vec = (t_vec){(t_pos){WIN_W / 2, WIN_H / 2 - 10},
	(t_pos){WIN_W / 2, WIN_H / 2 + 10}};
	if (wn->game.touch == 0)
		draw_line(wn, vec, 0xFF5BE50B, 0);
	else
		draw_line(wn, vec, 0x00FF00FF, 0);
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
}
