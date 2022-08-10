/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:40:13 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/08/09 19:23:20 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

long long	time_ms(t_philo *p)
{
	return (cur_time() - p->g->start_time);
}

void	printf_mutex(t_philo *p)
{
	pthread_mutex_t	print;

	pthread_mutex_init(&print, NULL);
	printf("Time %lld -> I'm alive %d\n", time_ms(p), p->nb);
}

void	*exec(void *arg)
{
	t_philo				*p;
	pthread_mutex_t	mutex;
	pthread_mutex_t	print;
	/*pthread_mutex_t	die;*/

	p = arg;
	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_lock(&mutex);
	pthread_mutex_init(&print, NULL);
	while (1)
	{
		pthread_mutex_lock(&print);
		usleep(100);
		printf("Time %lld\n", time_ms(p));
		pthread_mutex_unlock(&print);
	}
	/*pthread_mutex_init(&die, NULL);*/
	/*pthread_mutex_lock(&die);*/
	/*printf("Time %lld -> DEAD %d\n", time_ms(p), p->nb);*/
	/*exit (0);*/
	/*pthread_mutex_unlock(&die);*/
	pthread_mutex_unlock(&mutex);
	return(arg);
}
