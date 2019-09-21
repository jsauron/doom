/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <jsauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:03:10 by hben-yah          #+#    #+#             */
/*   Updated: 2019/09/22 00:14:11 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void
	draw_minimap(t_win *wn, t_game *game, SDL_Rect rect, SDL_Rect index)
{
	int	i;
	int	j;

	i = index.x;
	j = index.y;
	if (game->map[i][j] == 1 || game->map[i][j] == 7)
		draw_rect(wn, rect, 0xFF306bb0, &(game->minimap.limit));
	else if (game->map[i][j] > 200)
		draw_rect(wn, rect, 0xFFDC143C, &(game->minimap.limit));
	else if (game->map[i][j] == 0 || game->map[i][j] == 4)
		draw_rect(wn, rect, 0xFFffabe4, &(game->minimap.limit));
	else if (game->map[i][j] == 3)
		draw_rect(wn, rect, 0xFF2E8B57, &(game->minimap.limit));
	else if (game->map[i][j] > 100)
		draw_rect(wn, rect, 0xFFFFD700, &(game->minimap.limit));
	else if (game->map[i][j] == 6)
		draw_rect(wn, rect, 0xFF00BFFF, &(game->minimap.limit));
	else if (game->map[i][j] == 8)
		draw_rect(wn, rect, 0xFF0FFFFF, &(game->minimap.limit));
	else if (game->map[i][j] == 9)
		draw_rect(wn, rect, 0xFF306bb0, &(game->minimap.limit));
}
