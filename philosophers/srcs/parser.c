/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 23:31:58 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/08/02 01:42:05 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>
#include <stdlib.h>

static void	checker(t_data *d, int argc, int i)
{
	if (d->arg->nb_philo >= 0)
		i = 1;
	if (d->arg->time_die >= 0)
		i++;
	if (d->arg->time_eat >= 0)
		i++;
	if (d->arg->time_sleep >= 0)
		i++;
	if (argc == 6)
		if (d->arg->nb_eating >= 0)
			i++;
	if (argc == 5 && i == 4)
		return ;
	if (argc == 6 && i == 5)
		return ;
	printf("Please use only valid unsigned int as argument\n");
	exit (EXIT_FAILURE);
}

static void	init_variables(t_data *d, int argc, char **argv)
{
	d->arg->nb_philo = ft_atoi(argv[1]);
	d->arg->time_die = ft_atoi(argv[2]);
	d->arg->time_eat = ft_atoi(argv[3]);
	d->arg->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		d->arg->nb_eating = ft_atoi(argv[5]);
	else
		d->arg->nb_eating = -1;
}

void	parser(t_data *d, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("    !! Wrong number of arguments !!\n");
		printf("Set 4 arguments, number of philosophers");
		printf("time to die, time to eat, time to sleep!\n");
		printf("You can set a 5th opcianal argument for");
		printf("number of times to eat\n");
		exit (EXIT_FAILURE);
	}
	init_variables(d, argc, argv);
	checker(d, argc, 0);
printf("nb philo %d\n time die %d\n time eat %d\ntime sleep %d\nnb eating %d\n", d->arg->nb_philo, d->arg->time_die, d->arg->time_eat, d->arg->time_sleep, d->arg->nb_eating);
}

