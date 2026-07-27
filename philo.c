/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onotto <onotto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:48:14 by onotteau          #+#    #+#             */
/*   Updated: 2026/07/25 19:29:04 by onotto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_start_simulation(t_rules *rules)
{
	int	i;

	i = 0;
	rules->start_time = ft_get_time();
	while (i < rules->nb_philo)
	{
		rules->philos[i].last_meal = rules->start_time;
		pthread_create(&rules->philos[i].thread, NULL, ft_routine,
			&rules->philos[i]);
		i++;
	}
	ft_monitor(rules);
	i = 0;
	while (i < rules->nb_philo)
	{
		pthread_join(rules->philos[i].thread, NULL);
		i++;
	}
	free(rules->philos);
	free(rules->forks);
	return (0);
}

int	ft_usleep(t_philo *philo, long long time_to)
{
	long long	start;
	long long	now;

	start = ft_get_time();
	now = start;
	while ((now - start) < time_to)
	{
		if (ft_verif_stop(philo->rules) != 0)
			return (1);
		usleep(100);
		now = ft_get_time();
	}
	return (0);
}

int	ft_verif_stop(t_rules *rules)
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

void	ft_time_to_eat(t_philo *philo)
{
	if (philo->id % 2)
	{
		(pthread_mutex_lock(philo->left_fork), ft_message_fork(philo),
			pthread_mutex_lock(philo->right_fork), ft_message_fork(philo));
	}
	else
	{
		(pthread_mutex_lock(philo->right_fork), ft_message_fork(philo),
			pthread_mutex_lock(philo->left_fork), ft_message_fork(philo));
	}
	pthread_mutex_lock(&philo->mutex_last_meal);
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(&philo->mutex_last_meal);
	ft_message_eat(philo);
	if (ft_usleep(philo, philo->rules->time_to_eat) == 0)
	{
		pthread_mutex_lock(&philo->mutex_nb_meal);
		philo->nb_meal++;
		pthread_mutex_unlock(&philo->mutex_nb_meal);
	}
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (ft_verif_stop(philo->rules) == 0)
	{
		if (philo->rules->nb_philo == 1)
		{
			pthread_mutex_lock(philo->right_fork);
			ft_message_fork(philo);
			ft_usleep(philo, philo->rules->time_to_die);
			pthread_mutex_unlock(philo->right_fork);
			return (NULL);
		}
		ft_time_to_eat(philo);
		if (ft_verif_stop(philo->rules) != 0)
			return (NULL);
		ft_message_sleep(philo);
		ft_usleep(philo, philo->rules->time_to_sleep);
		if (ft_verif_stop(philo->rules) != 0)
			return (NULL);
		ft_message_think(philo);
	}
	return (NULL);
}
