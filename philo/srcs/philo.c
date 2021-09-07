/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 20:30:29 by rcabezas          #+#    #+#             */
/*   Updated: 2021/09/07 10:48:20 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	looking_for_die(t_data *d)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < d->no_philos)
		{
			printf("last_meal: %llu\n", get_time(get_timeval_ms(&d->philos[i].last_meal)));
			if ((uint64_t)d->philos[i].time_to_eat < get_time(get_timeval_ms(&d->philos[i].last_meal)))
				waiting_room(d);
			i++;
		}
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
	looking_for_die(d);
	//waiting_room(d);
}
