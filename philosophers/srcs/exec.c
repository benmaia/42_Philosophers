/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:40:13 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/08/07 15:58:54 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void	*exec(void *arg)
{
	t_philo			*p;
	struct timeval	tv;
	pthread_mutex_t mutex;
	/*pthread_mutex_t die;*/
	long long s_time;
	static int	state;

	p = arg;
	gettimeofday(&tv, NULL);
	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_lock(&mutex);
	s_time = cur_time(p);
	while (state == 0)
	{
		printf("Time %lld -> I'm alive %d\n", cur_time(p) - s_time, p->nb);
		if (cur_time(p) - s_time >= p->arg->t_die)
		{
			state = 1;
			printf("I'm dead %lld\n", cur_time(p) - s_time);
			exit(0);
		}
	pthread_mutex_unlock(&mutex);
	/*pthread_mutex_init(&die, NULL);*/
	/*pthread_mutex_lock(&die);*/
		/**p->state = state;*/
	/*pthread_mutex_unlock(&die);*/
	}
	return (arg);
}
