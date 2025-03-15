/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 01:08:22 by machaq            #+#    #+#             */
/*   Updated: 2025/03/15 03:57:33 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_data
{
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_time_eats;
	long long	start_time;
	sem_t		*sem_print;
	sem_t		*sem_fork;
	char		dead;
}				t_data;

typedef struct s_philo
{
	int			num_philo;
	pthread_t	thread_id;
	long long	last_meal;
	t_data		*data;
	int			num_eats;
	pid_t		pid;
}				t_philo;

typedef struct s_table
{
	int			num_philos;
	t_data		data;
	t_philo		*philos;
	pthread_t	monitor;
}				t_table;

/* Function prototypes */
int				free_resources(t_table *table);
int				start_routines(t_table *table);
int				ft_error(int error);
int				status_print(t_philo *philo, char *str, int print_death);
int				parsing_args(int argv, char **argc, t_table *table);
long long		timestamp(void);
unsigned int	real_time(long long time);
void			philo_sleep(long long time);

#endif