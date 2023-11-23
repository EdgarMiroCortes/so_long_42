/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teletransport.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:25:12 by emiro-co          #+#    #+#             */
/*   Updated: 2023/11/23 20:25:42 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int teletransport(t_map *map)
{
    t_point t1;
    t_point t2;
    
    t1 = set_point(map->box, 'T');
    t2 = set_point(map->box, 't');
    if(map->act.col == t1.col + 1)
    {
        map->box[map->act.row][map->act.col] = '0';
        map->act = t2;
        if (map->box[map->act.row][(map->act.col) - 1] == 'C')
			map->coins --;
        map->box[map->act.row][map->act.col - 1] = 'P';
        map->lastmove = 31;
    }
    else if(map->act.col == t2.col - 1)
    {
        map->box[map->act.row][map->act.col] = '0';
        map->act = t1;
        if (map->box[map->act.row][(map->act.col) + 1] == 'C')
			map->coins --;
        map->box[map->act.row][map->act.col + 1] = 'P'; 
        map->lastmove = 41;
    }
    return(1);
}