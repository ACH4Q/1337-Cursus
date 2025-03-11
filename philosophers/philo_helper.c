/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 07:18:10 by machaq            #+#    #+#             */
/*   Updated: 2025/03/11 01:16:43 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_detach(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->all->n_philos)
		pthread_detach(philo[i].thread);
	i = -1;
	while (++i < philo->all->n_philos)
		pthread_mutex_destroy(&philo->all->mutex[i]);
	pthread_mutex_destroy(&philo->all->write);
	pthread_mutex_destroy(&philo->all->death);
	philo_free(philo);
	return ((void *)0);
}

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parse_arguments(int ac, char **av)
{
	int	i;
	int	num;

	if (ac != 5 && ac != 6)
		return (printf("Error: Invalid number of arguments\n"), 1);
	i = 0;
	while (++i < ac)
	{
		if (!is_valid_number(av[i]))
			return (printf("Error: Invalid argument '%s'\n", av[i]), 1);
		num = ft_atoi(av[i]);
		if (i <= 4 && num <= 0)
			return (printf("Error: Argument %d must be positive\n", i), 1);
		if (i == 5 && num <= 0)
			return (printf("Error: Optional argument must be positive\n"), 1);
	}
	return (0);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
