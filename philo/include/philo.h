/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:21:51 by belkarto          #+#    #+#             */
/*   Updated: 2023/05/02 04:39:39 by belkarto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
#include <sys/time.h>
# define EATING "\033[0;1;2;32m philosopher is eating🍝\033[0;37m"
# define SLEEPING "\033[0;1;2;35mphilosopher is sleeping💤\033[0;1;2;37m"
# define THINKING "\033[0;1;2;34mphilosopher is thinking💭\033[0;1;2;37m"
# define DIE "\033[0;1;2;32mphilosopher died💀\033[0;1;2;37m"

typedef struct s_philo_data
{
	long	t_to_die;
	long	t_to_eat;
	long	t_to_sleep;
	uint64_t	time;
}	t_philo_data;

typedef struct s_philo
{
	int				rank;
	long			cycle;
	t_philo_data	data;
	pthread_t		philo;
	pthread_mutex_t	fork;
	struct s_philo	*right;
	struct s_philo	*left;
}	t_philo;

int		args_checker(int len, char **argv);
long	ft_atol(const char *str);
t_philo	*init_philos(char **argv, int len);
t_philo	*creat_philos(long philo_n, t_philo_data data, long cycle);
t_philo	*new_philo(t_philo_data data, int rank, long cycle);
void	philo_add_back(t_philo **head, t_philo *new_philo);
int		tread_creat(t_philo *philos, long len);

#endif
