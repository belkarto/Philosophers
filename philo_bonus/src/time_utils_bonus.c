/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:45:44 by belkarto          #+#    #+#             */
/*   Updated: 2023/05/07 06:24:14 by belkarto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

uint64_t	time_stamp(uint64_t init_time)
{
	struct timeval	now_time;
	uint64_t		time_stamp;

	gettimeofday(&now_time, NULL);
	time_stamp = now_time.tv_sec * 1000 + now_time.tv_usec / 1000;
	return (time_stamp - init_time);
}

uint64_t	now_time(void)
{
	struct timeval	now_time;
	uint64_t		time_stamp;

	gettimeofday(&now_time, NULL);
	time_stamp = now_time.tv_sec * 1000 + now_time.tv_usec / 1000;
	return (time_stamp);
}
