/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:32:10 by emiro-co          #+#    #+#             */
/*   Updated: 2023/09/06 11:50:27 by emiro-co         ###   ########.fr       */
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
	if (cur.row < 0 || cur.row >= size.row || cur.col < 0 || cur.col >= size.col
		|| tab[cur.row][cur.col] != to_fill)
		return ;
	tab[cur.row][cur.col] = 'F';
	fill(tab, size, (t_point){cur.col - 1, cur.row}, to_fill);
	fill(tab, size, (t_point){cur.col + 1, cur.row}, to_fill);
	fill(tab, size, (t_point){cur.col, cur.row - 1}, to_fill);
	fill(tab, size, (t_point){cur.col, cur.row + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.row][begin.col]);
}

int	check_all(t_map map)
{
	int			things;
	t_point		coin;
	int			i;
	int			j;

	i = 0;
	j = 0;
	things = 0;
	things += check_sol(map.exit, map.box_for_solution);
	while (map.box[i])
	{
		j = 0;
		while (map.box[i][j] != '\0')
		{
			if (map.box[i][j] == 'C')
			{
				coin.row = i;
				coin.col = j;
				things += check_sol(coin, map.box_for_solution);
			}
			j++;
		}
		i++;
	}
	return (things);
}

int	check_sol(t_point exit, char **map)
{
	if (map[exit.row - 1][exit.col] == 'F')
		return (1);
	if (map[exit.row + 1][exit.col] == 'F')
		return (1);
	if (map[exit.row][exit.col - 1] == 'F')
		return (1);
	if (map[exit.row][exit.col + 1] == 'F')
		return (1);
	return (0);
}
