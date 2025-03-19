/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:08:00 by machaq            #+#    #+#             */
/*   Updated: 2025/03/19 14:13:07 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_data(t_data *data, char **av, int ac)
{
	if (ac == 5)
	{
		if (!init_time_1(av, data))
			return (0);
	}
	else if (ac == 6)
	{
		if (!init_time_2(av, data))
			return (0);
	}
	sem_unlink("lock");
	sem_unlink("  alive");
	sem_unlink("forks");
	sem_unlink("counter");
	sem_unlink("mutex_fork");
	data->lock = sem_open("lock", O_CREAT, 0666, 1);
	data->alive = sem_open("/alive", O_CREAT, 0666, 1);
	data->forks = sem_open("forks", O_CREAT, 0666, data->number);
	data->count = sem_open("counter", O_CREAT, 0666, data->number);
	data->mutex_fork = sem_open("mutex_fork", O_CREAT, 0666, 1);
	return (1);
}

time_t	set_time(t_time start, t_time end)
{
	time_t	sec;
	time_t	usec;
	time_t	msec;

	sec = end.tv_sec - start.tv_sec;
	usec = end.tv_usec - start.tv_usec;
	if (usec < 0)
	{
		sec -= 1;
		usec += 1000000;
	}
	msec = sec * 1000 + usec / 1000;
	return (msec);
}

int	init_time_1(char **av, t_data *data)
{
	time_t	temp;

	temp = ft_atoi(av[1]);
	if (temp > INT_MAX || temp <= 0)
		return (0);
	data->number = (int)temp;
	temp = ft_atoi(av[2]);
	if (temp > INT_MAX || temp < 0)
		return (0);
	data->die = temp;
	temp = ft_atoi(av[3]);
	if (temp > INT_MAX || temp < 0)
		return (0);
	data->eat = temp;
	temp = ft_atoi(av[4]);
	if (temp > INT_MAX || temp < 0)
		return (0);
	data->sleep = temp;
	data->option_arg = -1;
	return (1);
}

int	init_time_2(char **av, t_data *data)
{
	time_t	temp;

	temp = ft_atoi(av[1]);
	if (temp > INT_MAX || temp <= 0)
		return (0);
	data->number = (int)temp;
	temp = ft_atoi(av[2]);
	if (temp > INT_MAX || temp < 0)
		return (0);
	data->die = temp;
	temp = ft_atoi(av[3]);
	if (temp > INT_MAX || temp < 0)
		return (0);
	data->eat = temp;
	temp = ft_atoi(av[4]);
	if (temp > INT_MAX || temp < 0)
		return (0);
	data->sleep = temp;
	temp = ft_atoi(av[5]);
	if (temp > INT_MAX || temp < 0)
		return (0);
	data->option_arg = (int)temp;
	return (1);
}
