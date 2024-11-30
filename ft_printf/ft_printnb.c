/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:06:39 by machaq            #+#    #+#             */
/*   Updated: 2024/11/30 16:07:12 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnb(int nb, char flag)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	else if (flag == '+')
	{
		ft_putchar('+');
		len++;
	}
	else if (flag == ' ')
	{
		ft_putchar(' ');
		len++;
	}
	if (nb >= 10)
		len += ft_printnb(nb / 10, 0);
	ft_putchar((nb % 10) + '0');
	return (len + 1);
}
