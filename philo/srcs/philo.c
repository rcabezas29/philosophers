/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 20:30:29 by rcabezas          #+#    #+#             */
/*   Updated: 2021/09/04 21:46:31 by rcabezas         ###   ########.fr       */
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
		pthread_mutexattr_init(&d->forks[i]);
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
	philo_eat();
	philo_sleep();
	philo_think();
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

void	create_philos(t_data *d)
{
	int i;
	
	i = 0;
	d->philos = malloc(sizeof(t_philo) * d->no_philos);
	while (i < d->no_philos)
	{
		d->philos[i].id = i;
		pthread_create(&d->philos[i].thread, NULL, philo_do, &d->philos[i].id);
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
