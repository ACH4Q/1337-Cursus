/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:18:20 by machaq            #+#    #+#             */
/*   Updated: 2024/12/26 09:14:59 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *s)
{
    while (*s)
    {
        ft_putchar(*s);
        s++;
    }
}

int ft_power(int nb, int power)
{
    int result = 1;

    if (power < 0)
        return (0);
    while (power > 0)
    {
        result *= nb;
        power--;
    }
    return (result);
}

void ft_putnbr(int n)
{
    if (n == -2147483648)
        ft_putstr("-2147483648");
    else if (n < 0)
    {
        ft_putchar('-');
        ft_putnbr(-n);
    }
    else if (n < 10)
        ft_putchar(n + '0');
    else
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
}

void ft_sender(__pid_t pid, char c)
{
    int bits = 0b10000000;

    while (bits)
    {
        if (c & bits)
        {
            if (kill(pid, SIGUSR2) < 0)
                return;
        }
        else
        {
            if (kill(pid, SIGUSR1) < 0)
                return;
        }
        bits >>= 1;
        usleep(200);
    }
}
