/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 20:29:07 by rcabezas          #+#    #+#             */
/*   Updated: 2021/08/31 12:44:46 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data
{
	int	no_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	eating_times;
	t_philo	*philos;
}	t_data;

typedef struct s_philo
{
	int	id;
	int	no_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	eating_times;
}	t_philo;

//philo.c
int	main(int argc, char **argv);
void	init_args(t_data *d, char **argv, int argc);
void	create_philos(t_data *d);

//ft.c
int	ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);

//error.c
void	handle_errors(int error);
#endif