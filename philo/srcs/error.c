/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 20:55:07 by rcabezas          #+#    #+#             */
/*   Updated: 2021/08/31 12:44:54 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	handle_errors(int error)
{
	if (error == 1)
	{
		printf("Error - Wrong arguments");
		exit(EXIT_SUCCESS);
	}
}
