/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 21:43:16 by rcabezas          #+#    #+#             */
/*   Updated: 2021/09/06 21:29:15 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->left_fork);
	printf("(\033[0;32m%llu\033[0;38m) - \033[0;33mEl filosofo (%i) ha cogido el tenedor derecho \033[0;38m 🍴\n", get_time(philo->start_time), philo->id);
	printf("(\033[0;32m%llu\033[0;38m) - \033[0;33mEl filosofo (%i) ha cogido el tenedor izquierdo \033[0;38m 🍴\n", get_time(philo->start_time), philo->id);
	printf("(\033[0;32m%llu\033[0;38m) - \033[0;34mEl filosofo (%i) esta comiendo \033[0;38m 🍝\n", get_time(philo->start_time), philo->id);
	gettimeofday(&philo->last_meal, NULL);
	usleep(philo->time_to_eat * 1000);
	philo->eaten_times += 1;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	philo_sleep(t_philo *philo)
{
	printf("(\033[0;32m%llu\033[0;38m) - \033[0;36mEl filosofo (%i) esta durmiendo \033[0;38m 💤\n", get_time(philo->start_time), philo->id);
	usleep(philo->time_to_sleep * 1000);
}

void	philo_think(t_philo *philo)
{
	printf("(\033[0;32m%llu\033[0;38m) - \033[0;35mEl filosofo (%i) esta pensando \033[0;38m 💭\n", get_time(philo->start_time), philo->id);
}
