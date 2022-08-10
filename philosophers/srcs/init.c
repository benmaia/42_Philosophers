/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:45:21 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/08/10 22:44:07 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <bits/pthreadtypes.h>
#include <bits/types/struct_timeval.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

void	init(t_data *g)
{
	int				i;

	i = -1;
	g->start_time = 0; 
	g->philo = malloc(sizeof(t_philo) * g->nb_philo);
	while (++i < g->nb_philo)
	{
		g->philo[i].nb = i + 1;
		g->philo[i].p_eat = 0;
		g->philo[i].global = g;
		if (pthread_mutex_init(&g->philo[i].fork, NULL))
		{
			perror("Error");
			ft_free((void *)g);
		}
		if (i != 0)
			gettimeofday(&g->s_time, NULL);
		g->philo[i].time = g->s_time;
		pthread_create(&g->philo[i].philo, NULL, &exec, &g->philo[i]);
		usleep(1000);
	}
}
