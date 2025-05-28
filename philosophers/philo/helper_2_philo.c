/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_2_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:39:54 by machaq            #+#    #+#             */
/*   Updated: 2025/03/19 21:37:51 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	mutex_init(t_mutex *ptr)
{
	pthread_mutex_init(ptr, NULL);
}

void	unlock(t_mutex *ptr)
{
	pthread_mutex_unlock(ptr);
}

void	ft_lock(t_mutex *ptr)
{
	pthread_mutex_lock(ptr);
}
