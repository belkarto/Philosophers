/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:45:44 by belkarto          #+#    #+#             */
/*   Updated: 2023/05/12 00:36:38 by belkarto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

uint64_t	now_time(void)
{
	struct timeval	now_time;

	gettimeofday(&now_time, NULL);
	return (now_time.tv_sec * 1000 + now_time.tv_usec / 1000);
}

uint64_t	time_stamp(uint64_t init_time)
{
	return (now_time() - init_time);
}

void	ft_to_sleep(uint64_t to_sleep)
{
	long	now;
	long	after;

	now = now_time();
	after = (now) + (to_sleep);
	while (now < after)
	{
		usleep(100);
		now = now_time();
	}
}
