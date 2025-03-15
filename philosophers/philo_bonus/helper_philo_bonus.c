/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_philo_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 01:55:04 by machaq            #+#    #+#             */
/*   Updated: 2025/03/15 04:00:55 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	timestamp(void)
{
	struct timeval	time;
	unsigned long	l;
	unsigned long	s;
	unsigned long	u;

	gettimeofday(&time, NULL);
	s = (time.tv_sec * 1000);
	u = (time.tv_usec / 1000);
	l = s + u;
	return (l);
}

unsigned int	real_time(long long time)
{
	long long	now;

	now = timestamp();
	return ((unsigned int)(now - time));
}

void	philo_sleep(long long time)
{
	long long	init_time;

	init_time = timestamp();
	while (1)
	{
		if ((timestamp() - init_time) >= time)
			break ;
		usleep(600);
	}
}

int	status_print(t_philo *philo, char *str, int print_death)
{
	if (sem_wait(philo->data->sem_print))
		return (errno);
	if (printf("%04u Philo %03d %s\n", real_time(philo->data->start_time),
			philo->num_philo, str) < 0)
		return (EIO);
	if (print_death == 1)
		return (0);
	if (sem_post(philo->data->sem_print))
		return (errno);
	return (0);
}
