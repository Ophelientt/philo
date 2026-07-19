/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onotteau <onotteau@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:40:16 by onotteau          #+#    #+#             */
/*   Updated: 2025/10/11 12:38:54 by onotteau         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <bsd/string.h>

void	*ft_memmove(void *dest, void *src, size_t n)
{
	size_t			cmpt;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while (n--)
			d[n] = s[n];
	}
	if (dest < src)
	{
		cmpt = 0;
		while (cmpt < n)
		{
			d[cmpt] = s[cmpt];
			cmpt++;
		}
	}
	return (dest);
}
