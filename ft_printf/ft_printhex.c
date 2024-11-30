/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 06:50:15 by machaq            #+#    #+#             */
/*   Updated: 2024/11/30 09:27:13 by machaq           ###   ########.fr       */
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

int ft_printhex(unsigned long adress,const char *s)
{
    if (adress == 0)
    {
        ft_putstr("(nil)");
        return (5);
    }
    if (adress > 15)
    {
        ft_printhex(adress / 16,s);
        ft_printhex(s[adress % 16],s);
    }
    else
        ft_putchar(s[adress % 16]);
    return(num_len(adress));
}