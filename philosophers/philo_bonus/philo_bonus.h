/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 01:08:22 by machaq            #+#    #+#             */
/*   Updated: 2025/03/19 14:39:42 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct timeval	t_time;

typedef struct s_data
{
	sem_t				*mutex_fork;
	sem_t				*forks;
	sem_t				*alive;
	sem_t				*count;
	int					number;
	int					option_arg;
	time_t				sleep;
	time_t				die;
	time_t				eat;
	sem_t				*lock;
	t_time				start;
}						t_data;

typedef struct s_process
{
	int					id;
	int					number_eat;
	pid_t				index;
	t_data				*data;
	t_time				last_meal_time;
	pthread_t			monitor;
}						t_process;

long					ft_atoi(char *str);
int						init_data(t_data *data, char **av, int ac);
time_t					set_time(t_time start, t_time end);
int						init_time_1(char **av, t_data *data);
int						init_time_2(char **av, t_data *data);
int						create_processes(t_process *philos);
int						validate_args(int ac, char **av, t_data *data);
void					kill_processes(t_process *philo);
int						initialize_simulation(int ac, char **av,
							t_process **philos, t_data *data);
void					eating(t_process *philo);
void					sleeping(t_process *philo);
void					thinking(t_process *philo);
void					cleanup(t_process *philos, t_data *data);
void					cleanup_child(t_process *philos);
t_process				*init_process(t_data *data);
void					taken_fork(t_process *philo);
void					simulation_1(t_process *philo);
void					simulation_2(t_process *philo);
void					simulation(t_process *philo);
void					one_philo(t_process *philo, t_time start);
void					monitor(t_process *philos);
void					wait_for_processes(t_data *data);
void					kill_processes(t_process *philo);
int						create_processes(t_process *philos);

#endif