/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:18:21 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/08/02 01:38:58 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>

void	ft_free(void **ptr)
{
	if (*ptr)
		free (*ptr);
	ptr = NULL;
}

int	ft_atoi(const char *str)
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
