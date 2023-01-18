/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:53:41 by asokolov          #+#    #+#             */
/*   Updated: 2022/08/21 10:24:35 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_start	start;

	if (input_error(argc, argv) == 1)
		return (1);
	init_start(&start);
	fill_start(&start, argc, argv);
	create_threads(&start);
	join_threads(&start);
	destroy_mutex(&start);
	free_all(&start);
	return (0);
}
