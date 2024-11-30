/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 05:59:16 by machaq            #+#    #+#             */
/*   Updated: 2024/11/30 08:45:22 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int checker(char const *s,va_list args)
{
    int i;
    i = 0;

    if (s == 'c')
        i = ft_putchar(va_arg(args,int));
    else (s == 's')
        i = ft_putstr(va_arg(args,int));
    else (s == 'd' || s == 'i')
        i = ft_printnb(va_arg(args,int));
    else (s == 'x')
        i = ft_printunsnb(va_arg(args,unsigned int),"0123456789abcdef");
    else (s == 'X')
        i = ft_printfunsnb(va_arg(args,unsigned int),"0123456789abcdef");
    else (s == 'p')
    {
        i = ft_putstr("0x")
        i = ft_printhex(va_arg(args,unsigned long),"0123456789abcdef");
    }
    else (s == '%')
        i = ft_putchar('%');
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
            i = checker(s,args);
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