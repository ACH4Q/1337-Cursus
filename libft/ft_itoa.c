/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:14:04 by machaq            #+#    #+#             */
/*   Updated: 2024/11/02 18:05:59 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	number_len(int n)
{
	int	counter;

	counter = 0;
	if (n <= 0)
	{
		counter++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	int			len;
	long long	j;
	char		*str;

    j = n;
	len = number_len(n);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (j < 0)
	{
		str[0] = '-';
		j = -j;
	}
	else if (j == 0)
		str[0] = '0';
	while (j > 0)
	{
		str[--len] = (j % 10) + '0';
		j /= 10;
	}
	return (str);
}
