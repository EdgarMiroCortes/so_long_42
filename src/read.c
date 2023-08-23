/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:32:10 by emiro-co          #+#    #+#             */
/*   Updated: 2023/08/23 15:34:45 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	ft_readmap(char *path)
{
	t_map	map;

	// comprovar que sea .ber
	if (!ft_strnstr(path, ".ber", ft_strlen(path)))
		exit(0);
	else
	{
		ft_printf("Format .ber OK\n");
	}
	map.rows = size_map_rows(path);
	map.box = fill_map(path, map.rows);
	map.cols = size_map_cols(path);
	ft_printf("\nRows: %d, Cols: %d\n", map.rows, map.cols);
	return (map);
}

char	**fill_map(char *path, int size)
{
	int		i;
	int		fd;
	char	**map;

	map = malloc(sizeof(char *) * (size + 1));
	i = 0;
	fd = open(path, O_RDONLY);
	map[i] = get_next_line(fd);
	while (map[i])
	{
		ft_printf("%s", map[i]);
		i++;
		map[i] = get_next_line(fd);
	}
	close(fd);
	return (map);
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
