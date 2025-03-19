/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_philo_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:14:44 by machaq            #+#    #+#             */
/*   Updated: 2025/03/19 14:15:48 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	check_death_1(t_process *philo)
{
	t_time	end;
	t_time	start;

	start = philo->data->start;
	while (1)
	{
		gettimeofday(&end, NULL);
		sem_wait(philo->data->lock);
		if (set_time(philo->last_meal_time, end) > philo->data->die)
		{
			printf("%ld %d died\n", set_time(start, end), philo->index);
			sem_wait(philo->data->alive);
			break ;
		}
		sem_post(philo->data->lock);
	}
}

static void	check_death_2(t_process *philo)
{
	t_time	end;
	t_time	start;

	start = philo->data->start;
	while (1)
	{
		sem_wait(philo->data->lock);
		if (philo->number_eat == philo->data->option_arg)
		{
			sem_post(philo->data->lock);
			return ;
		}
		gettimeofday(&end, NULL);
		if (set_time(philo->last_meal_time, end) > philo->data->die)
		{
			printf("%ld %d died\n", set_time(start, end), philo->index);
			while (philo->data->count->__align != 0)
				sem_wait(philo->data->count);
			break ;
		}
		sem_post(philo->data->lock);
	}
}

void	monitor(t_process *philo)
{
	if (philo->data->option_arg == -1)
	{
		check_death_1(philo);
	}
	else
	{
		check_death_2(philo);
	}
}
