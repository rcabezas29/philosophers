/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 20:29:07 by rcabezas          #+#    #+#             */
/*   Updated: 2021/09/17 11:54:03 by rcabezas         ###   ########.fr       */
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
	int				id;
	int				no_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eating_times;
	pthread_t		thread;
	int				eaten_times;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	uint64_t		start_time;
	struct timeval	last_meal;
	int				*died;
	int				ate;
	pthread_mutex_t	protection;
}	t_philo;

typedef struct s_data
{
	int				no_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eating_times;
	t_philo			*philos;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
	uint64_t		start_time;
	int				died;
}	t_data;

//philo.c
int			main(int argc, char **argv);
void		waiting_room(t_data *d);
void		looking_for_die(t_data *d);
void		*philo_do(void *arg);

//init.c
int			init_args(t_data *d, char **argv, int argc);
void		create_philos(t_data *d);
void		create_forks(t_data *d);
void		philo_chars(t_data *d, int i);

//ft.c
int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
int			ft_isdigit(int c);
int			check_args(char **argv);

//error.c
void		error_handling(int error);

//actions.c
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);
void		philo_take_fork(t_philo *philo);

//time.c
uint64_t	get_timeval_ms(struct timeval *time);
void		start_time(t_data *d);
uint64_t	get_time(uint64_t start_time);
void		ft_usleep(int no_philos, uint64_t millisec);
#endif