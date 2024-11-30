/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 05:59:16 by machaq            #+#    #+#             */
/*   Updated: 2024/11/30 13:37:25 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int checker(char const *s,va_list args,char flag)
{
    int i;
    i = 0;

    if (*s == '#' || *s == '+' || *s == ' ')
    {
        flag = *s;
        ++s;
    }
    if (*s == 'c')
        i = ft_putchar(va_arg(args,int));
    else if (*s == 's')
        i = ft_putstr(va_arg(args,char *));
    else if (*s == 'd' || *s == 'i')
        i = ft_printnb(va_arg(args,int),flag);
    else if (*s == 'u')
        i = ft_printunsnb(va_arg(args,unsigned int));
    else if (*s == 'x')
        i = ft_printhex(va_arg(args,unsigned long),"0123456789abcdef",flag);
    else if (*s == 'X')
        i = ft_printhex(va_arg(args,unsigned long),"0123456789ABCDEF",flag);
    else if (*s == 'p')
    {
        i = ft_putstr("0x");
        i += ft_printhex(va_arg(args,unsigned long),"0123456789abcdef",flag);
    }
    else if (*s == '%')
        i = ft_putchar('%');
    return (i);
}

int ft_printf(const char *s, ...)
{
    int i = 0;
    va_list args;
    char flag = 0;

    va_start(args, s);
    while (*s)
    {
        if (*s == '%')
        {
            ++s;
            if (*s == '#' || *s == '+' || *s == ' ')
            {
                flag = *s;
                ++s;
            }
            else
                flag = 0;
            i += checker(s, args, flag);
            ++s;
        }
        else
        {
            i += ft_putchar(*s);
            ++s;
        }
    }
    va_end(args);
    return (i);
}
