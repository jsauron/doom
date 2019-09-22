/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <jsauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:36:00 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/22 14:05:04 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

double			pythagore(double a, double b)
{
	return (sqrt(a * a + b * b));
}

void			set_cursor(t_win *wn)
{
	t_vec		vec;

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

void			ft_remove_light(Uint8 *component, double delta, int arg)
{
	if (*component > 0)
		*component = (*component * (1 - delta) + ((0x0 >> arg) * delta));
}

int				range_sprite(t_sprite *sprite, int n)
{
	int			i;
	t_sprite	tmp;

	i = 0;
	while (i + 1 < n)
	{
		if (sprite[i].new_distance < sprite[i + 1].new_distance)
		{
			tmp = sprite[i];
			sprite[i] = sprite[i + 1];
			sprite[i + 1] = tmp;
			i = 0;
		}
		i++;
	}
	return (0);
}

int				search_sprite(t_game *game, int id)
{
	int			n;

	n = 0;
	while (n <= game->n)
	{
		if (game->sprite[n].id == id)
			break ;
		n++;
	}
	return (n);
}
