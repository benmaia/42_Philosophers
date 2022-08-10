/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:18:21 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/08/10 22:48:20 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>

/*long long	time_ms(t_philo *p)*/
/*{*/
	/*return (cur_time() - p->g->start_time);*/
/*}*/

/*void	printf_mutex(t_philo *p)*/
/*{*/
	/*pthread_mutex_t	print;*/

	/*pthread_mutex_init(&print, NULL);*/
	/*pthread_mutex_lock(&print);*/
	/*printf("Time %lld -> I'm alive %d\n", time_ms(p), p->nb);*/
	/*pthread_mutex_unlock(&print);*/
/*}*/

long long	cur_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((tv.tv_sec * 1000) + (tv.tv_usec / 1000)));
}

void	ft_free(void **ptr)
{
	if (*ptr)
		free (*ptr);
	ptr = NULL;
}

unsigned int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	new;

	i = 0;
	sign = 1;
	while (((str[i] == ' ' || (str[i] > 8 && str[i] < 14))) && str[i])
		i++;
	if (str[i] == '-' || str[i] == '+'
		|| str[i] < '0' || str[i] > '9')
		return (-10);
	new = 0;
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		new = (new * 10) + (str[i] - '0');
		i++;
	}
	return (sign * new);
}
