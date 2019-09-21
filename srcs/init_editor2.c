/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_editor2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:56:08 by hben-yah          #+#    #+#             */
/*   Updated: 2019/09/21 18:56:32 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

t_win	*init(t_win *wn)
{
	int i;

	i = 0;
	if (!(wn->editor = malloc(sizeof(t_editor ))))
		exit(1);
	if (!(wn->editor->map = malloc(sizeof(int *) * XBLOC)))
		exit(1);
	while (i < XBLOC)
		wn->editor->map[i++] = malloc(sizeof(int) * YBLOC);
	init_structure(wn, wn->editor);
	init_sdl(wn);
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
		sdl_err_exit(0, NULL);
	return (wn);
}
