/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onotteau <onotteau@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:45:18 by onotteau          #+#    #+#             */
/*   Updated: 2025/10/03 14:26:08 by onotteau         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *ptr, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	v;
	size_t			cmpt;

	p = (unsigned char *)ptr;
	v = (unsigned char)c;
	cmpt = 0;
	while (cmpt < n)
	{
		if (*p == v)
		{
			return (p);
		}
		cmpt++;
		p++;
	}
	return (NULL);
}
