/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:40:08 by machaq            #+#    #+#             */
/*   Updated: 2025/03/19 19:40:12 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

int	main(int ac, char **av)
{
	if (ac == 6 || ac == 5)
		run_philo(av);
	else
	{
		write(2, "error:\n", 8);
		write(2, "./philo", 8);
		write(2, " number_of_philosophers", 24);
		write(2, " time_to_die time_to_eat time_to_sleep", 39);
		write(2, " [number_of_times_each_philosopher_must_eat]\n", 46);
	}
	return (0);
}
