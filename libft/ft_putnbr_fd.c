/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:48:00 by emiro-co          #+#    #+#             */
/*   Updated: 2023/05/12 10:08:44 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	k;

	nb = (long)n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = nb * (-1);
	}
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	k = nb % 10 + '0';
	ft_putchar_fd(k, fd);
}
