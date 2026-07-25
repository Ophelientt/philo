/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onotto <onotto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:48:14 by onotteau          #+#    #+#             */
/*   Updated: 2026/07/25 18:31:24 by onotto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_monitor(t_rules *rules)
{
    int i;
    int full;
    long long time;

    i = 0;
    while (ft_verif_stop(rules) == 0)
    {
        i = 0;
        full = 0;
        while (i < rules->nb_philo)
        {
            time = ft_get_time();
            pthread_mutex_lock(&rules->philos[i].mutex_last_meal);
            if ((time - rules->philos[i].last_meal)  >= rules->time_to_die)
            {
                pthread_mutex_unlock(&rules->philos[i].mutex_last_meal);
                pthread_mutex_lock(&rules->mutex_stop);
                rules->stop = 1;
                pthread_mutex_unlock(&rules->mutex_stop);
                ft_message_died(&rules->philos[i]);
                return ;
            }
            else
                pthread_mutex_unlock(&rules->philos[i].mutex_last_meal);
            if (rules->must_eat != -1)
            {
                pthread_mutex_lock(&rules->philos[i].mutex_nb_meal);
                if (rules->philos[i].nb_meal >= rules->must_eat)
                    full++;
                pthread_mutex_unlock(&rules->philos[i].mutex_nb_meal);
            }
            i++;
        }
        if (rules->must_eat != -1)
        {
            if (full == rules->nb_philo)
            {
                pthread_mutex_lock(&rules->mutex_stop);
                rules->stop = 1;
                pthread_mutex_unlock(&rules->mutex_stop);
                return;
            }
        }
    }
}
