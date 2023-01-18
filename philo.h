/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:52:45 by asokolov          #+#    #+#             */
/*   Updated: 2022/08/21 12:11:39 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct philo	t_philo;
typedef struct timeval	t_timeval;

typedef struct start
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_have_meals;
	int				number_of_forks;
	int				*forks;
	pthread_t		dead_search;
	pthread_t		*philo_threads;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	pr_mut;
	pthread_mutex_t	mutex_meal_count;
	pthread_mutex_t	mutex_last_meal;
	pthread_mutex_t	mutex_bool_die;
	t_timeval		t;
	long int		t_init;
	int				bool_die;
	t_philo			*all_philos;
}	t_start;

typedef struct philo
{
	t_start			*start;
	int				philo_id;
	int				*left_fork;
	int				*right_fork;
	int				time_last_meal;
	int				nb_meals;
	int				can_sleep;
	int				ate_enough;
}	t_philo;

int			input_error(int argc, char *argv[]);

void		init_start(t_start *start);
void		init_philo(t_philo *philo);
void		fill_start(t_start *start, int argc, char *argv[]);
void		fill_philo(t_start *start, t_philo *philo, int philo_nbr);

void		create_fork_mutex(t_start *start);
void		create_forks(t_start *start);
void		create_philos_treads(t_start *start);

void		create_threads(t_start *start);

void		write_sentence(t_philo *philo, char c);

long int	time_now(t_start *start);
void		optimised_usleep(t_start *start, int time);

int			fork_algorithm(t_philo *philo);
int			take_fork(t_philo *philo, int fork);
void		release_fork(t_philo *philo, int fork);
int			eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		*philo_actions(void *philo);

void		set_bool_die(t_start *start, int n);
int			check_if_dead(t_start *start);
int			check_meals(t_start *start);
int			check_dead_philo(t_start *start);
void		*dead_searching(void *start);

void		join_threads(t_start *start);
void		destroy_mutex(t_start *start);
void		free_all(t_start *start);

int			ft_atoi(const char *str);
int			ft_isdigit(int c);

#endif
