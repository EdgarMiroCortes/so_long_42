/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:32:10 by emiro-co          #+#    #+#             */
/*   Updated: 2023/11/23 17:40:56 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_select_img(t_vars vr, t_object obj, t_point x, t_point i)
{
	if (vr.map.box[i.col][i.row] == 'C')
		mlx_put_image_to_window(vr.mlx, vr.win, obj.fruit, x.col, x.row);
	if (vr.map.box[i.col][i.row] == '0')
		mlx_put_image_to_window(vr.mlx, vr.win, obj.floor, x.col, x.row);
	if (vr.map.box[i.col][i.row] == '1')
		mlx_put_image_to_window(vr.mlx, vr.win, obj.wall, x.col, x.row);
	if (vr.map.box[i.col][i.row] == 'E')
		mlx_put_image_to_window(vr.mlx, vr.win, obj.win, x.col, x.row);
	if (vr.map.box[i.col][i.row] == 'P')
	{
		if(vr.map.lastmove == MOVEUP)
			mlx_put_image_to_window(vr.mlx, vr.win, obj.pac_up, x.col, x.row);
		else if(vr.map.lastmove == MOVEDOWN)
			mlx_put_image_to_window(vr.mlx, vr.win, obj.pac_down, x.col, x.row);
		else if(vr.map.lastmove == MOVEIZQ)
			mlx_put_image_to_window(vr.mlx, vr.win, obj.pac_izq, x.col, x.row);
		else if(vr.map.lastmove == MOVEDER)
			mlx_put_image_to_window(vr.mlx, vr.win, obj.pac_der, x.col, x.row);
	}
	if ((vr.map.box[i.col][i.row] == 'T') || (vr.map.box[i.col][i.row] == 't'))
		mlx_put_image_to_window(vr.mlx, vr.win, obj.door, x.col, x.row);
	if (vr.map.box[i.col][i.row] == 'W')
		mlx_put_image_to_window(vr.mlx, vr.win, obj.win, x.col, x.row);
}

t_object	ft_ini_objs(void *mlx)
{
	t_object	obj;
	int			p;

	p = 25;
	obj.pac_up = mlx_xpm_file_to_image(mlx, "img/pacman/pac_up.xpm", &p, &p);
	obj.pac_down = mlx_xpm_file_to_image(mlx, "img/pacman/pac_down.xpm", &p, &p);
	obj.pac_izq = mlx_xpm_file_to_image(mlx, "img/pacman/pac_left.xpm", &p, &p);
	obj.pac_der = mlx_xpm_file_to_image(mlx, "img/pacman/pac_right.xpm", &p, &p);
	obj.fruit = mlx_xpm_file_to_image(mlx, "img/pacman/coin.xpm", &p, &p);
	obj.door = mlx_xpm_file_to_image(mlx, "img/pacman/door.xpm", &p, &p);
	obj.wall = mlx_xpm_file_to_image(mlx, "img/pacman/wall.xpm", &p, &p);
	obj.floor = mlx_xpm_file_to_image(mlx, "img/pacman/floor.xpm", &p, &p);
	obj.win = mlx_xpm_file_to_image(mlx, "img/pacman/win.xpm", &p, &p);
	return (obj);
}

int	closewindow_esc(int key, t_vars *vars)
{
	(void) vars;
	if (key == 53)
	{
		ft_free_solong(vars);
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0);
	}
	return (0);
}

int	closewindow(t_vars *vars)
{
	ft_free_solong(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}
