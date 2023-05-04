/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tread_creat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:28:18 by belkarto          #+#    #+#             */
/*   Updated: 2023/05/03 18:51:43 by belkarto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>
#include <stdio.h>

uint64_t	time_stamp(uint64_t init_time)
{
	struct timeval now_time;
	uint64_t time_stamp;

	gettimeofday(&now_time, NULL);
	time_stamp = now_time.tv_sec * 1000 + now_time.tv_usec / 1000;
	return (time_stamp - init_time);
}

void	*cycle(void *philos)
{
	t_philo *philo;

	philo = (t_philo *)philos;
	while (1)
	{
		pthread_mutex_lock(&philo->data.print);
		printf("timestamp %llu rank %d\n", time_stamp(philo->data.time), philo->rank);
		pthread_mutex_unlock(&philo->data.print);
		usleep(philo->data.t_to_eat);
	}
}

int	tread_creat(t_philo *philos, long len)
{
	int	i;
	t_philo *tmp;

	if (philos == NULL)
		return (1);
	i = -1;
	tmp = philos;
	pthread_mutex_init(&philos->data.print, NULL);
	while (++i < len)
	{
		if (tmp->rank % 2 == 0)
		{
			pthread_mutex_init(&tmp->fork, NULL);
			pthread_create(&tmp->philo, NULL, cycle, tmp);
		}
		tmp = tmp->right;
	}
	usleep(200);
	i = -1;
	while (++i < len)
	{
		if (tmp->rank % 2 != 0)
		{
			pthread_mutex_init(&tmp->fork, NULL);
			pthread_create(&tmp->philo, NULL, cycle, tmp);
		}
		tmp = tmp->right;
	}
	printf("%d \n", philos->rank);
	return (0);
}
