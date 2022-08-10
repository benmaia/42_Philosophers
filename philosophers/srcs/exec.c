/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:40:13 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/08/10 22:50:42 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	*exec(void *arg)
{
	t_philo				*p;
	t_data				*g;
	pthread_mutex_t	mutex;

	p = arg;
	g = p->global;
	(void) g;
	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_lock(&mutex);
	while (1)
	{
		printf("I'm %d\n", p->nb);
		usleep(10);
	}
	return(arg);
}
