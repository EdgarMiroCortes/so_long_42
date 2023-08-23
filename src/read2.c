/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:18:11 by emiro-co          #+#    #+#             */
/*   Updated: 2023/08/23 17:33:39 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fill(char **map, t_point size, t_point cur, char to_fill)
{
	if (map[cur.y][cur.x] == 'E')
		return (1);
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| map[cur.y][cur.x] != to_fill)
		return (0);
	if (fill(map, size, (t_point){cur.x - 1, cur.y}, to_fill) == 1)
		return (1);
	if (fill(map, size, (t_point){cur.x + 1, cur.y}, to_fill) == 1)
		return (1);
	if (fill(map, size, (t_point){cur.x, cur.y - 1}, to_fill) == 1)
		return (1);
	if (fill(map, size, (t_point){cur.x, cur.y + 1}, to_fill) == 1)
		return (1);
	return (0);
}

int	flood_fill(char **map, t_point size, t_point begin)
{
	if (fill(map, size, begin, map[begin.y][begin.x]) == 1)
	{
		ft_printf("\n\nPuerta Encontrada\n");
		return (1);
	}
	return (0);
}
