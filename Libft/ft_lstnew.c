/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onotteau <onotteau@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:11:44 by onotteau          #+#    #+#             */
/*   Updated: 2025/10/11 11:12:28 by onotteau         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;
	t_list	*lst;

	node = malloc (sizeof (t_list));
	if (!node)
		return (NULL);
	node ->content = content;
	node ->next = NULL;
	lst = node;
	return (lst);
}
