/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:25:12 by emiro-co          #+#    #+#             */
/*   Updated: 2023/08/30 17:45:26 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move(int key, void *map)
{
	t_map *aux;

	aux = (t_map *)map;
	if (key == 126)
	{
		move_up(*aux);
		//ft_printf("Key UP");
	}
	if (key == 125)
	{
		move_down(*aux);
		//ft_printf("Key UP");
	}
	if (key == 123)
		move_izq(*aux);

	if (key == 124)
		move_der(*aux);

	
	int i = 0;
	ft_printf("\n\n\n");
	while (i < aux->rows)
		ft_printf("%s",aux->box[i++]);
	return (1);
}

int	move_up(t_map map)
{
	if (map.box[map.act.x][map.act.y - 1] ==  'E')
	{
		// SI ENTRA AQUI DENTRO EL JUGADOR HA GANADO
		if (map.coins == 0)
			return (1);
		return (0);
	}
	if (map.box[map.act.x][map.act.y - 1] != '1')
	{
		map.box[map.act.x][map.act.y] = '0';
		map.box[map.act.x][map.act.y - 1] = 'P';
		map.act.y --; 
		return (1);
	}
	return (0);
}

int	move_down(t_map map)
{
	if (map.box[map.act.x][map.act.y + 1] ==  'E')
	{
		// SI ENTRA AQUI DENTRO EL JUGADOR HA GANADO
		if (map.coins == 0)
			return (1);
		return (0);
	}
	if (map.box[map.act.x][map.act.y + 1] != '1')
	{
		map.box[map.act.x][map.act.y] = '0';
		map.box[map.act.x][map.act.y + 1] = 'P';
		map.act.y ++; 
		return (1);
	}
	return (0);
}

int	move_izq(t_map map)
{
	if (map.box[map.act.x - 1][map.act.y] ==  'E')
	{
		// SI ENTRA AQUI DENTRO EL JUGADOR HA GANADO
		if (map.coins == 0)
			return (1);
		return (0);
	}
	if (map.box[map.act.x - 1][map.act.y] != '1')
	{
		map.box[map.act.x][map.act.y] = '0';
		map.box[map.act.x - 1][map.act.y] = 'P';
		map.act.x --; 

		return (1);
	}
	return (0);
}

int	move_der(t_map map)
{
	if (map.box[map.act.x + 1][map.act.y] ==  'E')
	{
		// SI ENTRA AQUI DENTRO EL JUGADOR HA GANADO
		if (map.coins == 0)
			return (1);
		return (0);
	}
	if (map.box[map.act.x + 1][map.act.y] != '1')
	{
		map.box[map.act.x][map.act.y] = '0';
		map.box[map.act.x + 1][map.act.y] = 'P';
		map.act.x ++;
		return (1);
	}
	return (0);
}
