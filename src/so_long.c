/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:25:12 by emiro-co          #+#    #+#             */
/*   Updated: 2023/08/21 22:09:15 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close(int keycode, t_vars *vars)
{
	int	i;

	i = keycode;
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	main(int argc, int **argv)
{
	t_vars	vars;
	t_map	map;

	if (argc != 2)
		exit(0);
	map = ft_readmap(argv[1]);
	ft_checkmap(map.box);

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L << 0, close, &vars);
	mlx_loop(vars.mlx);
}
