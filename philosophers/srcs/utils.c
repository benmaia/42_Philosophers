/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:18:21 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/08/06 22:05:27 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>

void	cur_time(t_philo *p)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	p->time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000)) - p->s_time - 1;
}

void	ft_free(void **ptr)
{
	if (*ptr)
		free (*ptr);
	ptr = NULL;
}

/*unsigned int	ft_atoi(const char *str)*/
/*{*/
	/*int	i;*/
	/*int	sign;*/
	/*int	new;*/

	/*i = 0;*/
	/*sign = 1;*/
	/*while (((str[i] == ' ' || (str[i] > 8 && str[i] < 14))) && str[i])*/
		/*i++;*/
	/*if (str[i] == '-' || str[i] == '+'*/
		/*|| str[i] < '0' || str[i] > '9')*/
		/*return (-10);*/
	/*new = 0;*/
	/*while ((str[i] >= '0' && str[i] <= '9') && str[i])*/
	/*{*/
		/*new = (new * 10) + (str[i] - '0');*/
		/*i++;*/
	/*}*/
	/*return (sign * new);*/
/*}*/

size_t	nb_len(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	nb;

	len = nb_len(n);
	nb = n;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (nb)
	{
		str[len] = nb % 10 + '0';
		len--;
		nb = nb / 10;
	}
	return (str);
}
