/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsnb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 06:43:42 by machaq            #+#    #+#             */
/*   Updated: 2024/11/30 10:33:19 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int num_len_unsigned(unsigned int i)
{
    int j;
    j = 0;
    
    if (i <= 0)
        j++;
    while(i)
    {
        j++;
        i /= 10;
    }
    return (j);
}

int ft_printunsnb(unsigned int i)
{
    if (i == 0)
    {
        ft_putchar('0');
        return (1);
    }
    if(i <= 9)
        ft_putchar(i + '0');
    else
    {
        ft_printunsnb(i / 10);
        ft_putchar(i % 10 + '0');
    }
    return (num_len_unsigned(i));
}