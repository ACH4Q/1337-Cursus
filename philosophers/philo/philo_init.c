/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 07:18:51 by machaq            #+#    #+#             */
/*   Updated: 2025/03/11 01:15:58 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	fork_init(t_all *all)
{
	all->mutex = malloc(sizeof(pthread_mutex_t) * all->n_philos);
	if (!all->mutex)
		return (1);
	return (0);
}

void	mutex_init(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->all->n_philos)
		pthread_mutex_init(&philo->all->mutex[i], NULL);
	pthread_mutex_init(&philo->all->write, NULL);
	pthread_mutex_init(&philo->all->death, NULL);
}

t_all	*all_init(char **av)
{
	t_all	*all;

	all = malloc(sizeof(t_all) * 1);
	if (!all)
		return ((void *)0);
	all->n_philos = ft_atoi(av[1]);
	all->t_die = ft_atoi(av[2]);
	all->t_eat = ft_atoi(av[3]);
	all->t_sleep = ft_atoi(av[4]);
	if (av[5])
		all->m_meals = ft_atoi(av[5]);
	else
		all->m_meals = 0;
	if (fork_init(all))
	{
		free(all);
		return ((void *)0);
	}
	all->s_time = get_time();
	return (all);
}

t_philo	*philo_init(t_all *all)
{
	t_philo	*philo;
	t_ul	time;
	int		i;

	philo = malloc(sizeof(t_philo) * all->n_philos);
	time = get_time();
	if (!philo)
	{
		free(all->mutex);
		free(all);
		return ((void *)0);
	}
	i = -1;
	while (++i < all->n_philos)
	{
		philo[i].all = all;
		philo[i].id = i;
		philo[i].l_meal = time;
		philo[i].n_eaten = 0;
		philo[i].is_dead = 0;
		philo[i].reached_eat = 0;
	}
	return (philo);
}

void	thread_create(t_philo *philo)
{
	int	i;

	i = 0;
	mutex_init(philo);
	while (i < philo->all->n_philos)
	{
		pthread_create(&philo[i].thread, NULL, &routine, &philo[i]);
		i += 2;
		usleep(5);
	}
	usleep(200);
	i = 1;
	while (i < philo->all->n_philos)
	{
		pthread_create(&philo[i].thread, NULL, &routine, &philo[i]);
		i += 2;
	}
}
