/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onotteau <onotteau@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:56:23 by onotteau          #+#    #+#             */
/*   Updated: 2025/10/09 14:23:24 by onotteau         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_intsign(int n)
{
	int	sign;

	if (n < 0)
		sign = 1;
	if (n == 0 || n > 0)
		sign = 0;
	return (sign);
}

int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = n * (-1);
	}
	if (n == 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nbr;
	int		len;
	int		sign;
	int		i;
	char	*str;

	nbr = n;
	sign = ft_intsign(nbr);
	len = ft_intlen(nbr) + sign;
	str = malloc (sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = len;
	str[i--] = '\0';
	if (sign == 1)
		nbr = nbr * (-1);
	while (i >= 0)
	{
		str[i] = ((nbr % 10) + '0');
		nbr = (nbr / 10);
		i--;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}
