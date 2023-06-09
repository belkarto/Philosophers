/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:21:09 by belkarto          #+#    #+#             */
/*   Updated: 2023/05/11 22:30:30 by belkarto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char *argv[])
{
	t_philo	*philos;

	if (args_checker(argc, argv) == 1)
		return (1);
	philos = init_philos(argv, argc);
	if (tread_creat(philos, ft_atol(argv[1])) == 1)
		return (EXIT_FAILURE);
	philos_spectator(philos);
	return (EXIT_SUCCESS);
}
