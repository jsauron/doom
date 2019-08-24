/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:01:36 by jsauron           #+#    #+#             */
/*   Updated: 2019/08/24 20:42:16 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void		ft_parsing_exit(int fd, char *msg, t_data *data)
{
	if (fd > -1)
		close(fd);
	ft_err_exit(msg, data);
}

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

static void		ft_get_mapsize(int fd, t_data *data)
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

static void		ft_parse_line(int fd, int i, char *line, t_data *data)
{
	int		val;
	int		j;

	j = 0;
	while (i < 15)
	{
		if (line[i] == '3')
		{
			if (data->player.position.x != -1)
				ft_parsing_exit(fd, "wolf3d: parsing error: bad spawn", data);
			data->player.position.x = j + 0.5;
			data->player.position.y = i + 0.5;
		}
		if (line[i] >= '0' && line[i] <= '6')
		{
			if ((val = line[i] + '0')  > 9)
				ft_parsing_exit(fd, "wolf3d alal : parsing error: bad bloc", data);
			data->map[i][j++] = line[i] + '0';
		}
		else if (line[i] != ' ')
		{
			printf("line[%d] = %c\n",i,  line[i]);
			printf("line[1] = %c\n",  line[i]);
			printf("line[2] = %c\n",  line[i]);
			ft_parsing_exit(fd, "wolf3d  llal: parsing error: bad bloc", data);
		}
		i++;
	}
}

void			ft_get_map(char *map, t_data *data)
{
	//char	*line;
	int		fd;
	int		i;

	i = 0;
	printf("map = %s\n", map);
	if ((fd = open(map, O_RDONLY)) == -1)
		ft_parsing_exit(-1, "wolf3d: parsing error: can't open the map", data);
	ft_get_mapsize(fd, data);
	if (!(data->map =
	(int **)(ft_memalloc_lt(sizeof(int *) * (MAP_SIZE)))))
		ft_parsing_exit(fd, "wolf3d: parsing error: out of memory", data);
//	while ((get_next_line(fd, &line)) > 0)
	while (i < MAP_SIZE)
	{
//	if (i >= MAP_SIZE || ft_nbwords(line) != MAP_SIZE)
//			ft_parsing_exit(fd, "wolf3d 6: parsing error: bad map format", data);
		if (!(data->map[i] =
		(int *)(ft_memalloc_lt(sizeof(int) * (MAP_SIZE)))))
			ft_parsing_exit(fd, "wolf3d: parsing error: out of memory", data);
		ft_parse_line(fd, i, map, data);
		lt_release((void *)map);
		i++;
	}
	if (data->player.position.x == -1.0)
		ft_parsing_exit(fd, "wolf3d 7: parsing error: bad map format", data);
	close(fd);
}
