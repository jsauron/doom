/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:14:13 by jsauron           #+#    #+#             */
/*   Updated: 2019/03/16 10:14:15 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_subjoinfree(char **line, char *buf, int i)
{
	char		*temp;
	char		*temp2;
	char		*new;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	temp = ft_strdup(*line);
	temp2 = ft_strsub(buf, 0, i);
	if (!(new = ft_strjoin(temp, temp2)))
		return (-1);
	lt_release((void *)temp);
	lt_release((void *)temp2);
	*line = new;
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	static char	buf[BUFF_SIZE + 1] = {'\0'};
	int			ret[2];

	if ((fd < 0 || !line) || !(*line = ft_strdup("")))
		return (-1);
	ret[0] = 1;
	while (ret[0])
	{
		if (!(*buf))
		{
			if ((ret[0] = read(fd, buf, BUFF_SIZE)) == 0 && **line)
				return (1);
			else if (ret[0] < 0)
				return (-1);
		}
		if ((ret[1] = ft_subjoinfree(line, buf, ret[1])) == -1)
			return (-1);
		if (buf[ret[1]] == '\n')
		{
			ft_strncpy(buf, buf + ret[1] + 1, BUFF_SIZE);
			return (1);
		}
		ft_strncpy(buf, buf + ret[1], BUFF_SIZE);
	}
	return (0);
}
