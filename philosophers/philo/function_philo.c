
#include "header.h"

void	take_fork_(t_philo *tph)
{
	ft_lock(&(tph->r_fork->fork));
	ft_lock(&(tph->box->write));
	if (check(tph->box))
		printf("%ld %d  has taken a fork\n", get_time() - tph->box->start,
			tph->id);
	unlock(&(tph->box->write));
	ft_lock(&(tph->l_fork->fork));
	ft_lock(&(tph->box->write));
	if (check(tph->box))
		printf("%ld %d  has taken a fork\n", get_time() - tph->box->start,
			tph->id);
	unlock(&(tph->box->write));
}

void	take_fork(t_philo *tph)
{
	if (tph->l_fork->id < tph->r_fork->id)
	{
		ft_lock(&(tph->l_fork->fork));
		ft_lock(&(tph->box->write));
		if (check(tph->box))
			printf("%ld %d  has taken a fork\n", get_time() - tph->box->start,
				tph->id);
		unlock(&(tph->box->write));
		ft_lock(&(tph->r_fork->fork));
		ft_lock(&(tph->box->write));
		if (check(tph->box))
			printf("%ld %d  has taken a fork\n", get_time() - tph->box->start,
				tph->id);
		unlock(&(tph->box->write));
	}
	else
		take_fork_(tph);
}

void	write_eat(t_philo *tph)
{
	ft_lock(&(tph->box->write));
	if (check(tph->box))
		printf("%ld %d is eating\n", tph->last_eat - tph->box->start, tph->id);
	unlock(&(tph->box->write));
	ft_sleep(tph, tph->box->time_to_eat);
	if (tph->l_fork->id < tph->r_fork->id)
	{
		unlock(&(tph->l_fork->fork));
		unlock(&(tph->r_fork->fork));
	}
	else
	{
		unlock(&(tph->r_fork->fork));
		unlock(&(tph->l_fork->fork));
	}
}

void	write_sleep(t_philo *tph)
{
	ft_lock(&(tph->box->write));
	if (check(tph->box))
		printf("%ld %d is sleeping\n", get_time() - tph->box->start, tph->id);
	unlock(&(tph->box->write));
	ft_sleep(tph, tph->box->time_to_sleep);
	ft_lock(&(tph->box->write));
	if (check(tph->box))
		printf("%ld %d is thinking\n", get_time() - tph->box->start, tph->id);
	unlock(&(tph->box->write));
	usleep(500);
}

void	*thread_philo(void *arg)
{
	t_philo	*thread;
	int		i;

	i = 0;
	thread = (t_philo *)arg;
	if (thread->id % 2)
		usleep(500);
	while (i != thread->box->number_looping)
	{
		take_fork(thread);
		ft_lock(&(thread->box->check_last));
		thread->last_eat = get_time();
		unlock(&(thread->box->check_last));
		write_eat(thread);
		write_sleep(thread);
		if (for25line(thread->box))
			break ;
		i++;
	}
	ft_lock(&(thread->box->check_stop));
	thread->box->stop++;
	unlock(&(thread->box->check_stop));
	return (NULL);
}
