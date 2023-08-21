/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:35:07 by emiro-co          #+#    #+#             */
/*   Updated: 2023/05/16 12:37:44 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	msize;

	msize = nmemb * size;
	ptr = malloc(msize);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, msize);
	return (ptr);
}
