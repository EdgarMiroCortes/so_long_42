/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:09:08 by emiro-co          #+#    #+#             */
/*   Updated: 2023/07/12 19:03:33 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	hexa_len(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	ft_printhexa(long int nb, char *base)
{
	char			c;

	if (nb / 16)
	{
		if (ft_printhexa(nb / 16, base) < 0)
			return (-1);
	}
	c = base[nb % 16];
	if (ft_putchar(c) < 0)
		return (-1);
	return (0);
}

int	ft_hexnum(unsigned int nbr, char s)
{
	static char		*base = "0123456789ABCDEF";
	static char		*base_lo = "0123456789abcdef";

	if (nbr == 0)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		return (1);
	}
	if (s == 'x')
	{
		if (ft_printhexa(nbr, base_lo) < 0)
			return (-1);
	}
	else
	{
		if (ft_printhexa(nbr, base) < 0)
			return (-1);
	}
	return (hexa_len(nbr));
}
