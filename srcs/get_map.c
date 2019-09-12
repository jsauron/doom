/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <jsauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:31:43 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/12 15:31:49 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void		parsing_exit(int fd, char *msg, t_game *game)
{
	if (fd > -1)
		close(fd);
	ft_err_exit(msg, game);
}

static int		map_is_digit(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static void		assign_elem_map(t_game *game, char *map, int i, int j)
{
	if (map[i * MAP_SIZE + j] == N_PLAYER)
	{
		if (game->player.position.x != -1)
			parsing_exit(2, "Doom: parsing error: bad spawn", game);
		game->player.position.x = i + 0.5;
		game->player.position.y = j + 0.5;
	}
	if (map[i * MAP_SIZE + j] >= N_VIDE
			&& map[i * MAP_SIZE + j] <= N_POSTER)
	{
		game->map[i][j] = map[i * MAP_SIZE + j] - '0';
	}
	else if (map[i * MAP_SIZE + j] != ' ')
		parsing_exit(2, "Doom: parsing error: bad bloc", game);
}

static void		parse_map_game(char *map, t_game *game)
{
	int		j;
	int		i;

	i = 0;
	while (i < MAP_SIZE)
	{
		j = 0;
		while (j < MAP_SIZE)
		{
			assign_elem_map(game, map, i, j);
			j++;
		}
		i++;
	}
}

void	get_map(char *file, t_game *game)
{
	int		fd;
	int		lu;
	char	map[MAP_SIZE * MAP_SIZE + 1];

	lu = 0;
	ft_bzero(map, MAP_SIZE * MAP_SIZE + 1);
	if ((fd = open(file, O_RDONLY)) == -1)
		parsing_exit(-1, "Doom : parsing error: can't open the map", game);
	if (!(lu = read(fd, map, MAP_SIZE * MAP_SIZE)))
		parsing_exit(-1, "Doom : parsing error: can't read the map", game);
	if (!(map_is_digit(map)))
		parsing_exit(-1, "Doom : parsing error: map is not digit", game);
	parse_map_game(map, game);
	if (game->player.position.x == -1.0)
		parsing_exit(fd, "Doom : parsing error: bad map format", game);
	close(fd);
}
