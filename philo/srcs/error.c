/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 20:55:07 by rcabezas          #+#    #+#             */
/*   Updated: 2021/09/01 12:08:49 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	error_handling(int error)
{
	if (error == 1)
	{
		printf("Error - Wrong arguments");
		exit(EXIT_SUCCESS);
	}
}
