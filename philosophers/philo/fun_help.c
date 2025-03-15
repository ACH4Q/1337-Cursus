
#include "header.h"

void	launch_philo(t_box *box, t_philo *thread)
{
	int	i;

	i = 0;
	while (i < box->number_of_philo)
	{
		thread[i].id = i + 1;
		thread[i].box = box;
		thread[i].l_fork = box->fork;
		thread[i].r_fork = box->fork->next;
		box->fork = box->fork->next;
		thread[i].last_eat = box->start;
		pthread_create(&thread[i].thread, NULL, thread_philo, &thread[i]);
		i++;
	}
}

int	f_25_line(t_box *box, int i)
{
	if (i == box->number_of_philo - 1)
	{
		ft_lock(&(box->check_stop));
		if (box->stop)
		{
			unlock(&(box->check_stop));
			return (1);
		}
		unlock(&(box->check_stop));
	}
	return (0);
}

void	wait_philo(t_box *box, t_philo *thread)
{
	int	i;

	i = 0;
	while (1)
	{
		if (f_25_line(box, i))
			break ;
		ft_lock(&(box->check_last));
		if (get_time() - thread[i].last_eat > box->time_to_die)
		{
			unlock(&(box->check_last));
			ft_lock(&(box->mutex_die));
			box->someone_die = 1;
			unlock(&(box->mutex_die));
			ft_lock(&(box->write));
			printf("%ld %d died\n", get_time() - box->start, i + 1);
			unlock(&(box->write));
			break ;
		}
		unlock(&(box->check_last));
		i++;
		if (i > box->number_of_philo - 1)
			i = 0;
	}
}

void	free_all(t_box *box, t_philo *thread)
{
	int		i;
	t_fork	*fork;

	i = 0;
	free(thread);
	while (i < box->number_of_philo)
	{
		fork = box->fork->next;
		pthread_mutex_destroy(&(box->fork->fork));
		free(box->fork);
		box->fork = fork;
		i++;
	}
	pthread_mutex_destroy(&(box->check_stop));
	pthread_mutex_destroy(&(box->check_last));
	pthread_mutex_destroy(&(box->write));
}

int	check(t_box *box)
{
	ft_lock(&(box->mutex_die));
	if (box->someone_die)
	{
		unlock(&(box->mutex_die));
		return (0);
	}
	unlock(&(box->mutex_die));
	return (1);
}
