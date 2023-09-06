/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:32:10 by emiro-co          #+#    #+#             */
/*   Updated: 2023/09/06 17:24:20 by emiro-co         ###   ########.fr       */
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
		mlx_put_image_to_window(vr.mlx, vr.win, obj.door, x.col, x.row);
	if (vr.map.box[i.col][i.row] == 'P')
		mlx_put_image_to_window(vr.mlx, vr.win, obj.dino, x.col, x.row);
	if (vr.map.box[i.col][i.row] == 'W')
		mlx_put_image_to_window(vr.mlx, vr.win, obj.win, x.col, x.row);
}

t_object	ft_ini_objs(void *mlx)
{
	t_object	obj;
	int			p;

	p = 50;
	obj.fruit = mlx_xpm_file_to_image(mlx, "img/xpm/fruit.xpm", &p, &p);
	obj.dino = mlx_xpm_file_to_image(mlx, "img/xpm/dino1.xpm", &p, &p);
	obj.door = mlx_xpm_file_to_image(mlx, "img/xpm/door.xpm", &p, &p);
	obj.wall = mlx_xpm_file_to_image(mlx, "img/xpm/wall.xpm", &p, &p);
	obj.floor = mlx_xpm_file_to_image(mlx, "img/xpm/floor.xpm", &p, &p);
	obj.win = mlx_xpm_file_to_image(mlx, "img/xpm/win.xpm", &p, &p);
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
