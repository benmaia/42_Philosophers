/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 02:59:52 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/08/03 15:58:35 by bmiguel-         ###   ########.fr       */
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
	int	n_philo;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	n_eat;
}	t_args;

typedef struct s_philo {
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	unsigned int	nb;
	int				state;
	pthread_t		th;
}	t_philo;

typedef struct s_data {
	t_args		*arg;
	t_philo		*philo;
	t_status	*status;
}	t_data;

void			parser(t_data *d, int argc, char **argv);

unsigned int	ft_atoi(const char *str);

void			ft_free(void **ptr);

// Colors
# define BLACK "\e[1;30m"
# define RED "\e[1;31m"
# define GREEN "\e[1;32m"
# define YELLOW "\e[1;33m"
# define BLUE "\e[1;34m"
# define PURPLE "\e[1;35m"
# define CYAN "\e[1;36m"
# define WHITE "\e[1;37m"
# define RES "\e[0m"
# define ORANGE1 "\033[38;5;214m"
# define ORANGE2 "\033[38;5;202m"

#endif
