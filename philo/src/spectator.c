/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:58:54 by brahim            #+#    #+#             */
/*   Updated: 2023/05/06 16:18:22 by brahim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>

int	is_dead(t_philo *philo)
{
	if (now_time() - philo->data.last_meal > (uint64_t)philo->data.t_to_die)
	{
		usleep(300);
		printf("%lld ms\t%d %s\n", time_stamp(philo->data.time), philo->rank, DIE);
		return (1);
	}
	return (0);
}

void	philos_spectator(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->data.print);
		usleep(300);
		if (is_dead(philo) == 1)
			return ;
		pthread_mutex_unlock(&philo->data.print);
		philo = philo->right;
	}
}
