/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tread_creat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:28:18 by belkarto          #+#    #+#             */
/*   Updated: 2023/05/09 03:36:48 by belkarto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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
	pthread_mutex_lock(&philo->last_meal_mutex);
	philo->data.last_meal = now_time();
	pthread_mutex_unlock(&philo->last_meal_mutex);
	if (philo->cycle != -1)
	{
		pthread_mutex_lock(&philo->cycle_mutex);
		philo->cycle--;
		pthread_mutex_unlock(&philo->cycle_mutex);
	}
	usleep(philo->data.t_to_eat * 1000);
	pthread_mutex_unlock(&philo->right->fork);
	pthread_mutex_unlock(&philo->fork);
	return (0);
}

void	*cycle(void *philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
	pthread_mutex_lock(&philo->last_meal_mutex);
	philo->data.last_meal = philo->data.time;
	pthread_mutex_unlock(&philo->last_meal_mutex);
	if (philo->rank % 2 == 0)
		usleep(philo->data.t_to_eat * 1000);
	while (1)
	{
		if (ft_eat(philo) == 1)
			return (NULL);
		ft_print(SLEEPING, philo->rank, philo);
		usleep(philo->data.t_to_sleep * 1000);
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
		pthread_mutex_init(&tmp->cycle_mutex, NULL);
		pthread_mutex_init(&tmp->fork, NULL);
		pthread_mutex_init(&tmp->last_meal_mutex, NULL);
		tmp = tmp->right;
	}
	i = -1;
	while (++i < len)
	{
		pthread_create(&tmp->philo, NULL, cycle, tmp);
		pthread_detach(tmp->philo);
		tmp = tmp->right;
	}
	return (0);
}
