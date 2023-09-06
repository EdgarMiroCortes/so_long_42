/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:25:12 by emiro-co          #+#    #+#             */
/*   Updated: 2023/09/06 16:31:26 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars		vars;

	if (argc != 2)
		exit(0);
	vars.map = ft_readmap(argv[1]);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, (vars.map.cols * 50), \
		(vars.map.rows * 50), ":)");
	mlx_hook(vars.win, 17, 0, closewindow, &vars);
	mlx_hook(vars.win, KEYUP, 1L << 0, closewindow_esc, (void *)&vars);
	mlx_hook(vars.win, KEYDOWN, 1L << 0, ft_move, (void *)&vars);
	ft_printmap(vars.map, vars, (ft_ini_objs(vars.mlx)));
	mlx_loop(vars.mlx);
}

void	ft_printmap(t_map map, t_vars vr, t_object obj)
{
	t_point		i;
	t_point		x;
	static int	finish_msg;

	x.row = 0;
	i.col = -1;
	while (map.box[++(i.col)])
	{
		x.col = 0;
		i.row = -1;
		while (map.box[i.col][++(i.row)])
		{
			ft_select_img(vr, obj, x, i);
			x.col += 50;
		}
		x.row += 50;
	}
	if (map.finished == 1 && finish_msg != 1)
	{
		ft_printf("\nYou Win!!! Total moves: %d\n", map.moves);
		ft_printf("\nPress ESC o the 'x' to close the game.\n");
		finish_msg = 1;
	}
}

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

void	ft_free(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	while (vars->map.box[i])
	{
		free(vars->map.box[i]);
		vars->map.box[i] = NULL;
		i++;
	}
	free(vars->map.box);
	while (vars->map.box_for_solution[i])
	{
		free(vars->map.box_for_solution[i]);
		vars->map.box_for_solution[i] = NULL;
		i++;
	}
	free(vars->map.box_for_solution);
}
