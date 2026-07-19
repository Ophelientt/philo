/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onotteau <onotteau@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:54:43 by onotteau          #+#    #+#             */
/*   Updated: 2025/10/11 11:59:57 by onotteau         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	count_word(char const *s, char c)
{
	int	i;
	int	nb_mots;

	i = 0;
	nb_mots = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			i++;
		}
		else
		{
			nb_mots++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (nb_mots);
}

char	*alloc_word(char const *s, char c)
{
	int		len;
	char	*word;
	int		i;

	i = 0;
	len = 0;
	while (s[len] != '\0' && s[len] != c)
	{
		len++;
	}
	word = (char *) malloc ((len + 1) * sizeof (char));
	if (word == NULL)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**freememory(char **result, int m)
{
	while (m >= 0)
	{
		free(result[m]);
		m--;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		m;
	int		i;

	result = (char **) malloc(((count_word(s, c)) + 1) * sizeof (char *));
	if (result == NULL)
		return (NULL);
	m = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			result[m] = alloc_word (&s[i], c);
			if (result[m] == NULL)
				return (freememory(result, m - 1), NULL);
			while (s[i] != '\0' && s[i] != c)
				i++;
			m++;
		}
	}
	result[m] = NULL;
	return (result);
}
