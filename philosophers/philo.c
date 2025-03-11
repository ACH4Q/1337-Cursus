/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:59:57 by machaq            #+#    #+#             */
/*   Updated: 2025/03/11 01:17:16 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_eaten(t_philo *philo)
{
	if (philo->n_eaten == philo->all->m_meals && philo->all->m_meals)
		philo->reached_eat = 1;
}

int	check_meals(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->all->n_philos)
	{
		if (philo[i].reached_eat != 1)
			return (0);
	}
	return (1);
}

void	is_dead(t_philo *philo)
{
	if (get_time() - philo->l_meal >= philo->all->t_die)
		philo->is_dead = 1;
}

void	philo_checker(t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&philo->all->death);
		is_eaten(&philo[i]);
		if (check_meals(philo))
			return ;
		is_dead(&philo[i]);
		if (philo[i].is_dead)
		{
			pthread_mutex_lock(&philo->all->write);
			printf("%lu %d %s\n", get_time() - philo->all->s_time, philo->id
				+ 1, DIED);
			return ;
		}
		i = (i + 1) % philo->all->n_philos;
		pthread_mutex_unlock(&philo->all->death);
	}
}

int	main(int ac, char **av)
{
	t_all	*all;
	t_philo	*philo;

	if (parse_arguments(ac, av) != 0)
		return (1);
	all = all_init(av);
	if (!all)
		return (printf("Failed to initialize\n"), 1);
	philo = philo_init(all);
	if (!philo)
		return (printf("Failed to initialize\n"), 1);
	thread_create(philo);
	philo_checker(philo);
	philo_detach(philo);
	return (0);
}
