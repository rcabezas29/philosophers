/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 21:43:16 by rcabezas          #+#    #+#             */
/*   Updated: 2021/09/06 17:37:54 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->left_fork);
	printf("(\033[0;32m%llu\033[0;38m) - \033[0;34mEl filosofo %i esta comiendo \033[0;38m🍽\n", get_time(philo->start_time), philo->id);
	usleep(philo->time_to_eat * 1000);
	philo->eaten_times += 1;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	philo_sleep(t_philo *philo)
{
	//printf("El filosofo %i esta durmiendo\n", philo->id);
	usleep(philo->time_to_sleep * 1000);
}

void	philo_think(t_philo *philo)
{
	//printf("El filosofo %i esta pensando\n", philo->id);
	usleep(philo->time_to_sleep * 1000);
}
