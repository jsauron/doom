/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:01:36 by jsauron           #+#    #+#             */
/*   Updated: 2019/08/25 14:36:21 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void		ft_parsing_exit(int fd, char *msg, t_data *data)
{
  if (fd > -1)
    close(fd);
  ft_err_exit(msg, data);
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
/*static void		ft_get_mapsize(int fd, t_data *data)
{
  char	*line;

  if ((get_next_line(fd, &line)) < 1)
    ft_parsing_exit(fd, "wolf3d1: parsing error: bad map format", data);
  if (!(*line))
    ft_parsing_exit(fd, "wolf3d2: parsing error: bad map format", data);
  else if (!ft_strdigit(line))
    ft_parsing_exit(fd, "wolf3d3: parsing error: bad map format", data);
  //	else if ((data->map_sz.w = ft_atoi(line)) <= 1)
  //		ft_parsing_exit(fd, "wolf3d4: parsing error: bad map format", data);
  //	else if ((data->map_sz.h =
  //	ft_atoi(line + ft_nbrlen(data->map_sz.w, 10))) <= 1)
  //		ft_parsing_exit(fd, "wolf3d5: parsing error: bad map format", data);
  lt_release((void *)line);
}
*/
static void		ft_parse_map(int fd, char *map,  t_data *data)
{
  int		j;
  int   i;

  i = 0;
  while (i < MAP_SIZE )
  {
    j = 0;
      while (j < MAP_SIZE )
      {
        if (map[i * MAP_SIZE + j] == '3')
        {
          if (data->player.position.x != -1)
            ft_parsing_exit(fd, "wolf3d: parsing error: bad spawn", data);
          data->player.position.x = i + 0.5;
          data->player.position.y = j + 0.5;
        }
         if (map[i * MAP_SIZE + j] >= '0' && map[i * MAP_SIZE + j] <= '6')
        {
          if (map[i * MAP_SIZE + j] > '9')
            ft_parsing_exit(fd, "wolf3d alal : parsing error: bad bloc", data);
          data->map[i][j] = map[i * MAP_SIZE + j] - '0';
        }
        else if (map[i * MAP_SIZE + j] != ' ')
          ft_parsing_exit(fd, "wolf3d  llal: parsing error: bad bloc", data);
      j++;
      }
    i++;
  }
}

void			ft_get_map(char *file, t_data *data)
{
  int fd;
  int lu;
  char  map[MAP_SIZE * MAP_SIZE + 1] = {0};
  
  lu = 0;
  if ((fd = open(file, O_RDONLY)) == -1)
    ft_parsing_exit(-1, "wolf3d: parsing error: can't open the map", data);
  lu = read(fd, map, MAP_SIZE * MAP_SIZE);
  // ft_get_mapsize(fd, data);
  //	while ((get_next_line(fd, &line)) > 0)
  //	if (i >= MAP_SIZE || ft_nbwords(line) != MAP_SIZE)
  //			ft_parsing_exit(fd, "wolf3d 6: parsing error: bad map format", data);
  ft_parse_map(fd, map,  data);
  //lt_release((void *)file);
  if (data->player.position.x == -1.0)
    ft_parsing_exit(fd, "wolf3d 7: parsing error: bad map format", data);
  close(fd);
}
