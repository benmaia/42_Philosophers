/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:40:13 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/08/12 00:21:07 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

void	print_eat(t_data *g, t_philo *p)
{
	if (!check_if_dead(g))
	{
		printf("%lld %d has taken a fork\n", time_ms(g), p->nb);
		printf("%lld %d has taken a fork\n", time_ms(g), p->nb);
		printf("%lld %d is eating\n", time_ms(g), p->nb);
		check_if_dead(g);
		usleep(g->t_eat * 1000);
		check_if_dead(g);
	}
	sleeping(g, p);
}

void	sleeping(t_data *g, t_philo *p)
{
	short	me;
	short	beside;

	me = p->nb;
	beside = p->nb - 1;
	if (p->nb == p->global->nb_philo)
	{
		me = beside;
		beside = 0;
	}
	pthread_mutex_unlock(&g->philo[beside].fork);
	pthread_mutex_unlock(&g->philo[me].fork);
	if (!check_if_dead(g))
		printf("%lld %d is sleeping \n", time_ms(g), p->nb);
	else
		return ;
	usleep(g->t_sleep * 1000);
	if (!check_if_dead(g))
		printf("%lld %d is thinking \n", time_ms(g), p->nb);
	else
		return ;
}

void	eat(t_data *g, t_philo *p)
{
	short	me;
	short	beside;

	me = p->nb;
	beside = p->nb - 1;
	if (p->nb == p->global->nb_philo)
	{
		me = beside;
		beside = 0;
	}
	if (check_if_dead(g))
		return ;
	ft_lock(g, me, beside);
	pthread_mutex_lock(&g->eating);
	gettimeofday(&p->time, NULL);
	p->p_eat++;
	if (check_if_dead(g))
	{
		pthread_mutex_unlock(&g->philo[me].fork);
		pthread_mutex_unlock(&g->philo[beside].fork);
		pthread_mutex_unlock(&g->eating);
		return ;
	}
	pthread_mutex_unlock(&g->eating);
	print_eat(g, p);
}

void	exec_philo(t_data *g, t_philo *p)
{
	if (check_if_dead(g))
		return ;
	eat(g, p);
	if (check_if_dead(g))
		return ;
}

void	*exec(void *arg)
{
	t_philo				*p;
	t_data				*g;

	p = arg;
	g = p->global;
	while (1)
	{
		if (check_if_dead(g))
			return (arg);
		exec_philo(g, p);
		if (check_if_dead(g))
			return (arg);
	}
	return(arg);
}
