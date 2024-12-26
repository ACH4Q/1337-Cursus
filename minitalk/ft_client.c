/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:16:03 by machaq            #+#    #+#             */
/*   Updated: 2024/12/26 09:17:51 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include "minitalk.h"

void ft_client(__pid_t pid, char *s)
{
    while (*s)
    {
        ft_sender(pid, *s);
        s++;
    }
    ft_sender(pid, '\n');
    ft_sender(pid, '\0');
}

int main(int ac, char **av)
{
    if (ac != 3)
    {
        ft_putstr("Usage: ./client <SERVER_PID> <MESSAGE>\n");
        return (1);
    }

    __pid_t pid = ft_atoi(av[1]);
    if (pid <= 0)
    {
        ft_putstr("Error: Invalid process ID.\n");
        return (1);
    }

    ft_client(pid, av[2]);
    return (0);
}
