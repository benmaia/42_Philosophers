/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 23:31:58 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/08/05 01:53:24 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

static void	checker(t_args **arg, int argc, int i)
{
	if ((*arg)->n_philo >= 1)
		i = 1;
	else
	{
		printf("Please set \e[1;36mat least 1 philosopher\e[0m\n");
		exit(EXIT_FAILURE);
	}
	if ((*arg)->t_die >= 0)
		i++;
	if ((*arg)->t_eat >= 0)
		i++;
	if ((*arg)->t_sleep >= 0)
		i++;
	if (argc == 6)
		if ((*arg)->n_eat >= 0)
			i++;
	if (argc == 5 && i == 4)
		return ;
	if (argc == 6 && i == 5)
		return ;
	printf(RED"🚨  ! Wrong arguments !  🚨\n"RES);
	printf("Please use only \e[1;36mvalid unsigned int \e[0mas arguments\n");
	printf(ORANGE1"No signs, no letters, no special chars\n"RES);
	ft_free ((void *)arg);
	exit (EXIT_FAILURE);
}

static void	init_variables(t_args **arg, int argc, char **argv)
{
	*arg = malloc(sizeof(t_args));
	(*arg)->n_philo = ft_atoi(argv[1]);
	(*arg)->t_die = ft_atoi(argv[2]);
	(*arg)->t_eat = ft_atoi(argv[3]);
	(*arg)->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		(*arg)->n_eat = ft_atoi(argv[5]);
	else
		(*arg)->n_eat = -1;
}

static void	init_mutex(t_data *d)
{
	pthread_mutex_init(d->philo->l_fork, NULL);
	pthread_mutex_init(d->philo->r_fork, NULL);
}

void	parser(t_data *d, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf(RED"    🚨 !! Wrong number of arguments !! 🚨\n"RES);
		printf("Set \e[1;33m4 arguments\e[0m, number of philosophers");
		printf(", time to die, time to eat, time to sleep!\n");
		printf("You can set a \e[1;33m5th opcional argument \e[0mfor");
		printf(" number of times to eat\n");
		exit (EXIT_FAILURE);
	}
	init_variables(&d->arg, argc, argv);
	checker(&d->arg, argc, 0);
}
