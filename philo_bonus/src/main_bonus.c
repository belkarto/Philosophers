/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:44:51 by belkarto          #+#    #+#             */
/*   Updated: 2023/05/12 18:40:23 by belkarto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"
#include <pthread.h>
#include <sys/wait.h>

void	ft_wait(pid_t *philos, long len)
{
	int	i;
	int	ex_statu;

	while (1)
	{
		waitpid(-1, &ex_statu, 0);
		if (WEXITSTATUS(ex_statu) == 2)
		{
			break ;
		}
	}
	i = -1;
	while (++i < len)
		kill(philos[i], SIGKILL);
}

void	*ft_spectator(void *param)
{
	t_philo		*philo;
	uint64_t	meal;

	philo = (t_philo *)param;
	while (1)
	{
		sem_wait(philo->last_meal_lock);
		meal = philo->last_meal.tv_sec * 1000 + philo->last_meal.tv_usec / 1000;
		if (now_time() - meal > (uint64_t)philo->data.t_to_die)
		{
			sem_wait(philo->data.sem_print);
			printf("%lld ms\t%d %s\n", time_stamp(philo->data.time),
				philo->rank, DIE);
			exit (2);
		}
		sem_post(philo->last_meal_lock);
		usleep(100);
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	pid_t	*philos;
	long	len;

	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("meal");
	sem_unlink("cycle");
	if (args_checker(argc, argv) == 1)
		return (1);
	philos = init_philos(argv, argc, &len);
	if (!philos)
		return (1);
	ft_wait(philos, len);
	return (EXIT_SUCCESS);
}
