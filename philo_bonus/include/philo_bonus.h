/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:21:51 by belkarto          #+#    #+#             */
/*   Updated: 2023/05/08 06:17:19 by belkarto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>
# define TAKE_FORK "has taken a fork🍽️"
# define EATING "philosopher is eating🍝"
# define SLEEPING "philosopher is sleeping💤"
# define THINKING "philosopher is thinking💭"
# define DIE "philosopher died💀"

typedef struct s_philo_data
{
	long			t_to_die;
	long			t_to_eat;
	long			t_to_sleep;
	sem_t			*sem_print;
	sem_t			*forks;
	uint64_t		time;
	long			len;
}	t_philo_data;

typedef struct s_philo
{
	int				rank;
	pid_t			philo;
	long			cycle;
	t_philo_data	data;
	uint64_t		last_meal;
}	t_philo;

int			args_checker(int len, char **argv);
long		ft_atol(const char *str);
pid_t		*init_philos(char **argv, int argc, long *len);
pid_t		*creat_philos(long philo_n, t_philo_data data, long cycle);
t_philo		*new_philo(t_philo_data data, int rank, long cycle);
void		philo_add_back(t_philo **head, t_philo *new_philo);
int			tread_creat(t_philo *philos, long len);
uint64_t	time_stamp(uint64_t init_time);
uint64_t	now_time(void);
void		philos_spectator(t_philo *philo);
void		ft_print(char *action, int philo_rank, t_philo philo);
void		ft_sleep(long milliseconds);
void		ft_clean(pid_t *philo, int len);
void		*ft_spectator(void *param);

#endif
