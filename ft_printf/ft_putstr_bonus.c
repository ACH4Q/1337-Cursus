/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 06:32:24 by machaq            #+#    #+#             */
/*   Updated: 2024/12/03 22:10:14 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putstr(const char *s)
{
	int	len;

	len = 0;
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (*s)
		len += ft_putchar(*s++);
	return (len);
}
