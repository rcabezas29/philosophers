/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 20:30:29 by rcabezas          #+#    #+#             */
/*   Updated: 2021/09/06 17:36:34 by rcabezas         ###   ########.fr       */
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

void	waiting_room(t_data *d)
{
	int	i;

	i = 0;
	while(i < d->no_philos)
	{
		pthread_join(d->philos[i].thread, NULL);
		i++;
	}
}

void	*philo_do(void *arg)
{
	while (1)
	{
		philo_eat((t_philo *)arg);
		philo_sleep((t_philo *)arg);
		philo_think((t_philo *)arg);	
	}
	return (0);
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
	d->philos[i].start_time = d->start_time;
	d->philos[i].id = i;
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

int	main(int argc, char **argv)
{
	t_philo	*p;
	t_data	*d;

	if (argc != 5 && argc != 6)
		error_handling(1);
	p = malloc(sizeof(t_philo));
	ft_bzero(p, sizeof(t_philo));
	d = malloc(sizeof(t_philo));
	ft_bzero(d, sizeof(t_philo));
	init_args(d, argv, argc);
	create_forks(d);
	create_philos(d);
	waiting_room(d);
}
