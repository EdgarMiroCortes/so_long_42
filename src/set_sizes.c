/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sizes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:32:10 by emiro-co          #+#    #+#             */
/*   Updated: 2023/09/06 17:22:55 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	set_size(int cols, int rows)
{
	t_point	size;

	size.col = cols - 1;
	size.row = rows - 1;
	return (size);
}

int	size_map_rows(char *path)
{
	int		fd;
	int		i;
	char	*str;

	i = 0;
	fd = open(path, O_RDONLY);
	str = get_next_line(fd);
	if (!str)
		return (-1);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

int	size_map_cols(char *path)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (-1);
	close(fd);
	i = ft_strlen(line) -1;
	free(line);
	return (i);
}

t_point	set_point(char **map, char c)
{
	t_point	begin;
	int		i;
	int		j;

	i = 0;
	j = 0;
	begin.col = 0;
	begin.row = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == c)
			{
				begin.row = i;
				begin.col = j;
				return (begin);
			}
			j++;
		}
		i++;
	}
	return (begin);
}
