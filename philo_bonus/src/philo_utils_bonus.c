/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:45:36 by belkarto          #+#    #+#             */
/*   Updated: 2023/05/08 03:48:28 by belkarto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

long	ft_atol(const char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		res = (res * 10);
		res += str[i] - '0';
		i++;
	}
	return (res * sign);
}

void	ft_sleep(long milliseconds)
{
	usleep(milliseconds * 1000);
}

void	ft_print(char *action, int philo_rank, t_philo philo)
{
	sem_wait(philo.data.sem_print);
	printf("%lld ms\t%d %s\n", time_stamp(philo.data.time), philo_rank, action);
	sem_post(philo.data.sem_print);
}

void	ft_clean(pid_t *philo, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		kill(philo[i], SIGTERM);
	free(philo);
	write(2, "Error fork: faild to creat processe\n", 36);
	exit (1);
}
