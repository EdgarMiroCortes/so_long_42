/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:05:01 by emiro-co          #+#    #+#             */
/*   Updated: 2023/11/23 17:32:51 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_checkmap(t_vars *vars)
{
	if (vars->map.format != 1)
	{
		ft_printf("Error\nInvalid Extension.\n");
		ft_free_solong(vars);
	}
	if ((!vars->map.box) || (!vars->map.walls)
		|| (check_size(vars->map.box) == 0)
		|| (check_characters(vars->map.box, vars->map.rows) == 0))
	{
		ft_printf("Error\nMap Error.\n");
		ft_free_solong(vars);
	}
	if ((check_initials(vars->map.box, vars->map.rows) == 0)
		|| (vars->map.coins == 0))
	{
		ft_printf("Error\n");
		ft_printf("Map need one inicial position (P), one Exit (E)");
		ft_printf(" and at least one Coin (C)\n");
		ft_free_solong(vars);
	}
	if (!vars->map.solution)
	{
		ft_printf("Error\nThe map must have a valid solution.\n");
		ft_free_solong(vars);
	}
}

int	check_size(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] == '\0' && ft_strlen(map[i]) != ft_strlen(map[0]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_characters(char **map, int rows)
{
	int		i;
	int		cols;
	char	*perm;
	char	act;
	int		j;

	perm = "10ECPTt\n";
	i = 0;
	cols = ft_strlen(map[0]);
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			act = map[i][j];
			if (ft_strchr(perm, act) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_initials(char **map, int rows)
{
	int		i;
	int		cols;
	int		j;
	int		p;
	int		e;

	i = 0;
	e = 0;
	p = 0;
	cols = ft_strlen(map[0]);
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (map[i][j] == 'E')
				e++;
			if (map[i][j] == 'P')
				p++;
			j++;
		}
		i++;
	}
	return (e == 1 && p == 1);
}
