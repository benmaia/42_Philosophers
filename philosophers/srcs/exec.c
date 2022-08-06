/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:40:13 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/08/06 22:04:58 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>
#include <stdlib.h>

void	*exec(void *arg)
{
	t_philo			*p;

	p = arg;
	cur_time(p);
	while (p->time != p->arg->t_die)
	{
		p->state = NONE;
		ft_printf("Time -> %lld ", p->time);
		ft_printf("Hello I'm %d\n", p->nb);
	}
	p->state = DIED;
	if (p->state == DIED)
	{
		ft_printf("I'm dead -> %d\n", p->nb);
		exit(EXIT_SUCCESS);
	}
	/*while (p->time != )*/
		/*p->state = NONE;*/
	/*while (p->time != SLEEPING)*/
		/*p->state = NONE;*/
	/*while (p->time != SLEEPING)*/
		/*p->state = NONE;*/
	return (arg);
}
