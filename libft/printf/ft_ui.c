/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ui.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:08:41 by emiro-co          #+#    #+#             */
/*   Updated: 2023/07/12 19:03:46 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ui_len(unsigned int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_putui(unsigned int n)
{
	char	c;

	if (n / 10)
	{
		if (ft_putui(n / 10) < 0)
			return (-1);
	}
	c = n % 10 + '0';
	if (ft_putchar(c) < 0)
		return (-1);
	return (0);
}

int	ft_ui(unsigned int n)
{
	if (n == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	if (ft_putui(n) < 0)
		return (-1);
	return (ui_len(n));
}
