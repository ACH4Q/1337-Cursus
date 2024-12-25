/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:16:03 by machaq            #+#    #+#             */
/*   Updated: 2024/12/25 16:48:45 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_client(__pid_t pid, char *s)
{
	while (*s)
	{
		ft_sender(pid, *s);
		++s;
	}
}

int	main(int ac, char **ag)
{
	if (ac <= 2)
	{
		ft_putstr("[!] Missing Arguments\n");
		return (0);
	}
	if (ft_atoi(ag[1]) <= 0)
	{
		ft_putstr("[!] Invalid Process Id\n");
		return (0);
	}
	ft_client(ft_atoi(ag[1]), ag[2]);
	return (0);
}