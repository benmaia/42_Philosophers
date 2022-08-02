/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 23:31:58 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/08/02 03:45:13 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>
#include <stdlib.h>

static void	checker(t_args **arg, int argc, int i)
{
	if ((*arg)->nb_philo >= 0)
		i = 1;
	if ((*arg)->time_die >= 0)
		i++;
	if ((*arg)->time_eat >= 0)
		i++;
	if ((*arg)->time_sleep >= 0)
		i++;
	if (argc == 6)
		if ((*arg)->nb_eating >= 0)
			i++;
	if (argc == 5 && i == 4)
		return ;
	if (argc == 6 && i == 5)
		return ;
	printf(RED"🚨  ! Wrong arguments !  🚨\n"RES);
	printf("Please use only \e[1;36mvalid unsigned int \e[0mas argument\n");
	printf(ORANGE1"No signs, no letters, no special chars\n"RES);
	ft_free ((void *)arg);
	exit (EXIT_FAILURE);
}

static void	init_variables(t_args **arg, int argc, char **argv)
{
	*arg = malloc(sizeof(t_args));
	(*arg)->nb_philo = ft_atoi(argv[1]);
	(*arg)->time_die = ft_atoi(argv[2]);
	(*arg)->time_eat = ft_atoi(argv[3]);
	(*arg)->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		(*arg)->nb_eating = ft_atoi(argv[5]);
	else
		(*arg)->nb_eating = -1;
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
/*printf("nb philo %d\ntime die %d\ntime eat %d\ntime sleep %d\nnb eating %d\n", d->arg->nb_philo, d->arg->time_die, d->arg->time_eat, d->arg->time_sleep, d->arg->nb_eating);*/
}

