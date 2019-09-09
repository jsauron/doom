/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:01:36 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/09 17:33:54 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void		ft_parsing_exit(int fd, char *msg, t_game *game)
{
	if (fd > -1)
		close(fd);
	ft_err_exit(msg, game);
}
/*
   static int		ft_strdigit(char *line)
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
   */
/*static void		ft_get_mapsize(int fd, t_game*game)
  {
  char	*line;

  if ((get_next_line(fd, &line)) < 1)
  ft_parsing_exit(fd, "wolf3d1: parsing error: bad map format", game);
  if (!(*line))
  ft_parsing_exit(fd, "wolf3d2: parsing error: bad map format", game);
  else if (!ft_strdigit(line))
  ft_parsing_exit(fd, "wolf3d3: parsing error: bad map format", game);
//	else if ((game->map_sz.w = ft_atoi(line)) <= 1)
//		ft_parsing_exit(fd, "wolf3d4: parsing error: bad map format", game);
//	else if ((game->map_sz.h =
//	ft_atoi(line + ft_nbrlen(game->map_sz.w, 10))) <= 1)
//		ft_parsing_exit(fd, "wolf3d5: parsing error: bad map format", game);
lt_release((void *)line);
}
*/
static void		ft_parse_map(int fd, char *map,  t_game *game)
{
	int		j;
	int   i;

	i = 0;
	while (i < MAP_SIZE )
	{
		j = 0;
		while (j < MAP_SIZE )
		{
			if (map[i * MAP_SIZE + j] == N_PLAYER)
			{
				if (game->player.position.x != -1)
					ft_parsing_exit(fd, "wolf3d: parsing error: bad spawn", game);
				game->player.position.x = i + 0.5;
				game->player.position.y = j + 0.5;
			}
			if (map[i * MAP_SIZE + j] >= N_VIDE && map[i * MAP_SIZE + j] <= N_POSTER)
			{
				game->map[i][j] = map[i * MAP_SIZE + j] - '0';
			}
			else if (map[i * MAP_SIZE + j] != ' ')
				ft_parsing_exit(fd, "wolf3d  llal: parsing error: bad bloc", game);
			j++;
		}
		i++;
	}
}

void			ft_get_map(char *file, t_game *game)
{
	int fd;
	int lu;
	char  map[MAP_SIZE * MAP_SIZE + 1] = {0};

	lu = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_parsing_exit(-1, "wolf3d: parsing error: can't open the map", game);
	lu = read(fd, map, MAP_SIZE * MAP_SIZE);
	// ft_get_mapsize(fd, game);
	//	while ((get_next_line(fd, &line)) > 0)
	//	if (i >= MAP_SIZE || ft_nbwords(line) != MAP_SIZE)
	//			ft_parsing_exit(fd, "wolf3d 6: parsing error: bad map format", game);
	ft_parse_map(fd, map, game);
	//lt_release((void *)file);
	if (game->player.position.x == -1.0)
		ft_parsing_exit(fd, "wolf3d 7: parsing error: bad map format", game);
	close(fd);
}
