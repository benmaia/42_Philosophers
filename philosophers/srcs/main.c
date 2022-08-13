/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 23:50:45 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/08/13 23:58:06 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Philosophers program will run the parser to */
/*get the args, then will init the threads and */
/*run the exec with the routine, and in the end*/
/*calls the destructer to clear any thread leak*/
#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	g;

	parser(&g, argc, argv);
	init(&g);
	while (check_if_dead(&g) == 0)
		keep_going(&g);
	thread_destroyer(&g);
	return (0);
}
