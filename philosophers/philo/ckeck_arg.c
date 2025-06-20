/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckeck_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:39:45 by machaq            #+#    #+#             */
/*   Updated: 2025/03/19 19:39:47 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

int	not_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+')
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
		{
			write(2, "error in: ", 11);
			write(2, s, ft_strlen(s));
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_arg(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (not_number(av[i]))
		{
			return (1);
		}
		else if (ft_atoi(av[i]) == 21474836479)
		{
			printf("error: '%s'\n", av[i]);
			return (1);
		}
		i++;
	}
	return (0);
}
