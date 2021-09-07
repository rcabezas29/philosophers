/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 20:29:07 by rcabezas          #+#    #+#             */
/*   Updated: 2021/09/07 10:49:24 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <sys/time.h>

typedef struct s_philo
{
	int			id;
	int			no_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			eating_times;
	pthread_t	thread;
	int			eaten_times;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	uint64_t	start_time;
	struct timeval	last_meal;
}	t_philo;

typedef struct s_data
{
	int			no_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			eating_times;
	t_philo		*philos;
	pthread_t	*threads;
	pthread_mutex_t	*forks;
	uint64_t	start_time;
}	t_data;

//philo.c
int		main(int argc, char **argv);
void	waiting_room(t_data *d);
void	looking_for_die(t_data *d);
void	*philo_do(void *arg);

//init.c
void	init_args(t_data *d, char **argv, int argc);
void	create_philos(t_data *d);
void	create_forks(t_data *d);
void	philo_chars(t_data *d, int i);

//ft.c
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);

//error.c
void	error_handling(int error);

//actions.c
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);

//time.c
uint64_t	get_timeval_ms(struct timeval *time);
void		start_time(t_data *d);
uint64_t	get_time(uint64_t start_time);
#endif