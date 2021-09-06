/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:41:07 by rcabezas          #+#    #+#             */
/*   Updated: 2021/09/06 16:31:48 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

uint64_t	get_timeval_ms(struct timeval *time)
{
	return (time->tv_sec * 1000 + time->tv_usec / 1000);
}

void	start_time(t_data *d)
{
	struct timeval t;

	gettimeofday(&t, NULL);
	d->start_time = get_timeval_ms(&t);
}

uint64_t	get_time(uint64_t start_time)
{
	struct timeval time;
	
	gettimeofday(&time, NULL);
	return(get_timeval_ms(&time) - start_time);
}