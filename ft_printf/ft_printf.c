/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 05:59:16 by machaq            #+#    #+#             */
/*   Updated: 2024/11/30 06:17:07 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int checker(char c,va_list args)
{
    if(c == 's')

}
int ft_printf(const char *s, ...)
{
    va_list args;
    va_start(args,s);
    while (s)
    {
        if(s =  '%')
        {
            *s++;
            checker
        }
    }
    
}