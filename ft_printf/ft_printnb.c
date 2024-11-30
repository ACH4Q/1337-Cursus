/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 06:36:09 by machaq            #+#    #+#             */
/*   Updated: 2024/11/30 09:27:06 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int num_len(int nb)
{
    int i;
    i = 0;
    if (nb <= 0)
        i++;
    while (nb)
    {
        ++i;
        nb /= 10;
    }
    return (i);
}

int ft_printnb(int nb)
{
	if (nb >= 0 && nb <= 9)
		ft_putchar(nb + 48);
	else if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_printnb(-nb);
	}
	else
	{
		ft_printnb(nb / 10);
		ft_printnb(nb % 10);
	}
    return(num_len(nb));
}