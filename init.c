/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 05:41:27 by asokolov          #+#    #+#             */
/*   Updated: 2022/08/21 12:11:08 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_start(t_start *start)
{
	start->number_of_philosophers = 0;
	start->number_of_forks = 0;
	start->time_to_die = 0;
	start->time_to_eat = 0;
	start->time_to_sleep = 0;
	start->must_have_meals = 0;
	start->forks = NULL;
	start->dead_search = -1;
	start->philo_threads = NULL;
	start->mutex = NULL;
	start->bool_die = 0;
	start->t_init = 0;
	start->all_philos = NULL;
}

void	init_philo(t_philo *philo)
{
	philo->start = NULL;
	philo->philo_id = 0;
	philo->left_fork = NULL;
	philo->right_fork = NULL;
	philo->time_last_meal = 0;
	philo->nb_meals = 0;
	philo->can_sleep = 0;
	philo->ate_enough = 0;
}

void	fill_start(t_start *start, int argc, char *argv[])
{
	start->number_of_philosophers = ft_atoi(argv[1]) - 1;
	start->number_of_forks = ft_atoi(argv[1]) - 1;
	start->time_to_die = ft_atoi(argv[2]);
	start->time_to_eat = ft_atoi(argv[3]);
	start->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 5)
		start->must_have_meals = -1;
	if (argc == 6)
		start->must_have_meals = ft_atoi(argv[5]);
	if (pthread_mutex_init(&start->pr_mut, NULL) != 0)
		return ;
	if (pthread_mutex_init(&start->mutex_meal_count, NULL) != 0)
		return ;
	if (pthread_mutex_init(&start->mutex_last_meal, NULL) != 0)
		return ;
	if (pthread_mutex_init(&start->mutex_bool_die, NULL) != 0)
		return ;
	create_fork_mutex(start);
	create_forks(start);
	create_philos_treads(start);
}

void	fill_philo(t_start *start, t_philo *philo, int philo_nbr)
{
	philo->start = start;
	philo->philo_id = philo_nbr;
	if (philo->philo_id == 0 && philo->start->number_of_philosophers == 0)
	{
		philo->right_fork = &start->forks[philo_nbr];
	}
	else if (philo->philo_id == 0)
	{
		philo->left_fork = &start->forks[philo_nbr];
		philo->right_fork = &start->forks[start->number_of_philosophers];
	}
	else
	{
		philo->left_fork = &start->forks[philo_nbr];
		philo->right_fork = &start->forks[philo_nbr - 1];
	}
	if (start->must_have_meals != -1)
		philo->time_last_meal = 0;
}
