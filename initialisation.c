/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onotto <onotto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:48:14 by onotteau          #+#    #+#             */
/*   Updated: 2026/07/25 19:25:13 by onotto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_nb(char *s)
{
	int	i;

	i = 0;
	if (!s || s[i] == '\0')
		return (1);
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_check_arg(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac != 5 && ac != 6)
		return (1);
	while (i < ac)
	{
		if (ft_is_nb(av[i]) == 0)
		{
			i++;
		}
		else
			return (1);
	}
	return (0);
}

int	ft_init_values_rules(t_rules *rules, int ac, char **av)
{
	long long	value;

	rules->philos = NULL;
	rules->forks = NULL;
	value = ft_atoll(av[1]);
	if (value <= 0 || value > INT_MAX)
		return (1);
	rules->nb_philo = (int)value;
	rules->time_to_die = ft_atoll(av[2]);
	rules->time_to_eat = ft_atoll(av[3]);
	rules->time_to_sleep = ft_atoll(av[4]);
	if (ac == 6)
		rules->must_eat = ft_atoll(av[5]);
	else
		rules->must_eat = -1;
	rules->start_time = 0;
	rules->stop = 0;
	if (rules->nb_philo <= 0 || rules->time_to_die <= 0
		|| rules->time_to_eat <= 0 || rules->time_to_sleep <= 0)
		return (1);
	return (0);
}

int	ft_allocations(t_rules *rules)
{
	rules->philos = malloc(sizeof(t_philo) * rules->nb_philo);
	if (!rules->philos)
		return (1);
	rules->forks = malloc(sizeof(pthread_mutex_t) * rules->nb_philo);
	if (!rules->forks)
	{
		free(rules->philos);
		return (1);
	}
	return (0);
}

void	ft_init_values_philo(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nb_philo)
	{
		rules->philos[i].id = i + 1;
		rules->philos[i].left_fork = &rules->forks[i];
		rules->philos[i].right_fork = &rules->forks[(i + 1) % rules->nb_philo];
		rules->philos[i].nb_meal = 0;
		rules->philos[i].last_meal = rules->start_time;
		rules->philos[i].rules = rules;
		i++;
	}
}
