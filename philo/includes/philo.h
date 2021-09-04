/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 20:29:07 by rcabezas          #+#    #+#             */
/*   Updated: 2021/09/04 21:35:52 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

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
	pthread_mutex_t left_fork;
	pthread_mutex_t right_fork;
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
	time_t		start_time;
}	t_data;

//philo.c
int		main(int argc, char **argv);
void	init_args(t_data *d, char **argv, int argc);
void	create_philos(t_data *d);
void	waiting_room(t_data *d);
void	create_forks(t_data *d);

//ft.c
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);

//error.c
void	error_handling(int error);
#endif