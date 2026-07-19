/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onotteau <onotteau@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 09:46:45 by onotteau          #+#    #+#             */
/*   Updated: 2025/10/08 09:50:03 by onotteau         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	while (lst != NULL && *lst != NULL)
	{
		temp = (*lst)-> next;
		del ((*lst)-> content);
		free (*lst);
		*lst = temp;
	}
	*lst = NULL;
}
