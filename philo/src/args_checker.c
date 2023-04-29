/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:24:10 by belkarto          #+#    #+#             */
/*   Updated: 2023/04/29 17:05:25 by belkarto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	checke_args_number(int len)
{
	if (len < 5)
	{
		write(2, "not enough arguments:\n  usage:", 31);
		write(2, "\n\t./philo n_philosophers time_to_die ", 37);
		write(2, "time_to_eat time_to_sleep\n", 26);
		return (1);
	}
	else if (len > 6)
	{
		write(2, "too many arrguments: \n  usage:", 30);
		write(2, "\n\t./philo n_philosophers time_to_die ", 37);
		write(2, "time_to_eat time_to_sleep\n", 26);
		return (1);
	}
	return (0);
}

int	args_checker(int len, char **argv)
{
	if (checke_args_number(len) == 1)
		return (1);
	(void)argv;
	return (0);
}
