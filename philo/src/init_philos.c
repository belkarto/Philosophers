/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:17:59 by belkarto          #+#    #+#             */
/*   Updated: 2023/05/10 22:31:35 by belkarto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <sys/time.h>
#include <unistd.h>

t_philo	*creat_philos(long philo_n, t_philo_data data, long cycle)
{
	int		i;
	t_philo	*philo;
	t_philo	*tmp;

	i = 0;
	philo = NULL;
	while (++i <= philo_n)
		philo_add_back(&philo, new_philo(data, i, cycle));
	tmp = philo;
	while (tmp->right)
		tmp = tmp->right;
	tmp->right = philo;
	philo->left = tmp;
	return (philo);
}

int	init_data(char *t_to_die, char *t_to_eat, char *t_to_sleep, \
		t_philo_data *data)
{
	data->t_to_die = ft_atol(t_to_die);
	data->t_to_eat = ft_atol(t_to_eat);
	data->t_to_sleep = ft_atol(t_to_sleep);
	if (data->t_to_sleep < 1 || data->t_to_eat < 1 || data->t_to_die < 1)
	{
		write(2, "time must be number bigger than 0\n", 35);
		return (1);
	}
	data->time = now_time();
	return (0);
}

int	init_cycle(long *cycle, long valeu)
{
	if (valeu < 0)
	{
		write(2, "how many time a philo should eat must be positive number",
			56);
		return (1);
	}
	*cycle = valeu;
	return (0);
}

t_philo	*init_philos(char **argv, int argc)
{
	long			philo_n;
	t_philo			*philos;
	t_philo_data	data;
	long			cycle;

	philo_n = ft_atol(argv[1]);
	if (philo_n < 1)
	{
		write(2, "philosopers number must be positive number bigger than 0\n", \
				58);
		return (NULL);
	}
	if (init_data(argv[2], argv[3], argv[4], &data) == 1)
		return (NULL);
	if (argc == 5)
		philos = creat_philos(philo_n, data, -1);
	else
	{
		if (init_cycle(&cycle, ft_atol(argv[5])) == 1)
			return (NULL);
		philos = creat_philos(philo_n, data, cycle);
	}
	return (philos);
}
