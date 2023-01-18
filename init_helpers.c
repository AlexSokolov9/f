/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 05:14:14 by asokolov          #+#    #+#             */
/*   Updated: 2022/08/21 12:10:38 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_fork_mutex(t_start *start)
{
	int	i;

	i = 0;
	start->mutex = (pthread_mutex_t *)malloc
		(sizeof(pthread_mutex_t) * (start->number_of_forks + 1));
	if (!start->mutex)
	{
		free_all(start);
		return ;
	}
	while (i <= start->number_of_forks)
	{
		if (pthread_mutex_init(&start->mutex[i], NULL) != 0)
		{
			free_all(start);
			return ;
		}
		i++;
	}
}

void	create_forks(t_start *start)
{
	int	i;

	i = 0;
	start->forks = (int *)malloc(sizeof(int) * (start->number_of_forks + 1));
	if (!start->forks)
	{
		free_all(start);
		return ;
	}
	while (i <= start->number_of_forks)
	{
		start->forks[i] = i;
		i++;
	}
}

void	create_philos_treads(t_start *start)
{
	start->all_philos = (t_philo *)malloc
		(sizeof(t_philo) * (start->number_of_philosophers + 1));
	if (!start->all_philos)
	{
		free_all(start);
		return ;
	}
	start->philo_threads = (pthread_t *)malloc
		(sizeof(pthread_t) * (start->number_of_philosophers + 1));
	if (!start->philo_threads)
	{
		free_all(start);
		return ;
	}
}
