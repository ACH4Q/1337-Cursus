/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utlis_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 00:53:12 by machaq            #+#    #+#             */
/*   Updated: 2025/03/15 03:58:15 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_atoi(const char *str, int *value)
{
	int		i;
	int		neg;
	long	res;

	i = 0;
	neg = 1;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	res = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	*value = res * neg;
	if ((res * neg) > INT_MAX || (res * neg) < INT_MIN)
		return (1);
	return (0);
}

int	parsing_args(int argv, char **argc, t_table *table)
{
	if (argv < 5)
		return (EINVAL);
	if (ft_atoi(argc[1], &table->num_philos) || ft_atoi(argc[2],
			&table->data.time_to_die) || ft_atoi(argc[3],
			&table->data.time_to_eat) || ft_atoi(argc[4],
			&table->data.time_to_sleep))
		return (EINVAL);
	table->data.number_time_eats = -1;
	if (argv == 6)
	{
		if (ft_atoi(argc[5], &table->data.number_time_eats))
			return (EINVAL);
	}
	if (table->num_philos < 1)
		return (EINVAL);
	if (table->data.time_to_die < 0 || table->data.time_to_eat < 0
		|| table->data.time_to_sleep < 0)
		return (EINVAL);
	return (0);
}

static int	write_error(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (write(2, str, len));
}

int	ft_error(int error)
{
	if (error == EINVAL)
		write_error("Invalid arguments\n");
	if (error == ENOMEM)
		write_error("Out of memory\n");
	return (error);
}
