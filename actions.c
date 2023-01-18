/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 00:33:49 by asokolov          #+#    #+#             */
/*   Updated: 2023/01/18 15:46:21 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_philo *philo, int fork)
{
	int	i;

	i = 0;
	if (pthread_mutex_lock(&philo->start->mutex[fork]) == 0)
	{
		i = 1;
	}	
	return (i);
}

void	release_fork(t_philo *philo, int fork)
{
	pthread_mutex_unlock(&philo->start->mutex[fork]);
}

int	eating(t_philo *philo)
{
	int	i;

	i = fork_algorithm(philo);
	if (i == 1)
	{
		write_sentence(philo, 'e');
		if (philo->start->must_have_meals != -1)
		{
			pthread_mutex_lock(&philo->start->mutex_meal_count);
			philo->nb_meals++;
			if (philo->start->must_have_meals == philo->nb_meals)
				philo->ate_enough = 1;
			pthread_mutex_unlock(&philo->start->mutex_meal_count);
		}
		pthread_mutex_lock(&philo->start->mutex_last_meal);
		philo->time_last_meal = time_now(philo->start);
		pthread_mutex_unlock(&philo->start->mutex_last_meal);
		optimised_usleep(philo->start, philo->start->time_to_eat);
		philo->can_sleep = 1;
		release_fork(philo, *philo->right_fork);
		release_fork(philo, *philo->left_fork);
	}
	else
		philo->can_sleep = 0;
	return (i);
}

void	sleeping(t_philo *philo)
{
	if (philo->can_sleep == 1 && check_if_dead(philo->start) == 0)
	{
		write_sentence(philo, 's');
		optimised_usleep(philo->start, philo->start->time_to_sleep);
		write_sentence(philo, 't');
	}
}

void	*philo_actions(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	while (check_if_dead(ph->start) == 0)
	{
		if (check_if_dead(ph->start) == 0)
			eating(ph);
		if (check_if_dead(ph->start) == 0 && ph->can_sleep == 1)
			sleeping(ph);
	}
	return (NULL);
}
