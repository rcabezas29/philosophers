/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 10:47:22 by rcabezas          #+#    #+#             */
/*   Updated: 2021/09/07 17:48:31 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	create_forks(t_data *d)
{
	int	i;

	i = 0;
	d->forks = malloc(sizeof(pthread_mutex_t) * d->no_philos);
	while (i < d->no_philos)
	{
		pthread_mutex_init(&d->forks[i], NULL);
		i++;
	}
}

void	create_philos(t_data *d)
{
	int i;
	
	i = 0;
	d->philos = malloc(sizeof(t_philo) * d->no_philos);
	start_time(d);
	while (i < d->no_philos)
	{
		philo_chars(d, i);
		pthread_create(&d->philos[i].thread, NULL, philo_do, &d->philos[i]);
		i++;
	}
}

void	init_args(t_data *d, char **argv, int argc)
{
	d->no_philos = ft_atoi(argv[1]);
	d->time_to_die = ft_atoi(argv[2]);
	d->time_to_eat = ft_atoi(argv[3]);
	d->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		d->eating_times = ft_atoi(argv[5]);
}

void	philo_chars(t_data *d, int i)
{
	d->philos[i].died = &d->died;
	d->philos[i].start_time = d->start_time;
	d->philos[i].id = i + 1;
	d->philos[i].time_to_eat = d->time_to_eat;
	d->philos[i].time_to_die = d->time_to_die;
	d->philos[i].time_to_sleep = d->time_to_sleep;
	d->philos[i].eating_times = d->eating_times;
	if (i == d->no_philos - 1)
		d->philos[i].right_fork = &d->forks[0];
	else
		d->philos[i].right_fork = &d->forks[i + 1];
	d->philos[i].left_fork = &d->forks[i];
}
