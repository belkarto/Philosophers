/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:58:54 by brahim            #+#    #+#             */
/*   Updated: 2023/05/09 03:32:20 by belkarto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->cycle_mutex);
	if (philo->cycle == 0)
	{
		pthread_mutex_lock(&philo->last_meal_mutex);
		return (1);
	}
	pthread_mutex_lock(&philo->last_meal_mutex);
	if (now_time() - philo->data.last_meal > (uint64_t)philo->data.t_to_die)
	{
		pthread_mutex_unlock(&philo->last_meal_mutex);
		pthread_mutex_unlock(&philo->cycle_mutex);
		printf("%lld ms\t%d %s\n", time_stamp(philo->data.time) - 1,
			philo->rank, DIE);
		return (1);
	}
	pthread_mutex_unlock(&philo->last_meal_mutex);
	pthread_mutex_unlock(&philo->cycle_mutex);
	return (0);
}

void	philos_spectator(t_philo *philo)
{
	usleep(TIME_TO_CREAT_THREAD);
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
