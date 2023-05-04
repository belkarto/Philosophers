/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tread_creat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:28:18 by belkarto          #+#    #+#             */
/*   Updated: 2023/05/04 10:56:14 by belkarto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

uint64_t	time_stamp(uint64_t init_time)
{
	struct timeval now_time;
	uint64_t time_stamp;

	gettimeofday(&now_time, NULL);
	time_stamp = now_time.tv_sec * 1000 + now_time.tv_usec / 1000;
	return (time_stamp - init_time);
}

uint64_t	now_time(void)
{
	struct timeval now_time;
	uint64_t time_stamp;

	gettimeofday(&now_time, NULL);
	time_stamp = now_time.tv_sec * 1000 + now_time.tv_usec / 1000;
	return (time_stamp);
}

void	ft_print(char *action, int philo_rank, t_philo *philo)
{
	pthread_mutex_lock(&philo->data.print);
	printf("%lld ms\t%d %s\n", time_stamp(philo->data.time), philo_rank, action);
	pthread_mutex_unlock(&philo->data.print);
}

void	ft_eat(t_philo *philo)
{
	philo->data.last_meal = now_time();
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&philo->right->fork);
	ft_print(TAKE_FORK, philo->rank, philo);
	ft_print(EATING, philo->rank, philo);
	usleep(philo->data.t_to_eat);
	pthread_mutex_unlock(&philo->right->fork);
	pthread_mutex_unlock(&philo->fork);
	philo->data.last_meal = now_time();
}

void	ft_sleep(t_philo *philo)
{
	ft_print(SLEEPING, philo->rank, philo);
	usleep(philo->data.t_to_sleep);
}

void	ft_think(t_philo *philo)
{
	ft_print(THINKING, philo->rank, philo);
}

void	*cycle(void *philos)
{
	t_philo *philo;

	philo = (t_philo *)philos;
	while (1)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
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
			pthread_detach(tmp->philo);
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
			pthread_detach(tmp->philo);
		}
		tmp = tmp->right;
	}
	sleep(10);
	printf("%d \n", philos->rank);
	return (0);
}
