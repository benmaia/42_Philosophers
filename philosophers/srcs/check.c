/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 20:48:56 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/08/11 23:01:21 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int	check_if_dead(t_data *g)
{
	int	flag;

	flag = 0;
	pthread_mutex_lock(&g->dying);
	if (g->dead)
		flag += 1;
	pthread_mutex_unlock(&g->dying);
	if (flag != 0)
		return (1);
	return (0);
}

int	dead_checker(t_data *g)
{
	int	i;

	i = -1;
	while(++i < g->nb_philo)
	{
		pthread_mutex_lock(&g->eating);
		if (time_2_eat(&g->philo[i]) >= g->t_die)
		{
			printf("%lld %d died\n", time_ms(g), g->philo[i].nb);
			pthread_mutex_unlock(&g->eating);
			return (1);
		}
		pthread_mutex_unlock(&g->eating);
	}
	return (0);
}

int	eat_checker(t_data *g)
{
	int	i;

	if (g->t_x_eat == 0)
		return (0);
	i = -1;
	while (++i < g->nb_philo)
	{
		pthread_mutex_lock(&g->eating);
		if (g->philo[i].p_eat < g->t_x_eat)
		{
			pthread_mutex_unlock(&g->eating);
			return (0);
		}
		pthread_mutex_unlock(&g->eating);
	}
	return (1);
}

int	keep_going(t_data *g)
{
	if (dead_checker(g) || eat_checker(g))
	{
		pthread_mutex_lock(&g->dying);
		g->dead = 1;
		pthread_mutex_unlock(&g->dying);
		return (1);
	}
	return (0);
}
