/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:25:12 by emiro-co          #+#    #+#             */
/*   Updated: 2023/11/23 16:25:54 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars		vars;

	if (argc != 2)
	{
		if (argc < 2)
			ft_printf("Error\nMissing Argv\n");
		else if (argc > 2)
			ft_printf("Error\nMultiple Argv Detected\n");
		exit(0);
	}
	vars.map = ft_readmap(argv[1]);
	vars.map.lastmove = 11;
	ft_checkmap(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, (vars.map.cols * 32), \
		(vars.map.rows * 32), ":)");
	mlx_hook(vars.win, 17, 0, closewindow, &vars);
	mlx_hook(vars.win, KEYUP, 1L << 0, closewindow_esc, (void *)&vars);
	mlx_hook(vars.win, KEYDOWN, 1L << 0, ft_move, (void *)&vars);
	vars.obj = ft_ini_objs(vars.mlx);
	ft_printmap(vars.map, vars, vars.obj);
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
			x.col += 32;
		}
		x.row += 32;
	}
	if (map.finished == 1 && finish_msg != 1)
	{
		ft_printf("\nYou Win!!! Total moves: %d\n", map.moves);
		ft_printf("\nPress ESC o the 'x' to close the game.\n");
		finish_msg = 1;
	}
}

void	ft_free_solong(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map.box[i])
	{
		free(vars->map.box[i]);
		vars->map.box[i] = NULL;
		i++;
	}
	free(vars->map.box);
	i = 0;
	while (vars->map.box_for_solution[i])
	{
		free(vars->map.box_for_solution[i]);
		vars->map.box_for_solution[i] = NULL;
		i++;
	}
	free(vars->map.box_for_solution);
	exit(1);
}
