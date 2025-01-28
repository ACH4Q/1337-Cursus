/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:24:54 by machaq            #+#    #+#             */
/*   Updated: 2025/01/08 18:43:38 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	clean_buffer(char *c, int *arr_numbit, int *arr_other_pid)
{
	if (*c != '\0')
		write(1, &*c, 1);
	*c = 0;
	*arr_numbit = 0;
	*arr_other_pid = 0;
}

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
	static int	arr[3];
	static char	c;

	check(&arr[PID], &arr[OTHER_PID], &info->si_pid);
	if (info->si_pid != arr[PID])
		return ;
	(void) context;
	if (sig == SIGUSR1)
		c |= (1 << arr[NUMBIT]);
	else if (sig == SIGUSR2)
		c |= (0 << arr[NUMBIT]);
	(arr[NUMBIT])++;
	if (arr[NUMBIT] == 8)
	{
		if (c == '\0')
		{
			write(1, "\n", 1);
			if (kill(info->si_pid, SIGUSR2) == -1)
				write(1, "\n[ ==> error while sending <== ]\n\n", 35);
		}
		clean_buffer(&c, &arr[NUMBIT], &arr[OTHER_PID]);
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		write(1, "\n[ ==> error while sending <== ]\n\n", 35);
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
		write(1, "this the pid :", 15);
		ft_putnbr(getpid());
		write (1, "\nwaiting for signal...\n", 24);
		while (1)
			sleep(1);
	}
	return (0);
}
