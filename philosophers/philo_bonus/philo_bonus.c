/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 00:53:04 by machaq            #+#    #+#             */
/*   Updated: 2025/03/19 14:39:07 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_process	*philos;
	t_data		data;

	if (!initialize_simulation(ac, av, &philos, &data))
		return (0);
	if (!create_processes(philos))
	{
		kill_processes(philos);
		cleanup(philos, &data);
		return (1);
	}
	if (philos->data->option_arg == -1)
	{
		while (1)
		{
			if (data.alive->__align == 0)
				break ;
		}
	}
	else
		wait_for_processes(&data);
	kill_processes(philos);
	cleanup(philos, &data);
	return (0);
}

void	wait_for_processes(t_data *data)
{
	while (1)
	{
		if (data->count->__align == 0)
			break ;
	}
}

void	kill_processes(t_process *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->number)
	{
		if (philo[i].id > 0)
		{
			kill(philo[i].id, SIGKILL);
		}
		i++;
	}
}

int	create_processes(t_process *philos)
{
	int	i;
	int	number;

	number = philos->data->number;
	i = 0;
	gettimeofday(&philos[i].data->start, NULL);
	while (i < number)
	{
		philos[i].id = fork();
		if (philos[i].id < 0)
			return (0);
		if (philos[i].id == 0)
		{
			simulation(&philos[i]);
			cleanup_child(&philos[i]);
			exit(0);
		}
		i++;
	}
	return (1);
}
