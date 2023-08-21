/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:27:32 by emiro-co          #+#    #+#             */
/*   Updated: 2023/05/19 11:18:50 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	if ((char )c == '\0')
		return ((char *)(str + ft_strlen(str)));
	else
	{
		while (*str != '\0')
		{
			if (*str == (char )c)
				return ((char *)str);
			str++;
		}
		return (0);
	}
}
