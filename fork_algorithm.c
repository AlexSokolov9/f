/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 05:33:27 by asokolov          #+#    #+#             */
/*   Updated: 2022/08/21 11:23:50 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	one_philosopher(t_philo *philo)
{
	if (philo->start->number_of_philosophers == 0)
	{
		take_fork(philo, *philo->right_fork);
		release_fork(philo, *philo->right_fork);
		write_sentence(philo, 'u');
		philo->ate_enough = 1;
		return (0);
	}
	return (1);
}

int	fork_algorithm_following(t_philo *philo, int i)
{
	if (i != 2)
	{
		release_fork(philo, *philo->left_fork);
		release_fork(philo, *philo->right_fork);
		return (0);
	}
	else
	{
		if (check_if_dead(philo->start) == 0)
			write_sentence(philo, 'f');
		return (1);
	}
}

int	fork_algorithm(t_philo *philo)
{
	int	i;

	i = 0;
	if (one_philosopher(philo) == 0)
		return (0);
	else if (philo->philo_id % 2 == 0)
	{
		if (take_fork(philo, *philo->right_fork) == 1)
			i++;
		if (take_fork(philo, *philo->left_fork) == 1)
			i++;
	}
	else
	{
		if (take_fork(philo, *philo->left_fork) == 1)
			i++;
		if (take_fork(philo, *philo->right_fork) == 1)
			i++;
	}
	return (fork_algorithm_following(philo, i));
}
