/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 23:31:58 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/08/14 00:09:28 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Checks if the numbers are positive or not*/
static void	checker(t_data *g, int argc, int i)
{
	if (g->nb_philo >= 1)
		i = 1;
	else
	{
		printf("Please set \e[1;36mat least 1 philosopher\e[0m\n");
		exit(EXIT_FAILURE);
	}
	if (g->t_die >= 0)
		i++;
	if (g->t_eat >= 0)
		i++;
	if (g->t_sleep >= 0)
		i++;
	if (argc == 6)
		if (g->t_x_eat >= 0)
			i++;
	if (argc == 5 && i == 4)
		return ;
	if (argc == 6 && i == 5)
		return ;
	printf(RED"🚨  ! Wrong arguments !  🚨\n"RES);
	printf("Please use only \e[1;36mvalid unsigned int \e[0mas arguments\n");
	printf(ORANGE1"No signs, no letters, no special chars\n"RES);
	free (g);
	exit (EXIT_FAILURE);
}

/*Init the global args passed by the user to a struct*/
static void	init_variables(t_data *g, int argc, char **argv)
{
	g->nb_philo = ft_atoi(argv[1]);
	g->t_die = ft_atoi(argv[2]);
	g->t_eat = ft_atoi(argv[3]);
	g->t_sleep = ft_atoi(argv[4]);
	g->dead = 0;
	if (argc == 6)
		g->t_x_eat = ft_atoi(argv[5]);
	else
		g->t_x_eat = 0;
}

/*Checks the number of argvs, and calls the functions*/
/*above to help it*/
void	parser(t_data *g, int argc, char **argv)
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
	init_variables(g, argc, argv);
	checker(g, argc, 0);
	if (g->nb_philo == 1)
	{
		usleep(g->t_die * 1000);
		printf("%lld %d died\n", g->t_die, 1);
		exit(EXIT_FAILURE);
	}
}
