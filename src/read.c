/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:32:10 by emiro-co          #+#    #+#             */
/*   Updated: 2023/08/21 23:01:22 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	ft_readmap(char *path)
{
	t_map	map;
	int		fd;

	// comprovar que sea .ber
	if (!ft_strnstr(path, ".ber", ft_strlen(path)))
		exit(0);
	else
	{
		ft_printf("map ok");
	}

	fd = open(path, O_RDONLY);
	getnextline(fd);
	return (map);
}

int	ft_check_format(char *str)
{
	//ft_strnstr
}
