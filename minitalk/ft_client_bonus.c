/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:19:40 by machaq            #+#    #+#             */
/*   Updated: 2025/01/01 17:26:47 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:16:03 by machaq            #+#    #+#             */
/*   Updated: 2024/12/26 10:45:00 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"


int	g_var = 0;

void	handel_kill(void)
{
	write(1, "\n[ ==> error while sending <== ]\n\n", 35);
	exit(1);
}

void	handle_ack(int sig)
{
	if (sig == SIGUSR1)
		g_var = 1;
	else
		write (1, "\n[ ==> your message has been recieved🙂! <== ]\n\n", 51);
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
		while (g_var == 0)
			pause();
		usleep(500);
		g_var = 0;
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
	pid = ft_atoi(av[1]);
	s = av[2];
	i = 0;
	if (pid < -1)
		handel_kill();
	if (pid == -1)
	{
		write (1, "invalide PID\n", 21);
		return (1);
	}
	signal(SIGUSR1, handle_ack);
	signal(SIGUSR2, handle_ack);
	while (s[i])
	{
		send_mess(pid, s[i]);
		i++;
	}
	send_mess(pid, '\0');
	return (0);
}