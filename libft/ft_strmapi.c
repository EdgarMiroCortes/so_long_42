/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:23:53 by emiro-co          #+#    #+#             */
/*   Updated: 2023/05/16 13:50:29 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*k;

	i = 0;
	k = ft_strdup(s);
	if (k == NULL)
		return (NULL);
	while (k[i])
	{
		k[i] = f(i, k[i]);
		i++;
	}
	return (k);
}
