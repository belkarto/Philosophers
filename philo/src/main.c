/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:21:09 by belkarto          #+#    #+#             */
/*   Updated: 2023/05/02 03:48:34 by belkarto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine()
{
	printf("i'm thread\n");
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_philo	*philos;

	if (args_checker(argc, argv) == 1)
		return (1);
	philos = init_philos(argv, argc);
	if (tread_creat(philos, ft_atol(argv[1])) == 1)
		return (EXIT_FAILURE);
	for (int i = 0; i < 6; i++)
	{
		printf("rank: %d | t_to_die: %lu | t_to_sleep: %lu | t_to_eat: %lu\n",\
				philos->rank, philos->data.t_to_die, philos->data.t_to_sleep, philos->data.t_to_eat);
		philos = philos->right;
	}
	return (EXIT_SUCCESS);
}
