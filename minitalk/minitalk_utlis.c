/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utlis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:18:20 by machaq            #+#    #+#             */
/*   Updated: 2024/12/25 16:48:03 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    ft_putchar(char c)
{
    write(1,&c,1);
}

void    ft_putstr(char *s)
{
    while (*s)
    {
        ft_putchar(s);
        s++;
    }
}

int     ft_power(int nb, int power)
{
    int i;
    if (power < 0)
        return (0);
    while (power > 0)
    {
        i *= nb;
        power--;
    }
    return (i);
}

void    ft_putnbr(int n)
{
	if (n >= 0 && n <= 9)
		ft_putchar(n + 48);
	else if (n == -2147483648)
        ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void	ft_sender(__pid_t pid, char c)
{
	int	bits;
	int	kill_status;

	bits = 0b10000000;
	while (bits)
	{
		if (c & bits)
		{
			kill_status = kill(pid, SIGUSR2);
			if (kill_status < 0)
				return ;
		}
		else
		{
			kill_status = kill(pid, SIGUSR1);
			if (kill_status < 0)
				return ;
		}
		bits >>= 1;
		usleep(250);
	}
} 