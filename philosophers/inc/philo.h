/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 02:59:52 by bmiguel-          #+#    #+#             */
/*   Updated: 2022/08/10 22:36:05 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <bits/pthreadtypes.h>

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

typedef struct s_data	t_data;

typedef struct s_philo {
	short					nb;
	short					p_eat;
	struct timeval		time;
	pthread_mutex_t	fork;
	pthread_t			philo;
	t_data				*global;
}	t_philo;

typedef struct s_data {
	short					nb_philo;
	short					*fork;
	struct timeval		s_time;
	pthread_mutex_t	dying;
	pthread_mutex_t	eating;
	long long			t_die;
	long long			t_eat;
	long long			t_sleep;
	long long			dead;
	long long			start_time;
	short					t_x_eat;
	t_philo				*philo;
}	t_data;

/*#################### PARSER ##################*/

void			parser(t_data *d, int argc, char **argv);

/*#################### EXEC ##################*/

void			*exec(void *arg);

/*#################### INIT ##################*/

void			init(t_data *g);

/*#################### UTILS ##################*/

unsigned int	ft_atoi(const char *str);

long long			cur_time(void);

long long			time_ms(t_philo *p);

void				printf_mutex(t_philo *p);

int				ft_isdigit(int arg);

/*#################### FREE ##################*/

void			ft_free(void **ptr);

#endif
