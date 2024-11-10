/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:01:26 by machaq            #+#    #+#             */
/*   Updated: 2024/11/08 21:16:58 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	src_len;
	char	*str_allocated;

	if (!s)
		return (NULL);
	src_len = ft_strlen(s);
	if (start >= src_len)
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str_allocated = malloc(len + 1);
	if (!str_allocated)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str_allocated[i] = s[i + start];
		i++;
	}
	str_allocated[i] = '\0';
	return (str_allocated);
}
