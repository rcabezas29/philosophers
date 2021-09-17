/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 21:43:16 by rcabezas          #+#    #+#             */
/*   Updated: 2021/09/17 11:53:28 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->protection);
	philo_take_fork(philo);
	if (*philo->died != 1)
		printf("[%llu] - (%i) is eating 🍝\n",
			get_time(philo->start_time), philo->id);
	gettimeofday(&philo->last_meal, NULL);
	ft_usleep(philo->no_philos, philo->time_to_eat);
	philo->eaten_times += 1;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(&philo->protection);
}

void	philo_sleep(t_philo *philo)
{
	if (*philo->died != 1)
		printf("[%llu] - (%i) is sleeping 💤\n",
			get_time(philo->start_time), philo->id);
	ft_usleep(philo->no_philos, philo->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	if (*philo->died != 1)
		printf("[%llu] - (%i) is thinking 💭\n",
			get_time(philo->start_time), philo->id);
	usleep(50);
}

void	philo_take_fork(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->right_fork);
		if (*philo->died != 1)
			printf("[%llu] - (%i) has taken right fork  🍴\n",
				get_time(philo->start_time), philo->id);
		pthread_mutex_lock(philo->left_fork);
		if (*philo->died != 1)
			printf("[%llu] - (%i) has taken left fork  🍴\n",
				get_time(philo->start_time), philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		if (*philo->died != 1 && philo->ate != 1)
			printf("[%llu] - (%i) has taken left fork  🍴\n",
				get_time(philo->start_time), philo->id);
		pthread_mutex_lock(philo->right_fork);
		if (*philo->died != 1 && philo->ate != 1)
			printf("[%llu] - (%i) has taken right fork  🍴\n",
				get_time(philo->start_time), philo->id);
	}
}
