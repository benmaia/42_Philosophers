/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:45:21 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/08/14 00:04:59 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Here is just to initialize the structs we have,*/
/*including the data and the info in each philo */
/*before even creating him, also init the fork mutex*/
void	init(t_data *g)
{
	int				i;

	i = -1;
	g->philo = malloc(sizeof(t_philo) * g->nb_philo);
	g->start_time = 0;
	while (++i < g->nb_philo)
		pthread_mutex_init(&g->philo[i].fork, NULL);
	pthread_mutex_init(&g->dying, NULL);
	pthread_mutex_init(&g->eating, NULL);
	i = -1;
	while (++i < g->nb_philo)
	{
		g->philo[i].nb = i + 1;
		g->philo[i].p_eat = 0;
		g->philo[i].global = g;
		if (i == 0)
			gettimeofday(&g->s_time, NULL);
		g->philo[i].time = g->s_time;
		pthread_create(&g->philo[i].philo, NULL, &exec, &g->philo[i]);
		usleep(1000);
	}
}
