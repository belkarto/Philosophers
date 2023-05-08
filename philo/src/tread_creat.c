/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tread_creat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:28:18 by belkarto          #+#    #+#             */
/*   Updated: 2023/05/08 11:19:34 by belkarto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void	ft_sleep(long milliseconds)
{
	usleep(milliseconds * 1000);
}

void	ft_print(char *action, int philo_rank, t_philo *philo)
{
	pthread_mutex_lock(&philo->data.print);
	printf("%lld ms\t%d %s\n", time_stamp(philo->data.time), philo_rank, action);
	pthread_mutex_unlock(&philo->data.print);
}

int	ft_eat(t_philo *philo)
{
	if (philo->cycle == 0)
		return (1);
	pthread_mutex_lock(&philo->fork);
	ft_print(TAKE_FORK, philo->rank, philo);
	pthread_mutex_lock(&philo->right->fork);
	ft_print(TAKE_FORK, philo->rank, philo);
	ft_print(EATING, philo->rank, philo);
	philo->data.last_meal = now_time();
	ft_sleep(philo->data.t_to_eat);
	pthread_mutex_unlock(&philo->right->fork);
	pthread_mutex_unlock(&philo->fork);
	if (philo->cycle != -1)
		philo->cycle--;
	return (0);
}

void	*cycle(void *philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
	philo->data.last_meal = philo->data.time;
	if (philo->rank % 2 == 0)
		ft_sleep(philo->data.t_to_eat);
	while (1)
	{
		if (ft_eat(philo) == 1)
			return (NULL);
		ft_print(SLEEPING, philo->rank, philo);
		ft_sleep(philo->data.t_to_sleep);
		ft_print(THINKING, philo->rank, philo);
	}
}

int	tread_creat(t_philo *philos, long len)
{
	int		i;
	t_philo	*tmp;

	if (philos == NULL)
		return (1);
	i = -1;
	tmp = philos;
	pthread_mutex_init(&philos->data.print, NULL);
	while (++i < len)
	{
		pthread_mutex_init(&tmp->fork, NULL);
		pthread_create(&tmp->philo, NULL, cycle, tmp);
		tmp = tmp->right;
	}
	return (0);
}
