/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:44:51 by belkarto          #+#    #+#             */
/*   Updated: 2023/05/07 22:34:58 by belkarto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"
#include <sys/wait.h>

void	ft_wait(pid_t *philos, long len)
{
	int	i;
	int	ex_statu;

	while (1)
	{
		waitpid(-1, &ex_statu, 0);
		if (WEXITSTATUS(ex_statu) == 2)
			break;
	}
	i = -1;
	while (++i < len)
		kill(philos[i], SIGKILL);
}

int	main(int argc, char *argv[])
{
	pid_t	*philos;
	long	len;

	sem_unlink("forks");
	sem_unlink("print");
	if (args_checker(argc, argv) == 1)
		return (1);
	philos = init_philos(argv, argc, &len);
	if (!philos)
		return (1);
	ft_wait(philos, len);
	return (EXIT_SUCCESS);
}
