/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:44:53 by emiro-co          #+#    #+#             */
/*   Updated: 2023/05/10 14:55:12 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n--)
	{
		if (*st1 != *st2)
			return (*st1 - *st2);
		st1++;
		st2++;
	}
	return (0);
}

/*int main ()
{
	char *s1 = "hol";
	char *s2 = "hola";
	size_t n = 5;
	printf("%d\n", ft_memcmp(s1, s2, n));
	printf("%d\n", memcmp(s1, s2, n));
	return (0);
}*/