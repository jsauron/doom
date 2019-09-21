/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <jsauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:29:35 by jsauron           #+#    #+#             */
/*   Updated: 2019/09/21 14:41:00 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	set_elem(int **map, char elem, int i, int j)
{
	if (elem == '0')
		map[i][j] = 0;
	if (elem == '1')
		map[i][j] = 1;
	if (elem == '2')
		map[i][j] = 2;
	if (elem == '3')
		map[i][j] = 3;
	if (elem == '4')
		map[i][j] = 4;
	if (elem == '5')
		map[i][j] = 5;
	if (elem == '6')
		map[i][j] = 6;
	if (elem == '7')
		map[i][j] = 7;
}

void	parse_map_file(char line_file[], int **map)
{
	int		i;
	int		j;
	char	elem;

	i = 0;
	while (i < XBLOC)
	{
		j = 0;
		while (j < YBLOC)
		{
			elem = (line_file[(i * XBLOC) + j]);
			set_elem(map, elem, i, j);
			j++;
		}
		i++;
	}
}

int		upload_map(int **map, char *input_map)
{
	FILE	*file;
	char	line_file[XBLOC * YBLOC + 1] = {0};

	file = NULL;
	file = fopen(input_map, "r");
	if (file == NULL)
		return (0);
	fgets(line_file, XBLOC * YBLOC + 1, file);
	parse_map_file(line_file, map);
	fclose(file);
	return (1);
}

int		save_map(int **map, char *input_map)
{
	FILE	*file;
	int		x;
	int		y;

	file = NULL;
	file = fopen(input_map, "w");
	if (file == NULL)
		return (0);
	y = 0;
	while (y < YBLOC)
	{
		x = 0;
		while (x < XBLOC)
		{
			fprintf(file, "%d", map[y][x]);
			x++;
		}
		y++;
	}
	fclose(file);
	return (1);
}
