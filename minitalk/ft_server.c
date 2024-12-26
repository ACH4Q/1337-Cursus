/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:51:11 by machaq            #+#    #+#             */
/*   Updated: 2024/12/26 09:15:42 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_btoa(int sig)
{
    static int  bit = 0;
    static char ascii = 0;

    if (sig == SIGUSR2)
        ascii |= (1 << (7 - bit));
    bit++;

    if (bit == 8)
    {
        ft_putchar(ascii);
        bit = 0;
        ascii = 0;
    }
}

int main(int argc, char **argv)
{
    int pid;

    (void)argv;
    if (argc != 1)
    {
        ft_putstr("Error\n");
        return (1);
    }
    pid = getpid();
    ft_putstr("The server PID: ");
    ft_putnbr(pid);
    ft_putchar('\n');

    signal(SIGUSR1, ft_btoa);
    signal(SIGUSR2, ft_btoa);

    while (1)
        pause();

    return (0);
}
