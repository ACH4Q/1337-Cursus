/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 05:59:16 by machaq            #+#    #+#             */
/*   Updated: 2024/11/30 06:20:21 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int checker(char c,va_list args)
{
    if(c == 's')

}
int ft_printf(const char *s, ...)
{
    char    *str;
    va_list args;
    va_start(args,s);
    while (s)
    {
        if(s =  '%')
        {
            ++s;
            str = checker
            ++s;
        }
        else
        {
            str = ft_putchar(*s); 
            ++s;    
        }
    }
    va_end(args);
}