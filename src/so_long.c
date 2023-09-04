/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:25:12 by emiro-co          #+#    #+#             */
/*   Updated: 2023/09/04 12:58:40 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
//{
//	char	*dst;
//
//	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//	*(unsigned int *)dst = color;
//}

int	closewindow(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars		vars;

	if (argc != 2)
		exit(0);
	vars.map = ft_readmap(argv[1]);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, (vars.map.cols * 50), (vars.map.rows * 50), ":)");
	mlx_hook(vars.win, 2, 1L << 0, closewindow, &vars);
	mlx_hook(vars.win, 17, 0, closewindow, &vars);
	mlx_hook(vars.win, KEYDOWN, 1L << 0, ft_move, (void *)&vars);
	ft_printmap(vars.map, vars, (ft_ini_objs(vars.mlx)));
	mlx_loop(vars.mlx);
}

void	ft_printmap(t_map map, t_vars vr, t_object obj)
{
	t_point		i;
	t_point		x;

	x.y = 0;
	i.x = -1;
	while (map.box[++(i.x)])
	{
		x.x = 0;
		i.y = -1;
		while (map.box[i.x][++(i.y)])
		{
			if (map.box[i.x][i.y] == 'C')
				mlx_put_image_to_window(vr.mlx, vr.win, obj.fruit, x.x, x.y);
			if (map.box[i.x][i.y] == '0')
				mlx_put_image_to_window(vr.mlx, vr.win, obj.floor, x.x, x.y);
			if (map.box[i.x][i.y] == '1')
				mlx_put_image_to_window(vr.mlx, vr.win, obj.wall, x.x, x.y);
			if (map.box[i.x][i.y] == 'E')
				mlx_put_image_to_window(vr.mlx, vr.win, obj.door, x.x, x.y);
			if (map.box[i.x][i.y] == 'P')
				mlx_put_image_to_window(vr.mlx, vr.win, obj.dino, x.x, x.y);
			x.x += 50;
		}
		x.y += 50;
	}
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
	return (obj);
}
