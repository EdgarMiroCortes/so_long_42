/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:22:09 by emiro-co          #+#    #+#             */
/*   Updated: 2023/05/19 10:30:08 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	if ((char)c == '\0')
		return ((char *)(s + ft_strlen(s)));
	else
	{
		while (*s != '\0')
		{
			i++;
			s++;
		}
		while (i >= 0)
		{
			if (*s == (char)c)
				return ((char *)s);
			s--;
			i --;
		}
		return (0);
	}
}
