/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:36:41 by emiro-co          #+#    #+#             */
/*   Updated: 2023/05/11 11:35:17 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *d, const char *s, size_t size)
{
	size_t			i;
	size_t			ret;
	size_t			lend;

	i = 0;
	lend = ft_strlen(d);
	if (size > lend)
		ret = lend + ft_strlen(s);
	else
		ret = ft_strlen(s) + size;
	while (s[i] != '\0' && ((lend + 1) < size))
	{
		d[lend] = s[i];
		lend++;
		i++;
	}
	d[lend] = '\0';
	return (ret);
}
