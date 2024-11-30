/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 05:59:16 by machaq            #+#    #+#             */
/*   Updated: 2024/11/30 06:27:31 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int checker(char c,va_list args)
{
    int i;
    i = 0;

    if(c == 'c')
        i += ft_putchar(va_arg(args,int));
}
int ft_printf(const char *s, ...)
{
    int     *i;
    va_list args;
    va_start(args,s);
    i = 0;

    while (s)
    {
        if(s == '%')
        {
            ++s;
            i = checker();
            ++s;
        }
        else
        {
            i = ft_putchar(*s); 
            ++s;    
        }
    }
    va_end(args);
    return(i);
}