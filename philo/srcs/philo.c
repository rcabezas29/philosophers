/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 20:30:29 by rcabezas          #+#    #+#             */
/*   Updated: 2021/08/30 21:31:18 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	init_args(t_data *d, char **argv, int argc)
{
	d->no_philos = ft_atoi(argv[1]);
	d->time_to_die = ft_atoi(argv[2]);
	d->time_to_eat = ft_atoi(argv[3]);
	d->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		d->eating_times = ft_atoi(argv[5]);
}

int	main(int argc, char **argv)
{
	t_philo	*p;
	t_data	*d;
	
	if (argc != 5 || argc != 6)
		error_handling(1);
	p = malloc(sizeof(t_philo));
	ft_bzero(p, sizeof(t_philo));
	d = malloc(sizeof(t_philo));
	ft_bzero(d, sizeof(t_philo));
	init_args(d, argv, argc);
}