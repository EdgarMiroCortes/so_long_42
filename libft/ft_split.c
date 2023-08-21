/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:14:38 by emiro-co          #+#    #+#             */
/*   Updated: 2023/07/12 19:05:11 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_splits(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && s[i] != c)
			count++;
		if (i > 0 && s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static size_t	ft_search_split(char const *s, char c, size_t i)
{
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

char	**ftfree(char **s, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
		free(s[i++]);
	free(s);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	end;
	char	**ret;

	i = 0;
	j = 0;
	ret = (char **)malloc(sizeof(char *) * (ft_count_splits(s, c) + 1));
	if (ret == NULL)
		return (NULL);
	while (s[i])
	{
		if ((i > 0 && s[i] != c && s[i - 1] == c) || (i == 0 && s[i] != c))
		{
			end = ft_search_split(s, c, i) - i;
			ret[j] = (ft_substr(s, i, end));
			if (ret[j] == NULL)
				return (ftfree(ret, j));
			j++;
		}
		i++;
	}
	ret[j] = NULL;
	return (ret);
}
