/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_phil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:40:13 by machaq            #+#    #+#             */
/*   Updated: 2025/03/19 19:40:18 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

void	run_philo(char **av)
{
	if (check_arg(av))
		return ;
	if (ft_atoi(av[1]) == 1)
		creat_one_philo(av);
	else
		creat_philo(av);
}
