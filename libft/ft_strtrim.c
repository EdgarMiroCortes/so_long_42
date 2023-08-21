/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:34:57 by emiro-co          #+#    #+#             */
/*   Updated: 2023/05/18 10:55:00 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*k;

	i = 0;
	while (check(s1[i], set) == 1)
		i++;
	if (i >= ft_strlen(s1))
	{
		k = ft_strdup("");
		if (k == NULL)
			return (NULL);
		else
			return (k);
	}
	j = ft_strlen(s1) - 1;
	while (check(s1[j], set) == 1)
		j--;
	k = ft_substr(s1, i, (j - i + 1));
	if (k == NULL)
		return (NULL);
	else
		return (k);
}
