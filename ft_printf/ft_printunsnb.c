/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsnb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 06:43:42 by machaq            #+#    #+#             */
/*   Updated: 2024/11/30 06:48:32 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int num_len(unsigned int i)
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

int ft_printfunsnb(unsigned int i)
{
    if(i <= 9)
        ft_putchar(i);
    else
    {
        ft_printfunsnb(i);
        ft_printfunsnb(i);
    }
    return (num_len(i));
}