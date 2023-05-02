/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tread_creat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:28:18 by belkarto          #+#    #+#             */
/*   Updated: 2023/05/02 04:42:28 by belkarto         ###   ########.fr       */
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
		printf("timestamp %llu\n", time_stamp(philo->data.time));
		usleep(1000);
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
	while (++i < len)
	{
		pthread_mutex_init(&tmp->fork, NULL);
		pthread_create(&tmp->philo, NULL, cycle, tmp);
		tmp = tmp->right;
	}
	sleep(10);
	printf("%d \n", philos->rank);
	return (0);
}
