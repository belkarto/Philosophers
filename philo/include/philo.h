/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:21:51 by belkarto          #+#    #+#             */
/*   Updated: 2023/05/09 03:16:54 by belkarto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# define TAKE_FORK "has taken a fork🍽️"
# define EATING "philosopher is eating🍝"
# define SLEEPING "philosopher is sleeping💤"
# define THINKING "philosopher is thinking💭"
# define DIE "philosopher died💀"
# define TIME_TO_CREAT_THREAD 50

typedef struct s_philo_data
{
	long			t_to_die;
	long			t_to_eat;
	long			t_to_sleep;
	pthread_mutex_t	print;
	uint64_t		time;
	uint64_t		last_meal;
}	t_philo_data;

typedef struct s_philo
{
	int				rank;
	long			cycle;
	pthread_mutex_t	cycle_mutex;
	pthread_mutex_t	last_meal_mutex;
	t_philo_data	data;
	pthread_t		philo;
	pthread_mutex_t	fork;
	struct s_philo	*right;
	struct s_philo	*left;
}	t_philo;

int			args_checker(int len, char **argv);
long		ft_atol(const char *str);
t_philo		*init_philos(char **argv, int len);
t_philo		*creat_philos(long philo_n, t_philo_data data, long cycle);
t_philo		*new_philo(t_philo_data data, int rank, long cycle);
void		philo_add_back(t_philo **head, t_philo *new_philo);
int			tread_creat(t_philo *philos, long len);
uint64_t	time_stamp(uint64_t init_time);
uint64_t	now_time(void);
void		philos_spectator(t_philo *philo);
void		ft_print(char *action, int philo_rank, t_philo *philo);

#endif
