/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:49:04 by machaq            #+#    #+#             */
/*   Updated: 2025/03/10 20:44:01 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define MSG "%lld %d %s\n"

# define THINKING "is thinking"
# define FORKING "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define DIED "died"

typedef unsigned long	t_ul;

typedef struct s_all
{
	int					n_philos;
	int					m_meals;
	t_ul				t_die;
	t_ul				t_eat;
	t_ul				t_sleep;
	t_ul				s_time;
	pthread_mutex_t		write;
	pthread_mutex_t		death;
	pthread_mutex_t		*mutex;
}						t_all;

typedef struct s_philo
{
	int					id;
	int					is_dead;
	int					n_eaten;
	pthread_t			thread;
	int					reached_eat;
	t_ul				l_meal;
	t_all				*all;
}						t_philo;

int						ft_isdigit(int c);
int						parse_arguments(int ac, char **av);
t_all					*all_init(char **av);
t_philo					*philo_init(t_all *all);
void					*routine(void *arg);
void					thread_create(t_philo *philo);
t_ul					get_time(void);
int						ft_atoi(char *str);
int						_usleep(t_ul _sleep);
void					write_locker(char *s, t_philo *philo);
void					mutex_init(t_philo *philo);
void					philo_free(t_philo *philo);
void					*philo_detach(t_philo *philo);

#endif