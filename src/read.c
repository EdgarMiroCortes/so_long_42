/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:32:10 by emiro-co          #+#    #+#             */
/*   Updated: 2023/08/23 17:51:05 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	ft_readmap(char *path)
{
	t_map	map;
	t_point	size;
	
	map.format = check_format(path);
	map.rows = size_map_rows(path);
	map.box = fill_map(path, map.rows);
	map.cols = size_map_cols(path);
	map.coins = count_coins(map.box);
	size.x = map.cols;
	size.y = map.rows;
	map.walls = check_walls(map.box, (map.rows - 1), (map.cols - 1));
	map.begin = set_begin(map.box);
	map.box_for_solution = set_solution_box(map.box);
	
	ft_printf("\nRows: %d, Cols: %d\n", map.rows, map.cols);
	ft_printf("Format Status: %d, Coins: %d\n", map.format, map.coins);
	ft_printf("Walls Stauts: %d\n", map.walls);
	ft_printf("Map Begin: cols: %d. rows: %d\n", map.begin.x, map.begin.y);
	
	map.solution = flood_fill(map.box, size, map.begin);
	return (map);
}

t_point set_begin(char **map)
{
	t_point	begin;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'E')
			{
				begin.y = i;
				begin.x = j;
			}
			j++;
		}
		i++;
	}
	return (begin);
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

/* comprobar que sea .ber*/
int	check_format(char *path)
{
	if (!ft_strnstr(path, ".ber", ft_strlen(path)))
		return (0);
	return (1);
}

int count_coins(char **map)
{
	int	coins;
	int	i;
	int	j;

	coins = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				coins++;
			j++;
		}
		i++;
	}
	return (coins);
}

int check_walls(char **map, int last, int col)
{
	int	i;
	int	rows;

	rows = last;
	i = 0;
	while (rows)
	{
		if ((map[i][0] != '1') || (map[i][col] != '1'))
			return (0);
		i++;
		rows --;
	}
	i = 0;
	while (map[0][i] != '\0' && map[last][i])
	{
		if ((map[0][i] != '1') || (map[last][i] != '1'))
			return (0);
		i++;
	}
	return (1);
}
