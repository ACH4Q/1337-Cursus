/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:45:10 by machaq            #+#    #+#             */
/*   Updated: 2025/03/14 20:26:07 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int (i), (sign), (result);
	(1) && (i = 0), (sign = 1), (result = 0);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (str[i] != '\0')
		return (-1337);
	return (sign * result);
}

t_ul	get_time(void)
{
	struct timeval	t;
	t_ul			msc;

	gettimeofday(&t, NULL);
	msc = t.tv_sec * 1000 + t.tv_usec / 1000;
	return (msc);
}

int	_usleep(t_ul _sleep)
{
	t_ul	start;

	start = get_time();
	while (get_time() - start < _sleep)
		usleep(200);
	return (0);
}

void	write_locker(char *s, t_philo *philo)
{
	pthread_mutex_lock(&philo->all->write);
	printf("%lu %d %s\n", get_time() - philo->all->s_time, philo->id + 1, s);
	pthread_mutex_unlock(&philo->all->write);
}

void	philo_free(t_philo *philo)
{
	free(philo->all->mutex);
	free(philo->all);
	free(philo);
}
