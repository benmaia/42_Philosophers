/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:45:21 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/08/09 19:10:20 by bmiguel-         ###   ########.fr       */
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

void	init_philos(t_data *g)
{
	int				i;
	/*static int		died;*/

	i = -1;
	g->start_time = cur_time();
	g->state = NONE;
	g->philo = malloc(sizeof(t_philo) * g->arg->n_philo);
	while (++i < g->arg->n_philo)
	{
		g->philo[i].nb = i + 1;
		g->philo[i].g = g;
		if (pthread_mutex_init(&g->philo[i].r_fork, NULL))
		{
			perror("Error");
			ft_free((void *)g);
		}
		if (i != 0)
			g->philo[i].l_fork = g->philo[i - 1].r_fork;
	}
	g->philo[0].l_fork = g->philo[i].r_fork;
}

void	init(t_data *g)
{
	pthread_t	*philo;
	int			i;

	i = -1;
	philo = malloc(sizeof(pthread_t *) * g->arg->n_philo);
	init_philos(g);
	while (++i < g->arg->n_philo)
		pthread_create(&philo[i], NULL, &exec, (void *)&g->philo[i]);
	i = -1;
	while (++i < g->arg->n_philo)
		pthread_join(philo[i], NULL);
	ft_free ((void *)&philo);
	ft_free ((void *)&g->philo);
}
