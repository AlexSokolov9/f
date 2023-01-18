/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 05:41:06 by asokolov          #+#    #+#             */
/*   Updated: 2022/08/21 11:31:49 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_bool_die(t_start *start, int n)
{
	pthread_mutex_lock(&start->mutex_bool_die);
	start->bool_die = n;
	pthread_mutex_unlock(&start->mutex_bool_die);
}

int	check_if_dead(t_start *start)
{	
	int	i;

	i = 0;
	pthread_mutex_lock(&start->mutex_bool_die);
	if (start->bool_die > 0)
		i = 1;
	pthread_mutex_unlock(&start->mutex_bool_die);
	return (i);
}

int	check_meals(t_start *start)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&start->mutex_meal_count);
	while (i <= start->number_of_philosophers)
	{
		if (start->all_philos[i].ate_enough == 0)
		{
			pthread_mutex_unlock(&start->mutex_meal_count);
			return (0);
		}
		i++;
	}
	pthread_mutex_unlock(&start->mutex_meal_count);
	return (1);
}

int	check_dead_philo(t_start *start)
{
	long int	time_n;
	int			i;

	i = 0;
	pthread_mutex_lock(&start->mutex_last_meal);
	while (i <= start->number_of_philosophers)
	{
		time_n = time_now(start);
		if (time_n - start->all_philos[i].time_last_meal > start->time_to_die)
		{
			write_sentence(&start->all_philos[i], 'd');
			pthread_mutex_unlock(&start->mutex_last_meal);
			return (1);
		}
		i++;
	}
	pthread_mutex_unlock(&start->mutex_last_meal);
	return (0);
}

void	*dead_searching(void *start)
{
	t_start	*s;
	int		i;

	s = (t_start *)start;
	while (42 == 42)
	{
		i = -1;
		while (++i <= s->number_of_philosophers)
		{
			if (s->must_have_meals > 0)
				if (s->number_of_philosophers > 0 && check_meals(s) == 1)
					set_bool_die(start, 2);
			if (check_if_dead(s) > 0)
				return (NULL);
			if (check_dead_philo(s) == 1)
				set_bool_die(start, 1);
			if (check_if_dead(s) > 0)
				return (NULL);
		}
	}
	return (NULL);
}
