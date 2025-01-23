/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:05:13 by machaq            #+#    #+#             */
/*   Updated: 2024/12/04 13:15:06 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checker(char spec, va_list args, char flag)
{
	int	len;

	len = 0;
	if (spec == 'c')
		len = ft_putchar(va_arg(args, int));
	else if (spec == 's')
		len = handle_string(va_arg(args, char *));
	else if (spec == 'd' || spec == 'i')
		len = ft_printnb(va_arg(args, int), flag);
	else if (spec == 'u')
		len = ft_printunsnb(va_arg(args, unsigned int));
	else if (spec == 'x')
		len = ft_printhex((unsigned long)va_arg(args, unsigned int),
				"0123456789abcdef", flag);
	else if (spec == 'X')
		len = ft_printhex((unsigned long)va_arg(args, unsigned int),
				"0123456789ABCDEF", flag);
	else if (spec == 'p')
		len = handle_pointer((unsigned long)va_arg(args, void *));
	else if (spec == '%')
		len = ft_putchar('%');
	return (len);
}

int	handle_string(const char *str)
{
	int	len;
	int	str_len;

	len = 0;
	str_len = 0;
	if (str == NULL)
		str = "(null)";
	while (str[str_len])
		str_len++;
	len += ft_putstr(str);
	return (len);
}

int	handle_pointer(unsigned long address)
{
	int	len;

	len = 0;
	if (address == 0)
		len = ft_putstr("(nil)");
	else
	{
		len += ft_putstr("0x");
		len += ft_printhex(address, "0123456789abcdef", 0);
	}
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		len;
	char	flag;

	len = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			flag = 0;
			if (*s == '#' || *s == '+' || *s == ' ')
				flag = *s++;
			if (*s)
				len += checker(*s, args, flag);
		}
		else
			len += ft_putchar(*s);
		if (*s)
			s++;
	}
	va_end(args);
	return (len);
}
