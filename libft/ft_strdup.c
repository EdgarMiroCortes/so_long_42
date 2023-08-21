/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:42:05 by emiro-co          #+#    #+#             */
/*   Updated: 2023/05/16 13:05:04 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*k;

	k = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!k)
		return (NULL);
	ft_strlcpy(k, (char *)s, ft_strlen(s) + 1);
	return (k);
}
