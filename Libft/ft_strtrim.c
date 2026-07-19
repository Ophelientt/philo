/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onotteau <onotteau@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:13:34 by onotteau          #+#    #+#             */
/*   Updated: 2025/10/03 09:10:45 by onotteau         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

int	comp_str(char c, char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *str)
{
	char	*s3;
	size_t	start;
	size_t	end;
	size_t	n;
	size_t	len;

	len = ft_strlen (s1);
	start = 0;
	end = len - 1;
	while (comp_str(s1[start], str))
	{
		start++;
	}
	if (start == len)
		return (ft_strdup(""));
	while (comp_str (s1[end], str))
	{
		end--;
	}
	n = end - start + 1;
	s3 = ft_substr (s1, start, n);
	return (s3);
}
