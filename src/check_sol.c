/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:32:10 by emiro-co          #+#    #+#             */
/*   Updated: 2023/08/30 16:04:02 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**set_solution_box(char **map, int rows, int cols)
{
	char	**new_map;
	int		i;
	char	c;
	int		j;

	i = 0;
	new_map = (char **)malloc((rows + 1) * sizeof(char *));
	while (i < rows)
	{
		new_map[i] = (char *)malloc((cols + 1) * sizeof(char));
		j = 0;
		while (j < cols)
		{
			c = map[i][j];
			if (c == '1' || c == '0' || c == 'E')
				new_map[i][j] = c;
			else
				new_map[i][j] = '0';
			j++;
		}
		new_map[i][cols] = '\0';
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] != to_fill)
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

int	check_sol(t_point exit, char **map)
{
	if (map[exit.y - 1][exit.x] == 'F')
		return (1);
	if (map[exit.y + 1][exit.x] == 'F')
		return (1);
	if (map[exit.y][exit.x - 1] == 'F')
		return (1);
	if (map[exit.y][exit.x + 1] == 'F')
		return (1);
	return (0);
}
