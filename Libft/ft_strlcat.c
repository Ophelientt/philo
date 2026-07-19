/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onotteau <onotteau@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:57:40 by onotteau          #+#    #+#             */
/*   Updated: 2025/10/02 16:01:21 by onotteau         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <bsd/string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	i;
	size_t	j;
	size_t	len_src;
	size_t	len_dst;

	i = ft_strlen(dst);
	j = 0;
	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (dsize <= len_dst)
		return (dsize + len_src);
	else
	{
		while (i < (dsize - 1) && (src[j] != '\0'))
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	return (len_dst + len_src);
}
/*
int	main()
{
	printf("Resultat attendu: %zu\n", strlcat("Hello[50]", "world", 8));
	printf("Resultat obtenu: %zu\n", ft_strlcat("Hello[50]", "world", 8));
	return (0);
}
*/	