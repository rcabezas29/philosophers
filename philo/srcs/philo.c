/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 20:30:29 by rcabezas          #+#    #+#             */
/*   Updated: 2021/09/09 21:06:46 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	looking_for_die(t_data *d)
{
	int	i;

	while (d->died != 1)
	{
		i = 0;
		while (i < d->no_philos)
		{
			if ((uint64_t)d->philos[i].time_to_die
				< get_time(get_timeval_ms(&d->philos[i].last_meal)))
				philo_die(&d->philos[i]);
			if (d->eating_times!= 0 && d->philos[i].eaten_times == d->eating_times)
				pthread_detach(d->philos[i].thread);
			i++;
		}
	}
}

void	waiting_room(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->no_philos)
	{
		pthread_join(d->philos[i].thread, NULL);
		i++;
	}
}

void	*philo_do(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (*philo->died != 1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data	*d;

	if (argc != 5 && argc != 6)
		error_handling(1);
	d = malloc(sizeof(t_philo));
	ft_bzero(d, sizeof(t_philo));
	init_args(d, argv, argc);
	create_forks(d);
	create_philos(d);
	looking_for_die(d);
	waiting_room(d);
	free(d->philos);
	free(d->forks);
	free(d);
	return (0);
}
