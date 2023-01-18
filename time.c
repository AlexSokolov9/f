/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 05:38:10 by asokolov          #+#    #+#             */
/*   Updated: 2023/01/18 15:25:21 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	time_now(t_start *start)
{
	long int	time;

	gettimeofday(&start->t, NULL);
	time = start->t.tv_sec * 1000 + start->t.tv_usec / 1000;
	return (time - start->t_init);
}

void	optimised_usleep(t_start *start, int time)
{
	long int	l_time;

	l_time = time_now(start);
	usleep(time * 900);
	while (time_now(start) < time + l_time)
	{
		usleep(100);
	}
}
