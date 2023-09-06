/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:25:12 by emiro-co          #+#    #+#             */
/*   Updated: 2023/09/06 16:01:47 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move(int key, void *vars)
{
	t_vars	*aux;

	aux = (t_vars *)vars;
	if (aux->map.finished != 1 && (key == ON_KEYUP) && (move_up(&(aux->map))))
	{
		aux->map.act.row --;
		ft_printf("Moves: %d, Coins: %d\n", ++(aux->map.moves), aux->map.coins);
	}
	if (aux->map.finished != 1 && (key == ON_KEYDOWN) && move_down(&(aux->map)))
	{
		aux->map.act.row ++;
		ft_printf("Moves: %d, Coins: %d\n", ++(aux->map.moves), aux->map.coins);
	}
	if (aux->map.finished != 1 && (key == ON_KEYIZQ) && move_izq(&(aux->map)))
	{
		aux->map.act.col --;
		ft_printf("Moves: %d, Coins: %d\n", ++(aux->map.moves), aux->map.coins);
	}
	if (aux->map.finished != 1 && (key == ON_KEYDER) && move_der(&(aux->map)))
	{
		aux->map.act.col ++;
		ft_printf("Moves: %d, Coins: %d\n", ++(aux->map.moves), aux->map.coins);
	}
	ft_printmap(aux->map, *aux, (ft_ini_objs(aux->mlx)));
	return (1);
}

int	move_izq(t_map *map)
{
	if (map->box[map->act.row][(map->act.col) - 1] == 'E' && map->coins == 0)
	{
		map->box[map->act.row][map->act.col] = '0';
		map->box[map->act.row][(map->act.col) - 1] = 'W';
		map->finished = 1;
		return (1);
	}
	if (map->box[map->act.row][(map->act.col) - 1] != '1')
	{
		if (map->box[map->act.row][(map->act.col) - 1] == 'C')
			map->coins --;
		if (map->act.row == map->exit.row && map->act.col == map->exit.col)
			map->box[map->act.row][map->act.col] = 'E';
		else
			map->box[map->act.row][map->act.col] = '0';
		map->box[map->act.row][(map->act.col) - 1] = 'P';
		return (1);
	}
	return (0);
}

int	move_der(t_map *map)
{
	if (map->box[map->act.row][(map->act.col) + 1] == 'E' && map->coins == 0)
	{
		map->box[map->act.row][map->act.col] = '0';
		map->box[map->act.row][(map->act.col) + 1] = 'W';
		map->finished = 1;
		return (1);
	}
	if (map->box[map->act.row][(map->act.col) + 1] != '1')
	{
		if (map->box[map->act.row][(map->act.col) + 1] == 'C')
			map->coins --;
		if (map->act.row == map->exit.row && map->act.col == map->exit.col)
			map->box[map->act.row][map->act.col] = 'E';
		else
			map->box[map->act.row][map->act.col] = '0';
		map->box[map->act.row][(map->act.col) + 1] = 'P';
		return (1);
	}
	return (0);
}

int	move_up(t_map *map)
{
	if (map->box[(map->act.row) - 1][map->act.col] == 'E' && map->coins == 0)
	{
		map->box[map->act.row][map->act.col] = '0';
		map->box[(map->act.row) - 1][map->act.col] = 'W';
		map->finished = 1;
		return (1);
	}
	if (map->box[(map->act.row) - 1][map->act.col] != '1')
	{
		if (map->box[(map->act.row) - 1][map->act.col] == 'C')
			map->coins --;
		if (map->act.row == map->exit.row && map->act.col == map->exit.col)
			map->box[map->act.row][map->act.col] = 'E';
		else
			map->box[map->act.row][map->act.col] = '0';
		map->box[(map->act.row) - 1][map->act.col] = 'P';
		return (1);
	}
	return (0);
}

int	move_down(t_map *map)
{
	if (map->box[(map->act.row) + 1][map->act.col] == 'E' && map->coins == 0)
	{
		map->box[map->act.row][map->act.col] = '0';
		map->box[(map->act.row) + 1][map->act.col] = 'W';
		map->finished = 1;
		return (1);
	}
	if (map->box[(map->act.row) + 1][map->act.col] != '1')
	{
		if (map->box[(map->act.row) + 1][map->act.col] == 'C')
			map->coins --;
		if (map->act.col == map->exit.col && map->act.row == map->exit.row)
			map->box[map->act.row][map->act.col] = 'E';
		else
			map->box[map->act.row][map->act.col] = '0';
		map->box[(map->act.row) + 1][map->act.col] = 'P';
		return (1);
	}
	return (0);
}
