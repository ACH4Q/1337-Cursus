/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 04:54:40 by machaq            #+#    #+#             */
/*   Updated: 2024/10/25 05:06:30 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	size_i;
	size_t	size_j;

	size_i = 0;
	size_j = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	while (haystack[size_i] && size_i < len)
	{
		while (haystack[size_i + size_j] == needle[size_j] && haystack[size_i
				+ size_j] && size_i + size_j < len)
		{
			size_j++;
			if (needle[size_j] == 0)
				return ((char *)haystack + size_i);
		}
		size_i++;
		size_j = 0;
	}
	return (0);
}
