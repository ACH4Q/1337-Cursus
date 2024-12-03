/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 05:59:16 by machaq            #+#    #+#             */
/*   Updated: 2024/12/03 22:09:11 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	checker(char spec, va_list args, char flag)
{
	int	len;

	len = 0;
	if (spec == 'c')
		len = ft_putchar(va_arg(args, int));
	else if (spec == 's')
		len = ft_putstr(va_arg(args, char *));
	else if (spec == 'd' || spec == 'i')
		len = ft_printnb(va_arg(args, int), flag);
	else if (spec == 'u')
		len = ft_printunsnb(va_arg(args, unsigned int));
	else if (spec == 'x')
		len = ft_printhex(va_arg(args, unsigned long), "0123456789abcdef", flag);
	else if (spec == 'X')
		len = ft_printhex(va_arg(args, unsigned long), "0123456789ABCDEF", flag);
	else if (spec == 'p')
	{
		len = ft_putstr("0x");
		len += ft_printhex(va_arg(args, unsigned long), "0123456789abcdef", flag);
	}
	else if (spec == '%')
		len = ft_putchar('%');
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	char	flag;

	va_start(args, s);
	i = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			flag = 0;
			if (*s == '#' || *s == '+' || *s == ' ')
			{
				flag = *s;
				s++;
			}
			if (*s)
				i += checker(*s, args, flag);
		}
		else
			i += ft_putchar(*s);
		s++;
	}
	va_end(args);
	return (i);
}
