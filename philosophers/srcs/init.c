/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:45:21 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/08/04 22:25:47 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void	array_struct(t_data *d, t_data *g, int i)
{
	d = malloc(sizeof(t_data) * g->arg->n_philo);
	while (++i < g->arg->n_philo)
	{
		d[i].philo->nb = i + 1;
		if (pthread_mutex_init(d[i].philo->r_fork, NULL))
		{
			perror("Error");
			ft_free((void *)d);
		}
		if (i == 0)
			/*d[i].philo->l_fork = d[g->arg->n_philo - 1].philo->r_fork;*/
			i = 0;
		else
			d[i].philo->l_fork = d[i - 1].philo->r_fork;
	}
	d[0].philo->l_fork = d[g->arg->n_philo - 1].philo->r_fork;
}

static void	*init_philos(void *arg)
{
	t_data		*d;

	d = arg;
	printf("%d\n", d->arg->n_philo);
	return (arg);
}

void	init(t_data *d, t_data *g, int i)
{
	pthread_t	*philo;

	array_struct(d, g, -1);
	philo = malloc(sizeof(pthread_t *));
	while (++i < g->arg->n_philo)
		pthread_create(&philo[i], NULL, &init_philos, (void *)g);
	i = -1;
	while (++i < g->arg->n_philo)
		pthread_join(philo[i], NULL);
	ft_free ((void *)&philo);
}
