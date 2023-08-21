/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:51:56 by emiro-co          #+#    #+#             */
/*   Updated: 2023/05/11 12:53:50 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;
	char	*s;
	char	a;

	a = (int) c;
	s = (char *)str;
	i = 0;
	while (i < n)
	{
		if (*s == a)
			return (s);
		i++;
		s++;
	}
	return (0);
}
