/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:08:32 by machaq            #+#    #+#             */
/*   Updated: 2024/12/03 22:09:52 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
