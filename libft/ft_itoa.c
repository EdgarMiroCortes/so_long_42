/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:33:59 by emiro-co          #+#    #+#             */
/*   Updated: 2023/05/16 12:35:56 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	numlen(int n)
{
	int	i;

	i = 0;
	if (n == -2147483647 -1)
	{
		return (10);
	}
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

void	ft_2itoa(char *k, int n)
{
	int	i;
	int	imax;

	i = 0;
	imax = 0;
	if (n < 0)
	{
		k[i] = '-';
		n = n * -1;
		i++;
		imax = 1;
	}
	i = numlen(n) + imax;
	while (n > 9 && i >= imax)
	{
		k[i] = (n % 10 + '0');
		i --;
		n = n / 10;
	}
	k[i] = (n % 10 + '0');
}

char	*ft_itoa(int n)
{
	char	*k;

	k = (char *)malloc(sizeof(char) * (numlen(n)) + 2);
	if (!k)
		return (NULL);
	if (n == -2147483647 - 1)
	{
		ft_strlcpy(k, "-2147483648", 12);
		return (k);
	}
	k[numlen(n) + 1] = '\0';
	ft_2itoa(k, n);
	return (k);
}
