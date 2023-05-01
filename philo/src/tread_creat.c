/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tread_creat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:28:18 by belkarto          #+#    #+#             */
/*   Updated: 2023/05/01 18:05:17 by belkarto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>
#include <stdio.h>

void	*cycle(void *philos)
{
	t_philo *philo;

	philo = (t_philo *)philos;
	while (1)
	{
		printf("%d eating\n", philo->rank);
	}
}

int	tread_creat(t_philo *philos, long len)
{
	int	i;
	t_philo *tmp;

	if (philos == NULL)
		return (1);
	i = -1;
	tmp = philos;
	while (++i < len)
	{
		pthread_create(&tmp->philo, NULL, cycle, tmp);
		tmp = tmp->right;
	}
	printf("%d \n", philos->rank);
	return (0);
}
