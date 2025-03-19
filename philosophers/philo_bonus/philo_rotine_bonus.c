/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rotine_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 00:53:10 by machaq            #+#    #+#             */
/*   Updated: 2025/03/19 14:12:57 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	taken_fork(t_process *philo)
{
	t_time	end;
	t_time	start;

	start = philo->data->start;
	sem_wait(philo->data->mutex_fork);
	sem_wait(philo->data->forks);
	sem_wait(philo->data->forks);
	sem_post(philo->data->mutex_fork);
	sem_wait(philo->data->lock);
	gettimeofday(&end, NULL);
	printf("%ld %d has taken a fork\n", set_time(start, end), philo->index);
	printf("%ld %d has taken a fork\n", set_time(start, end), philo->index);
	sem_post(philo->data->lock);
}

void	eating(t_process *philo)
{
	t_time	end;
	t_time	start;

	start = philo->data->start;
	sem_wait(philo->data->lock);
	gettimeofday(&end, NULL);
	printf("%ld %d is eating\n", set_time(start, end), philo->index);
	gettimeofday(&philo->last_meal_time, NULL);
	sem_post(philo->data->lock);
	usleep(1000 * philo->data->eat);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

void	sleeping(t_process *philo)
{
	t_time	end;
	t_time	start;

	start = philo->data->start;
	sem_wait(philo->data->lock);
	gettimeofday(&end, NULL);
	printf("%ld %d is sleeping\n", set_time(start, end), philo->index);
	sem_post(philo->data->lock);
	usleep(1000 * philo->data->sleep);
}

void	thinking(t_process *philo)
{
	t_time	end;
	t_time	start;

	start = philo->data->start;
	sem_wait(philo->data->lock);
	gettimeofday(&end, NULL);
	printf("%ld %d is thinking\n", set_time(start, end), philo->index);
	sem_post(philo->data->lock);
}
