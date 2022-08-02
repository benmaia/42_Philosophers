/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 02:59:52 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/08/02 00:21:17 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <unistd.h>

typedef enum s_status {
	EATING,
	SLEEPING,
	DIED,
	NONE
}	t_status;

typedef struct s_args {
	int	nb_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	nb_eating;
}	t_args;

typedef struct s_philo {
	pthread_mutex_t	fork;
	int				nb;
	int				state;
}	t_philo;

typedef struct s_data {
	t_args	*arg;
	t_philo	*philo;
	t_status	*st;
}	t_data;

void	parser(t_data *d, int argc, char **argv);

int	ft_atoi(const char *str);

void	ft_free(void **ptr);

#endif
