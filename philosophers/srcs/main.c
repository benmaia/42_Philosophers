/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 02:57:47 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/08/04 18:25:13 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <pthread.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_data	*d;
	t_data	g;

	parser(&g, argc, argv);
	init(d, &g, -1);
	ft_free ((void *)&g.arg);
}
