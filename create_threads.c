/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 05:45:00 by asokolov          #+#    #+#             */
/*   Updated: 2022/08/21 12:20:44 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philos(t_start *start)
{
	int	i;

	i = 0;
	while (i <= start->number_of_philosophers)
	{
		init_philo(&start->all_philos[i]);
		i++;
	}
	i = 0;
	while (i <= start->number_of_philosophers)
	{
		fill_philo(start, &start->all_philos[i], i);
		i++;
	}
	start->t_init = time_now(start);
}

void	create_threads(t_start *start)
{
	int	i;

	i = 0;
	create_philos(start);
	while (i <= start->number_of_philosophers)
	{
		if (pthread_create(&start->philo_threads[i],
				NULL, philo_actions, &start->all_philos[i]) != 0)
		{
			free_all(start);
			return ;
		}
		i++;
	}
	if (pthread_create(&start->dead_search, NULL, dead_searching, start) != 0)
	{
		free_all(start);
		return ;
	}
}
