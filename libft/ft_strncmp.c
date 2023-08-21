/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:00:50 by emiro-co          #+#    #+#             */
/*   Updated: 2023/05/11 12:51:41 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		if ((s1[i] == 0) && (s2[i] == 0))
			return (0);
		else if (s1[i] == 0)
		{
			return (-1);
		}
		else if (s2[i] == 0)
		{
			return (1);
		}
		else if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		else
		{
			i ++;
			n --;
		}
	}
	return (0);
}
