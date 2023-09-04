/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sizes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:32:10 by emiro-co          #+#    #+#             */
/*   Updated: 2023/09/04 15:31:22 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	set_size(int cols, int rows)
{
	t_point	size;

	size.x = cols - 1;
	size.y = rows - 1;
	return (size);
}

int	size_map_rows(char *path)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd))
		i++;
	close(fd);
	return (i);
}

int	size_map_cols(char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	close(fd);
	return (ft_strlen(line) -1);
}

t_point	set_point(char **map, char c)
{
	t_point	begin;
	int		i;
	int		j;

	i = 0;
	j = 0;
	begin.x = 0;
	begin.y = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == c)
			{
				begin.y = i;
				begin.x = j;
				return (begin);
			}
			j++;
		}
		i++;
	}
	return (begin);
}
