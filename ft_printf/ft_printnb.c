/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 06:36:09 by machaq            #+#    #+#             */
/*   Updated: 2024/11/30 13:10:46 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printnb(int nb, char flag)
{
    if (nb == -2147483648)
    {
        write(1, "-2147483648", 11);
        return (11);
    }

    if (nb < 0)
    {
        ft_putchar('-');
        nb = -nb;
    }
    else if (flag == '+')
        ft_putchar('+');
    else if (flag == ' ')
        ft_putchar(' ');

    if (nb >= 10)
        return (num_len(nb) + ft_printnb(nb / 10, 0));

    ft_putchar((nb % 10) + '0');
    return (num_len(nb));
}
