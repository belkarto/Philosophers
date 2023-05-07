/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:45:21 by belkarto          #+#    #+#             */
/*   Updated: 2023/05/07 07:04:11 by belkarto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <sys/semaphore.h>
#include <sys/time.h>

void	*ft_spectator(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	while (1)
	{
		if (now_time() - philo->data.last_meal > (uint64_t)philo->data.t_to_die)
			exit (2);
		ft_sleep(1);
	}
	return (NULL);
}

void	ft_cycle(t_philo philo)
{
	pthread_t	spectator;

	printf("rankiiing  %d\n", philo.rank);
	sleep(1);
	pthread_create(&spectator, NULL, ft_spectator, &philo);
	while (1)
	{
		sem_wait(philo.data.forks);
		ft_print(TAKE_FORK, philo.rank, philo);
		sem_wait(philo.data.forks);
		ft_print(TAKE_FORK, philo.rank, philo);
		ft_print(EATING, philo.rank, philo);
		// philo.data.last_meal = now_time();
		ft_sleep(philo.data.t_to_eat);
		sem_post(philo.data.forks);
		sem_post(philo.data.forks);
		ft_print(SLEEPING, philo.rank, philo);
		ft_sleep(philo.data.t_to_sleep);
		ft_print(THINKING, philo.rank, philo);
	}
	exit(0);
}

t_philo	*creat_philos(long philo_n, t_philo_data data, long cycle)
{
	t_philo	*philo;
	int	i;

	i = -1;
	philo = malloc(philo_n * sizeof(t_philo));
	if (!philo)
		return (NULL);
	while (++i < philo_n)
	{
		philo[i].rank = i + 1;
		philo[i].cycle = cycle;
		philo[i].data = data;
		philo[i].philo = fork();
		if (philo[i].philo == -1)
		{
			ft_clean(philo, i);
			return (NULL);
		}
		else if (philo[i].philo == 0)
			ft_cycle(philo[i]);
	}
	return (philo);
}

void	init_data(char *t_to_die, char *t_to_eat, char *t_to_sleep, \
		t_philo_data *data)
{
	data->t_to_die = ft_atol(t_to_die);
	data->t_to_eat = ft_atol(t_to_eat);
	data->t_to_sleep = ft_atol(t_to_sleep);
	if (data->t_to_sleep < 1 || data->t_to_eat < 1 || data->t_to_die < 1)
	{
		write(2, "time must be number bigger than 0\n", 35);
		exit (1);
	}
	data->time = now_time();
}

t_philo	*init_philos(char **argv, int argc)
{
	long			philo_n;
	t_philo			*philos;
	t_philo_data	data;

	philo_n = ft_atol(argv[1]);
	if (philo_n < 1)
	{
		write(2, "philosopers number must be positive number bigger than 0\n", \
				58);
		exit (1);
	}
	init_data(argv[2], argv[3], argv[4], &data);
	data.len = philo_n;
	data.sem_print = sem_open("print", O_CREAT, 0666, 1);
	data.forks = sem_open("forks", O_CREAT, 0666, philo_n);
	if (argc == 5)
		philos = creat_philos(philo_n, data, -1);
	else
		philos = creat_philos(philo_n, data, ft_atol(argv[5]));
	return (philos);
}
