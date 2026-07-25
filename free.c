/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onotto <onotto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:48:14 by onotteau          #+#    #+#             */
/*   Updated: 2026/07/23 15:43:43 by onotto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_error_message(void)
{
    write(2, "Error\n", 6);
    return (1);
}

void ft_destroy_forks(t_rules *rules, int i)
{
    int j;

    j = 0;
    while (j < i)
    {
        pthread_mutex_destroy(&rules->forks[i]);
        j++;
    }
}

void ft_destroy_last_meal(t_rules *rules, int i)
{
    int j;
    
    j = 0;
    while (j < i)
    {
        pthread_mutex_destroy(&rules->philos[j].mutex_last_meal);
        j++;
    } 
}
void	ft_free_allocations(t_rules *rules)
{
	if (rules->philos)
	{
		free(rules->philos);
		rules->philos = NULL;
	}
	if (rules->forks)
	{
		free(rules->forks);
		rules->forks = NULL;
	}
}