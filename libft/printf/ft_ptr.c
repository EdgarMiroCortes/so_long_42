/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:08:51 by emiro-co          #+#    #+#             */
/*   Updated: 2023/07/12 19:03:43 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ptr_len(unsigned long long n)
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

int	ft_printptr(unsigned long long n, char *base)
{
	char			c;

	if (n / 16)
		ft_printhexa(n / 16, base);
	c = base[n % 16];
	if (ft_putchar(c) < 0)
		return (-1);
	return (0);
}

int	ft_ptr(unsigned long long n)
{
	static char	*base_lo = "0123456789abcdef";

	if (ft_printstr("0x") < 0)
		return (-1);
	if (ft_printptr(n, base_lo) == 0)
		return (ptr_len(n) + 2);
	return (-1);
}
