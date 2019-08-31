#include "doom.h"

int     upload_map(int **map, char *input_map)
{
	FILE    *file = NULL;
	char	line_file[XBLOC * YBLOC + 1] = {0};
	int i = 0;
	int j = 0;
	char elem;

	file = fopen(input_map, "r");
	if (file == NULL)
		return (0);

	fgets(line_file, XBLOC * YBLOC + 1, file);
	while ( i < XBLOC)
	{
		j = 0;
		while (j < YBLOC)
		{
			elem = (line_file[(i * XBLOC) + j]);
			if (elem ==  '0')
				map[i][j] = 0;
			if (elem == '1')
				map[i][j] = 1;
			if (elem ==  '2')
				map[i][j] = 2;
			if (elem == '3')
				map[i][j] = 3;
			if (elem ==  '4')
				map[i][j] = 4;
			if (elem ==  '5')
				map[i][j] = 5;
			if (elem ==  '6')
				map[i][j] = 6;
			if (elem ==  '7')
				map[i][j] = 7;
			j++;
		}
		i++;
	}
	fclose(file);
	return (1);
}

int		save_map(int **map, char *input_map)
{
	FILE	*file = NULL;
	int	 x = 0;
	int y = 0;

	file = fopen(input_map, "w");
	if (file == NULL)
		return (0);
	while (y < YBLOC)
	{
		x = 0;
		while (x < XBLOC)
		{
			fprintf(file,"%d", map[y][x]);
			x++;
		}
		y++;
	}
	fclose(file);
	return (1);
}
