/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:05:13 by machaq            #+#    #+#             */
/*   Updated: 2024/11/30 18:13:27 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checker(char spec, va_list args, char flag)
{
	int	i;

	i = 0;
	if (spec == 'c')
		i = ft_putchar(va_arg(args, int));
	else if (spec == 's')
		i = ft_putstr(va_arg(args, char *));
	else if (spec == 'd' || spec == 'i')
		i = ft_printnb(va_arg(args, int), flag);
	else if (spec == 'u')
		i = ft_printunsnb(va_arg(args, unsigned int));
	else if (spec == 'x')
		i = ft_printhex(va_arg(args, unsigned long), "0123456789abcdef", flag);
	else if (spec == 'X')
		i = ft_printhex(va_arg(args, unsigned long), "0123456789ABCDEF", flag);
	else if (spec == 'p')
	{
		i = ft_putstr("0x");
		i += ft_printhex(va_arg(args, unsigned long), "0123456789abcdef", flag);
	}
	else if (spec == '%')
		i = ft_putchar('%');
	return (i);
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
			i += checker(*s, args, flag);
		}
		else
			i += ft_putchar(*s);
		s++;
	}
	va_end(args);
	return (i);
}
