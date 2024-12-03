/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:06:10 by machaq            #+#    #+#             */
/*   Updated: 2024/12/03 22:12:02 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned long address, const char *base, char flag)
{
	int	len;

	len = 0;
	if (address == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (flag == '#' && address != 0)
	{
		ft_putchar('0');
		if (base[10] == 'a')
			ft_putchar('x');
		else
			ft_putchar('X');
		len += 2;
	}
	if (address >= 16)
		len += ft_printhex(address / 16, base, 0);
	ft_putchar(base[address % 16]);
	return (len + 1);
}
