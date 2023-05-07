/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:44:51 by belkarto          #+#    #+#             */
/*   Updated: 2023/05/07 06:50:38 by belkarto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"
#include <sys/wait.h>

void	ft_wait(t_philo *philos)
{
	int	i;
	int	ex_statu;

	i = -1;
	while (1)
	{
		waitpid(-1, &ex_statu, 0);
		if (WEXITSTATUS(ex_statu) == 2)
		{
			i = -1;
			while (++i < philos->data.len)
				kill(philos[i].philo, SIGTERM);
			usleep(300);
		}
		if (i == philos->data.len)
			i = -1;
	}
}

int	main(int argc, char *argv[])
{
	t_philo	*philos;

	sem_unlink("forks");
	sem_unlink("print");
	if (args_checker(argc, argv) == 1)
		return (1);
	philos = init_philos(argv, argc);
	if (!philos)
		return (1);
	ft_wait(philos);
	return (EXIT_SUCCESS);
}
