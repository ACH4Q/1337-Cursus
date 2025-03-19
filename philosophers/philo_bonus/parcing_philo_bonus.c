/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_philo_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:14:42 by machaq            #+#    #+#             */
/*   Updated: 2025/03/19 14:39:26 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	validate_args(int ac, char **av, t_data *data)
{
	if (ac != 5 && ac != 6)
	{
		printf("invalid syntax.\n");
		return (0);
	}
	if (!init_data(data, av, ac))
	{
		printf("invalid arguments.\n");
		return (0);
	}
	return (1);
}

int	initialize_simulation(int ac, char **av, t_process **philos, t_data *data)
{
	if (!validate_args(ac, av, data))
		return (0);
	*philos = init_process(data);
	if (!*philos)
	{
		printf("Error in the initialization of the process.\n");
		return (0);
	}
	return (1);
}

t_process	*init_process(t_data *data)
{
	int			i;
	t_process	*process;

	process = (t_process *)malloc(sizeof(t_process) * data->number);
	if (!process)
		return (NULL);
	i = 0;
	while (i < data->number)
	{
		process[i].data = data;
		process[i].index = i + 1;
		process[i].number_eat = 0;
		i++;
	}
	return (process);
}

void	one_philo(t_process *philo, t_time start)
{
	t_time	end;

	sem_wait(philo->data->lock);
	gettimeofday(&end, NULL);
	printf("%ld %d has taken a fork\n", set_time(start, end), philo->id);
	printf("%ld %d died\n", set_time(start, end), philo->id);
	sem_post(philo->data->lock);
	if (philo->data->option_arg == -1)
		sem_wait(philo->data->alive);
	else
		sem_wait(philo->data->count);
}
