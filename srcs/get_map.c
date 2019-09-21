/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:31:43 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/21 18:53:23 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

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

static void		assign_sprite_map(t_game *game, int x, int y)
{
	if (game->map[y][x] == KEY)
		set_key_sprite(game, x, y);
	else if (game->map[y][x] == MEAN)
		set_mean_sprite(game, x, y);
	else if (game->map[y][x] == GOAL)
		set_exit_sprite(game, x, y);
}

static void		parse_sprite_map(t_game *game, int size)
{
	int		y;
	int		x;

	y = 0;
	if (!(game->sprite = malloc(sizeof(t_sprite) * size)))
		ft_err_exit("Doom: Error malloc t_sprite failed", game);
	ft_bzero(game->sprite, size);
	while (y < MAP_SIZE)
	{
		x = 0;
		while (x < MAP_SIZE)
		{
			assign_sprite_map(game, x, y);
			x++;
		}
		y++;
	}
}

void			get_map(char *file, t_game *game)
{
	int		fd;
	int		lu;
	char	map[MAP_SIZE * MAP_SIZE + 1];
	int		sprite;

	lu = 0;
	sprite = 0;
	ft_bzero(map, MAP_SIZE * MAP_SIZE + 1);
	if ((fd = open(file, O_RDONLY)) == -1)
		parsing_exit(-1, "Doom : parsing error: can't open the map", game);
	if (!(lu = read(fd, map, MAP_SIZE * MAP_SIZE)))
		parsing_exit(-1, "Doom : parsing error: can't read the map", game);
	if (!(map_is_digit(map)))
		parsing_exit(-1, "Doom : parsing error: map is not digit", game);
	sprite = parse_map_game(map, game);
	if (game->player.position.x == -1.0)
		parsing_exit(fd, "Doom : parsing error: bad map format", game);
	parse_sprite_map(game, sprite);
	if (game->map_exit == 0)
		parsing_exit(fd, "Doom : parsing error: no exit", game);
	close(fd);
}
