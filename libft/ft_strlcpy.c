/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:09:24 by emiro-co          #+#    #+#             */
/*   Updated: 2023/04/13 15:07:08 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	n;
	char	*s;

	s = src;
	i = 0;
	n = ft_strlen(s);
	if (size != 0)
	{
		while (--size && s[i] != '\0')
		{
			dest[i] = s[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (n);
}

/*int main ()
{
    char string[] = "Hello there, Venus";
    char buffer[19];
    int r;
	int size = 3;

    r = ft_strlcpy(buffer,string,size);

    printf("Copied '%s' into '%s', length %d\n",
            string,
            buffer,
            r
          );
	return (0);
}*/