/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:14:07 by mhaddou           #+#    #+#             */
/*   Updated: 2025/02/03 16:31:20 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_pos_nig(int c)
{
	return (c == '+' || c == '-');
}

int	ft_iswspace(int c)
{
	return ((c >= 9 && c <= 13) || (c == 32));
}

int	ft_atoi_checker(char *c, int *string_n)
{
	size_t	i;

	i = -1;
	int (val), (inside);
	val = 1;
	inside = 0;
	while (c[++i])
	{
		if (!ft_iswspace(c[i]) && !ft_pos_nig(c[i]) && !ft_isdigit(c[i]))
			return (1);
		if (ft_pos_nig(c[i]) && (ft_pos_nig(c[i + 1]) || c[i + 1] == '\0'
				|| ft_iswspace(c[i + 1])))
			return (1);
		if (ft_pos_nig(c[i]) && i > 0 && !ft_iswspace(c[i - 1]))
			return (1);
		(*string_n) += 1 * (ft_isdigit(c[i]) && !inside);
		inside = ((ft_isdigit(c[i]) && !inside)
				|| (inside * !ft_iswspace(c[i])));
	}
	(*string_n) += (!!(*string_n) && (*string_n) != 1);
	val = 1 * (!*string_n);
	return (1 * (val == 1 || !c[0]) + 0 * (!val));
}

long	ft_atoi(const char *nptr)
{
	ssize_t	index;
	long	sign;
	long	result;

	result = 0;
	sign = 1;
	index = 0;
	while (ft_iswspace(nptr[index]))
		index++;
	if (ft_pos_nig(nptr[index]))
	{
		if (nptr[index] == '-')
			sign = -1;
		index++;
	}
	while (ft_isdigit(nptr[index]))
	{
		result = result * 10 + (nptr[index] - 48);
		index++;
	}
	return (result * sign);
}


/*
list of errors:
""
"+"
"-"
"++"
"--"
"+-"
"-+"
"13+37"
"+484sfdf"
*/