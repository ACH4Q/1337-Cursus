
#include "header.h"

t_fork	*creat_fork(int i)
{
	t_fork	*fork;

	fork = ft_calloc(1, sizeof(t_fork));
	fork->id = i;
	mutex_init(&(fork->fork));
	return (fork);
}

void	creat_fork_list(t_box *thread)
{
	t_fork	*fork;
	int		i;

	i = 1;
	fork = creat_fork(i);
	thread->fork = fork;
	while (i < thread->number_of_philo)
	{
		i++;
		fork->next = creat_fork(i);
		fork = fork->next;
	}
	fork->next = thread->fork;
}

void	init_philo(t_box *thread, char **av)
{
	thread->number_of_philo = ft_atoi(av[1]);
	thread->time_to_die = ft_atoi(av[2]);
	thread->time_to_eat = ft_atoi(av[3]);
	thread->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		thread->number_looping = ft_atoi(av[5]);
	else
		thread->number_looping = -1;
	creat_fork_list(thread);
	mutex_init(&(thread->write));
	mutex_init(&(thread->check_stop));
	mutex_init(&(thread->mutex_die));
	pthread_mutex_init(&(thread->check_last), NULL);
	thread->start = 0;
	thread->stop = 0;
	thread->someone_die = 0;
}

void	creat_philo(char **av)
{
	t_box	box;
	t_philo	*thread;
	int		i;

	init_philo(&box, av);
	thread = malloc(box.number_of_philo * sizeof(t_philo));
	box.start = get_time();
	launch_philo(&box, thread);
	wait_philo(&box, thread);
	i = 0;
	while (i < box.number_of_philo)
		pthread_join(thread[i++].thread, NULL);
	free_all(&box, thread);
}
