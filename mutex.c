/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onotto <onotto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:48:14 by onotteau          #+#    #+#             */
/*   Updated: 2026/07/25 19:26:23 by onotto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int ft_init_mutex(t_rules *rules)
{
    int i;

    i = 0;
    while (i < rules->nb_philo)
    {
        if (pthread_mutex_init(&rules->forks[i], NULL) != 0)
            return (ft_destroy_forks(rules, i), ft_destroy_last_meal(rules, i),
                ft_free_allocations(rules), ft_destroy_nb_meal(rules, i), 1);
        if (pthread_mutex_init(&rules->philos[i].mutex_last_meal, NULL) != 0)
            return (ft_destroy_forks(rules, i + 1), ft_destroy_last_meal(rules, i),
                ft_destroy_nb_meal(rules, i), ft_free_allocations(rules), 1);
        if (pthread_mutex_init(&rules->philos[i].mutex_nb_meal, NULL) != 0)
            return (ft_destroy_forks(rules, i + 1), ft_destroy_last_meal(rules, i),
                ft_destroy_nb_meal(rules, i), ft_free_allocations(rules), 1);
        i++;
    }
    if (pthread_mutex_init(&rules->mutex_print, NULL) != 0)
        return (ft_destroy_forks(rules, rules->nb_philo), ft_destroy_last_meal(rules, rules->nb_philo),
            ft_free_allocations(rules), 1);
    if (pthread_mutex_init(&rules->mutex_stop, NULL) != 0)
        return (ft_destroy_forks(rules, rules->nb_philo), ft_destroy_last_meal(rules, rules->nb_philo),
           pthread_mutex_destroy(&rules->mutex_print), ft_free_allocations(rules), 1);
    return (0);
}