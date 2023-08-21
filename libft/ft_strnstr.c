/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:50:07 by emiro-co          #+#    #+#             */
/*   Updated: 2023/05/11 12:50:01 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == '\0' || little == NULL)
		return ((char *)big);
	while (len > i && big[i] != 0)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (little[j] != 0 && big[i] == little[j] && len > i)
			{
				j++;
				i++;
			}
			if (little[j] == 0)
				return ((char *)&big[i - j]);
			i = i - j;
		}
		i ++;
	}
	return (0);
}
