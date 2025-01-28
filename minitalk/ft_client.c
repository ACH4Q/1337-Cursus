/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:16:03 by machaq            #+#    #+#             */
/*   Updated: 2025/01/08 19:12:17 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handel_kill(void)
{
	write(1, "\n[ ==> error while sending <== ]\n\n", 35);
	exit(1);
}

void	send_mess(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				handel_kill();
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				handel_kill();
		}
		usleep(500);
		i++;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*s;
	int		i;

	if (ac != 3)
	{
		write(1, "\n[ ==> ./client <server_pid> <message> <== ]\n\n", 47);
		return (1);
	}
	if (ft_strlen(av[1]) > 11)
		return (1);
	pid = ft_atoi(av[1]);
	s = av[2];
	i = 0;
	if (pid <= 0)
		handel_kill();
	while (s[i])
	{
		send_mess(pid, s[i]);
		i++;
	}
	send_mess(pid, '\0');
	return (0);
}
