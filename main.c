/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onotto <onotto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:48:14 by onotteau          #+#    #+#             */
/*   Updated: 2026/07/25 11:09:23 by onotto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_rules	rules;

	if (ft_check_arg(ac, av) != 0)
		return (ft_error_message());
	if (ft_init_values_rules(&rules, ac, av) != 0)
		return (ft_error_message());
	if (ft_allocations(&rules) != 0)
		return (ft_error_message());
	ft_init_mutex(&rules);
	ft_init_values_philo(&rules);
	ft_start_simulation(&rules);
	return (0);
}
