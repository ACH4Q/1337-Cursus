/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:41:05 by machaq            #+#    #+#             */
/*   Updated: 2024/11/06 00:09:44 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			char_c;
	char			*last_one;

	i = 0;
	char_c = (char)c;
	last_one = NULL;
	while (s[i])
	{
		if (s[i] == char_c)
		{
			last_one = (char *)&s[i];
		}
		i++;
	}
	if (char_c == '\0')
	{
		return ((char *)&s[i]);
	}
	return (last_one);
}
