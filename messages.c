/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onotto <onotto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:48:14 by onotteau          #+#    #+#             */
/*   Updated: 2026/07/25 12:42:11 by onotto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_message_fork(t_philo *philo)
{
    pthread_mutex_lock(&philo->rules->mutex_print);
    printf("The philosopher %d has taken a fork.\n", philo->id);
    pthread_mutex_unlock(&philo->rules->mutex_print);
}
void    ft_message_eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->rules->mutex_print);
    printf("The philosopher %d is eating.\n", philo->id);
    pthread_mutex_unlock(&philo->rules->mutex_print);
}
void    ft_message_sleep(t_philo *philo)
{
    pthread_mutex_lock(&philo->rules->mutex_print);
    printf("The philosopher %d is sleeping.\n", philo->id);
    pthread_mutex_unlock(&philo->rules->mutex_print);
}
void    ft_message_think(t_philo *philo)
{
    pthread_mutex_lock(&philo->rules->mutex_print);
    printf("The philosopher %d is thinking.\n", philo->id);
    pthread_mutex_unlock(&philo->rules->mutex_print);
}
void    ft_message_died(t_philo *philo)
{
    pthread_mutex_lock(&philo->rules->mutex_print);
    printf("The philosopher %d died.\n", philo->id);
    pthread_mutex_unlock(&philo->rules->mutex_print);
}