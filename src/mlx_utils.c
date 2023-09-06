/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:32:10 by emiro-co          #+#    #+#             */
/*   Updated: 2023/09/06 16:15:57 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	closewindow_esc(int key, t_vars *vars)
{
	(void) vars;
	if (key == 53)
	{
		ft_free(vars);
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0);
	}
	return (0);
}

int	closewindow(t_vars *vars)
{
	ft_free(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}
