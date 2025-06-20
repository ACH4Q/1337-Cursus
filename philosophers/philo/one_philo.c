/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:40:05 by machaq            #+#    #+#             */
/*   Updated: 2025/03/19 19:40:07 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	creat_one_philo(char **av)
{
	long	start;

	start = get_time();
	printf("%d %d  has taken a fork\n", 0, 1);
	ft_sleep_for_one(ft_atoi(av[2]));
	printf("%ld %d died\n", get_time() - start, 1);
}

int	for25line(t_box *box)
{
	ft_lock(&(box->mutex_die));
	if (box->someone_die)
	{
		unlock(&(box->mutex_die));
		return (1);
	}
	unlock(&(box->mutex_die));
	return (0);
}
