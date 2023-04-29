/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:21:09 by belkarto          #+#    #+#             */
/*   Updated: 2023/04/29 16:53:12 by belkarto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>

void	*routine()
{
	printf("i'm thread\n");
	return (NULL);
}

int	main(int argc, char *argv[])
{
	if (args_checker(argc, argv) == 1)
		return (1);
	(void)argc;
	(void)argv;
	return (EXIT_SUCCESS);
}
