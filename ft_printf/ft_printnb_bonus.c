/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnb_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 06:36:09 by machaq            #+#    #+#             */
/*   Updated: 2024/11/30 18:07:46 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printnb(int nb, char flag)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
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
