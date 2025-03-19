/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utlis_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 00:53:12 by machaq            #+#    #+#             */
/*   Updated: 2025/03/19 14:12:28 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_whitespace(char *str, int *i)
{
	int	sign;

	sign = 1;
	(*i) = 0;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	check_digit(int i, char *str)
{
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	ft_atoi(char *str)
{
	long	nbr;
	int		i;
	int		sign;

	nbr = 0;
	if (!str)
		return ((long)INT_MAX + 1);
	sign = ft_whitespace(str, &i);
	if (!check_digit(i, str))
		return ((long)INT_MAX + 1);
	while (str[i] <= '9' && str[i] >= '0')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	nbr *= sign;
	return (nbr);
}

void	cleanup(t_process *philos, t_data *data)
{
	if (data->lock)
		sem_close(data->lock);
	if (data->alive)
		sem_close(data->alive);
	if (data->forks)
		sem_close(data->forks);
	if (data->mutex_fork)
		sem_close(data->mutex_fork);
	if (data->count)
	{
		sem_close(data->count);
	}
	sem_unlink("/alive");
	sem_unlink("lock");
	sem_unlink("forks");
	sem_unlink("counter");
	sem_unlink("mutex_fork");
	free(philos);
}

void	cleanup_child(t_process *philos)
{
	if (philos->data->lock)
		sem_close(philos->data->lock);
	if (philos->data->forks)
		sem_close(philos->data->forks);
	if (philos->data->mutex_fork)
		sem_close(philos->data->mutex_fork);
	if (philos->data->count)
	{
		sem_close(philos->data->count);
	}
}
