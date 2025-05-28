/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:39:56 by machaq            #+#    #+#             */
/*   Updated: 2025/03/19 19:39:58 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_sleep(t_philo *pth, long end)
{
	long	start;

	(void)pth;
	start = get_time();
	while ((get_time() - start < end))
	{
		ft_lock(&(pth->box->mutex_die));
		if (pth->box->someone_die)
		{
			unlock(&(pth->box->mutex_die));
			break ;
		}
		unlock(&(pth->box->mutex_die));
		usleep(100);
	}
}

void	ft_sleep_for_one(long end)
{
	long	start;

	start = get_time();
	while ((get_time() - start < end))
	{
		usleep(200);
	}
}
