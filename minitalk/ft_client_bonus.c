/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:19:40 by machaq            #+#    #+#             */
/*   Updated: 2024/12/26 11:24:01 by machaq           ###   ########.fr       */
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

void ft_client(__pid_t pid, char *s)
{
    while (*s)
    {
        ft_sender(pid, *s);
        pause();
        s++;
    }
    ft_sender(pid, '\n');
    pause();
    ft_sender(pid, '\0');
    pause();
}

void ft_acknowledge(int sig)
{
    (void)sig;
}

int main(int ac, char **av)
{
    if (ac != 3)
    {
        ft_putstr("Usage: ./client_bonus <SERVER_PID> <MESSAGE>\n");
        return (1);
    }

    __pid_t pid = ft_atoi(av[1]);
    if (pid <= 0)
    {
        ft_putstr("Error: Invalid process ID.\n");
        return (1);
    }

    signal(SIGUSR1, ft_acknowledge);
    ft_client(pid, av[2]);
    return (0);
}
