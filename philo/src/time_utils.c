/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:45:50 by brahim            #+#    #+#             */
/*   Updated: 2023/05/05 17:46:08 by brahim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

uint64_t	time_stamp(uint64_t init_time)
{
	struct timeval now_time;
	uint64_t time_stamp;

	gettimeofday(&now_time, NULL);
	time_stamp = now_time.tv_sec * 1000 + now_time.tv_usec / 1000;
	return (time_stamp - init_time);
}

uint64_t	now_time(void)
{
	struct timeval now_time;
	uint64_t time_stamp;

	gettimeofday(&now_time, NULL);
	time_stamp = now_time.tv_sec * 1000 + now_time.tv_usec / 1000;
	return (time_stamp);
}
