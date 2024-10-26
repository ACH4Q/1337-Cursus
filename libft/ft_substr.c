/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:01:26 by machaq            #+#    #+#             */
/*   Updated: 2024/10/26 22:33:56 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size_allocated;
	char	*str_allocated;

	size_allocated = ft_strlen(s + start);
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	if (len > size_allocated)
	{
		len = size_allocated + 1;
	}
	str_allocated = malloc(size_allocated);
	if (!str_allocated)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		str_allocated[i] = s[i + start];
		i++;
	}
	str_allocated[i] = '\0';
	return (str_allocated);
}
