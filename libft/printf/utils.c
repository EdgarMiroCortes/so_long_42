/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:08:30 by emiro-co          #+#    #+#             */
/*   Updated: 2023/07/12 19:03:49 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putchar(char c)
{
	if (write (1, &c, sizeof(char)) < 0)
		return (-1);
	return (1);
}

int	ft_printstr(char *s)
{
	int	ret;
	int	cnt;

	cnt = 0;
	ret = 0;
	if (s == NULL)
		return (ft_printstr("(null)"));
	else
	{
		while (*s)
		{
			ret = ft_putchar(*s);
			if (ret < 0)
				return (-1);
			s++;
			cnt += ret;
		}
	}
	return (cnt);
}
