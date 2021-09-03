/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 12:12:08 by rcabezas          #+#    #+#             */
/*   Updated: 2021/09/01 17:58:59 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	ft_number(const char *str, int min, int max, int i)
{
	int	j;

	j = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		j = j * 10 + (str[i] - '0');
		i++;
	}
	if (min > 1 || max > 1 || min + max > 1)
		j = 0;
	else if (min == 1)
		j = -j;
	if (j <= -469762049)
		return (-1);
	if (j >= 469762049)
		return (0);
	return (j);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	min;
	int	max;

	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	min = 0;
	max = 0;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			min++;
		else if (str[i] == 43)
			max++;
		i++;
	}
	return (ft_number(str, min, max, i));
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*p;

	i = 0;
	p = s;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}
