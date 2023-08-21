/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:09:16 by emiro-co          #+#    #+#             */
/*   Updated: 2023/07/12 19:03:26 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	nbr_len(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	unsigned int	nb;
	char			c;

	if (n < 0)
	{
		nb = (unsigned int) -n;
		if (ft_putchar('-') < 0)
			return (-1);
	}
	else
		nb = (unsigned int) n;
	if (nb / 10)
	{
		if (ft_putnbr(nb / 10) < 0)
			return (-1);
	}
	c = nb % 10 + '0';
	if (ft_putchar(c) < 0)
		return (-1);
	return (0);
}

int	ft_print_int(int num)
{
	if (num == 0)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		return (1);
	}
	if (ft_putnbr(num) == 0)
		return (nbr_len(num));
	return (-1);
}
