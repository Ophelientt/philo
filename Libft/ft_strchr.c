/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onotteau <onotteau@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:57:30 by onotteau          #+#    #+#             */
/*   Updated: 2025/10/11 12:12:51 by onotteau         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	p;

	p = (char) c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == p)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (p == '\0')
	{
		return ((char *)&s[i]);
	}
	return (0);
}
/*
int	main()
{
	char *s = "svghstgjdsgf";
	printf("%d\n", ft_strchr(s, 't' + 256) == s);
}
*/	
