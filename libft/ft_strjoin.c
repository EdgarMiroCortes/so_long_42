/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:05:10 by emiro-co          #+#    #+#             */
/*   Updated: 2023/05/16 15:34:16 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*k;

	k = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (k == NULL)
		return (NULL);
	ft_strlcat(k, s1, ft_strlen(s1) + 1);
	ft_strlcat(k, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (k);
}
