/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:58:54 by brahim            #+#    #+#             */
/*   Updated: 2023/05/05 19:19:24 by belkarto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>

int	is_dead(t_philo *philo)
{
	if (philo->data.last_meal - now_time() >= (uint64_t)philo->data.t_to_die)
	{
		pthread_mutex_lock(&philo->data.print);
		printf("%lld ms\t%d %s\n", time_stamp(philo->data.time), philo->rank, DIE);
		return (1);
	}
	return (0);
}

void	philos_spectator(t_philo *philo)
{
	while (1)
	{
		if (is_dead(philo) == 1)
			return ;
		philo = philo->right;
	}
}
