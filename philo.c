/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onotto <onotto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:48:14 by onotteau          #+#    #+#             */
/*   Updated: 2026/07/25 12:48:55 by onotto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_start_simulation(t_rules *rules)
{
    int i;

    i = 0;
    rules->start_time = ft_get_time();
    while (i < rules->nb_philo)
    {
        rules->philos[i].last_meal = rules->start_time;
        pthread_create(&rules->philos[i].thread, NULL, ft_routine, &rules->philos[i]);
        i++;
    }
    i = 0;
    while (i < rules->nb_philo)
    {
        pthread_join(rules->philos[i].thread, NULL);
        i++;
    }
    return (0);
}
int     ft_verif_stop(t_rules *rules)
{
    pthread_mutex_lock(&rules->mutex_stop);
    if (rules->stop == 0)
    {
        pthread_mutex_unlock(&rules->mutex_stop);
        return (0);
    }
    pthread_mutex_unlock(&rules->mutex_stop);
    return (1);
}

void    ft_time_to_eat(t_philo *philo)
{
    if (philo->id % 2)
    {
        pthread_mutex_lock(philo->left_fork);
        ft_message_fork(philo);
        pthread_mutex_lock(philo->right_fork);
        ft_message_fork(philo);
    }
    else
    {
        pthread_mutex_lock(philo->right_fork);
        ft_message_fork(philo);
        pthread_mutex_lock(philo->left_fork);
        ft_message_fork(philo);
    }
    pthread_mutex_lock(&philo->mutex_last_meal);
    philo->last_meal = ft_get_time();
    pthread_mutex_unlock(&philo->mutex_last_meal);
    ft_message_eat(philo);
    usleep(philo->rules->time_to_eat * 1000);
    philo->nb_meal++;
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
}
void	*ft_routine(void *arg)
{
    t_philo *philo;
    
    philo = (t_philo *)arg;
    while (ft_verif_stop(philo->rules) == 0)
    {
        
        
        ft_time_to_eat(philo);
    }

    return(NULL);
}
