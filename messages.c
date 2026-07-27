/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onotto <onotto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:48:14 by onotteau          #+#    #+#             */
/*   Updated: 2026/07/25 18:12:47 by onotto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_message_fork(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->rules->mutex_print);
	pthread_mutex_lock(&philo->rules->mutex_stop);
	if (philo->rules->stop != 0)
	{
		pthread_mutex_unlock(&philo->rules->mutex_stop);
		pthread_mutex_unlock(&philo->rules->mutex_print);
		return ;
	}
	pthread_mutex_unlock(&philo->rules->mutex_stop);
	time = ft_get_time() - philo->rules->start_time;
	printf("%lld : The philosopher %d has taken a fork.\n", time, philo->id);
	pthread_mutex_unlock(&philo->rules->mutex_print);
}

void	ft_message_eat(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->rules->mutex_print);
	pthread_mutex_lock(&philo->rules->mutex_stop);
	if (philo->rules->stop != 0)
	{
		pthread_mutex_unlock(&philo->rules->mutex_stop);
		pthread_mutex_unlock(&philo->rules->mutex_print);
		return ;
	}
	pthread_mutex_unlock(&philo->rules->mutex_stop);
	time = ft_get_time() - philo->rules->start_time;
	printf("%lld : The philosopher %d is eating.\n", time, philo->id);
	pthread_mutex_unlock(&philo->rules->mutex_print);
}

void	ft_message_sleep(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->rules->mutex_print);
	pthread_mutex_lock(&philo->rules->mutex_stop);
	if (philo->rules->stop != 0)
	{
		pthread_mutex_unlock(&philo->rules->mutex_stop);
		pthread_mutex_unlock(&philo->rules->mutex_print);
		return ;
	}
	pthread_mutex_unlock(&philo->rules->mutex_stop);
	time = ft_get_time() - philo->rules->start_time;
	printf("%lld : The philosopher %d is sleeping.\n", time, philo->id);
	pthread_mutex_unlock(&philo->rules->mutex_print);
}

void	ft_message_think(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->rules->mutex_print);
	pthread_mutex_lock(&philo->rules->mutex_stop);
	if (philo->rules->stop != 0)
	{
		pthread_mutex_unlock(&philo->rules->mutex_stop);
		pthread_mutex_unlock(&philo->rules->mutex_print);
		return ;
	}
	pthread_mutex_unlock(&philo->rules->mutex_stop);
	time = ft_get_time() - philo->rules->start_time;
	printf("%lld : The philosopher %d is thinking.\n", time, philo->id);
	pthread_mutex_unlock(&philo->rules->mutex_print);
}

void	ft_message_died(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->rules->mutex_print);
	time = ft_get_time() - philo->rules->start_time;
	printf("%lld : The philosopher %d died.\n", time, philo->id);
	pthread_mutex_unlock(&philo->rules->mutex_print);
}
