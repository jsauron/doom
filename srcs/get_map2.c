/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:52:23 by hben-yah          #+#    #+#             */
/*   Updated: 2019/09/21 19:07:14 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			parsing_exit(int fd, char *msg, t_game *game)
{
	if (fd > -1)
		close(fd);
	ft_err_exit(msg, game);
}

int				assign_elem_map(t_game *game, char *map, int i, int j)
{
	int	count_sprite;

	count_sprite = 0;
	if (map[i * MAP_SIZE + j] == N_PLAYER)
	{
		if (game->player.position.x != -1)
			parsing_exit(2, "Doom: parsing error: bad spawn", game);
		game->player.position.x = i + 0.5;
		game->player.position.y = j + 0.5;
	}
	else if (map[i * MAP_SIZE + j] == N_KEY || map[i * MAP_SIZE + j] == N_MEAN
		|| map[i * MAP_SIZE + j] == N_EXIT)
	{
		if (map[i * MAP_SIZE + j] == N_EXIT)
			game->map_exit = 1;
		count_sprite++;
	}
	if (map[i * MAP_SIZE + j] >= N_VIDE
			&& map[i * MAP_SIZE + j] <= N_POSTER)
	{
		game->map[i][j] = map[i * MAP_SIZE + j] - '0';
	}
	else if (map[i * MAP_SIZE + j] != ' ')
		parsing_exit(2, "Doom: parsing error: bad bloc", game);
	return (count_sprite);
}

int				parse_map_game(char *map, t_game *game)
{
	int		j;
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (i < MAP_SIZE)
	{
		j = 0;
		while (j < MAP_SIZE)
		{
			c += assign_elem_map(game, map, i, j);
			j++;
		}
		i++;
	}
	return (c);
}
