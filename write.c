/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 05:06:15 by asokolov          #+#    #+#             */
/*   Updated: 2022/08/21 13:08:46 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_sentence_following(t_philo *philo, char c, long int t)
{
	if (c == 's')
	{
		printf("%s", "\033[31m");
		printf("%ld %d is sleeping\n", t, philo->philo_id + 1);
	}
	if (c == 't')
	{
		printf("%s", "\033[32m");
		printf("%ld %d is thinking\n", t, philo->philo_id + 1);
	}
	if (c == 'f' && philo->ate_enough == 0)
	{
		printf("%s", "\033[36m");
		printf("%ld %d has taken a fork\n", t, philo->philo_id + 1);
		printf("%ld %d has taken a fork\n", t, philo->philo_id + 1);
	}
	if (c == 'e' && philo->ate_enough == 0)
	{
		printf("%s", "\033[33m");
		printf("%ld %d is eating\n", t, philo->philo_id + 1);
	}
}

void	write_sentence(t_philo *philo, char c)
{
	long int	t;

	if (check_if_dead(philo->start) > 0)
		return ;
	t = time_now(philo->start);
	pthread_mutex_lock(&philo->start->pr_mut);
	if (c == 'd')
	{
		printf("%s", "\033[37m");
		printf("%ld %d died\n", t, philo->philo_id + 1);
	}
	if (check_if_dead(philo->start) == 0)
	{
		if (c == 'u' && philo->ate_enough == 0)
		{
			printf("%s", "\033[36m");
			printf("%ld %d has taken a fork\n", t, philo->philo_id + 1);
		}
		write_sentence_following(philo, c, t);
	}
	pthread_mutex_unlock(&philo->start->pr_mut);
}
