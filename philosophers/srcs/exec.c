/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:40:13 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/08/10 03:15:28 by bmiguel-         ###   ########.fr       */
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
	pthread_mutex_t	mutex;

	p = arg;
	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_lock(&mutex);
	while (1)
	{
		usleep(10);
		printf_mutex(p);
	}
	return(arg);
}
