/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_destroy_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 05:19:28 by asokolov          #+#    #+#             */
/*   Updated: 2022/08/21 12:15:06 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_threads(t_start *start)
{
	int	i;
	int	nb;

	i = 0;
	nb = start->number_of_philosophers;
	while (i <= nb)
	{
		if (pthread_join(start->philo_threads[i], NULL) != 0)
			return ;
		i++;
	}
	if (pthread_join(start->dead_search, NULL) != 0)
		return ;
}

void	destroy_mutex(t_start *start)
{
	int	i;

	i = 0;
	while (i <= start->number_of_forks)
	{	
		if (pthread_mutex_destroy(&start->mutex[i]) != 0)
			return ;
		i++;
	}
	if (pthread_mutex_destroy(&start->pr_mut) != 0)
		return ;
	if (pthread_mutex_destroy(&start->mutex_meal_count) != 0)
		return ;
	if (pthread_mutex_destroy(&start->mutex_bool_die) != 0)
		return ;
	if (pthread_mutex_destroy(&start->mutex_last_meal) != 0)
		return ;
}

void	free_all(t_start *start)
{
	if (start->mutex)
		free(start->mutex);
	if (start->forks)
		free(start->forks);
	if (start->philo_threads)
		free(start->philo_threads);
	if (start->all_philos)
		free(start->all_philos);
}
