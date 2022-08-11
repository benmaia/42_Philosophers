/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:18:21 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/08/12 00:24:21 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <pthread.h>
#include <stdio.h>

long long	time_2_eat(t_philo *p)
{
	struct timeval	tv;
	long long		sec;
	long long		usec;

	gettimeofday(&tv, NULL);
	sec = tv.tv_sec - p->time.tv_sec;
	usec = tv.tv_usec - p->time.tv_usec;
	return ((usec / 1000) + (sec * 1000));
}

long long	time_ms(t_data *g)
{
	struct timeval	tv;
	long long		sec;
	long long		usec;

	gettimeofday(&tv, NULL);
	sec = tv.tv_sec - g->s_time.tv_sec;
	usec = tv.tv_usec - g->s_time.tv_usec;
	return ((usec / 1000) + (sec * 1000));
}

void	thread_destroyer(t_data *g)
{
	int	i;

	i = -1;
	while (++i < g->nb_philo)
		pthread_join(g->philo[i].philo, NULL);
	pthread_mutex_destroy(&g->dying);
	pthread_mutex_destroy(&g->eating);
	i = -1;
	while (++i < g->nb_philo)
		pthread_mutex_destroy(&g->philo[i].fork);
	free (g->philo);
}

unsigned int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	new;

	i = 0;
	sign = 1;
	while (((str[i] == ' ' || (str[i] > 8 && str[i] < 14))) && str[i])
		i++;
	if (str[i] == '-' || str[i] == '+'
		|| str[i] < '0' || str[i] > '9')
		return (-10);
	new = 0;
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		new = (new * 10) + (str[i] - '0');
		i++;
	}
	return (sign * new);
}

void	ft_lock(t_data *g, int me, int beside)
{
	pthread_mutex_lock(&g->philo[beside].fork);
	check_if_dead(g);
	pthread_mutex_lock(&g->philo[me].fork);
}
