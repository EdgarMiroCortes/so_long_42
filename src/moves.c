/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:25:12 by emiro-co          #+#    #+#             */
/*   Updated: 2023/09/04 17:17:38 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move(int key, void *vars)
{
	t_vars	*aux;

	aux = (t_vars *)vars;
	if ((key == ON_KEYUP) && (move_up(&(aux->map))))
	{
		aux->map.act.x --;
		ft_printf("Moves: %d, Coins: %d, Finished: %d \n", (aux->map.moves)++, aux->map.coins, aux->map.finished);
	}
	if ((key == ON_KEYDOWN) && move_down(&(aux->map)))
	{
		aux->map.act.x ++;
		ft_printf("Moves: %d, Coins: %d, Finished: %d \n", (aux->map.moves)++, aux->map.coins, aux->map.finished);
	}
	if ((key == ON_KEYIZQ) && move_izq(&(aux->map)))
	{
		aux->map.act.y --;
		ft_printf("Moves: %d, Coins: %d, Finished: %d \n", (aux->map.moves)++, aux->map.coins, aux->map.finished);
	}
	if ((key == ON_KEYDER) && move_der(&(aux->map)))
	{
		aux->map.act.y ++;
		ft_printf("Moves: %d, Coins: %d, Finished: %d \n", (aux->map.moves)++, aux->map.coins, aux->map.finished);
	}
	ft_printmap(aux->map, *aux, (ft_ini_objs(aux->mlx)));
	return (1);
}

int	move_izq(t_map *map)
{
	if (map->box[map->act.x][(map->act.y) - 1] == 'E' && map->coins == 0)
	{
		map->finished = 1;
		return (1);
	}
	if (map->box[map->act.x][(map->act.y) - 1] != '1')
	{
		if (map->box[map->act.x][(map->act.y) - 1] == 'C')
			map->coins --;
		if (map->act.x == map->exit.y && map->act.y == map->exit.x)
			map->box[map->act.x][map->act.y] = 'E';
		else
			map->box[map->act.x][map->act.y] = '0';
		map->box[map->act.x][(map->act.y) - 1] = 'P';
		return (1);
	}
	return (0);
}

int	move_der(t_map *map)
{
	if (map->box[map->act.x][(map->act.y) + 1] == 'E' && map->coins == 0)
	{
		map->finished = 1;
		return (1);
	}
	if (map->box[map->act.x][(map->act.y) + 1] != '1')
	{
		if (map->box[map->act.x][(map->act.y) + 1] == 'C')
			map->coins --;
		if (map->act.x == map->exit.y && map->act.y == map->exit.x)
			map->box[map->act.x][map->act.y] = 'E';
		else
			map->box[map->act.x][map->act.y] = '0';
		map->box[map->act.x][(map->act.y) + 1] = 'P'; 
		return (1);
	}
	return (0);
}

int	move_up(t_map *map)
{
	if (map->box[(map->act.x) - 1][map->act.y] == 'E' && map->coins == 0)
	{
		map->finished = 1;
		return (1);
	}
	if (map->box[(map->act.x) - 1][map->act.y] != '1')
	{
		if (map->box[(map->act.x) - 1][map->act.y] == 'C')
			map->coins --;
		if (map->act.x == map->exit.y && map->act.y == map->exit.x)
			map->box[map->act.x][map->act.y] = 'E';
		else
			map->box[map->act.x][map->act.y] = '0';
		map->box[(map->act.x) - 1][map->act.y] = 'P';
		return (1);
	}
	return (0);
}

int	move_down(t_map *map)
{
	if (map->box[(map->act.x) + 1][map->act.y] == 'E' && map->coins == 0)
	{
		map->finished = 1;
		return (1);
	}
	if (map->box[(map->act.x) + 1][map->act.y] != '1')
	{
		if (map->box[(map->act.x) + 1][map->act.y] == 'C')
			map->coins --;
		if (map->act.x == map->exit.y && map->act.y == map->exit.x)
			map->box[map->act.x][map->act.y] = 'E';
		else
			map->box[map->act.x][map->act.y] = '0';
		map->box[(map->act.x) + 1][map->act.y] = 'P';
		return (1);
	}
	return (0);
}
