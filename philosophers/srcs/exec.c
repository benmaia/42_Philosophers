/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:40:13 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/08/14 00:03:55 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Again always checking if someone died, after*/
/*unlocks the forks it used to eat, and will start*/
/*"sleeping" with the usleep function and then */
/*print that exact same action*/
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

/*Here will check if one philo is dead, because */
/*they can die while wating as well, then prints */
/*the time, the id of the philo and that is eating*/
/*after eating checks if it died while eating and*/
/*if not, it calls the function sleeping above*/
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

/*Here, the philo will check if the forks are */
/*unlocked or not, if they are, they will lock*/
/*them and start to eat, the prints come in the*/
/*print_eat function above*/
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

/*Checks if someone is dead again because*/
/*functions spend miliseconds as well*/
void	exec_philo(t_data *g, t_philo *p)
{
	if (check_if_dead(g))
		return ;
	eat(g, p);
	if (check_if_dead(g))
		return ;
}

/*This function is called in every philo thread*/
/*always checking if someone die and only then */
/*executes the routine and keeps looking for dead */
void	*exec(void *arg)
{
	t_philo	*p;
	t_data	*g;

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
	return (arg);
}
