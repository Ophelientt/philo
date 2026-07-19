/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onotteau <onotteau@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 09:55:20 by onotteau          #+#    #+#             */
/*   Updated: 2025/10/11 12:08:22 by onotteau         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newnode;
	t_list	*newlist;
	void	*content;

	newlist = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst != NULL)
	{
		content = f(lst ->content);
		if (content == NULL)
			return (ft_lstclear (&newlist, del), NULL);
		newnode = ft_lstnew (content);
		if (newnode == NULL)
		{
			del(content);
			ft_lstclear (&newlist, del);
			return (NULL);
		}
		ft_lstadd_back (&newlist, newnode);
		lst = lst->next;
	}
	return (newlist);
}
