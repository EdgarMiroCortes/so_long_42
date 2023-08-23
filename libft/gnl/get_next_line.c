/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:55:55 by emiro-co          #+#    #+#             */
/*   Updated: 2023/08/23 14:17:32 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_gnl(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
		str = NULL;
		return (NULL);
	}
	return (NULL);
}

char	*ft_fill_gnl(char *temp, int fd)
{
	char		*buf;
	int			nr_byt;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ft_free_gnl(&temp));
	nr_byt = 1;
	while (nr_byt > 0 && !ft_strlen_gnl(temp, 2))
	{
		nr_byt = read(fd, buf, BUFFER_SIZE);
		if (nr_byt == -1)
		{
			ft_free_gnl(&buf);
			return (ft_free_gnl(&temp));
		}
		if (nr_byt > 0)
		{
			buf[nr_byt] = '\0';
			temp = ft_strjoin_gnl(temp, buf);
			if (!temp)
				return (ft_free_gnl(&buf));
		}
	}
	free (buf);
	return (temp);
}

char	*ft_get_line_gnl(char *temp)
{
	char		*line;
	ssize_t		i;

	i = ft_strlen_gnl(temp, 3);
	if (temp[i] == '\n')
		line = ft_substr_gnl(temp, 0, i + 1);
	else
		line = ft_substr_gnl(temp, 0, i);
	return (line);
}

char	*ft_clean_gnl(char *s, char *line)
{
	char	*temp2;

	if (ft_strlen_gnl(s, 2) && s[ft_strlen_gnl(s, 3) + 1])
	{
		temp2 = s;
		s = ft_substr_gnl(s, ft_strlen_gnl(line, 1), ft_strlen_gnl(s, 1));
		if (temp2 != NULL)
			free(temp2);
		if (s == NULL)
			return (ft_free_gnl(&s));
	}
	else
	{
		free(s);
		s = NULL;
	}
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*temp = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = ft_fill_gnl(temp, fd);
	if (!temp)
		return (NULL);
	line = ft_get_line_gnl(temp);
	if (line == NULL)
		return (ft_free_gnl(&temp));
	temp = ft_clean_gnl(temp, line);
	return (line);
}
