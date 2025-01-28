/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:51:11 by machaq            #+#    #+#             */
/*   Updated: 2025/01/08 18:52:57 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_arr[3];

void	check(int *arr_pid, int *arr_other_pid, int *info)
{
	if (!*arr_other_pid)
	{
		*arr_pid = *info;
		*arr_other_pid = 1;
	}
}

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char	c;

	check(&g_arr[0], &g_arr[1], &info->si_pid);
	if (info->si_pid != g_arr[0])
		return ;
	(void) context;
	if (sig == SIGUSR1)
		c |= (1 << g_arr[2]);
	else if (sig == SIGUSR2)
		c |= (0 << g_arr[2]);
	g_arr[2]++;
	if (g_arr[2] == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		c = 0;
		g_arr[2] = 0;
		g_arr[1] = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	if (ac == 1)
	{
		sa.sa_sigaction = handle_signal;
		sa.sa_flags = SA_SIGINFO;
		if (sigaction(SIGUSR1, &sa, NULL) == -1
			|| sigaction(SIGUSR2, &sa, NULL) == -1)
		{
			write(1, "\n[ ==> error setting up signal handlers <== ]\n\n", 48);
			return (1);
		}
		write(1, "Server PID: ", 12);
		ft_putnbr(getpid());
		write(1, "\nWaiting for signals...\n", 24);
		while (1)
			pause();
	}
	return (0);
}
