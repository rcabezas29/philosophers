/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 21:43:16 by rcabezas          #+#    #+#             */
/*   Updated: 2021/09/07 21:12:34 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->left_fork);
	printf("(\033[0;32m%llu\033[0;38m) - \033[0;33m (%i) has taken right fork \033[0;38m 🍴\n", get_time(philo->start_time), philo->id);
	printf("(\033[0;32m%llu\033[0;38m) - \033[0;33m (%i) has taken left fork \033[0;38m 🍴\n", get_time(philo->start_time), philo->id);
	printf("(\033[0;32m%llu\033[0;38m) - \033[0;34m (%i) is eating \033[0;38m 🍝\n", get_time(philo->start_time), philo->id);
	gettimeofday(&philo->last_meal, NULL);
	usleep(philo->time_to_eat * 1000);
	philo->eaten_times += 1;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	philo_sleep(t_philo *philo)
{
	printf("(\033[0;32m%llu\033[0;38m) - \033[0;36m (%i) is sleeping \033[0;38m 💤\n", get_time(philo->start_time), philo->id);
	usleep(philo->time_to_sleep * 1000);
}

void	philo_think(t_philo *philo)
{
	printf("(\033[0;32m%llu\033[0;38m) - \033[0;35m (%i) is thinking \033[0;38m 💭\n", get_time(philo->start_time), philo->id);
}

void	philo_die(t_philo *philo)
{
	*philo->died = 1;
	printf("(\033[0;32m%llu\033[0;38m) - \033[0;36m (%i) died \033[0;38m 💤\n", get_time(philo->start_time), philo->id);
}