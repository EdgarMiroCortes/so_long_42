/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:45:54 by emiro-co          #+#    #+#             */
/*   Updated: 2023/05/18 12:36:20 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*temp;

	if (lst == NULL || f == NULL)
		return (NULL);
	ret = NULL;
	while (lst)
	{
		temp = ft_lstnew((f(lst->content)));
		if (!temp)
		{
			ft_lstclear(&temp, del);
			return (NULL);
		}
		ft_lstadd_back(&ret, temp);
		lst = lst->next;
	}
	return (ret);
}
