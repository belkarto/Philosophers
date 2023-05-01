/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:31:47 by belkarto          #+#    #+#             */
/*   Updated: 2023/05/01 15:44:08 by belkarto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	ft_atol(const char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		res = (res * 10);
		res += str[i] - '0';
		i++;
	}
	return (res * sign);
}

t_philo	*new_philo(t_philo_data data, int rank, long cycle)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->data = data;
	philo->rank = rank;
	philo->cycle = cycle;
	philo->left = NULL;
	philo->right = NULL;
	return (philo);
}

void	philo_add_back(t_philo **head, t_philo *new_philo)
{
	t_philo	*tmp;

	tmp = *head;
	if (tmp == NULL)
	{
		(*head) = new_philo;
		return ;
	}
	while (tmp->right)
		tmp = tmp->right;
	tmp->right = new_philo;
	new_philo->left = tmp;
}
