/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:06:39 by machaq            #+#    #+#             */
/*   Updated: 2024/12/03 22:11:26 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnb(int nb, char flag)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb = -nb;
	}
	else if (flag == '+' || flag == ' ')
		len += ft_putchar(flag);
	if (nb >= 10)
		len += ft_printnb(nb / 10, 0);
	len += ft_putchar((nb % 10) + '0');
	return (len);
}
