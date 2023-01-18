/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 05:57:23 by asokolov          #+#    #+#             */
/*   Updated: 2022/08/21 05:56:19 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error_message(void)
{
	printf("%s", "\033[33m");
	printf("\nError == The program is waiting for the following args : \
	\n\t1 == number_of_philosophers \
	\n\t2 == time_to_die \
	\n\t3 == time_to_eat \
	\n\t4 == time_to_sleep \
	\n\t5 = number_of_times_each_philosopher_must_eat = optional\n\n");
}

int	input_error_following(char *argv[])
{
	if (ft_atoi(argv[1]) == -1 || ft_atoi(argv[1]) == 0
		|| ft_atoi(argv[2]) == -1 || ft_atoi(argv[3]) == -1
		|| ft_atoi(argv[4]) == -1
		|| (argv[5] && ft_atoi(argv[5]) == -1)
		|| (argv[5] && ft_atoi(argv[5]) == 0))
	{
		print_error_message();
		return (1);
	}
	return (0);
}

int	input_error(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		print_error_message();
		return (1);
	}
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
			{
				print_error_message();
				return (1);
			}
			j++;
		}
		i++;
	}
	return (input_error_following(argv));
}
