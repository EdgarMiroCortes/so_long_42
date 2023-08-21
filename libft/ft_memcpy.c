/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:32:33 by emiro-co          #+#    #+#             */
/*   Updated: 2023/05/11 12:52:14 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{	
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!d && !s)
		return (0);
	while (n--)
		*d++ = *s++;
	return (dest);
}
