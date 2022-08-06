/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:45:21 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/08/06 01:36:25 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

void	init_philos(t_data *g)
{
	int	i;

	i = -1;
	g->philo = malloc(sizeof(t_philo) * g->arg->n_philo);
	while (++i < g->arg->n_philo)
	{
		g->philo[i].nb = i + 1;
		g->philo->time = g->philo->time;
		if (pthread_mutex_init(&g->philo[i].r_fork, NULL))
		{
			perror("Error");
			ft_free((void *)g);
		}
		if (i != 0)
			g->philo[i].l_fork = g->philo[i - 1].r_fork;
	}
	g->philo[0].l_fork = g->philo[i - 1].r_fork;
}

void	*exec(void *arg)
{
	t_philo			*p;

	p = arg;
	printf("Hello I'm %d\n", p->nb);
	return (arg);
}

void	init(t_data *g)
{
	pthread_t	*philo;
	int			i;

	i = -1;
	init_philos(g);
	philo = malloc(sizeof(pthread_t *) * g->arg->n_philo);
	while (++i < g->arg->n_philo)
		pthread_create(&philo[i], NULL, &exec, (void *)&g->philo[i]);
	i = -1;
	while (++i < g->arg->n_philo)
		pthread_join(philo[i], NULL);
	ft_free ((void *)&philo);
	ft_free ((void *)&g->philo);
}
