/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onotteau <onotteau@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:15:41 by onotteau          #+#    #+#             */
/*   Updated: 2025/10/02 16:51:10 by onotteau         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	longueurdes;
	size_t	i;
	size_t	n;
	char	*sub;

	i = 0;
	if (s == NULL)
		return (NULL);
	longueurdes = ft_strlen(s);
	if (start >= longueurdes)
		n = 0;
	else if (len > longueurdes - start)
		n = longueurdes - start;
	else
		n = len;
	sub = malloc (n + 1);
	if (sub == NULL)
		return (NULL);
	while (i < n)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[n] = '\0';
	return (sub);
}
